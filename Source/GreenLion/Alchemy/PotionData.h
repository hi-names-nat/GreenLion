#pragma once

#include <optional>
#include "CoreMinimal.h"
#include <variant>
#include "ReagentData.h"
#include "PotionData.generated.h"

/// The possible potion effects
UENUM()
enum struct EPotionEffectType
{
	Fire,
	NightVision,
	Poison,
	InstantHarm,
	Speed,
	Health,
};
	
///The possible potion bottle types
UENUM()
enum EPotionBottleType
{
	Quaff,
	Thrown,
	Shake,
	Mist,
	Arrow,
};

USTRUCT()
struct FPotionEffect
{
	GENERATED_BODY()
	//The type of effect to add to the potion
	EPotionEffectType Type;

	//  The modifier of the value.
	//	For instance: Speed with a modifier of 1.5 will multiply the user's
	//	speed by 1.5x for the duration.
	float Modifier;
};

USTRUCT()
struct FPotionBottle: public FAlchemyHoldableObject
{
	GENERATED_BODY()

};

USTRUCT()
struct FPotionProps {
	GENERATED_BODY()
	TArray<FPotionEffect> Effects;
	int Value;
	int Duration;
	int SellValue;
};
