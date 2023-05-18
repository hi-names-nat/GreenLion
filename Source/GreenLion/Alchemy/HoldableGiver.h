// (c) Natalie Soltis & Dark Frog SGS 2022-23.

#pragma once

#include "CoreMinimal.h"
#include "ReagentData.h"
#include "../Player/Interaction/InteractInterface.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "HoldableGiver.generated.h"


struct FReagentData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GREENLION_API UHoldableGiver : public UBoxComponent, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHoldableGiver();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void Interact(APlayerController* PlayerController) override;

public:
	//Bottle Giver Stats
	UPROPERTY(EditAnywhere)
	FAlchemyHoldableData Data;
};
