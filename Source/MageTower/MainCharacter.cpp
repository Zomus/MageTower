// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstSidescroller.h"
#include "MainCharacter.h"
#include "cmath"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
    HP = 100.0;
    Attack = 2.0f;
    Speed = 2.0f;
    State = 1;
    //enemy starts by walking
}

// Called every frame
void AMainCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
    if(State == 1){ // if moving
        Advance(GetActorLocation(), MoveSpeed, DeltaTime);
    }
    else if(State == 2){ // if climbing
        Climb(GetActorLocation(), ClimbSpeed, DeltaTime);
    }
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

//Function "Advance" moves the character forward
void Advance (FVector Location, float Speed, float DeltaTime){
    //set animation to walking
    Location.X += Speed * DeltaTime;
    SetActorLocation(Location);
}

//Function "Climb" moves the character forward
void Climb (FVector Location, float Speed, float DeltaTime){
    //set animation to climbing
    Location.Y += Speed * DeltaTime;
    SetActorLocation(Location);
}

float distBetween2D (FVector Location1, FVector Location2){
    return sqrt(pow(Location2.X - Location1.X, 2) + pow(Location2.Y - Location1.Y, 2));
}




