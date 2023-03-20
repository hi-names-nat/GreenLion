// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <optional>
#include "CoreMinimal.h"
#include <variant>
#include "ReagentData.generated.h"

struct FRecipe;

/// This is a small enum that represents all of our possible Reagents.
/// Likely there is a better way to do this, but I can't think of one.
/// If this gets too big, let's pull it out into its own file.
/// TODO: Turn this into a blueprint enum to allow quick changing of
/// what reagents are included.
UENUM()
enum struct EReagentClassification
{
	Reagent1,	Reagent2,	Reagent3,
	Reagent4,	Reagent5,	Reagent6,
	Reagent7,	Reagent8,	Reagent9,
	Reagent10,	Reagent11,	Reagent12,
	Reagent13,	Reagent14,	Reagent15,
	Reagent16,	Reagent17,	Reagent18,
	Reagent19,	Reagent20,
};

UENUM()
enum struct EModifierType : uint8
{
	Heated,
	Distilled,
	Crushed,
};

USTRUCT()
struct FAlchemyHoldableObject {
	GENERATED_BODY()
};

constexpr float DISTILL_FORGIVENESS = .1F;

USTRUCT()
struct FReagentData: public FAlchemyHoldableObject
{
	
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

	/* TODO: Turn the ModifierOrder into a bitmask u16. I.E.
	* 000 000 000 0000000
	* R_1 R_2 R_3 [Unused]	
	* R_1: Heated
	* R_2: Crushed
	* R_3: Distilled
	* Combine with DistillValue for final equality check (or append DistillValue upon our bitmask?)
	*														^ No, no. That won't work if we want a
	*														  forgiveness. Think about it.
	*/
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