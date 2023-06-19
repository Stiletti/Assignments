// Assignment1 by OwnliE

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ass1Explosive.generated.h"

class USphereComponent;
class URadialForceComponent;

UCLASS()
class ASSIGNMENT1_API AAss1Explosive : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAss1Explosive();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Component)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Component)
	URadialForceComponent* RadialForceComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Component)
	USphereComponent* SphereComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
