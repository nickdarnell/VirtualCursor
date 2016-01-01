// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VirtualCursor.h"
#include "SAutoPanner.h"



void SAutoPanner::Construct(const FArguments& InArgs)
{
	LocalMousePosition = FVector2D::ZeroVector;
	NormalizedCursorPosition = FVector2D::ZeroVector;
	PaddingScale = InArgs._PaddingScale;
	this->ChildSlot
	[
		InArgs._Content.Widget
	];
}

void SAutoPanner::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	const EVisibility ChildVisibility = ChildSlot.GetWidget()->GetVisibility();
	if (ArrangedChildren.Accepts(ChildVisibility))
	{
		const FVector2D ChildDesiredSize = ( AllottedGeometry.Size * PaddingScale );
		const FVector2D Offset = -LocalMousePosition / AllottedGeometry.Size * (ChildDesiredSize - AllottedGeometry.Size);

		ArrangedChildren.AddWidget(ChildVisibility, AllottedGeometry.MakeChild(
			ChildSlot.GetWidget(),
			FVector2D(Offset.X, Offset.Y),
			FVector2D(ChildDesiredSize)
			));
	}
}

FReply SAutoPanner::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	LocalMousePosition = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	NormalizedCursorPosition = LocalMousePosition / MyGeometry.Size;
	return FReply::Unhandled();
}

void SAutoPanner::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	LocalMousePosition = AllottedGeometry.AbsoluteToLocal(FSlateApplicationBase::Get().GetCursorPos());
	NormalizedCursorPosition = LocalMousePosition / AllottedGeometry.Size;
}

void SAutoPanner::SetContent(const TSharedRef<SWidget>& InContent)
{
	this->ChildSlot
	[
		InContent
	];
}

FVector2D SAutoPanner::GetNormalizedCursorPosition() const
{
	return NormalizedCursorPosition;
}