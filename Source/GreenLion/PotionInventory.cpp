// Fill out your copyright notice in the Description page of Project Settings.


#include "PotionInventory.h"
#include "Potion.h"

	/*enum Effect { Heal, Speed, Fire, None };
	struct potionProps {
		Effect effect;
		int value;
		int duration;
		int sellValue;
	};*/

	TArray<FPotionProps> UPotionInventory::GrabPotion(int index) { //Returns the props at index
		//std::vector<potionProps> props;                              //If you want to use the potion,
		if (index < thePotions.Num()) {                               //Combine this with ThrowPotion
			return thePotions[index] -> GetProps();
		} else {
		
			printf("Index is invalid");
			
			TArray<FPotionProps> error;
			return error;
			
		}
	}

	bool UPotionInventory::ThrowPotion(int index)      //Removes the element at index, then returns if it's thrown or not
	{
		if(index < thePotions.Num())
		{
			bool throwable = thePotions[index] -> IsThrown();
			thePotions.RemoveAt(index);
			return throwable;
			
		} else
		{
			printf("Index is invalid");
			return false;
		}
	}

	bool UPotionInventory::IsThrown(int index) //Gets the isThrown bool without removing the element from the array
	{                                          //(Presumably for UI purposes or smth)
		if(index < thePotions.Num())
		{
			return(thePotions[index] -> IsThrown());
			
		} else
		{
			printf("Index is invalid");
			return false;
		}
		
	}

	int UPotionInventory::Sell(int index)  //Removes the element at index, returns its sell value
	{
		int sellPrice = 0;
		if(index < thePotions.Num())
		{
			sellPrice = thePotions[index] -> GetSellPrice();
			thePotions.RemoveAt(index);
		}
		return sellPrice;
	}

	int UPotionInventory::SellAll()           //Clears the list of potions, then returns the total sell value of all of them
	{
		int sellPrice = 0;
		for(int i = 0; i < thePotions.Num(); i++)
		{
			sellPrice += thePotions[i] -> GetSellPrice();
		}
		thePotions.Empty();
		return sellPrice;
	}
