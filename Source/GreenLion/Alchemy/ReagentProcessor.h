// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReagentData.h"
#include "ReagentProcessor.generated.h"

UCLASS()
class GREENLION_API AReagentProcessor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	EModifier Modifier;

	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* ModelToApply;
	
	UPROPERTY()
	USceneComponent* ModifiedSpawnPoint;

public:
	// Sets default values for this actor's properties
	AReagentProcessor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ProcessReagent(AReagent* ReagentData);
};
