// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class ACNH_DATA_API SMenuWidget : public SCompoundWidget
{
public:

	// get ref to the hud
	SLATE_BEGIN_ARGS(SMenuWidget) {}
		// pass my widget to the hud
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual bool SupportsKeyboardFocus() const override { return true; }

	// compound widget is not UObject -> no garbage collecter -> manually manage object
	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	FReply OnQuitClicked() const;
};
