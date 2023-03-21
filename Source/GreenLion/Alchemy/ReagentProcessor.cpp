// Fill out your copyright notice in the Description page of Project Settings.
#include "ReagentProcessor.h"
#include "ReagentData.h"
#include "Components/AudioComponent.h"
#include "GreenLion/Player/AlchemyPlayer.h"


// Sets default values
AReagentProcessor::AReagentProcessor()
{
	PrimaryActorTick.bCanEverTick = true;

	ProcessAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("Process Sound"));
	ProcessedReagentMesh = CreateDefaultSubobject<UStaticMeshComponent>("Processed Reagent Mesh");
	HeldReagent = nullptr;
}

// Called when the game starts or when spawned
void AReagentProcessor::BeginPlay()
{
	Super::BeginPlay();
	ProcessedReagentMesh->SetVisibility(false);

	//We do this so we don't have to check this every frame, since ReagentProcessors never change what sort of
	//Process they perform.
	isDistill = (Modifier == EModifierType::Distilled);

	//Only the distillery needs to tick, so we conditionally turn it on in case this is a distillery.
	PrimaryActorTick.bCanEverTick = isDistill;
	
}

// Called every frame
void AReagentProcessor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//If we're a distillation processor, we continuously process this object until it is picked up.
	if (isDistill && HeldReagent)
	{
		HeldReagent.Get()->DistillValue += DeltaTime * DISTILLATION_PER_SECOND;
	}
}

void AReagentProcessor::ProcessReagent()
{
	if (!HeldReagent) return;

	//We set the reagent to have our contained modifier...
	HeldReagent.Get()->ApplyModifier(Modifier, ProcessedReagentMesh->GetStaticMesh(), DistillValue);

	//And then show our imposter mesh!
	ProcessedReagentMesh->SetVisibility(true);
}

void AReagentProcessor::Interact(APlayerController* PlayerController)
{
	IInteractInterface::Interact(PlayerController);
	AAlchemyPlayer* Player = Cast<AAlchemyPlayer>(PlayerController->GetPawn());

	//If the player is holding nothing, and the Reagent has processed something...
	if (!Player->GetHeldObject())
	{
		//These are split into two independent checks so that we don't need an if-else at the bottom!
		if (HeldReagent)
		{
			//...We give the player our processed value...
			auto data = HeldReagent.Get();
			HeldReagent = nullptr;
			Player->SetHeldObject(data);
			//...hide the imposter mesh...
			ProcessedReagentMesh->SetVisibility(false);
			//reset our distillation value...
			DistillValue = isDistill? 0 : -1;
			//...and stop the associated sound, given it isn't empty, in case it's a looping clip!
			if (ProcessAudio) ProcessAudio->Stop();
		}
		return;
	}
	//if the player IS holding something, see if it's a FReagentData...
	if (auto Data = Cast<FReagentData>(Player->GetHeldObject().Get())) //if it is...
	{
		//...Give us the player's heldObject...
		Player->SetHeldObject(nullptr);
		HeldReagent = TUniquePtr<FReagentData>(Data);
		//...set our DistillValue to a proper value if it's a distillery...
		DistillValue = isDistill? 0 : -1;
		//...process it...
		ProcessReagent();
		//...and play the associated sound, given it isn't empty!
		if (ProcessAudio) ProcessAudio->Play();
	}
}

