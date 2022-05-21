// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObj/MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
 	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComp);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	CurrentLocation = StartLocation;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	CurrentLocation = CurrentLocation + (Velocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);

	if (DistanceMoved > MoveDistance)
	{
		FVector MoveDirection = Velocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		Velocity = -Velocity;
	}
}

