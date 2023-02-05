// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Potion.generated.h"

/**
 * 
 */
enum EPotionEffect { Heal, Speed, Fire, None };

USTRUCT()
struct FPotionProps {
	GENERATED_BODY()
	EPotionEffect effect;
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

public:
	UPotion();
	bool IsThrown();
	TArray<FPotionProps> GetProps();
	int GetSellPrice();
};

