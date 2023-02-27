// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "InteractInterface.h"
#include "Camera/CameraComponent.h"
#include "GreenLion/Player/GLMainCharacter.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractionComponent::AttemptInteract()
{
	auto Owner = Cast<ABasePlayerCharacter>(GetOwner());
	auto CameraPos = Owner->GetCamera()->GetComponentLocation();
	auto CameraForward = Owner->GetCamera()->GetForwardVector();
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	FHitResult Out_Hit;

	auto World = GetWorld();
	
	if (!World->LineTraceSingleByChannel(Out_Hit, CameraPos, CameraPos +
		(CameraForward * interactReach), ECC_Visibility, CollisionParams)) return;
	DrawDebugLine(World, CameraPos, CameraPos + (CameraForward * interactReach), FColor::Red,
		false, 5);
	if (auto t = Cast<IInteractInterface>(Out_Hit.Component->GetOwner()))
	{
		t->Interact(Cast<APlayerController>(Owner->GetController()));
	}
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

