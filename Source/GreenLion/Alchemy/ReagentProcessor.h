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

	/**
	 * @brief How much we distill per second.
	 */
	const float DISTILLATION_PER_SECOND = .1f;

	/**
	 * @brief The modifier to apply.
	 */
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	EModifierType Modifier;

	/**
	 * @brief The imposter mesh we display when we're holding a reagent.
	 */
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ProcessedReagentMesh;

	/**
	 * @brief The audio we play when we place a reagent inside this processor.
	 */
	UPROPERTY(EditAnywhere)
	UAudioComponent* ProcessAudio;

	/**
	 * @brief The container for our reagent.
	 */
	TUniquePtr<FReagentData> HeldReagent;

	/**
	 * @brief A cache we use to tell if this processor is used as a distillery.
	 */
	bool isDistill = false; 

	

public:
	// Sets default values for this actor's properties
	AReagentProcessor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ProcessReagent();
	
	/**
	 * @brief The distillation value to give the modifier. MUST be '-1' if irrelevant.
	 */
	float DistillValue = -1;

private:
	/**
	 * @brief Interact, in this situation is used to pick up reagents.
	 * @param PlayerController The playercontroller initiating this interact
	 */
	virtual void Interact(APlayerController* PlayerController) override;
};
