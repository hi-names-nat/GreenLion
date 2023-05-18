// (c) Natalie Soltis & Dark Frog SGS 2022-23.


#include "HoldableGiver.h"
#include "../Player/AlchemyPlayer.h"
#include "GameFramework/PlayerController.h"


// Sets default values for this component's properties
UHoldableGiver::UHoldableGiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UHoldableGiver::BeginPlay()
{
	Super::BeginPlay();
}

void UHoldableGiver::Interact(APlayerController* PlayerController)
{
	IInteractInterface::Interact(PlayerController);

	const auto Player = Cast<AAlchemyPlayer>(PlayerController->GetCharacter());
	
	Player->SetHeldObject(Data);
}