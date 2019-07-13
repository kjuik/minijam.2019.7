// Fill out your copyright notice in the Description page of Project Settings.

#include "Dice.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "CoreMinimal.h"

// Sets default values
ADice::ADice()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);

	DebugText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Debug text"));
	DebugText->AddLocalOffset(FVector(0.0f, 0.0f, 100.0f));

	RefreshDebugText();
}

// Called when the game starts or when spawned
void ADice::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called when the game starts or when spawned
bool ADice::isRolling()
{
	return Mesh->GetPhysicsAngularVelocity().SizeSquared() > RollingAngularVelocityThreshold;
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

	RefreshDebugText();
	
	DebugText->SetWorldLocation(GetActorLocation() + FVector(0.0f, 0.0f, 100.0f));

	if (GEngine) {
		FVector CameraLocation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraLocation();
		DebugText->SetWorldRotation((CameraLocation - DebugText->GetComponentLocation()).Rotation());
	}
}

void ADice::RefreshDebugText() {
	if (isRolling()) {
		DebugText->SetText(FString(TEXT("rolling")));
	}
	else
	{
		DebugText->SetText(FString(TEXT("not rolling")));
	}

	
}

