// ALLES MEINS !

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Ass1AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT1_API UAss1AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	// We need to know the actual speed of the Pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Anim)
	float MovementSpeed;

	// We check if the Pawn is in air
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Anim)
	bool bIsInAir;

	// Our reference to the possessed Pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Anim)
	APawn* AnimPawn;

	// Kinda BeginPLay for animations
	virtual void NativeInitializeAnimation() override;

	// Here we update our properties
	UFUNCTION(BlueprintCallable)
	void UpdateAnimProperties();
	
};
