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
 
// ������� ����� �� ���� ����
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

// ������, �����������, �����...
void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "����� ���������� � ���� ���� � ������";
	std::cout << std::endl << std::endl;
	std::cout << "����� ���� ����� ������� ����� � ������� " << WORD_LENGTH << " ����, ��� ������� ��� ��� �� �����?";
	std::cout << std::endl << std::endl;
	std::cout << "�������:\n���� �� ������ ����� � �� �����, ���� ������� - \"���\", ���� ������ ������� ���������� ����� ������ \"������\".\n� ���� 5 �������.";
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
		std::cout << "��� ������� - " << Guess << std::endl;
		std::cout << "____________________________________________" << std::endl;
		std::cout << std::endl;

		// TODO summarise game
	}
	return;
}


// ��������� �������� �� ������
FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "���� " << CurrentTry <<  " �������: ";

	FText Guess = "";
	std::getline(std::cin, Guess);

	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "������ ������� ����� y/n ?";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y')  || (Response[0] == 'Y');
}
