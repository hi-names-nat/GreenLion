// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectablePlant.h"

#include "DSP/AudioDebuggingUtilities.h"
#include "GreenLion/Player/GLPlayerController.h"


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
	auto EPC = Cast<AGLPlayerController>(PlayerController);
	if (!EPC) return;
	
	switch (Type)
	{
	case EType::Berry:
		EPC->numBerry++;
		break;
	case EType::Flower:
		EPC->numFlower++;
		break;
	case EType::Herb:
		EPC->numRoot++;
		break;
	case EType::Shroom:
		EPC->numShroom++;
		break;
	}

	Destroy();

}

