// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerCharacter.h"
#include "GameFramework/Character.h"
#include "GreenLion/Alchemy/ReagentData.h"
#include "AlchemyPlayer.generated.h"

class UInteractionComponent;
class UCameraComponent;

UCLASS()
class GREENLION_API AAlchemyPlayer : public ABasePlayerCharacter
{
	GENERATED_BODY()

////////////////////////////////////////////////////////////////////////
/////////////////////////// VARIABLES //////////////////////////////////
protected:

	TSharedPtr<FAlchemyHoldableObject> HeldObject;
public:

////////////////////////////////////////////////////////////////////////
/////////////////////////// FUNCTIONS //////////////////////////////////

public:
	// Sets default values for this pawn's properties
	AAlchemyPlayer();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TSharedPtr<FAlchemyHoldableObject> GetHeldObject() const {return HeldObject;}
	void SetHeldObject(FAlchemyHoldableObject* Object) {HeldObject = TSharedPtr<FAlchemyHoldableObject>(Object);}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/** Called for movement input */
	void MoveX(const float Value);
	void MoveY(const float Value);
	
	/** Called for looking input */
	void LookX(const float Value);
	void LookY(const float Value);
	
};
