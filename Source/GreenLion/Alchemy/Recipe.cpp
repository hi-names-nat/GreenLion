

#include "Recipe.h"

void URecipes::EvaluatePossibleRecipes(TArray<FReagentData> CurrentContents)
{
	for (auto Recipe : Recipes)
	{
		bool bValidRecipe = true;
		auto Reagents = Recipe.RequiredReagents;
		for (int i = 0; i < Recipe.RequiredReagents.Num(); i++)
		{
			if (!CurrentContents.Contains(Reagents[i]))
			{
				bValidRecipe = false;
			}
		}
		if (bValidRecipe)
		{
			CurrentRecipe = Recipe;
			return;
		}
	}
}