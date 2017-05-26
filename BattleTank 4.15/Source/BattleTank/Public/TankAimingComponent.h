// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//enum for aiming state
UENUM()
enum class EFiringState : uint8 
{ 
	Reloading,
	Aiming,
	Locked
};

 //forward.declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Holds Barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

		
protected:


	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringState FiringState = EFiringState::Reloading;


private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	virtual void BeginPlay();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;

	FVector AimDirection;
};
