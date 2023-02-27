// Fill out your copyright notice in the Description page of Project Settings.


#include "AlchemyPlayer.h"

#include "Camera/CameraComponent.h"
#include "Interaction/InteractionComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAlchemyPlayer::AAlchemyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);

	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("Interaction"));
}

// Called when the game starts or when spawned
void AAlchemyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAlchemyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAlchemyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//binds for click-around
	
	//Interaction
	PlayerInputComponent->BindAction("Interact", IE_Pressed, InteractionComponent,
		&UInteractionComponent::AttemptInteract);

	//Move
	PlayerInputComponent->BindAxis("MoveX", this, &AAlchemyPlayer::MoveZ);
	PlayerInputComponent->BindAxis("MoveY", this, &AAlchemyPlayer::MoveX);


	//Looking
	PlayerInputComponent->BindAxis("LookPitch", this, &AAlchemyPlayer::LookY);
	PlayerInputComponent->BindAxis("LookYaw", this, &AAlchemyPlayer::LookX);
}

void AAlchemyPlayer::MoveX(const float Value)
{
	// input is a Vector2D

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(RightDirection, Value);
	}
}

void AAlchemyPlayer::MoveZ(const float Value)
{
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 

		// add movement 
		AddMovementInput(ForwardDirection, Value);
	}
}

void AAlchemyPlayer::LookX(const float Value)
{
	// input is a Vector2D

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		if (Controller != nullptr)
		{
			// add yaw and pitch input to controller
			CameraComponent->AddLocalRotation(FRotator(-Value * 2, 0 , 0));
			auto ClampedRotation = FMath::Clamp(CameraComponent->GetComponentRotation().Pitch, -80, 80);
			CameraComponent->SetWorldRotation(FRotator(ClampedRotation, CameraComponent->GetComponentRotation().Yaw, CameraComponent->GetComponentRotation().Roll)); 
		}
	}
}

void AAlchemyPlayer::LookY(const float Value)
{
	// input is a Vector2D

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Value);
	}
}

