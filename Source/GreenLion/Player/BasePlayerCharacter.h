// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class GREENLION_API ABasePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasePlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess= "true"))
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess= "true"))
	class UInteractionComponent* InteractionComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UCameraComponent* GetCamera() {return CameraComponent;}
};
