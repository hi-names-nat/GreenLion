#pragma once

#include "CoreMinimal.h"
#include <variant>
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

USTRUCT()
struct FPotionEffect
{
	GENERATED_BODY()

	explicit FPotionEffect(
		const EPotionEffectType Effect = EPotionEffectType::Fire,
		const float Mod = 0
		):
	Type(Effect), Modifier(Mod) {}
	
	//The type of effect to add to the potion
	UPROPERTY(EditAnywhere)
	EPotionEffectType Type = EPotionEffectType::Fire;

	//  The modifier of the value.
	//	For instance: Speed with a modifier of 1.5 will multiply the user's
	//	speed by 1.5x for the duration.
	UPROPERTY(EditAnywhere)
	float Modifier = 0;
};

USTRUCT()
struct FPotionProps {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TArray<FPotionEffect> Effects;
	UPROPERTY(EditAnywhere)
	UTexture2D* UISprite;
	UPROPERTY(EditAnywhere)
	UStaticMesh* PotionModel;
	UPROPERTY(EditAnywhere)
	int32 Value;
	UPROPERTY(EditAnywhere)
	int32 Duration;
	UPROPERTY(EditAnywhere)
	int32 SellValue;
};
