// Keywords2.cpp

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

int main()
{
	// Display Title of program to user
	std::cout << "Code Breaker\n";

	// Ask the recruit to login using thier name
	std::cout << "Enter your username: ";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	std::string name;
	std::cin >> name;

	// Display an overview of what Keywords II is to the recruit
	std::cout << "\nYou must guess a total of three words, you will have 8 tries to guess each word\n";
	std::cout << "At the end of each round you will be asked if you wish to continue.\n";

	// Display an directions to the recruit on how to use Keywords
	std::cout << "You will enter one letter that you guess may be in the word and you will be told if\n";
	std::cout << "it is wrong or correct. You will also be informed of the letters you have entered.\n";


	// Create a collection of 10 words you had wrote down manually
	std::vector<std::string> words;
	words.push_back("agent");
	words.push_back("bagman");
	words.push_back("cipher");
	words.push_back("code");
	words.push_back("compromised");
	words.push_back("cryptology");
	words.push_back("deaddrop");
	words.push_back("doubleagent");
	words.push_back("mole");
	words.push_back("pattern");

	// Create an int var to count the number of simulations being run starting at 1
	int sims = 1;

	// Create an int var equal to the max amount of guesses
	const int MAX_GUESSES = 8;

	// Create an int var to count the number of guesses that were made
	int guesses = 0;

    // Seed the random number generator
	std::srand(static_cast<unsigned int>(time(0)));

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	std::string wordOne = words[rand() % words.size()];
	std::string wordTwo = words[rand() % words.size()];
	std::string wordThree = words[rand() % words.size()];

	// Create a list of the random words for easier access
	std::vector<std::string> randomWords;
	randomWords.push_back(wordOne);
	randomWords.push_back(wordTwo);
	randomWords.push_back(wordThree);
	
	// Create a list of guessed letters
	std::string lettersGuessed = "";

	// Create a string var of guessed letters
	std::string guessedSoFar(randomWords[sims - 1].size(), '-');

	// Display the simulation # is staring to the recruit. 
	std::cout << "Simulation #" << sims << " starting... Welcome " << name << std::endl;

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while (guesses != MAX_GUESSES)
	{
		//     Tell recruit how many incorrect guesses he or she has left
		std::cout << "You have " << (MAX_GUESSES - guesses) << " guesses left!\n";

		//     Show recruit the letters he or she has guessed
		if (lettersGuessed.empty())
		{
			std::cout << "No letters guessed.\n";
		}
		else
		{
			std::cout << lettersGuessed << std::endl;
		}

		//     Show player how much of the secret word he or she has guessed
		std::cout << "Guessed so far: " << guessedSoFar << std::endl;

		//     Get recruit's next guess
		char guess;

		std::cout << "Enter your guess " << name << ": ";
		std::cin >> guess;

		//     While recruit has entered a letter that he or she has already guessed
		while (lettersGuessed.find(guess) != std::string::npos)
		{
			std::cout << "\nYou've already guessed " << guess << std::endl;
			//          Get recruit ’s guess
			std::cout << "Enter your guess " << name << ": ";
			std::cin >> guess;
		}

		//     Add the new guess to the group of used letters
		lettersGuessed += guess;

		//     If the guess is in the secret word
		if (randomWords[sims - 1].find(guess) != std::string::npos)
		{
			// Tell the recruit the guess is correct
			std::cout << "The letter " << guess << " is correct!\n";
			
			// Update the word guessed so far with the new letter
			for (int index = 0; index < randomWords[sims - 1].length(); index++)
			{
				if (randomWords[sims - 1][index] == guess)
				{
					guessedSoFar[index] = guess;
				}
			}
		}
		//     Otherwise
		else
		{
			// Tell the recruit the guess is incorrect
			std::cout << "Sorry, " << guess << " isn't in the word.\n";
			// Increment the number of incorrect guesses the recruit has made
			guesses++;
		}

		// If the recruit has made too many incorrect guesses
		if (guesses == MAX_GUESSES) 
		{
			// Tell the recruit that he or she has failed the Keywords II course.
			std::cout << "You have failed the Keywords II course.\n";
		}
		// Otherwise
		else if (guessedSoFar == randomWords[sims - 1])
		{
			// Congratulate the recruit on guessing the secret words
			std::cout << "You guessed it! Congratulations " << name << "!\n";

			// Ask the recruit if they would like to run the simulation again
			std::cout << "Would you like to run the simulation again " << name << " (y/n)? ";

			std::string answer;
			std::cin >> answer;

			// If the recruit wants to run the simulation again
			if (answer == "y")
			{
				//     Increment the number of simiulations ran counter
				sims++;

				guessedSoFar = std::string(randomWords[sims - 1].size(), '-');

				lettersGuessed = "";

				// Display the simulation # is staring to the recruit. 
				std::cout << "Simulation #" << sims << " starting... Welcome " << name << std::endl;

				//     Move program execution back up to // Display the simulation # is staring to the recruit. 
				continue;
			}
			// Otherwise
			else
			{
				//     Display End of Simulations to the recruit
				std::cout << "Keywords II simulation has ended.";

				//     Pause the Simulation with press any key to continue
				system("pause");
			}
		}
	}
}
