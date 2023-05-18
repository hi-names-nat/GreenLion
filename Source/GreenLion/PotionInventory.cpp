// Fill out your copyright notice in the Description page of Project Settings.


#include "PotionInventory.h"

	/*enum Effect { Heal, Speed, Fire, None };
		struct potionProps {
			Effect effect;
			int value;
			int duration;
			int sellValue;
		};*/

	UPotionInventory::UPotionInventory()
	{

	}

	void UPotionInventory::SwitchPotion(const int index) { //Returns the props at index
		//std::vector<potionProps> props;                              //If you want to use the potion,
		if (index < Potions.Num()) {                               //Combine this with ThrowPotion
			CurrentProps = Potions[index];
		} else {
		
		}
	}

	bool UPotionInventory::ThrowPotion(const int Index)      //Removes the element at index, then returns if it's thrown or not
	{
		//TODO
		return false;

	}

	int UPotionInventory::Sell(const int Index)  //Removes the element at index, returns its sell value
	{
		int sellPrice = 0;
		if(Index < Potions.Num())
		{
			// sellPrice = Potions[Index].SellValue;
			Potions.RemoveAt(Index);
		}
		return sellPrice;
	}

	int UPotionInventory::SellAll()           //Clears the list of potions, then returns the total sell value of all of them
	{
		int sellPrice = 0;
		for(int i = 0; i < Potions.Num(); i++)
		{
			// sellPrice += Potions[i].SellValue;
		}
		Potions.Empty();
		return sellPrice;
	}