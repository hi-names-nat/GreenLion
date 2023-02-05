// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AlchemyPlayer.generated.h"

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
class GREENLION_API AAlchemyPlayer : public APawn
{
	GENERATED_BODY()

	void ButtonPressed(Inputs GivenInput);

	UCameraComponent* CameraComponent;

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

private:
	//individual input actions
	void JumpPressed() {ButtonPressed(Inputs::Jump);}
	void CrouchPressed() {ButtonPressed(Inputs::Crouch);}
	void SprintPressed() {ButtonPressed(Inputs::Sprint);}
	void AttackPressed() {ButtonPressed(Inputs::Attack);}
	void ThrowPressed() {ButtonPressed(Inputs::Throw);}
	void InteractPressed() {ButtonPressed(Inputs::Interact);}
	void UsePressed() {ButtonPressed(Inputs::Use);}

	void SelectObject();



};
