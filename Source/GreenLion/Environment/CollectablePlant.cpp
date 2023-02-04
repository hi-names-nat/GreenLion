// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectablePlant.h"

#include "NavigationSystemTypes.h"


// Sets default values
ACollectablePlant::ACollectablePlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollectablePlant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectablePlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACollectablePlant::Interact(APlayerController* PlayerController)
{
	UE_LOG(LogTemp, Log, TEXT("Interacted with."));

}

