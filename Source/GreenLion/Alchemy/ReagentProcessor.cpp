// Fill out your copyright notice in the Description page of Project Settings.
#include "ReagentProcessor.h"

#include "ReagentData.h"
#include "Components/AudioComponent.h"
#include "GreenLion/Player/AlchemyPlayer.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AReagentProcessor::AReagentProcessor()
{
	PrimaryActorTick.bCanEverTick = true;
	bHasReagent = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	ProcessorVisuals = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Processor Mesh"));
	ProcessorVisuals->SetupAttachment(RootComponent);
	
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Process Sound"));
	AudioComponent->SetupAttachment(RootComponent);
	
	ParticleEmitter = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle Emitter"));
	ParticleEmitter->SetupAttachment(RootComponent);
	
	ReagentImposter = CreateDefaultSubobject<UStaticMeshComponent>("Processed Reagent Mesh");
	ReagentImposter->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AReagentProcessor::BeginPlay()
{
	Super::BeginPlay();
	ReagentImposter->SetVisibility(false);

	//We do this so we don't have to check this every frame, since ReagentProcessors never change what sort of
	//Process they perform.
	bIsDistill = (Modifier == EModifierType::Distilled);

	//Only the distillery needs to tick, so we conditionally turn it on in case this is a distillery.
	PrimaryActorTick.bCanEverTick = bIsDistill;
	bIsDistill ? DistillValue = 0: DistillValue = -1;
	
}

// Called every frame
void AReagentProcessor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//If we're a distillation processor, we continuously process this object until it is picked up.
	if (bIsDistill && bHasReagent)
	{
		if (HeldReagent.DistillValue >= 1) {HeldReagent.DistillValue = 1; return;}
		HeldReagent.DistillValue += DeltaTime * DISTILLATION_PER_SECOND;
	}
}

void AReagentProcessor::ProcessReagent()
{
	//We set the reagent to have our contained modifier...
	HeldReagent.ApplyModifier(Modifier, ReagentImposter->GetStaticMesh(), DistillValue);

	//And then show our imposter mesh!
	ReagentImposter->SetVisibility(true);

	bHasReagent = true;
}

void AReagentProcessor::Interact(APlayerController* PlayerController)
{
	IInteractInterface::Interact(PlayerController);
	AAlchemyPlayer* Player = Cast<AAlchemyPlayer>(PlayerController->GetPawn());
	UE_LOG(LogTemp, Log, TEXT("Doing this"));

	//If the player is holding nothing, and the Reagent has processed something...
	if (bHasReagent)	
	{
		UE_LOG(LogTemp, Log, TEXT("Player !Hold"));
		if (Player->IsHoldingObject())
		{
			UE_LOG(LogTemp, Log, TEXT("Player was holding an object and we had a reagent. Exiting."))
			return;
		}
		//These are split into two independent checks so that we don't need an if-else at the bottom!
		//...We give the player our processed value...
		bHasReagent = false;
		Player->SetHeldObject(HeldReagent);
		//...hide the imposter mesh...
		ReagentImposter->SetVisibility(false);
		//reset our distillation value...
		DistillValue = bIsDistill? 0 : -1;
		//...and stop the associated sound, given it isn't empty, in case it's a looping clip!
		AudioComponent->Stop();
		return;
	}
	//if the player IS holding something, see if it's a Reagent...
	const auto HeldObject = Player->GetHeldObject();
	if (!HeldObject) return;
	if (HeldObject->ObjectType == EHoldableType::Reagent) 
	{	//if it is...
		UE_LOG(LogTemp, Log, TEXT("Player is Hold"));
		//...Give us the player's heldObject...	
		HeldReagent = *HeldObject;
		//...set our DistillValue to a proper value if it's a distillery (or the existing value)...
		if (bIsDistill) HeldReagent.DistillValue = HeldReagent.DistillValue == -1? 0 : HeldReagent.DistillValue;
		Player->EmptyHeldObject();
		//...process it...
		ProcessReagent();
		//...and play the associated sound, given it isn't empty!
		if (AudioComponent) AudioComponent->Play();
	}
}

