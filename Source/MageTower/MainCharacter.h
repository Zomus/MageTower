// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MainCharacter.generated.h"

UCLASS()
class MYFIRSTSIDESCROLLER_API AMainCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    int maxHP;
    //amount of maximum HP (HP as it spawns)
    int HP;
    //amount of remaining HP
    float Attack;
    //attack power of enemy
    float MoveSpeed;
    //speed at which the enemy moves
    float ClimbSpeed;
    //speed at which the enemy climbs ladders
    
    int state;
    /*state of the enemy
     0 = not moving
     1 = walking (moves sideways)
     2 = climbing (moves upwards)
     */
	
    //Function "Advance" moves the character forward
    void Advance (float Speed, float DeltaTime);
    
    //Function "Climb" changes the animation of the character to climb and moves the character up at the speed of its ClimbSpeed
    void Climb (float Speed, float DeltaTime);
    
    //Function "DistBetween2D" calculates the 2D distance between two positions (NOTE: should move this to Main)
    float DistBetween2D (FVector Location1, FVector Location2);
};
