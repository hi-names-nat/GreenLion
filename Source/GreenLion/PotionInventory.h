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
