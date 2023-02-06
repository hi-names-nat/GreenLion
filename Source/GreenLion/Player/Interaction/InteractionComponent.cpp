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
	UE_LOG(LogTemp, Log, TEXT("Pew"));
	auto owner = Cast<AGLMainCharacter>(GetOwner());
	auto cameraPos = owner->GetFollowCamera()->GetComponentLocation();
	auto cameraForward = owner->GetFollowCamera()->GetForwardVector();
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	FHitResult OUT_Hit;
	
	if (!GetWorld()->LineTraceSingleByChannel(OUT_Hit, cameraPos, cameraPos +
		(cameraForward * interactReach), ECC_Visibility, CollisionParams)) return;
	DrawDebugLine(GetWorld(), cameraPos, cameraPos + (cameraForward * interactReach), FColor::Red,
		false, 5);
	if (auto t = Cast<IInteractInterface>(OUT_Hit.Component->GetOwner()))
	{
		t->Interact(Cast<APlayerController>(owner->GetController()));
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

