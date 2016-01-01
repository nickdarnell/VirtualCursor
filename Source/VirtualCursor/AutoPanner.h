// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UMG.h"

#include "AutoPanner.generated.h"

class SAutoPanner;

UCLASS()
class UAutoPanner : public UContentWidget
{
	GENERATED_UCLASS_BODY()

public:
	/** The padding scale applied to the widget. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Auto Panner")
	FVector2D PaddingScale;

public:
	UFUNCTION(BlueprintCallable, Category = "Auto Panner")
	FVector2D GetNormalizedCursorPosition() const;


public:

	// UWidget interface
	virtual void SynchronizeProperties() override;
	// End of UWidget interface

	// UVisual interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	// End of UVisual interface

	// Begin UObject interface
	virtual void PostLoad() override;
	// End of UObject interface

protected:
	// UPanelWidget
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* Slot) override;
	virtual void OnSlotRemoved(UPanelSlot* Slot) override;
	// End UPanelWidget

protected:
	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface

private:
	TSharedPtr<SAutoPanner> MyAutoPanner;

};