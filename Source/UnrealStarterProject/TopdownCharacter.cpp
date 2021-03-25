// Fill out your copyright notice in the Description page of Project Settings.


#include "TopdownCharacter.h"

// Sets default values
ATopdownCharacter::ATopdownCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATopdownCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopdownCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(*direction * moveSpeed * DeltaTime);
	SetActorRotation(FRotationMatrix::MakeFromX(directionSafe->GetSafeNormal()).Rotator());
}

// Called to bind functionality to input
void ATopdownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Horizontal", this, &ATopdownCharacter::HorizontalAxis);
	PlayerInputComponent->BindAxis("Vertical", this, &ATopdownCharacter::VerticalAxis);
}

void ATopdownCharacter::HorizontalAxis(float value)
{
	direction->Y = value;
	if (direction->Size() != 0.f) 
	{
		directionSafe->Y = value;
	}
}
void ATopdownCharacter::VerticalAxis(float value)
{
	direction->X = value;
	if (direction->Size() != 0.f)
	{
		directionSafe->X = value;
	}
}
