// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GreenLion/Player/Interaction/InteractInterface.h"
#include "CollectablePlant.generated.h"

UENUM()
enum struct EType
{
	Berry,
	Flower,
	Shroom,
	Herb,
};

class UInteractableComponent;
UCLASS()
class GREENLION_API ACollectablePlant : public AActor, public IInteractInterface
{
	GENERATED_BODY()

	UInteractableComponent *InteractableComponent;

	UPROPERTY(EditAnywhere)
	EType Type;
	
public:
	// Sets default values for this actor's properties
	ACollectablePlant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact(APlayerController* PlayerController) override;
};
