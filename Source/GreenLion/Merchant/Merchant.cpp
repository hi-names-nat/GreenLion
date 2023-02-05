// Fill out your copyright notice in the Description page of Project Settings.


#include "Merchant.h"

#include "GreenLion/Player/GLPlayerController.h"

// Sets default values
AMerchant::AMerchant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("This is Mesh Component"));
	MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMerchant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMerchant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMerchant::SellPotion(AGLPlayerController* Player, UPotionInventory* PInv, int index)
{
	Player -> Money += PInv -> Sell(index);
	
}

/*
void AMerchant::BuyItem(AGLPlayerController Player, URegent BoughtItem)
{
	if(Player.Money >= BoughtItem.SellPrice)
	{
		Player.Money -= BoughtItem.SellPrice;
		
		//Player.Inventory.Add(BoughtItem);
	}
}
*/


