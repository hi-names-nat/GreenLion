// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <optional>
#include "CoreMinimal.h"
#include <variant>
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

USTRUCT()
struct FReagentData
{
	const float DISTILL_FORGIVENESS = .1F;
	
	GENERATED_BODY();

	/**
	 * @brief The value (between 0 and 1) that the reagent was distilled to.
	 * This value Will be ignored if the reagent has not been distilled.
	 */
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	float DistillValue = -1;

	/**
	 * @brief The order in which modifiers were applied. 
	 */
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	TArray<EModifierType> ModifierOrder;

	/**
	 * @brief The mesh that this object will use when encapsulated into an AWorldReagent
	 */
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	UStaticMesh* Mesh;
	
	/**
	* @brief apply a modifier to the reagent. These are used to add to the complexity of the alchemy system
	* @param Modifier The modifier to apply
	* @param NewModel The model for the worldmodel to reflect
	* @param Val the value for valued modifiers. Not required for boolean modifiers, but REQUIRED for float modifiers.
	 */
	void ApplyModifier(EModifierType Modifier, UStaticMesh* NewModel, std::optional<float> Val);

	/**
	 * @brief 
	 * @param rhs the other FReagentData to check against
	 * @return If this reagent and the other reagent contain the same modifier order and DistillValue, within a static
	 *			value DISTILL_FORGIVENESS
	 */
	bool operator==(const FReagentData& rhs) const
	{
		return (ModifierOrder == rhs.ModifierOrder && (abs(DistillValue- rhs.DistillValue) <= DISTILL_FORGIVENESS));
	}

	//TODO: Turn the ModifierOrder into a bitmask u16. I.E.
	// 000 _ 000 _ 000 _ 000 _ 000 _ 0
	// R_1	 R_2   R_3   [  Unused  ]
	// 3-Byte array functions as (in big endian order)
	// Index 0: Heated
	// Index 1: Crushed
	// Index 2: Distilled
	//Combine with DistillValue for final equality check (or append DistillValue upon our bitmask?)
														// ^ No, no. That won't work if we want a
														// forgiveness. Think about it.
};

UCLASS()
class AWorldReagent: public AActor
{
	GENERATED_BODY()

public:
	AWorldReagent();

	/**
	 * @brief Gets the owned ReagentData
	 * @return The owned ReagentData.
	 */
	TSharedPtr<FReagentData> GetReagentData() {return Data;}
	
private:
	/**
	 * @brief The associated Mesh with this object.
	 */
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess= "true"))
	UStaticMeshComponent* MeshComponent;

	/**
	 * @brief The associated ReagentData
	 */
	TSharedPtr<FReagentData> Data;
};