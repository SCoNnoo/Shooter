// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "AmmoType.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EWT_SubmachineGun UMETA(DisplayName = "SubmachineGun"),
	EWT_AssaultRifle UMETA(DisplayName = "AssaultRifle"),

	EWT_MAX UMETA(DisplayName = "DefaultMax"),
};

/**
 * 
 */
UCLASS()
class SHOOTER_API AWeapon : public AItem
{
	GENERATED_BODY()


public:
	AWeapon();

	virtual void Tick(float DeltaTime) override;

protected:



	void StopFalling();


private:

	FTimerHandle ThrowWeaponTimer;

	float ThrowWeaponTime;

	bool bFalling;

	/** Ammo count for this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	int32 Ammo;

	/** Maximun ammo that our weapon can hold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	int32 MagazineCapacity;

	/** The type of weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	/**The type of ammo for this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	EAmmoType AmmoType;

	/** FName for the reload montage section */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	FName ReloadMontageSection;

	/** True when moving the clip while reloading */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	bool bMovingClip;

	/** Name for the clip bone */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "WeaponProperties", meta = (AllowPrivateAccess = "true"))
	FName ClipBoneName;

public:

	/** Adds an impulse to the weapon*/
	void ThrowWeapon();

	FORCEINLINE int32 GetAmmo() const { return Ammo; }

	/** Called from character class when firing weapon */
	void DecrementAmmo();

	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; }

	FORCEINLINE EAmmoType GetAmmoType() const { return AmmoType; }

	FORCEINLINE int32 GetMagazineCapcity() const { return MagazineCapacity; }

	FORCEINLINE FName GetReloadMontageSection() const { return ReloadMontageSection; }

	void ReloadAmmo(int32 Amount);

	FORCEINLINE FName GetBoneClipName() const { return ClipBoneName; }

	FORCEINLINE void SetMovingClip(bool Move) { bMovingClip = Move; }

	bool ClipIsFull();

	
};
