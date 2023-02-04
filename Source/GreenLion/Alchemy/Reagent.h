// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Reagent.generated.h"

UENUM()
enum Modifier
{
	Distilled = 0b001,
	Heated = 0b010,
	Pestled = 0b100,
};

/**
 * 
 */
USTRUCT()
struct FReagent
{
	GENERATED_BODY()

	int ModifierSign = 0b000;
};