// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerCharacter.h"
#include "GameFramework/Character.h"
#include "GLMainCharacter.generated.h"


UCLASS(config=Game)
class AGLMainCharacter : public ABasePlayerCharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	AGLMainCharacter();

protected:

	/** Called for movement input */
	void MoveX(const float Value);
	void MoveZ(const float Value);

	
	/** Called for looking input */
	void LookX(const float Value);
	void LookY(const float Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};

