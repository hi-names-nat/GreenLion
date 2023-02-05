// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GreenLion/Player/GLPlayerController.h"

#include "./GreenLion/PotionInventory.h"
#include "./GreenLion/Potion.h"

#include "Merchant.generated.h"

UCLASS()
class GREENLION_API AMerchant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMerchant();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void SellPotion(AGLPlayerController* Player, UPotionInventory* PInv, int Index);
	//void BuyItem(AGLPlayerController Player, URegent BoughtItem);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
};
