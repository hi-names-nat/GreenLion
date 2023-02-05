// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Potion.generated.h"

/**
 * 
 */


enum Effect { Heal, Speed, Fire, None };

USTRUCT()
struct FPotionProps {
	GENERATED_BODY()
	Effect effect;
	int value;
	int duration;
	int sellValue;
};

UCLASS()
class GREENLION_API UPotion : public UObject
{
	
	GENERATED_BODY()
private:
	TArray<FPotionProps> theEffects; //All the effects of the potion
	bool thrown;                         //Whether or not it's throwable
	//
	//Icon image?
	//
public:
	bool IsThrown();
	TArray<FPotionProps> GetProps();
	int GetSellPrice();
};

