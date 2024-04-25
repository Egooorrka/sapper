int endGame(char **GRID_BE, char **GRID_FE, int length, int width, bool dead, bool win);

int endGame(char **GRID_BE, char **GRID_FE, int length, int width, bool dead, bool win)
{   if (dead)
    {   for (int i = 0; i < length; i++)
            for (int j = 0; j < width; j++)
                GRID_FE[i][j] = GRID_BE[i][j];
    }

    if (win)
	{	for (int i = 0; i < length; i++)
			for (int j = 0; j < width; j++)
			{	if (GRID_FE[i][j] == 'F') continue;
				else GRID_FE[i][j] = GRID_BE[i][j];			
			}
	}

	return 0;
}