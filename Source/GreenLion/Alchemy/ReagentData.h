// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReagentData.generated.h"
	
UENUM()
enum struct EReagentType
{
	Berry,
	Flower,
	Herb,
	Animal,	
};

UENUM()
enum struct EReagentClassification
{
	Fae,
	Earthen,
	
};
	
UENUM()
enum struct EPotionEffectType : int
{
	Fire,
	NightVision,
	Poison,
	InstantHarm,
	Speed,
};

USTRUCT()
struct FPotionEffect
{
	//The type of effect to add to the potion
	EModifierType Type;

	//The modifier of the value.
	//For instance: Speed with a modifier of 1.5 will multiply the user's
	//	speed by 1.5x for the duration.
	float Modifier;
};

/**
 * 
 */
USTRUCT()
struct FReagentData
{
	GENERATED_BODY()

	int ModifierSign = 0b000;

	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;
	
};

UCLASS()
class AReagent: public AActor
{
	GENERATED_BODY()


public:
	AReagent();

	void ApplyModifier(EModifier Modifier, UStaticMesh* NewMesh);

private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	FReagentData ReagentData;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess= "true"))
	UStaticMeshComponent* MeshComponent;
};