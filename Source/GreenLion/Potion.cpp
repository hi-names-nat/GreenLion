// Fill out your copyright notice in the Description page of Project Settings.
#include "Potion.h"

UPotion::UPotion()
{
	
}

bool UPotion::IsThrown() {return thrown;}                   //Get whether or not it's throwable

TArray<FPotionProps> UPotion::GetProps() {//Get the effects
	return theEffects;
}

int UPotion::GetSellPrice(){
	int sellPrice = 0;
	for(int i = 0; i < theEffects.Num(); i++)
	{
		sellPrice += theEffects[i].sellValue;
	}
	return sellPrice;
}


