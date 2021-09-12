// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);


}




void APawnBase::RotateTurretFunction(FVector LookAtTarget) 
{
	//Change turret rotation based on where the player is at

	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);

	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();

	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire() 
{
	//Spawn a projectile and attack the actor where the projectile lands
	UE_LOG(LogTemp, Warning, TEXT("Fire condition success"));
}

void APawnBase::HandleDestruction() 
{
	// --- UNIVERSAL IMPLEMENTATION ---
	// Hide all components of the actor

	// --- CHILD IMPLEMENTATION ---
	
	//PawnTurret
	//Destroy the handle
	//Let the gamemode know that the actor has been destroyed

	//PawnTank
	//Just hide all components and let the gamemode know
}
