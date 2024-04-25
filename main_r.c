#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "workWithUser.c"
#include <locale.h>
#include "setDifficulty.c"
#include "generateField.c"
#include "fillField.c"
#include "setStep.c"
#include "checkWin.c"
#include "endGame.c"
#include "dealloc.c"



int main()
{
	setlocale(0, "");
	srand(time(NULL));	
	int length, width, mineAmount, x = 9, y = 9;
	bool firstStep = true, dead = false, win = false;
	char ** GRID_BE; // ?????? ???
	char ** GRID_FE; // ?????? ???
	char type;
	int userChoice, difInput;
	showMenu(&userChoice, &difInput);
	setDifficulty(difInput, &length, &width, &mineAmount);
	switch (userChoice){
	case 1: {
		generateField(length, width, mineAmount, &GRID_BE, &GRID_FE);
		drawField(length, width, GRID_FE);
		while(true)
		{	int errorCode = 0;
		showTips();
		userInput(&x, &y, &type);
		system("cls");
		errorCode = setStep(x, y, length, width, mineAmount, type, GRID_BE, GRID_FE, &firstStep, &dead);
		win = checkWin(GRID_BE, GRID_FE, length, width, mineAmount);
		if (dead || win) break;
		if (errorCode == -1) printf("\n??? ??? ????!");
		if (errorCode == -2) printf("\n???? ??????? ?????!");
		updateField(GRID_FE, length, width);
		}
		endGame(GRID_BE, GRID_FE, length, width, dead, win);
		if (win) showWinMessage();
		if (dead) showLoseMessage();
		updateField(GRID_FE, length, width);
		dealloc(length, width, &GRID_BE, &GRID_FE);
		getchar(); getchar();

	}; break;

	case 2: //settings();
	break;

	case 3: exit(0);
	break;

	default: exit(1);
	break;
	}
	return 0;
}
