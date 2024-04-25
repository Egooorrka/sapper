int generateField(int length, int width, int mineAmount, char ***GRID_BE, char ***GRID_FE);

int generateField(int length, int width, int mineAmount, char ***GRID_BE, char ***GRID_FE)
{	//printf("TEST");
	*GRID_BE = calloc(length, sizeof(char *)); 		// Выедляем память 
	if (*GRID_BE == NULL) return 3;				// под нашу сетку
	for(int i = 0; i < length; i++)					// с минами
	{	(*GRID_BE)[i] = calloc(width, sizeof(char));
		if ( (*GRID_BE)[i] == NULL ) return 3;
	}


	//printf("-------------------------------\n");
	*GRID_FE = calloc(length, sizeof(char *));
	if (*GRID_BE == NULL) return 3;						// Выделяем память
	for(int i = 0; i < length; i++)							// под сетку
	{	(*GRID_FE)[i] = calloc(width, sizeof(char));		// которую будет видеть
		if ( (*GRID_FE)[i] == NULL ) return 3;				// игрок		
	}

	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)	(*GRID_FE)[i][j] = 'X';	
	
	return 0;
}