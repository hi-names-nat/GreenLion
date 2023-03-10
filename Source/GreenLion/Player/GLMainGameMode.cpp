// Copyright Epic Games, Inc. All Rights Reserved.

#include "GLMainGameMode.h"
#include "GLMainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGLMainGameMode::AGLMainGameMode()
{

	CurrentInv = FInventory{0,0, 0};
}

void AGLMainGameMode::CollectItem(const EItemType Type, const int Amt)
{
	switch (Type)
	{
	case Item1:
		CurrentInv.NumItem1 += Amt;
		break;
	case Item2:
		CurrentInv.NumItem2 += Amt;
		break;
	case Item3:
		CurrentInv.NumItem3 += Amt;
		break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Error: CollectItem in GLMainGameMode did not find known type!"));
	}
}
