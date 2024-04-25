int kOutOfBounds(int i, int k, int length)
{	if ( (i == 0 && k < i) || (i == length - 1 && k > i) )
		return 1;
	return 0;
}
int lOutOfBounds(int j, int l, int width)
{	if ( (j == 0 && l < j) || (j == width - 1 && l > j) )
		return 1;
	return 0;
}

int fillField(int length, int width, int mineAmount, int x, int y, char **GRID_BE, bool secret);

int fillField(int length, int width, int mineAmount, int x, int y, char **GRID_BE, bool secret)
{	
	for (int i = 0; i < length; i++)				// Заполняем сетку
	{	for (int j = 0; j < width; j++)				// с минами
			GRID_BE[i][j] = '0';					// пустыми клетками
	}

	// Тестовый входной контроль )))
	if (mineAmount > length * width) {	printf("\nС таким количеством мин ты отправишься в бесконечный цикл, дружище.\n"); exit(1);	}
	//printf("Случайно сгенерированные координаты для каждой мины:\n"); 	// Посмотреть координаты для мин (для тестов)
	for(int i = 0; i < mineAmount; i++)							
	{	int ri = rand() % length; int rj = rand() % width;		
		/*printf("i = %d ri = %d, rj = %d\n", i, ri, rj);*/
		if (GRID_BE[ri][rj] == '*' || (ri == x && rj == y)) 	// Заполняем сетку
		{	i--;												// с минами
			continue;											// этими самыми минами
		}
		GRID_BE[ri][rj] = '*';
	}


	for (int i = 0; i < length; i++)						// Заполняем каждую
        for (int j = 0; j < width; j++)						// пустую клетку
        {   if (GRID_BE[i][j] != '*')						// количеством мин
            {   int localCount = 0;							// находящимся рядом
                for (int k = i - 1; k <= i + 1; k++)		// с этой клеткой
                    for (int l = j - 1; l <= j + 1; l++)
                    {   if (kOutOfBounds(i, k, length)) continue;
						if (lOutOfBounds(j, l, width)) continue;
						if (GRID_BE[k][l] == '*') localCount++;
                    }
                GRID_BE[i][j] = (char) localCount + '0';	// весь этот алгоритм просто какой-то сумашедший вышел
            }												// я вообще хз, как я до него додумался O_O

        }

	if (secret) GRID_BE[x][y] = '9';

	printf("\n\n");

}