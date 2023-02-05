// Fill out your copyright notice in the Description page of Project Settings.


#include "GLPlayerController.h"

#include "GreenLion/PotionInventory.h"

AGLPlayerController::AGLPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	Potions = CreateDefaultSubobject<UPotionInventory>(TEXT("Potions"));
}


