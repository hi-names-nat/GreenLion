// Fill out your copyright notice in the Description page of Project Settings.
#include "ReagentProcessor.h"
#include "ReagentData.h"


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

void AReagentProcessor::ProcessReagent(AReagent* ReagentData)
{
	ReagentData->ApplyModifier(Modifier, ModelToApply);
	ReagentData->SetActorLocation(ModifiedSpawnPoint->GetComponentLocation());
}
