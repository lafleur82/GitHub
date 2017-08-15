///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// DEMONSTRATION LAB I.3.A-2 ///////////////////////////////
/////////////////////////////////////// Variable Scope ////////////////////////////////////
///////////////////////////////// "I'm thinking of a number..." ///////////////////////////
////////////////////////////////////// Instructor Solution ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// The objective of this lab is to take user input (a "magic number") and to write a
//     function that will "randomize" numbers until it "guesses" the "magic number".
//     The function should not choose "randomized" numbers as "guesses" if those "guesses"
//     have already been used.  A macro named MAX_GUESS is used to establish the range
//     of "magic numbers" (1 to MAX_GUESS).  Main() and the function will not directly
//     communicate the "guesses".  Instead, they'll use the global uint8_t array to 
//     determine if the function has guessed the "magic number".  The function will update
//     the global array with "guesses" and main() will watch the global array to determine
//     if the "magic number" has been guessed.
//
// main() should:
//     1. Take input
//     2. Verify that input falls between 1 and MAX_GUESS (inclusive)
//     3. Watch the global array to see if the "magic number" has been guessed
//     4. Loop the function until the "magic number" has been guessed in the array
//     5. Print the total number of randomizations the function performed once the "magic
//         number is guessed
//
// guess_a_number() should:
//     1. Randomize a number between 1 and MAX_SIZE
//     2. Increment the variable storing the total number of randomizations
//     3. Check the global array to see if that number has already been "guessed"
//         3.a. If it's been guessed already, go back to Step #1
//         3.b. If it hasn't been guessed, modify the global array to indicate
//             it's been guessed.
//     4. Return the number of times the function has "randomized" a number
//         NOTE:  "Randomizing" a number is different than "guessing" a number because
//             some "randomized" numbers have already been "guessed"
///////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <stdint.h>
/* The following MACRO determines the available range of "magic numbers" and, subsequently, the "guesses" */
#define MAX_GUESS 100 // Available numbers range from 1 to MAX_GUESS

uint8_t previous_guesses[MAX_GUESS + 1] = { 0 };

uint8_t guess_a_number(void); // Function prototype

int main(void)
{
	uint8_t magicNumber = 0; // User input.  Represents the number to be guessed.
	uint8_t computerRandomizations = 0; // Local variable to store return value from guess_a_number()

	/* PICK A NUMBER */
	do
	{
		printf("Pick a number between 1 and %d.\n", MAX_GUESS);
		_flushall();
		scanf("%d", &magicNumber);
		if (magicNumber > MAX_GUESS || magicNumber < 1)
		{
			printf("That number was not between 1 and %d.\nTry again.\n", MAX_GUESS);
		}
	} 
	while (magicNumber > MAX_GUESS || magicNumber < 1); // Continues looping until user complies with appropriate input

//	printf("You chose %d\n", magicNumber); // DEBUGGING

	/* GUESS A NUMBER */
	/* main() will continue to loop guess_a_number() until guess_a_number() updates the "magic number" in previous_guesses[] */
	while (!previous_guesses[magicNumber]) // While the "magic number" is set to 0 in previous_guesses[]...
	{
		computerRandomizations = guess_a_number(); // Run guess_a_number() and store the return value
	}
	/* While loop ends when guess_a_number() updates the previous_guesses[] element corresponding to the "magic number" */
	printf("The computer randomized %d numbers to guess your number.\n", computerRandomizations);

	return 0;
}

/*
* FUNCTION:   uint8_t guess_a_number(void)
*
* ARGUMENTS:  This function takes no parameters although it *should* update the previous_guesses global array
*
* RETURNS:	  Total number of "randomizations" 
*             NOTE:  One "randomization" is one function call to rand() while one "guess" is one update to
*                 previous_guesses[]
*
* NOTES:      This function randomizes numbers from 1 to MAX_SIZE.
*             Each randomized number is checked against the previous_guesses global array.
*             If the value had already been guessed, the function will randomize another number
*             If the value had not already been guessed, this function will update the global array
*/
uint8_t guess_a_number(void)
{
	static uint64_t randomizations = 0;
	uint8_t randomNumber = 0;
//	Sleep(1000);
//	sleep();
	/* This */
	if (!randomizations)
	{
		srand((unsigned)time(NULL));
	}

	do
	{
		randomNumber = (rand() % MAX_GUESS) + 1; // Original statement
//		randomNumber = rand(); // DEBUGGING
//		randomNumber = (randomNumber % MAX_GUESS) + 1; // DEBUGGING
		printf("The function randomized: %d \n", randomNumber); // DEBUGGING
		randomizations++;
	}
	while (previous_guesses[randomNumber]);
	previous_guesses[randomNumber] = 1;
	

	return randomizations;
}
