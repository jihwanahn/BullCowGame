// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	void ProcessGuess(const FString& Guess);
	static bool IsIsogram(FString Word);
	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	FBullCowCount GetBullCows(const FString& Guess) const;
	
	void EndGame();

	// Your declarations go below!
	private:
		UPROPERTY()
			FString HiddenWord;
		UPROPERTY()
			int32 Lives;
		UPROPERTY()
			bool bGameOver;
		UPROPERTY()
			TArray<FString> Words;
		UPROPERTY()
			TArray<FString> Isograms;
};
