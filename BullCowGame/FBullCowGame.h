#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// two integers, intialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;


	void Reset(); // TODO make a moere rich value.
	bool CheckGuessValidity(FString); // TODO make a more rich value
	FBullCowCount SubmitGuess(FString);
	
	//Please try and ignire this and focus on the interface above ^^
private:
	// see constructor for initialisatyion
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};