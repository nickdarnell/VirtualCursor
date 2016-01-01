// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "VaultModel.generated.h"

class UVaultItem;

UCLASS(BlueprintType)
class UVaultModel : public UObject
{
	GENERATED_UCLASS_BODY()
	public:
		
		void PopulateModel();

		const TArray<UVaultItem*>& GetItems() const;

	protected:
		
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultModel")
		TArray<UVaultItem*> Items;
};