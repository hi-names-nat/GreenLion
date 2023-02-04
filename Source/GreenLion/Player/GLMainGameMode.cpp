// Copyright Epic Games, Inc. All Rights Reserved.

#include "GLMainGameMode.h"
#include "GLMainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGLMainGameMode::AGLMainGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
