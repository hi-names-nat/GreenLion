// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PotionData.h"
#include "Recipe.h"
#include "ReagentData.h"
#include "GameFramework/Actor.h"
#include "../Player/Interaction/InteractInterface.h"
#include "Cauldron.generated.h"


UCLASS()
class GREENLION_API ACauldron : public AActor, public IInteractInterface
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

	void AddReagent(const FAlchemyHoldableData& NewReagent);
	void CreateNewPotion(FAlchemyHoldableData* Bottle, APlayerController* PlayerController);
	
private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	URecipes* Recipes;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	TArray<FReagentData> CurrentContents;


	virtual void Interact(APlayerController* PlayerController) override;

};