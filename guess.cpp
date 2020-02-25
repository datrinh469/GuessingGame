/*
 * Name:		Trinh, Dylan
 * Project:		1
 * Due:			February 26, 2020
 * Course:		CS-2560-01-Sp20
 *
 * Description:
 * 				This program is designed to generate a random number between 1-100 and prompt
 * 				the user to guess for it. The random number seed can be set to a specific seed
 * 				or have a random one with the time function. The user will be able to guess 8
 * 				times for the random number, with each incorrect time the program will hint at
 * 				whether or not the guess was too high or low. If the user enters an invalid guess,
 * 				the program will prompt the user to make another guess while not counting that guess.
 * 				If the user guess right, the program will notify the user with the number of guesses
 * 				that it took. If the user guesses eight times and is still wrong, the program will
 * 				automatically print the secret number out. If the user enters a 0 for the guess, the
 * 				program will print the secret number and end.
 *
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main (int ac, char *av[]){

	int secretNum, guess = -1, numOfGuesses = 0;
	string pluralGuess;
	bool win, quit;
	win = quit = false;

	/* creates and initialize random seed */
	unsigned seed = ac == 2 ? atoi(av[1]) : time(NULL);
	srand(seed);

	/* creates secret number between 1 - 100 */
	secretNum = rand() % 100 + 1;

	/* start of the game */
	cout << "Number Guessing Game by D. Trinh" << endl << endl;
	cout << "A secret number between 1-100 generated..." << endl << endl;

	/* where main game is played and makes sure conditions to continue are met */
	while (guess != secretNum && numOfGuesses < 8 && guess != 0){
		cout << "Please enter your guess? ";
		cin >> guess;

		/* checks if guess is valid */
		if (guess >= 1 && guess <= 100){

			numOfGuesses++;

			/* checks if guess is too low */
			if (guess < secretNum && numOfGuesses != 8){
				cout << "Guess is low..." << endl;
			} // end if

			/* checks if guess is too high */
			else if (guess > secretNum && numOfGuesses != 8){
				cout << "Guess is high..." << endl;
			} // end else if

			/* prints win message */
			else if (guess == secretNum){
				pluralGuess = numOfGuesses == 1 ? " guess." : " guesses.";
				win = true;
				cout << endl << "Correct in " << numOfGuesses << pluralGuess << endl;
			} // end else

		} // end if

		/* checks for sentinel value */
		else if (guess == 0){
			quit = true;
			cout << endl << "The secret number was " << secretNum << "." << endl;
		} // end else if

		/* notifies user of invalid input */
		else {
			cout << "Invalid guess." << endl;
		} // end else

	} // end while

	/* prints losing message if conditions are met */
	if (!win && !quit){
		cout << endl << "Too many guesses, the secret number was " << secretNum << "." << endl;
	} // end if

	return 0;
} // end main
