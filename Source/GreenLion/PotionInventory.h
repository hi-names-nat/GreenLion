<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PotionInventory.generated.h"


struct FPotionProps;

/**
 * 
 */
class UPotion;

UCLASS()
class GREENLION_API UPotionInventory : public UObject
{
	GENERATED_BODY()
private:
	TArray<UPotion*> thePotions;

public:
	TArray<FPotionProps> GrabPotion(int i);
	bool IsThrown(int index);
	bool ThrowPotion(int index);
	int Sell(int index);
	int SellAll();
	
	
};
=======
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PotionInventory.generated.h"


struct FPotionProps;

/**
 * 
 */
class UPotion;

UCLASS()
class GREENLION_API UPotionInventory : public USceneComponent
{
	GENERATED_BODY()
private:

public:
	UPotionInventory();
	TArray<UPotion*> thePotions;

	
	TArray<FPotionProps> GrabPotion(int i);
	bool IsThrown(int index);
	bool ThrowPotion(int index);
	int Sell(int index);
	int SellAll();
	
	
};
>>>>>>> f1823ce9b0520cf0ca0ec553d23b6a4cb3b061bd
