// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthBar.h"

void SHealthBar::Construct(const FArguments& InArgs)
{
	Health = InArgs._Health;
	TotalHealth = InArgs._TotalHealth;
	SlateHud = InArgs._SlateHud;
	//TPercent.Bind(this, &SHealthBar::SetPercentage);
	ChildSlot
		[
			SNew(SProgressBar)
			.Percent(this, &SHealthBar::SetPercentage)//Percent(TOptional<float>(Health / TotalHealth))//.Percent(this, &SHealthBar::GetPersentage)
		];
}

TOptional<float> SHealthBar::SetPercentage() const
{
	return TOptional<float>(Health / (float)TotalHealth);
}


SHealthBar::~SHealthBar()
{
}
