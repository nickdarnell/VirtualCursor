// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VirtualCursorFunctionLibrary.generated.h"

class UVaultModel;

/**
 * 
 */
UCLASS()
class VIRTUALCURSOR_API UVirtualCursorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category="Game")
	static void EnableVirtualCursor(class APlayerController* PC);

	UFUNCTION(BlueprintCallable, Category = "Game")
	static void DisableVirtualCursor(class APlayerController* PC);

	UFUNCTION(BlueprintCallable, Category = "Game")
	static UVaultModel* NewVaultModel();

	UFUNCTION(BlueprintPure, Category="Game")
	static bool IsCursorOverInteractableWidget();
};
