/*
This is the console executable, that makes use of the BullCow class
This acts as the viev in a MVC pattern, and is responsible for all user interaction. 
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game
 
// Входная точка ко всей игре
int main()  
{
	std::cout << BCGame.GetCurrentTry();

	setlocale(LC_ALL, "Russian");
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} 	while (bPlayAgain);

	return 0;
}

// Начало, приветствие, старт...
void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Добро пожаловать в игру БЫКИ И БЫЧИЦЫ";
	std::cout << std::endl << std::endl;
	std::cout << "Здесь тебе нужно угадать слово в котором " << WORD_LENGTH << " букв, как думаешь что это за слово?";
	std::cout << std::endl << std::endl;
	std::cout << "Правила:\nЕсли ты угадал букву и ее место, тебе напишет - \"БЫК\", если просто угадешь правильную букву выдаст \"БЫЧИЦА\".\nУ тебя 5 попыток.";
	std::cout << std::endl << std::endl;
	return;
}

void PlayGame() 
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guess
	// TODO change forim FOR to WHILE loop once we are validating tries
	for (int32 Count = 0; Count < MaxTries; Count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bills and cows
		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << ", Cows =  " << BullCowCount.Cows << std::endl;
		std::cout << "Ваш вариант - " << Guess << std::endl;
		std::cout << "____________________________________________" << std::endl;
		std::cout << std::endl;

		// TODO summarise game
	}
	return;
}


// Получение варианта от игрока
FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Твой " << CurrentTry <<  " вариант: ";

	FText Guess = "";
	std::getline(std::cin, Guess);

	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Хотите сыграть снова y/n ?";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y')  || (Response[0] == 'Y');
}
