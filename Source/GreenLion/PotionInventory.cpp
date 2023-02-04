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

	std::vector<potionProps> UPotionInventory::GrabPotion(int index) { //Returns the props at index
		//std::vector<potionProps> props;                              //If you want to use the potion,
		if (index < thePotions.size()) {                               //Combine this with ThrowPotion
			return thePotions[index].GetProps();
		} else
		{
			printf("Index is invalid");
		}
	}

	bool UPotionInventory::ThrowPotion(int index)      //Removes the element at index, then returns if it's thrown or not
	{
		if(index < thePotions.size())
		{
			bool throwable = thePotions[index].IsThrown();
			thePotions.erase(thePotions.begin() + index);
			return throwable;
			
		} else
		{
			printf("Index is invalid");
		}
	}

	bool UPotionInventory::IsThrown(int index) //Gets the isThrown bool without removing the element from the array
	{                                          //(Presumably for UI purposes or smth)
		if(index < thePotions.size())
		{
			return(thePotions[index].IsThrown());
			
		} else
		{
			printf("Index is invalid");
		}
		
	}

	int UPotionInventory::Sell(int index)  //Removes the element at index, returns its sell value
	{
		int sellPrice = 0;
		if(index < thePotions.size())
		{
			sellPrice = thePotions[index].GetSellPrice();
			thePotions.erase(thePotions.begin() + index);
		}
		return sellPrice;
	}

	int UPotionInventory::SellAll()           //Clears the list of potions, then returns the total sell value of all of them
	{
		int sellPrice = 0;
		for(int i = 0; i < thePotions.size(); i++)
		{
			sellPrice += thePotions[i].GetSellPrice();
		}
		thePotions.clear();
		return sellPrice;
	}
