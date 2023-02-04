// Fill out your copyright notice in the Description page of Project Settings.


#include "AlchemyPlayer.h"

#include "Camera/CameraComponent.h"

void AAlchemyPlayer::ButtonPressed(Inputs GivenInput)
{
	
}

// Sets default values
AAlchemyPlayer::AAlchemyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
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
	

	//binds for QTEs
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AAlchemyPlayer::SprintPressed);
	PlayerInputComponent->BindAction("Sneak", IE_Pressed, this, &AAlchemyPlayer::CrouchPressed);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AAlchemyPlayer::JumpPressed);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AAlchemyPlayer::AttackPressed);
	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &AAlchemyPlayer::ThrowPressed);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AAlchemyPlayer::InteractPressed);
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AAlchemyPlayer::UsePressed);
}

void AAlchemyPlayer::SelectObject()
{
	FVector Position, Direction;
	Cast<APlayerController>(this->GetController())->DeprojectMousePositionToWorld(Position, Direction);
	FHitResult OUT_HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	
	GetWorld()->LineTraceSingleByChannel(OUT_HitResult, Position, Position + (Direction * 100), ECC_Visibility, CollisionParams);
	//Add interact with object.
}

