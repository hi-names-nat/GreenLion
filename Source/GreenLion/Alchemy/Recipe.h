#pragma once

#include "PotionData.h"
#include "Recipe.generated.h"


USTRUCT()
struct FRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FReagentData> RequiredReagents;

	UPROPERTY(EditAnywhere)
	float RequiredDistillationValue = -1;

	UPROPERTY(EditAnywhere)
	float distillForgivenessRange = .3F;

	UPROPERTY(EditAnywhere)
	FPotionProps Effect;

	UPROPERTY(EditAnywhere)
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
