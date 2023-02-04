#pragma once

struct FReagent;

USTRUCT()
struct FRecipe
{
	TArray<FReagent> RequiredReagents;

	//Add resultant here.
};

class URecipes : UClass
{
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TArray<FRecipe> Recipes;
	
};
