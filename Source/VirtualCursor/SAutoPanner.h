// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "VirtualCursor.h"
#include "SlateBasics.h"

class SAutoPanner : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAutoPanner){}
		SLATE_DEFAULT_SLOT(FArguments, Content)
		/** The extra size added to the screen. */
		SLATE_ARGUMENT(FVector2D, PaddingScale)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// Begin SWidget interface
	void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	// End SWidget interface

	void SetContent(const TSharedRef<SWidget>& InContent);

	void SetPaddingScale(FVector2D InPaddingScale) { PaddingScale = InPaddingScale; }
	FVector2D GetPaddingScale() const { return PaddingScale; }

	FVector2D GetNormalizedCursorPosition() const;

private:
	FVector2D LocalMousePosition;
	FVector2D NormalizedCursorPosition;

	FVector2D PaddingScale;
};