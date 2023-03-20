// Fill out your copyright notice in the Description page of Project Settings.


#include "Cauldron.h"

#include "Recipe.h"
#include "GreenLion/Player/AlchemyPlayer.h"
#include "GreenLion/Player/GLPlayerController.h"


// Sets default values
ACauldron::ACauldron()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Recipes = CreateDefaultSubobject<URecipes>(TEXT("Recipes"));
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


void ACauldron::AddReagent(FReagentData NewReagent)
{
	CurrentContents.Push(NewReagent);
	Recipes->EvaluatePossibleRecipes(CurrentContents);
}

void ACauldron::CreateNewPotion(Alchemy::Potions::FPotionBottle Bottle, APlayerController* PlayerController)
{
	auto playerController = Cast<AGLPlayerController>(PlayerController);
}

void ACauldron::Interact(APlayerController* PlayerController)
{
	AAlchemyPlayer* player = Cast<AAlchemyPlayer>(PlayerController->GetPawn());
	if (auto reagent = Cast<FReagentData>(player->GetHeldObject().Get()))
	{
		AddReagent(*reagent);
	}
	else if (auto bottle = Cast<Alchemy::Potions::FPotionBottle>(player->GetHeldObject().Get()))
	{
		
	}
}

