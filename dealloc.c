int dealloc(int length, int width, char ***GRID_BE, char ***GRID_FE);

int dealloc(int length, int width, char ***GRID_BE, char ***GRID_FE)
{   for(int i = 0; i < length; i++)
        free((*GRID_BE)[i]);
    free(*GRID_BE);


	for(int i = 0; i < length; i++)
        free((*GRID_FE)[i]);
    free(*GRID_FE);

	return 0;
}