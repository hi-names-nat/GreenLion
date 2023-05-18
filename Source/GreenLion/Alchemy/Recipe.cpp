
#include "Recipe.h"

void URecipes::EvaluatePossibleRecipes(const TArray<FReagentData>& CurrentContents)
{
	UE_LOG(LogTemp, Log, TEXT("Evaluating possible recipes"))
	for (const auto &[RequiredReagents, distillForgivenessRange, Result] : Recipes)
	{
		if (RequiredReagents.Num() != CurrentContents.Num()) break;
		bool valid = true;
		for (auto RequiredReagent : RequiredReagents)
		{
			if (!CurrentContents.Contains(RequiredReagent))
			{
				valid = false;
			}
		}
		if (valid) CurrentResult = Result;
	}
}