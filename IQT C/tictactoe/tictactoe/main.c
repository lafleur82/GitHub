#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//function prototypes
int get_move(int moves, int move, char player, char board[3][3]);
int check_move(int move, char board[3][3]);
int check_win(int moves, char player, char board[3][3]);
void reset_board(char board[3][3]);
void display_board(char board[3][3]);


int main()
{
	/* Board:
	[00][01][02]
	[10][11][12]
	[20][21][22] */
	char board[3][3] = { 0 };
	char player;
	int moves;
	int move;
	char play = 0;

	//start the program

	do
	{
		_flushall();
		printf("Would you like to play Tic Tac Toe? (y/n)\n");
		scanf("%c%*c", &play);

		if (play != 'n')
		{
			//initialize the variables
			reset_board(board);
			moves = 0;
			player = 'X';
			move = 0;

			while (check_win(moves, player, board) == 0)
			{
				display_board(board);

				printf("%c: Enter 1 - 9 to select your move.\n", player);
				scanf("%d%*c", &move);

				if (check_move(move, board))
				{
					moves = get_move(moves, move, player, board);

					if (check_win(moves, player, board) == 1)
					{
						printf("%c wins!\n", player);
					}
					else if (check_win(moves, player, board) == 2)
					{
						printf("It was a tie!\n");
					}
					else
					{
						//swap player turn if no winner
						if (player == 'X')
						{
							player = 'O';
						}
						else
						{
							player = 'X';
						}
					}
				}
				else if(!check_move(move, board))
				{
					printf("That position is already taken...\n");
				}
				else
				{
					printf("Unknown error.\n");
				}
			}
		}
		else
		{
			break;
		}
	} while (1);

	getchar();
	return 0;
}


int get_move(int moves, int move, char player, char board[3][3])
{
	/* The board:
	  [00][01][02]
	  [10][11][12]
	  [20][21][22] */

	switch (move)
	{
	case 1:
		board[0][0] = player;
		break;
	case 2:
		board[0][1] = player;
		break;
	case 3:
		board[0][2] = player;
		break;
	case 4:
		board[1][0] = player;
		break;
	case 5:
		board[1][1] = player;
		break;
	case 6:
		board[1][2] = player;
		break;
	case 7:
		board[2][0] = player;
		break;
	case 8:
		board[2][1] = player;
		break;
	case 9:
		board[2][2] = player;
		break;
	}

	return ++moves;
}


int check_move(int move, char board[3][3])
{
	switch (move)
	{
	case 1:
		if (board[0][0] == 49)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 2:
		if (board[0][1] == 50)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 3:
		if (board[0][2] == 51)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 4:
		if (board[1][0] == 52)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 5:
		if (board[1][1] == 53)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 6:
		if (board[1][2] == 54)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 7:
		if (board[2][0] == 55)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 8:
		if (board[2][1] == 56)
		{
			return 1;
			break;
		}
		else
			return 0;
	case 9:
		if (board[2][2] == 57)
		{
			return 1;
			break;
		}
		else
			return 0;
	default:
		return -1; //Move input wasn't 0 - 9. Return an error.
	}
}

int check_win(int moves, char player, char board[3][3])
{
	/* The board:
	[00][01][02]
	[10][11][12]
	[20][21][22] */

	//check win conditions
	if (//across
		board[0][0] + board[0][1] + board[0][2] == player * 3 ||
		board[1][0] + board[1][1] + board[1][2] == player * 3 ||
		board[2][0] + board[2][1] + board[2][2] == player * 3 ||
		//down
		board[0][0] + board[1][0] + board[2][0] == player * 3 ||
		board[0][1] + board[1][1] + board[2][1] == player * 3 ||
		board[0][2] + board[1][2] + board[2][2] == player * 3 ||
		//diagonal
		board[0][0] + board[1][1] + board[2][2] == player * 3 ||
		board[0][2] + board[1][1] + board[2][0] == player * 3)
	{
		return 1; //win
	}
	else if (moves == 9)
	{
		return 2; //tie
	}
	else
	{
		return 0; //no winner yet
	}
}


void display_board(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i == 1 && j == 0) || (i == 2 && j == 0))
			{
				printf("\n");
			}

			if (j == 0)
			{
				printf("|");
			}

			printf(" %c |", board[i][j]);
		}
	}
	printf("\n\n");
}


void reset_board(char board[3][3])
{
	int p = 49; //position on the board

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = p;
			p++;
		}
	}
}
