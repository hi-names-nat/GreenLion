// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PotionInventory.generated.h"

/**
 * 
 */
UCLASS()
class GREENLION_API UPotionInventory : public UObject
{
	GENERATED_BODY()
private:
	std::vector<UPotion> thePotions;

public:
	std::vector<potionProps> UPotionInventory::GrabPotion(int i);
	bool ThrowPotion(int index);
	int Sell(int index);
	int SellAll();
	
	
};
