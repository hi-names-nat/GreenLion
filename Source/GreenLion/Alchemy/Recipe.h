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

	//Add resultant here.
};

UCLASS()
class URecipes : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TArray<FRecipe> Recipes;
	
};
