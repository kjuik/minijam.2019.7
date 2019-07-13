// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dice.generated.h"

UCLASS()
class MINIJAM_2019_7_API ADice : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	bool isRolling();

	int GetCurrentValue();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
};
