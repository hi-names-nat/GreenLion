// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerCharacter.h"
#include "GameFramework/Character.h"
#include "GreenLion/Alchemy/ReagentData.h"
#include "AlchemyPlayer.generated.h"

class UInteractionComponent;
class UCameraComponent;

enum Inputs
{
	Jump,
	Crouch,
	Sprint,
	Attack,
	Throw,
	Use,
	Interact,
};

UCLASS()
class GREENLION_API AAlchemyPlayer : public ABasePlayerCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAlchemyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TSharedPtr<FReagentData> GetHeldReagent() const {return HeldReagent;}

private:

	/** Called for movement input */
	void MoveX(const float Value);
	void MoveY(const float Value);
	
	/** Called for looking input */
	void LookX(const float Value);
	void LookY(const float Value);
	
	TSharedPtr<FReagentData> HeldReagent;
};
