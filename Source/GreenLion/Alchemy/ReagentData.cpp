// Fill out your copyright notice in the Description page of Project Settings.


#include "ReagentData.h"

AWorldReagent::AWorldReagent()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
}

void FReagentData::ApplyModifier(const EModifierType Modifier, UStaticMesh* NewModel, const std::optional<float> Val = std::nullopt)
{
	if (Modifier == EModifierType::Distilled)
	{
			if (!Val.has_value()) {
				UE_LOG(LogTemp, Fatal, TEXT("DID NOT GET A FLOAT VALUE WITH A VALUE REQUIREMENT. THIS IS INVALID."))
			}

		DistillValue = Val.value();
	}
	
	ModifierOrder.Push(Modifier);
	Mesh = NewModel;
}
