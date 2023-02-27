// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <optional>
#include <stack>

#include "CoreMinimal.h"
#include <variant>
#include <stack>
#include "ReagentData.generated.h"

struct FRecipe;
UENUM()
enum struct EReagentType
{
	Berry,
	Flower,
	Herb,
	Animal,	
};

UENUM()
enum struct EReagentClassification
{
	Fae,
	Earthen,
	
};
	
UENUM()
enum struct EPotionEffectType
{
	Fire,
	NightVision,
	Poison,
	InstantHarm,
	Speed,
};

UENUM()
enum struct EModifierType : uint8
{
	Heated,
	Distilled,
	Crushed,
};

USTRUCT()
struct FPotionEffect
{
	GENERATED_BODY()
	//The type of effect to add to the potion
	EPotionEffectType Type;

	//The modifier of the value.
	//	For instance: Speed with a modifier of 1.5 will multiply the user's
	//	speed by 1.5x for the duration.
	float Modifier;
};

/**
 * 
 */
// USTRUCT()
// struct FReagentModifier
// {
// 	GENERATED_BODY()
//
// 	std::variant<void, float> Heated, Distilled, Crushed;
//
// 	UPROPERTY(EditAnywhere)
// 	UStaticMesh* Mesh;
// 	
// };

USTRUCT()
struct FReagentData
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	float DistillValue = -1;
	
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	TArray<EModifierType> ModifierOrder;
	
	bool operator==(const FReagentData& rhs) const
	{
		return (ModifierOrder == rhs.ModifierOrder && DistillValue == rhs.DistillValue);
	}
};

UCLASS()
class AReagent: public AActor
{
	GENERATED_BODY()


	

public:
	AReagent();

	/**
	 * @brief 
	 * @param Modifier The modifier to apply
	 * @param Val the value for valued modifiers. Not required for boolean modifiers, but REQUIRED for float modifiers.
	 */
	void ApplyModifier(EModifierType Modifier, UStaticMesh* NewModel, std::optional<float> Val);

	bool operator==(const FReagentData& rhs) const
	{
		return (Data == rhs);
	}

	FReagentData GetReagentData() {return Data;}
	
private:
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess= "true"))
	UStaticMeshComponent* MeshComponent;

	FReagentData Data;

};