// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector MoveVelocity;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float MoveDistance;

	UPROPERTY(EditAnywhere, Category = "Rotation")
		FRotator RotationVelocity;

	FVector StartLocation;

	void MovingPlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool CanReturn();
	float GetDistanceMoved();
};
