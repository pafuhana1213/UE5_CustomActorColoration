// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomActorColorationSettings.h"

void UCustomActorColorationSettings::FillCollisionPresetColorMap()
{
	TArray<TSharedPtr<FName>> ProfileNames;
	UCollisionProfile::Get()->GetProfileNames(ProfileNames);

	// remove
	TArray<FName> RemoveItems;
	for (auto& CollisionPresetColorItem : CollisionPresetColorMap)
	{
		const bool bIsFound = ProfileNames.ContainsByPredicate([&](const TSharedPtr<FName>& ProfileName)
		{
			return *ProfileName == CollisionPresetColorItem.Key;
		});
		if(!bIsFound)
		{
			RemoveItems.Add(CollisionPresetColorItem.Key);
		}
	}
	for (auto& RemoveItem : RemoveItems)
	{
		CollisionPresetColorMap.Remove(RemoveItem);
	}
	
	// add
	for (TSharedPtr<FName> ProfileName : ProfileNames)
	{
		if(!CollisionPresetColorMap.Contains(*ProfileName))
		{
			CollisionPresetColorMap.Add(*ProfileName, FLinearColor::White);
		}
	}
}

UCustomActorColorationSettings::UCustomActorColorationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FillCollisionPresetColorMap();
}

#if WITH_EDITOR
void UCustomActorColorationSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FillCollisionPresetColorMap();
}
#endif