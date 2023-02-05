// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReagentData.generated.h"
	
UENUM()
enum struct EModifier 
{
	Distilled = 0b001,
	Heated =	0b010,
	Pestled =	0b100,
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