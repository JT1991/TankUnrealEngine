// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 TankTrack is used to set maximum driving force, and apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle -1/+1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//max force PER TRACK in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; //assume 40 ton tank and 1G acceleration
	
private:
	UTankTrack();
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpluse, const FHitResult& Hit);
	void DriveTrack();
	float CurrentThrottle = 0;
};
