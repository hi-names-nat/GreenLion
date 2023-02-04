// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Potion.generated.h"

/**
 * 
 */



UCLASS()
class GREENLION_API UPotion : public UObject
{
	
	GENERATED_BODY()
private:
	TArray<potionProps> theEffects; //All the effects of the potion
	bool thrown;                         //Whether or not it's throwable
	//
	//Icon image?
	//
public:
	bool IsThrown();
	TArray<potionProps> UPotion::GetProps();
	int UPotion::GetSellPrice();
};

enum Effect { Heal, Speed, Fire, None };
struct potionProps {
	Effect effect;
	int value;
	int duration;
	int sellValue;
};