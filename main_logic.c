#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "setDifficulty.c"
#include "input.c"
#include "generateField.c"
#include "drawField.c"
#include "fillField.c"
#include "setStep.c"
#include "checkWin.c"
#include "endGame.c"
#include "dealloc.c"
#define main_logic main

int updateField(char **GRID_FE, int length, int width)
{	printf("\n\n");
	for (int i = 0; i <= length; i++)									// Выводим сетку
	{	for (int j = 0; j <= width; j++)								// для игрока
		{	if (i == 0 && j == 0) {	printf("%2d", j); continue;	}
			else if (i == 0 && i > 9) {	printf("%2d", j); continue;	}
            else if (i == 0 && i < 10) {	printf("%3d", j); continue;	}
			if (j == 0)		printf("%2d", i);
			printf("%3c", GRID_FE[i - 1][j]);
		}
		printf("\n");
	}
}

int main_logic()
{	setlocale(0, "");
	srand(time(NULL));	int input, length, width, mineAmount, x = 9, y = 9;
	bool firstStep = true, dead = false, win = false;
	char inputAction;
	printf("Выберите сложность (1/2/3)\n>>>");
	scanf("%d", &input);
	setDifficulty(input, &length, &width, &mineAmount);
	printf("Размеры сетки: %d x %d\nКоличество мин: %d\n", length, width, mineAmount);
	if (input == 666) printf("\n\n\t\tУДАЧИ :D\n\n");
	// printf("Введите длину сетки (length): ");
	// scanf("%d", &length);
	// printf("Введите ширину сетки (width): ");
	// scanf("%d", &width);
	// printf("Введите количество мин (mineAmount): ");
	// scanf("%d", &mineAmount);
	char **GRID_BE; // Создаём фронтэндвую сетку
	char **GRID_FE; // Создаём бэктэндвую сетку
	generateField(length, width, mineAmount, &GRID_BE, &GRID_FE);
	drawField(length, width, GRID_FE);
	while(true)
	{	int errorCode = 0;
	input_coords(&x, &y, &inputAction);
	system("cls");
	errorCode = setStep(x, y, length, width, mineAmount, inputAction, GRID_BE, GRID_FE, &firstStep, &dead);
	win = checkWin(GRID_BE, GRID_FE, length, width, mineAmount);
	if (dead || win) break;
	if (errorCode == -1) printf("Ошибка ввода операции!\n");
	updateField(GRID_FE, length, width);
	}
	//printf("\n\nrWIN == %d", win);
	endGame(GRID_BE, GRID_FE, length, width, dead, win);
	if (win) printf("\n\n\t\t^----ПОБЕДА!!!----^\n\n");
	if (dead) printf("\n\n\t\t^----СМЕРТЪ----^\n\n");
	updateField(GRID_FE, length, width);
	dealloc(length, width, &GRID_BE, &GRID_FE);
	getchar(); getchar();
}