// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ass1Character.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ASSIGNMENT1_API AAss1Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAss1Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	USpringArmComponent* SpringArmComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ProjectileClass)
	TSubclassOf<AActor> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void FireProjectile();
};
