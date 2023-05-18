// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerCharacter.h"
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

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess="true"))
	bool HasObject = false;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess="true"))
	FAlchemyHoldableData HeldObject;
	
public:
////////////////////////////////////////////////////////////////////////
/////////////////////////// FUNCTIONS //////////////////////////////////

	bool IsHoldingObject() const {return HasObject;}
public:
	// Sets default values for this pawn's properties
	AAlchemyPlayer();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	FAlchemyHoldableData* GetHeldObject()
	{
		if (HasObject) return &HeldObject; else return nullptr;
	}
	void SetHeldObject(const FAlchemyHoldableData& Object) {HeldObject = Object; HasObject = true;}
	void EmptyHeldObject() {HasObject = false;}

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
