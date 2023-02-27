#include "Recipe.h"

void URecipes::EvaluatePossibleRecipes(TArray<FReagentData> CurrentContents)
{
	for (auto recipe : Recipes)
	{
		bool validRecipe = true;
		auto Reagents = recipe.RequiredReagents;
		for (int i = 0; i < recipe.RequiredReagents.Num(); i++)
		{
			if (!(CurrentContents.Contains(Reagents[i])))
			{
				validRecipe = false;
			}
		}
		if (validRecipe)
		{
			CurrentRecipe = recipe;
			return;
		}
	}
}