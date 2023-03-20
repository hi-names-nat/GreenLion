// Fill out your copyright notice in the Description page of Project Settings.
#include "ReagentProcessor.h"
#include "ReagentData.h"
#include "GreenLion/Player/AlchemyPlayer.h"


// Sets default values
AReagentProcessor::AReagentProcessor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReagentProcessor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReagentProcessor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AReagentProcessor::ProcessReagent(AWorldReagent* ReagentData)
{
	ReagentData->ApplyModifier(Modifier, ModelToApply, DistillValue);
}

void AReagentProcessor::Interact(APlayerController* PlayerController)
{
	IInteractInterface::Interact(PlayerController);
	AAlchemyPlayer* player = Cast<AAlchemyPlayer>(PlayerController->GetPawn());
	player->GetHeldReagent()->ApplyModifier(Modifier, ModelToApply, DistillValue);

}

