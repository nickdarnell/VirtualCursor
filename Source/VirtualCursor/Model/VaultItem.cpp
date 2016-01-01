// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VirtualCursor.h"

#include "VaultItem.h"

#define LOCTEXT_NAMESPACE "VirtualCursor"

static FName GetRandomItemTexture()
{
	static FName ItemTextures[] =
	{ "/Game/UI/Icons/Weapons/Belt_2.Belt_2"
	, "/Game/UI/Icons/Weapons/Bracelet_2.Bracelet_2"
	, "/Game/UI/Icons/Weapons/Glove_2.Glove_2"
	, "/Game/UI/Icons/Weapons/Hammer1_3.Hammer1_3"
	, "/Game/UI/Icons/Weapons/Hood_2.Hood_2"
	, "/Game/UI/Icons/Weapons/Leather_Bracelet_1.Leather_Bracelet_1"
	, "/Game/UI/Icons/Weapons/Leather_Glove_1.Leather_Glove_1"
	, "/Game/UI/Icons/Weapons/Light_Armor_1.Light_Armor_1"
	, "/Game/UI/Icons/Weapons/Light_Belt_1.Light_Belt_1"
	, "/Game/UI/Icons/Weapons/Light_Boot_1.Light_Boot_1"
	, "/Game/UI/Icons/Weapons/Light_Helm_1.Light_Helm_1"
	, "/Game/UI/Icons/Weapons/Light_Pants_1.Light_Pants_1"
	, "/Game/UI/Icons/Weapons/Pants_2.Pants_2"
	, "/Game/UI/Icons/Weapons/Robe_2.Robe_2"
	, "/Game/UI/Icons/Weapons/Shoes_2.Shoes_2"
	, "/Game/UI/Icons/Weapons/Sword2.Sword2"
	, "/Game/UI/Icons/Weapons/Wand2_1.Wand2_1"
	, "/Game/UI/Icons/Weapons/Wizard_Belt_1.Wizard_Belt_1"
	, "/Game/UI/Icons/Weapons/Wizard_Bracelet_1.Wizard_Bracelet_1"
	, "/Game/UI/Icons/Weapons/Wizard_Glove_1.Wizard_Glove_1"
	, "/Game/UI/Icons/Weapons/Wizard_Hat_1.Wizard_Hat_1"
	, "/Game/UI/Icons/Weapons/Wizard_Pants_1.Wizard_Pants_1"
	, "/Game/UI/Icons/Weapons/Wizard_Robe_1.Wizard_Robe_1"
	, "/Game/UI/Icons/Weapons/Wizard_Shoe_1.Wizard_Shoe_1"
	};

	const int32 Count = sizeof(ItemTextures) / sizeof(FName);
	const int32 IconIndex = FMath::Rand() % Count;
	return ItemTextures[IconIndex];
}

UVaultItem::UVaultItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NameText = LOCTEXT("Name1", "WEAPON OF POWER");
	TypeText = LOCTEXT("Type1", "Rifle");
	FlavorText = LOCTEXT("Flavor1", "Once there was a weapon said to be so powerful it could kill all the things.  This is not that weapon.");

	RequiredLevel = FMath::RoundToInt(FMath::FRand() * 50);

	Damage = FMath::RoundToInt(FMath::FRand() * 10000.0) / 10.0f;
	Range = FMath::RoundToInt(FMath::FRand() * 10000.0) / 10.0f;
	Durability = FMath::RoundToInt(FMath::FRand() * 10000.0) / 10.0f;
	CriticalHitChance = FMath::RoundToInt(FMath::FRand() * 1000.0) / 10.0f;

	Rarity = (ERarity)(FMath::Rand() % 5);

	static FName CosmeticSlotNames[] = {
		"Primary",
		"Secondary",
		"Extra1",
		"Extra2"
	};

	const int32 CosmeticCount = sizeof(CosmeticSlotNames) / sizeof(FName);

	for ( int32 i = 0; i < CosmeticCount; i++ )
	{
		FCosmeticSlot Slot;
		Slot.Name = CosmeticSlotNames[i];
		Slot.Color = FLinearColor::MakeRandomColor();

		CosmeticSlots.Add(Slot);
	}

	IconTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *GetRandomItemTexture().ToString()));
}

FLinearColor UVaultItem::GetRarityColor() const
{
	switch ( Rarity )
	{
	case ERarity::Common:
		return FLinearColor(0.3, 0.3, 0.3);
	case ERarity::Uncommon:
		return FLinearColor(0, 0.3, 0);
	case ERarity::Rare:
		return FLinearColor(0, 0.065, 1);
	case ERarity::Epic:
		return FLinearColor(0.4, 0.0, 1);
	case ERarity::Legendary:
		return FLinearColor(1, 0.248, 0);
	}

	return FLinearColor(1, 1, 1);
}

FText UVaultItem::GetRarityText() const
{
	const static UEnum* RarityEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("ERarity"), true);

	return RarityEnum->GetEnumText((int32)Rarity);
}

#undef LOCTEXT_NAMESPACE
