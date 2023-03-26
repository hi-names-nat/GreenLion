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

	/**
	 * @brief Get a potion ready to throw. This will bring the character in a ready stance and bring the camera to
	 * the throwing angle
	 */
	void ReadyPotion();
	/**
	 * @brief When in ready position, throw the potion. This means removing a potion from the potion inventory,
	 * changing that potion to a potion projectile object, and setting that projectile object.
	 */
	void ThrowPotion();
	/**
	 * @brief Get the next potion in the potion inventory
	 * @param previous if true, instead get the last potion 
	 */
	void GetNextPotion(bool previous);
	/**
	 * @brief Open the potion wheel. DW about this atm.
	 */
	void OpenPotionWheel();
	/**
	 * @brief Close the potion wheel. DW about this atm.
	 */
	void ClosePotionWheel();
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};

