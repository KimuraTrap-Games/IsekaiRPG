// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordComponent.generated.h"

UCLASS()
class ISEKAIRPG_API ASwordComponent : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASwordComponent();

	//Sword Attack Functions
	void LightAttack();
	//Tap left mouse button for chain light attacks

	void HeavyAttack();
	//Hold left mouse button for heavy attack

	void StartBlocking();
	//Hold right mouse button to block

	void StopBlocking();
	//Release right mouse button to stop blocking

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Helper Function
	void PerformAttack(float Damage, FName MontageSection);

	//Combat State
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	bool bIsBlocking;

	//Attack Damage Values
	UPROPERTY(EditAnywhere, Category = "Combat")
	float LightAttackDamage;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float HeavyAttackDamage;

	//Animations
	UPROPERTY(EditAnywhere, Category = "Combat")
	class UAnimMontage* AttackMontage;

	//Reference to the owning character
	UPROPERTY()
	class ACharacter* OwningCharacter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
