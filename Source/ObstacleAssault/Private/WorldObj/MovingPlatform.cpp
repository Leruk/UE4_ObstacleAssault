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
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	MovingPlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovingPlatform(float DeltaTime)
{
	if (MoveVelocity.IsZero()) return;

	if (CanReturn())
	{
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (MoveVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	if (RotationVelocity.IsZero()) return;

	FRotator CurrentRotaton = GetActorRotation();
	CurrentRotaton = CurrentRotaton + (RotationVelocity * DeltaTime);
	SetActorRotation(CurrentRotaton);
}

bool AMovingPlatform::CanReturn()
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Distance(StartLocation, GetActorLocation());
}