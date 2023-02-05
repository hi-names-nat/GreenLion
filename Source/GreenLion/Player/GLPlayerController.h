// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GLPlayerController.generated.h"

class UPotionInventory;
/**
 * 
 */
UCLASS()
class GREENLION_API AGLPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	int numBerry = 0;
	int numFlower = 0;
	int numRoot = 0;
	int numShroom = 0;
	
	UPotionInventory* Potions;

<<<<<<< HEAD
public:
	int Money;
=======


	AGLPlayerController();
	
>>>>>>> f1823ce9b0520cf0ca0ec553d23b6a4cb3b061bd
	
};
