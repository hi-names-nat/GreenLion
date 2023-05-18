// Fill out your copyright notice in the Description page of Project Settings.


#include "Cauldron.h"

#include "GreenLion/Player/AlchemyPlayer.h"
#include "GreenLion/Player/GLPlayerController.h"

	// Sets default values
	ACauldron::ACauldron()
	{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

		Recipes = CreateDefaultSubobject<URecipes>(TEXT("Recipe manager"));
	}

	// Called when the game starts or when spawned
	void ACauldron::BeginPlay()
	{
		Super::BeginPlay();
	
	}	

	// Called every frame
	void ACauldron::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
	}


	void ACauldron::AddReagent(const FAlchemyHoldableData& NewReagent)
	{
		UE_LOG(LogTemp, Log, TEXT("Adding reagent"))
		const FReagentData Data {.DistillValue = NewReagent.DistillValue, .ModifierOrder = NewReagent.ModifierOrder};
		CurrentContents.Add(Data);
		Recipes->EvaluatePossibleRecipes(CurrentContents);
	}

	void ACauldron::CreateNewPotion(FAlchemyHoldableData* Bottle, APlayerController* PlayerController)
	{
		// auto GLController = Cast<AGLPlayerController>(PlayerController);
		// if (!GLController) {
		// 	
		// }
		
	}

	void ACauldron::Interact(APlayerController* PlayerController)
	{
		AAlchemyPlayer* player = Cast<AAlchemyPlayer>(PlayerController->GetPawn());
		const auto Held = player->GetHeldObject();
		if (Held->ObjectType == EHoldableType::Reagent)
		{
			AddReagent(*Held);
		}
		else if (Held->ObjectType == EHoldableType::Bottle)
		{
			CreateNewPotion(Held, PlayerController);
		}
	}