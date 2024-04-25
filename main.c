#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "workWithUser.c"
#include "setDifficulty.c"
#include "generateField.c"
#include "fillField.c"
#include "checkFirstStep.c"
#include "setStep.c"
#include "checkWin.c"
#include "endGame.c"
#include "dealloc.c"



int main(void)
{
	setlocale(0, "");
	srand(time(NULL));
	system("cls");	
	int length, width, mineAmount, x = 9, y = 9, errorCode = 0;
	bool firstStep = true, youAreAlreadyDead = false, dead = false, win = false;
	char ** GRID_BE = NULL; // Áýêýíäîâàÿ ñåòêà
	char ** GRID_FE = NULL; // Ôðîíòýíäàâàÿ ñåòêà
	char type;
	int userChoice, difInput;
	errorCode = showMenu(&userChoice, &difInput);
	//checkErrors(errorCode);
	setDifficulty(difInput, &length, &width, &mineAmount);
	switch (userChoice){
	case 1: {
		errorCode = generateField(length, width, mineAmount, &GRID_BE, &GRID_FE);
		//checkErrors(errorCode);
		drawField(length, width, GRID_FE);

//__________________________________________________________________________________________________________//



//__________________________________________________________________________________________________________//
		
		while(true)
		{	errorCode = 0;
		showTips();
		errorCode = userInput(&x, &y, &type);
		//checkErrors(errorCode);

		if ( checkFirstStep(length, width, &mineAmount, &firstStep, &youAreAlreadyDead) )
		{	if (x > length - 1 || x < 0 || y > width - 1 || y < 0)
        	{	//checkErrors(2);
				printf("\nÒÛ ×ÅÃÎ ÂÂÎÄÈØÜ ÁËßßß!!!");
				system("PAUSE");
				exit(1);
			}
			else
			{	fillField(length, width, mineAmount, x - 1, y - 1, GRID_BE, youAreAlreadyDead);
				GRID_FE[x-1][y-1] = GRID_BE[x-1][y-1];
			}
		}

		system("cls");

		errorCode = setStep(x, y, length, width, mineAmount, type, GRID_BE, GRID_FE, &firstStep, &dead);
		win = checkWin(GRID_BE, GRID_FE, length, width, mineAmount);
		showStats(GRID_FE, length, width, mineAmount);
		//checkErrors(errorCode);
		if (dead || win) break;
		updateField(GRID_FE, length, width);
		}

//__________________________________________________________________________________________________________//

		endGame(GRID_BE, GRID_FE, length, width, dead, win);
		if (win) showWinMessage();
		if (dead) showLoseMessage();
		updateField(GRID_FE, length, width);
		dealloc(length, width, &GRID_BE, &GRID_FE);
		getchar(); getchar();

	}; break;

	case 2: exit(0);
	break;

	default: exit(1);
	break;
	}
	return 0;
}
