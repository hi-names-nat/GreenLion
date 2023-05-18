// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReagentData.h"
#include "GreenLion/Player/Interaction/InteractInterface.h"
#include "ReagentProcessor.generated.h"



/**
 * @brief Acquires and processes reagents given to it via interaction.
 * @details To use:
 * - Have an interactor call Interact, it will apply the modification process when it has received a reagent.
 * It is tolerant of non-reagent held objects. It will simply not do anything with them.
 * - In the case that it has received a reagent, a second interaction will give the reagent back to the interactor.
 * @note On distillery objects, this object will continuously process the HeldReagent from an initial value of 0 to a
 * maximum possible value of 1.
 * @warning you are REQUIRED to set 'Modifier',
 * 'ProcessedReagentMesh', and optionally 'ProcessAudio' in-editor.
 * 
 **/
UCLASS()
class GREENLION_API AReagentProcessor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
////////////////////////////////////////////////////////////////////////
/////////////////////////// VARIABLES //////////////////////////////////

protected:
	/**
	 * @brief How much we increase the purity of the reagent per second, up to a maximum of 1.
	 */
	const float DISTILLATION_PER_SECOND = .1f;

	/**
	 * @brief The modifier to apply.
	 */
	UPROPERTY(EditAnywhere, Category="Processor Globals", meta=(AllowPrivateAccess = "true"))
	EModifierType Modifier;

	/**
	 * @brief The distillation value to give the modifier. MUST be '-1' if irrelevant.
	 */
	UPROPERTY(VisibleAnywhere, Category="Processor Globals", meta=(EditCondition="Modifier == EModifierType::Distilled", EditConditionHides))
	float DistillValue = -1;

	/**
	 * @brief 
	 */
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* ProcessorVisuals;
	
	/**
	 * @brief The mesh of the reagent, displayed when containing an imposter.
	 */
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* ReagentImposter;
	
	/**
	 * @brief 
	 */
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	UAudioComponent* AudioComponent;

	/**
	 * @brief 
	 */
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	class UParticleSystemComponent* ParticleEmitter;

	/**
	 * @brief The container for our reagent.
	 */
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	FAlchemyHoldableData HeldReagent;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	bool bHasReagent = false;

	/**
	 * @brief A cache we use to tell if this processor is a distillery.
	 */
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	bool bIsDistill = false; 

public:

	
////////////////////////////////////////////////////////////////////////
/////////////////////////// FUNCTIONS //////////////////////////////////
	
public:
	// Constructor.
	AReagentProcessor();

	/**
	* @brief Interact, in this situation is used to pick up reagents.
	* @param PlayerController The APlayerController initiating this interaction
	*/
	virtual void Interact(APlayerController* PlayerController) override;

protected:
	// First-Frame setup stuff
	virtual void BeginPlay() override;

	// This is only used if this processor is a distillery.
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Processes our HeldReagent.
	 */
	void ProcessReagent();
};
