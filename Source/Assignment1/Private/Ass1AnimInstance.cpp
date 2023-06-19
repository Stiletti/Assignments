// ALLES MEINS !


#include "Ass1AnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

void UAss1AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// When animation is called we check if our Pawn is valid
	if (AnimPawn == nullptr)
	{
		AnimPawn = TryGetPawnOwner();
	}
}

void UAss1AnimInstance::UpdateAnimProperties()
{
	if (AnimPawn == nullptr)
	{
		AnimPawn = TryGetPawnOwner();
	}

	if (AnimPawn)
	{
		// We check the actual speed of the Pawn
		FVector Speed = AnimPawn->GetVelocity();
	
		// We need to check the lateral movement too, thats what we are doin here
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.0f);
	
		// .Size() returns the "magnitude" which means we get the float value back
		MovementSpeed = LateralSpeed.Size();

		bIsInAir = AnimPawn->GetMovementComponent()->IsFalling();	
	}
}


