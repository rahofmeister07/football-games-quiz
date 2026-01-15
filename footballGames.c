/*
 * team_games.c
 * C Programming Quiz – Game outcome program
 * Prompts user for a team and game number, then outputs Win/Loss
 * Extra credit: prints table of all teams’ win/loss records
 */

#include <stdio.h>

/* Program Inputs */
int team_number;
int game_number;

/* Initialize Program Array */
int game_outcomes[4][4] =  {{1, 0, 0, 0},
							{0, 1, 0, 0},
							{0, 0, 1, 1},
							{1, 1, 0, 1}};

/* Program Outputs */
int game_outcome;

/* Function Prototypes */
void print_records(void);

int main(void)
{
	/* Prompt user for team */
	printf("0. Lions\n");
	printf("1. Vikings\n");
	printf("2. Bears\n");
	printf("3. Packers\n");
	printf("\nEnter the team number from the menu above: ");
	scanf("%d", &team_number);

	/* Prompt user for game number */
	printf("\n0. Game 0\n");
	printf("1. Game 1\n");
	printf("2. Game 2\n");
	printf("3. Game 3\n");
	printf("\nEnter the game number from the menu above: ");
	scanf("%d", &game_number);

	/* Get win or loss from array */
	game_outcome = game_outcomes[team_number][game_number];

	/* Print game result */
	printf("\nResult = ");
	if (game_outcome == 0)
	{
		printf("Loss\n\n");
	}
	else
	{
		printf("Win\n\n");
	}

	/* Print the wins and losses for each team */
	print_records();
	printf("\n\n");

	return(0);
}

/* Extra credit - print table of team records */
void print_records(void)
{
	int wins = 0;
	int losses = 0;

	/* Print table header */
	printf("	    W	    L");
	printf("\n	   ****    ****");

	for (int i = 0; i <= 3; i++)
	{
		/* Print team name */
		switch(i)
		{
			case 0:
				printf("\nLions");
				break;

			case 1:
				printf("\nVikings");
				break;
			
			case 2:
				printf("\nBears");
				break;

			case 3:
				printf("\nPackers");
				break;

			default:
				printf("Error");
				break;
		}
		
		/* Compute wins and losses */
		for (int j = 0; j <= 3; j++)
		{
			if(game_outcomes[i][j] == 0)
			{
				losses++;
			}
			else
			{
				wins++;
			}
		}

		/* Print wins and losses */
		printf("	    %d	    %d", wins, losses);

		/* Reset wins and losses for next team */
		wins = 0;
		losses = 0;
	}
}
