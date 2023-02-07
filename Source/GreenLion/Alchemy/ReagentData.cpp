// Fill out your copyright notice in the Description page of Project Settings.


#include "ReagentData.h"

AReagent::AReagent()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetStaticMesh(ReagentData.Mesh);
	
}

void AReagent::ApplyModifier(EPotionEffectType Modifier, UStaticMesh* NewMesh)
{
	ReagentData.ModifierSign += static_cast<int>(Modifier);
	MeshComponent->SetStaticMesh(NewMesh);
	
}
