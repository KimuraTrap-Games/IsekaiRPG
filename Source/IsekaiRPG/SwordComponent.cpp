// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ASwordComponent::ASwordComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsBlocking = false;
	LightAttackDamage = 10.f;
	HeavyAttackDamage = 25.f;

}

// Called when the game starts or when spawned
void ASwordComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwordComponent::PerformAttack(float Damage, FName MontageSection)
{
	// Logic to perform attack, apply damage to hit targets, play animations, etc.
	if (!OwningCharacter)
	{
		OwningCharacter = Cast<ACharacter>(GetOwner());
	}

	if (OwningCharacter && AttackMontage)
	{
		UAnimInstance* AnimInstance = OwningCharacter->GetMesh()->GetAnimInstance();
        // Add this include at the top of the file to resolve the incomplete type error
        
		if (AnimInstance)
		{
			AnimInstance->Montage_Play(AttackMontage);
			AnimInstance->Montage_JumpToSection(MontageSection, AttackMontage);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Sword Attack: %s | Damage: %.1f"), *MontageSection.ToString(), Damage);
}

void ASwordComponent::LightAttack()
{
	PerformAttack(LightAttackDamage, "LightAttack");
}

void ASwordComponent::HeavyAttack()
{
	PerformAttack(HeavyAttackDamage, "HeavyAttack");
}

void ASwordComponent::StartBlocking()
{
	bIsBlocking = true;
	UE_LOG(LogTemp, Warning, TEXT("Blocking with a sword..."));
}

void ASwordComponent::StopBlocking()
{
	bIsBlocking = false;
	UE_LOG(LogTemp, Warning, TEXT("Stopped blocking with a sword..."));
}

// Called every frame
void ASwordComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

