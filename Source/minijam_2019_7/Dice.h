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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice", Meta = (BlueprintProtected = "true"))
	float RollingAngularVelocityThreshold;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Pickups")
	bool isRolling();

	UFUNCTION(BlueprintPure, Category = "Pickups")
	int GetCurrentValue();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* DebugText;

	void RefreshDebugText();
};
