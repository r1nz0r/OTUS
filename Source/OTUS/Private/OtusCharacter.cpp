// Fill out your copyright notice in the Description page of Project Settings.


#include "OtusCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AOtusCharacter::AOtusCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AOtusCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOtusCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOtusCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent) return;
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AOtusCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOtusCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AOtusCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AOtusCharacter::AddControllerYawInput);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AOtusCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AOtusCharacter::ResetJumpState);
}

void AOtusCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AOtusCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

