/******************
** Joel LaFleur  **
**   Blackjack   **
** 15 March 2017 **
******************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//functions
int give_me_a_card(int cards[11]);
bool existsInArray(int var, int arr[], int size);

int main()
{
	//declare variables
	int dealerNumCards, dealerTotal, playerNumCards, playerTotal;
	int play;
	char userResponse;
	int playerCards[11];
	int dealerCards[11];
	int cardsDealt[11];

	//loop until user quits
	while (1)
	{
		printf("Play blackjack? (y/n)\n");
		scanf("%c%*c", &userResponse);
		if (userResponse == 'n')
		{
			break;
		}
		else
		{

			//initialize or reset variables
			dealerNumCards = 0;
			dealerTotal = 0;
			playerNumCards = 0;
			playerTotal = 0;
			userResponse = 'y';
			play = 1;

			for (int i = 0; i < 11; i++)
			{
				if (i < 10)
				{
					cardsDealt[i] = 0;
				}
				playerCards[i] = 0;
				dealerCards[i] = 0;
			}

			//deal the cards
			dealerCards[dealerNumCards++] = give_me_a_card(cardsDealt);
			dealerCards[dealerNumCards++] = give_me_a_card(cardsDealt);
			dealerTotal = dealerCards[0] + dealerCards[1];

			// check to see if the player is over 21. If they have an ace 
			// change the value of that card to 1 and reduce their total
			if (dealerTotal > 21)
			{
				if (existsInArray(11, dealerCards, dealerNumCards))
				{
					for (int i = 0; i < dealerNumCards; i++)
					{
						if (dealerCards[i] == 11 && dealerTotal > 21)
						{
							playerCards[i] = 1;
							dealerTotal -= 10;
						}
					}
				}
			}

			playerCards[playerNumCards++] = give_me_a_card(cardsDealt);
			playerCards[playerNumCards++] = give_me_a_card(cardsDealt);
			playerTotal = playerCards[0] + playerCards[1];

			// check to see if the player total is over 21. If they have an ace 
			// change the value of that card to 1 and reduce their total
			if (playerTotal > 21)
			{
				if (existsInArray(11, playerCards, playerNumCards))
				{
					for (int i = 0; i < playerNumCards; i++)
					{
						if (playerCards[i] == 11 && playerTotal > 21)
						{
							playerCards[i] = 1;
							playerTotal -= 10;
						}
					}
				}
			}

			//start the game
			if (dealerTotal == 21 && playerTotal < 21)
			{
				printf("You have: %d and %d.\n", playerCards[0], playerCards[1]);
				printf("Dealer has: %d and dealer's hole card is %d and has Blackjack... You lose!\n", dealerCards[1], dealerCards[0]);
				continue;
			}
			else if (dealerTotal == 21 && playerTotal == 21)
			{
				printf("You have: %d and %d.\n", playerCards[0], playerCards[1]);
				printf("Dealer has: %d and dealer's hole card is %d, so you both have 21. It's a push!\n", dealerCards[1], dealerCards[0]);
				continue;
			}
			else if (playerTotal == 21 && dealerTotal < 21)
			{
				printf("You have: %d and %d.\n", playerCards[0], playerCards[1]);
				printf("Dealer has: %d and dealer's hole card is %d, but you have Blackjack! You win!\n", dealerCards[1], dealerCards[0]);
				continue;
			}
			else
			{
				printf("You have: %d and %d.\n", playerCards[0], playerCards[1]);
				printf("Dealer has: %d and a hole card.\n", dealerCards[1]);

				//allow the player to hit until 21 or bust
				while (1)
				{
					if (playerTotal == 21)
					{
						printf("Your total is 21.\n");
						break;
					}
					else if (playerTotal > 21)
					{
						printf("Your total is over 21: BUST!\n");
						play = 0;
						break;
					}
					else if (userResponse != 'y')
					{
						printf("Your total is: %d.\n", playerTotal);
						break;
					}
					else
					{
						printf("Hit? (y/n)\n");
						scanf("%c%*c", &userResponse);
						if (userResponse == 'y')
						{
							playerCards[++playerNumCards] = give_me_a_card(cardsDealt);
							playerTotal += playerCards[playerNumCards];

							// check to see if the player total is over 21. If they have an ace 
							// change the value of that card to 1 and reduce their total
							if (playerTotal + playerCards[playerNumCards] > 21)
							{
								if (existsInArray(11, playerCards, playerNumCards))
								{
									for (int i = 0; i < playerNumCards; i++)
									{
										if (playerCards[i] == 11 && playerTotal > 21)
										{
											playerCards[i] = 1;
											playerTotal -= 10;
										}
									}
								}
							}
							printf("You were dealt a %d.\n", playerCards[playerNumCards]);
						}
						
					} // end win check if
				} // end player draw card loop

				//hit for the dealer until 16 or bust
				while (play)
				{
					if (dealerTotal == 21 && playerTotal < 21)
					{
						printf("Dealer has: %d and dealer's hole card is %d and total is 21: You lose!\n", dealerCards[1], dealerCards[0]);
						break;
					}
					else if (dealerTotal > 21)
					{
						printf("Dealer has: %d and dealer's hole card is %d and total is %d which is over 21: You win!\n", dealerCards[1], dealerCards[0], dealerTotal);
						break;
					}
					else if (dealerTotal > 17 && dealerTotal < playerTotal)
					{
						printf("Dealer has: %d and dealer's hole card is %d and total is %d... You win!\n", dealerCards[1], dealerCards[0], dealerTotal);
						break;
					}
					else
					{
						dealerCards[++dealerNumCards] = give_me_a_card(cardsDealt);
						dealerTotal += dealerCards[dealerNumCards];

						// check to see if the player is over 21. If they have an ace 
						// change the value of that card to 1 and reduce their total
						if (dealerTotal + dealerCards[dealerNumCards] > 21)
						{
							if (existsInArray(11, dealerCards, dealerNumCards))
							{
								for (int i = 0; i < dealerNumCards; i++)
								{
									if (dealerCards[i] == 11 && dealerTotal > 16)
									{
										playerCards[i] = 1;
										dealerTotal -= 10;
									}
								}
							}
						}
						printf("Dealer was dealt a %d.\n", dealerCards[dealerNumCards]);
					}
				} // end dealer card draw loop
			} //end dealer instant win conditional
		}
	}
}

//takes the reference for the cards played and numbers of cards for the dealer or player receiving cards
int give_me_a_card(int cards[11])
{
	int card = 1;
	static int randomized = 0;
	
	if (!randomized)
	{
		srand((unsigned)time(NULL));
	}

	// pick a random number and see if it would still be in the deck
	// if not then draw a new random number and try again
	while (1)
	{
		card = (rand() % 12) + 1;


		// 11 (jack), 12 (queen), and 13 (king) are all value 10 in blackjack
		if (card > 10)
		{
			card = 10;
		}

		// set 1 (ace) equal to 11. Will change back to 1 if value is over 21 later
		if (card == 1)
		{
			card = 11;
		}

		//check to make sure there aren't more cards played than can exist in the deck
		if ((card < 10 || card == 11) && cards[card - 1] > 3)
		{
			continue;
		}
		else if (card == 10 && cards[card - 1] > 12)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	// increment the cards played array and total number of cards for the dealer or player
	cards[card - 1]++;

	return card;
}

bool existsInArray(int var, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == var)
		{
			return true;
		}
	}

	return false;
}