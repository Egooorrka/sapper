int drawField(int length, int width, char **GRID_FE);

int drawField(int length, int width, char **GRID_FE)
{   for (int i = 0; i <= length; i++)									// Выводим сетку
	{	for (int j = 0; j <= width; j++)								// для игрока
		{	if (i == 0 && j == 0) {	printf("%2d", j); continue;	}
			else if (i == 0 && i > 9) {	printf("%2d", j); continue;	}
            else if (i == 0 && i < 10) {	printf("%3d", j); continue;	}
			if (j == 0)		printf("%2d", i);
			printf("%3c", GRID_FE[i - 1][j]);
		}
		printf("\n");
	}

    return 0;
}