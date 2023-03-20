// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alchemy/PotionData.h"
#include "UObject/NoExportTypes.h"
#include "PotionInventory.generated.h"

namespace Alchemy
{
	/**
 * 
 */
	class UPotion;

	UCLASS()
	class GREENLION_API UPotionInventory : public UStaticMeshComponent
	{
		GENERATED_BODY()
	private:

	public:
		UPotionInventory();
		TArray<Alchemy::Potions::FPotionProps> Potions;

		Alchemy::Potions::FPotionProps CurrentProps;
	
		void SwitchPotion(int I);
		bool ThrowPotion(int Index);
		int Sell(int Index);
		int SellAll();
	};

}

