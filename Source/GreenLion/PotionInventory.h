// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alchemy/PotionData.h"
#include "UObject/NoExportTypes.h"
#include "PotionInventory.generated.h"

	class UPotion;

/**
 * The way this object is intended to work is to manage all of the potions
 * we have, as well as rendering the potion that we currently have.
 * This object should have functions that the player can call to
 * change, ready, and throw potions.
 * This system requires us to set up a list of potions. You should probably
 * set up a way to have a number of each potion type (maybe a small struct with
 * FPotionProps prop, int number). We need to be able to switch between potions
 * linearly via D pad (d pad left -> current = potions[(index of current) + 1],
 * visa versa) and also choose a potion via random access (select index I)
 * We should also probably add an image for UI for each potion props, a model
 * for you to set this to for each model, and the like.
 * On throw, this object will create a projectile object when thrown that will
 * cause the effect type. You'll have to implement those.
 * I will send you a design on paper about this stuff!!
 **/
	UCLASS()
	class GREENLION_API UPotionInventory : public UStaticMeshComponent
	{
	GENERATED_BODY()
	private:

	public:
		UPotionInventory();
		TArray<FPotionProps> Potions;

		FPotionProps CurrentProps;
	
		void SwitchPotion(int I);
		bool ThrowPotion(int Index);
		int Sell(int Index);
		int SellAll();
	};

