	// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GLMainGameMode.generated.h"

USTRUCT()
struct FInventory
{
	GENERATED_BODY()
	int NumItem1;
	int NumItem2;
	int NumItem3;
	///... add more here if we need :)
};

	UENUM()
	enum EItemType
	{
		Item1,
		Item2,
		Item3,
		//etc!!!
	};

	UCLASS(minimalapi)
class AGLMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

		FInventory CurrentInv;
		

public:
	AGLMainGameMode();
		void CollectItem(EItemType type, int Amt);
};



