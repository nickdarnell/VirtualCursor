// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VirtualCursor.h"
#include "GameGlobals.h"

UGameGlobals::UGameGlobals(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MaxAnalogCursorSpeed = 1300.0f;
	MaxAnalogCursorSpeedWhenHovered = 650.0f;
	AnalogCursorDragCoefficient = 8.0f;
	AnalogCursorDragCoefficientWhenHovered = 14.0f;
	MinAnalogCursorSpeed = 5.0f;
	AnalogCursorDeadZone = 0.15f;
	AnalogCursorAccelerationMultiplier = 9000.0f;
	AnalogCursorSize = 40.0f;

	AnalogCursorAccelerationCurve.EditorCurveData.AddKey(0, 0);
	AnalogCursorAccelerationCurve.EditorCurveData.AddKey(1, 1);
}
