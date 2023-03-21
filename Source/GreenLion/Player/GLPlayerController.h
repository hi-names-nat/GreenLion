// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GreenLion/Alchemy/Cauldron.h"

using namespace Alchemy;

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GreenLion/PotionInventory.h"
#include "GLPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GREENLION_API AGLPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	//TODO: This needs to be changed!!!!!!
	int numBerry = 0;
	int numFlower = 0;
	int numRoot = 0;
	int numShroom = 0;

	UPROPERTY(EditAnywhere)
	UPotionInventory* Potions;
public:
	
	AGLPlayerController();
};
