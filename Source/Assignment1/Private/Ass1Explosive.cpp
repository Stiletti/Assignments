// Assignment1 by OwnliE


#include "Ass1Explosive.h"

#include "Components/SphereComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AAss1Explosive::AAss1Explosive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = StaticMeshComponent;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(RootComponent);

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComponent");
	RadialForceComponent->Radius = 1000.0f;
	RadialForceComponent->ForceStrength = 1000.0f;
	RadialForceComponent->bImpulseVelChange = true;
	RadialForceComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAss1Explosive::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AAss1Explosive::OnOverlap);
}

// Called every frame
void AAss1Explosive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAss1Explosive::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("OVERLAAAAAAAAAAAAP"));
		RadialForceComponent->FireImpulse();
	}
}
