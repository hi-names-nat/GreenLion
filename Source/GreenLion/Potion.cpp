<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
	/*enum Effect { Heal, Speed, Fire, None };
	struct potionProps {
		Effect effect;
		int value;
		int duration;
		int sellValue;
	};*/

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


=======
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


>>>>>>> f1823ce9b0520cf0ca0ec553d23b6a4cb3b061bd
