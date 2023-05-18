#pragma once

#include "PotionData.h"
#include "ReagentData.h"
#include "Recipe.generated.h"


USTRUCT()
struct FReagentData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	EReagentClassification ReagentClass;
	
	/**
	 * @brief 
	 * @param RHS the other FReagentData to check against
	 * @return If this reagent and the other reagent contain the same modifier order and DistillValue, within a static
	 *			value DISTILL_FORGIVENESS
	 */
	bool operator==(const FReagentData& RHS) const
	{
		return (ModifierOrder == RHS.ModifierOrder) && (ReagentClass == RHS.ReagentClass) && abs(DistillValue - RHS.DistillValue) <= DISTILL_FORGIVENESS;
	}

	bool operator!=(const FReagentData& RHS) const
	{
		return (ModifierOrder != RHS.ModifierOrder) || (ReagentClass != RHS.ReagentClass) || abs(DistillValue - RHS.DistillValue) > DISTILL_FORGIVENESS;
	}

	/**
	 * @brief 
	 * @param RHS the other FReagentData to check against
	 * @return If this reagent and the other reagent contain the same modifier order and DistillValue, within a static
	 *			value DISTILL_FORGIVENESS
	 */
	bool operator==(const FAlchemyHoldableData& RHS) const
	{
		return ModifierOrder == RHS.ModifierOrder && ReagentClass == RHS.ReagentClass && abs(DistillValue - RHS.DistillValue) <= DISTILL_FORGIVENESS;
	}
	
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
	* @brief apply a modifier to the reagent. These are used to add to the complexity of the alchemy system
	* @param Modifier The modifier to apply
	* @param NewModel The model for the worldmodel to reflect
	* @param Val the value for valued modifiers. Not required for boolean modifiers, but REQUIRED for float modifiers.
	 */
	void ApplyModifier(EModifierType Modifier, UStaticMesh* NewModel, std::optional<float> Val);

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

USTRUCT()
struct FRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FReagentData> RequiredReagents;
	
	UPROPERTY(EditAnywhere)
	float distillForgivenessRange = .3F;

	UPROPERTY(EditAnywhere)
	FPotionProps Result;
};

UCLASS(Blueprintable)
class URecipes : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TArray<FRecipe> Recipes;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	TArray<FRecipe> PossibleRecipes;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	FPotionProps CurrentResult;

public:
	void EvaluatePossibleRecipes(const TArray<FReagentData>& CurrentContents);
};
