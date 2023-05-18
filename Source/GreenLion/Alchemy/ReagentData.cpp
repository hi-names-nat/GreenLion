// Fill out your copyright notice in the Description page of Project Settings.


#include "ReagentData.h"


FAlchemyHoldableData::FAlchemyHoldableData(const EReagentClassification Class, UStaticMesh* ReagentMesh): Mesh(ReagentMesh)
{
	ReagentClass = Class;
	DistillValue = 0;
	ModifierOrder = TArray<EModifierType>();
	ModifierOrder.Empty();
	ObjectType = EHoldableType::Reagent;
}

FAlchemyHoldableData::FAlchemyHoldableData(const EPotionBottleType Type, UStaticMesh* BottleMesh): BottleType(Type)
{
	ObjectType = EHoldableType::Bottle;
	Mesh = BottleMesh;
}

void FAlchemyHoldableData::ApplyModifier(const EModifierType Modifier, UStaticMesh* NewModel, const std::optional<float> Val = std::nullopt)
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

AWorldAlchemyHoldable::AWorldAlchemyHoldable()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
}

void AWorldAlchemyHoldable::Interact(APlayerController* PlayerController)
{
	IInteractInterface::Interact(PlayerController);
}
