// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "VaultItem.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticSlot
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticSlot")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticSlot")
	FLinearColor Color;
};

UENUM()
enum class ERarity : uint8
{
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

UCLASS(BlueprintType)
class UVaultItem : public UObject
{
	GENERATED_BODY()

public:
	UVaultItem(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	FText NameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	FText TypeText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	int32 RequiredLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	FText FlavorText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	ERarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	float Range;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	float Durability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	float CriticalHitChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultItem")
	TArray<FCosmeticSlot> CosmeticSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VaultItem")
	UTexture2D* IconTexture;

public:
	UFUNCTION(BlueprintCallable, Category = "VaultItem")
	FLinearColor GetRarityColor() const;

	UFUNCTION(BlueprintCallable, Category = "VaultItem")
	FText GetRarityText() const;
};
