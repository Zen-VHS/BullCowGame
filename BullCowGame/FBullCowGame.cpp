#include "FBullCowGame.h"



FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;


	const FString HIDDEN_WORD = "end";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receves a VALID guess, incriments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;
	// setup a return variable 
	FBullCowCount BullCowCount;
	// loop though
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// if they match them
				if (MHWChar == GChar) { // increment bulls if they are in the same place
					BullCowCount.Bulls++; // increment bulls
				}
				else
				{ // increment cows if not
					BullCowCount.Cows++; 
				}
			}
		}
	}

	return BullCowCount;
}


