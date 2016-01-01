// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VirtualCursor.h"

#include "VaultModel.h"
#include "VaultItem.h"

UVaultModel::UVaultModel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


const TArray<UVaultItem*>& UVaultModel::GetItems() const
{
	return Items;
}

void UVaultModel::PopulateModel()
{
	for (int32 i = 0; i < 100; ++i)
	{
		Items.Add( NewObject<UVaultItem>() );
	}
}