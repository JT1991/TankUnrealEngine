// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank)) {
		//TODO move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);//check unit is in cm
		//aim at the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); //TODO stop firing every frame.
	}
}


