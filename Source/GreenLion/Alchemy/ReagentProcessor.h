// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReagentData.h"
#include "GreenLion/Player/Interaction/InteractInterface.h"
#include "ReagentProcessor.generated.h"

UCLASS()
class GREENLION_API AReagentProcessor : public AActor, public IInteractInterface
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	EModifierType Modifier;

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
	
	/**
	 * @brief The distillation value to give the modifier. MUST be '-1' if irrelevant.
	 */
	float DistillValue = -1;

private:
	virtual void Interact(APlayerController* PlayerController) override;

};
