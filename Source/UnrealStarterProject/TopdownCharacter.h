// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopdownCharacter.generated.h"

UCLASS()
class UNREALSTARTERPROJECT_API ATopdownCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopdownCharacter();

private:
	UPROPERTY(EditAnywhere)
	float moveSpeed{ 100.0f };
	FVector* direction { new FVector() };
	FVector* directionSafe { new FVector() };

	void HorizontalAxis(float value);
	void VerticalAxis(float value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
