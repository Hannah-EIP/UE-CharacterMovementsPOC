// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/HannahCharacter.h"

// Sets default values
AHannahCharacter::AHannahCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AddPoseableMeshComponent();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("HannahCharacter initialized."));
}

void AHannahCharacter::AddPoseableMeshComponent()
{
	if (this->GetMesh())
		this->GetMesh()->DestroyComponent();
	PoseableMesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("PoseableMesh"));
	PoseableMesh->SetupAttachment(RootComponent);
	this->AddInstanceComponent(PoseableMesh);
}

// Called when the game starts or when spawned
void AHannahCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHannahCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator rot = PoseableMesh->GetBoneRotationByName(FName("hand_l"), EBoneSpaces::WorldSpace);
	FRotator rot2 = PoseableMesh->GetBoneRotationByName(FName("lowerarm_l"), EBoneSpaces::WorldSpace);
	rot.Roll += 1;
	if (rot2.Yaw > 130)
		rot2.Yaw -= 100;
	else
		rot2.Yaw += 1;
	PoseableMesh->SetBoneRotationByName(FName("hand_l"), rot, EBoneSpaces::WorldSpace);
	PoseableMesh->SetBoneRotationByName(FName("lowerarm_l"), rot2, EBoneSpaces::WorldSpace);

	FRotator rot3 = PoseableMesh->GetBoneRotationByName(FName("hand_r"), EBoneSpaces::WorldSpace);
	FRotator rot4 = PoseableMesh->GetBoneRotationByName(FName("lowerarm_r"), EBoneSpaces::WorldSpace);
	rot3.Roll += 1;
	if (rot4.Yaw > 130)
		rot4.Yaw += 100;
	else
		rot4.Yaw -= 1;
	PoseableMesh->SetBoneRotationByName(FName("hand_r"), rot3, EBoneSpaces::WorldSpace);
	PoseableMesh->SetBoneRotationByName(FName("lowerarm_r"), rot4, EBoneSpaces::WorldSpace);
}

// Called to bind functionality to input
void AHannahCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

