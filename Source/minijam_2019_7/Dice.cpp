// Fill out your copyright notice in the Description page of Project Settings.

#include "Dice.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADice::ADice()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ADice::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called when the game starts or when spawned
bool ADice::isRolling()
{
	return false;
}

// Called when the game starts or when spawned
int ADice::GetCurrentValue()
{
	return 0;
}

// Called every frame
void ADice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

