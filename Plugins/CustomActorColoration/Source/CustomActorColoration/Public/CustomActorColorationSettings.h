// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CustomActorColorationSettings.generated.h"


UCLASS(config = CustomActorColoration, defaultconfig)
class CUSTOMACTORCOLORATION_API UCustomActorColorationSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	
	UCustomActorColorationSettings(const FObjectInitializer& ObjectInitializer);
	static const UCustomActorColorationSettings* Get()
	{
		return GetDefault<UCustomActorColorationSettings>();
	}
	
	virtual FName GetCategoryName() const override
	{
		return TEXT("Plugins");
	}

#if WITH_EDITOR
	virtual FText GetSectionText() const override
	{
		return NSLOCTEXT("CustomActorColoration", "CustomActorColoration", "Custom Actor Coloration");
	}
	
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

private:
	void FillCollisionPresetColorMap();

public:

	UPROPERTY(EditDefaultsOnly, Config, Category="Rendering")
	bool bUseColorationCastShadow = true;
	UPROPERTY(EditDefaultsOnly, Config, Category="Rendering")
	bool bUseColorationCastCapsuleShadow = true;
	
	UPROPERTY(EditDefaultsOnly, Config, Category="Physics")
	bool bUseColorationPhysicalMaterial = true;
	UPROPERTY(EditDefaultsOnly, Config, Category="Physics")
	TMap<TSoftObjectPtr<UPhysicalMaterial>, FLinearColor> PhysicalMaterialColorMap;

	UPROPERTY(EditDefaultsOnly, Config, Category="Physics")
	bool bUseColorationCollisionPreset = true;
	UPROPERTY(EditDefaultsOnly, Config, Category="Physics")
	TMap<FName, FLinearColor> CollisionPresetColorMap;
};
