// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VirtualCursor.h"
#include "GameGlobals.h"
#include "GameAnalogCursor.h"
#include "VirtualCursorFunctionLibrary.h"
#include "Model/VaultModel.h"
#include "Model/VaultItem.h"

void UVirtualCursorFunctionLibrary::EnableVirtualCursor(class APlayerController* PC)
{
	FGameAnalogCursor::EnableAnalogCursor(PC, TSharedPtr<SWidget>());
}

void UVirtualCursorFunctionLibrary::DisableVirtualCursor(class APlayerController* PC)
{
	FGameAnalogCursor::DisableAnalogCursor(PC);
}

UVaultModel* UVirtualCursorFunctionLibrary::NewVaultModel()
{
	UVaultModel* NewModel = NewObject<UVaultModel>();
	NewModel->PopulateModel();
	return NewModel;
}

bool UVirtualCursorFunctionLibrary::IsCursorOverInteractableWidget()
{
	TSharedPtr<FGameAnalogCursor> Analog = GetDefault<UGameGlobals>()->GetAnalogCursor();
	if ( Analog.IsValid() )
	{
		return Analog->IsHovered();
	}

	return false;
}
