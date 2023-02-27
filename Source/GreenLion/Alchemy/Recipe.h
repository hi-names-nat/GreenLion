#pragma once

#include "ReagentData.h"
#include "Recipe.generated.h"

struct FReagentData;

USTRUCT()
struct FRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FReagentData> RequiredReagents;

	float RequiredDistillationValue = -1;
	float distillForgivenessRange = .3F;

	TArray<FPotionEffect> Effects;
	float EffectModifier;
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
	FRecipe CurrentRecipe;

public:
	void EvaluatePossibleRecipes(TArray<FReagentData> CurrentContents);
};
