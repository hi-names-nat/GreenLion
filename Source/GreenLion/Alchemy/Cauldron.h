// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cauldron.generated.h"
		
UCLASS()
class GREENLION_API ACauldron : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACauldron();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
