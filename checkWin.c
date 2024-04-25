bool checkWin(char **GRID_BE, char **GRID_FE, int length, int width, int mineamount);

bool checkWin(char **GRID_BE, char **GRID_FE, int length, int width, int mineamount)
{   int currentFlags = 0;
    for (int i = 0; i < length; i++)
    {    for (int j = 0; j < width; j++)
            if (GRID_FE[i][j] == 'F')
            {   if (GRID_BE[i][j] == '*')
                    currentFlags++;
                else break;
            }
    }
    if (currentFlags == mineamount) return true;
    else return false;
}