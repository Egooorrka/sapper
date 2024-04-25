bool checkZeroth(char **GRID_BE, int d1, int d2, int length, int width, bool *active);

bool checkZeroth(char **GRID_BE, int d1, int d2, int length, int width, bool *active)
{   if (d1 < 0 || d1 > length - 1) { *active = false; return false; }
    if (d2 < 0 || d2 > width - 1) { *active = false; return false; }
    
    if (GRID_BE[d1][d2] == '0')
        return true;

    *active = false;
    return false;
}

void revealCells(char **GRID_BE, char **GRID_FE, int d1, int d2, int length, int width);

void revealCells(char **GRID_BE, char **GRID_FE, int d1, int d2, int length, int width)
{   
    for (int k = d1 - 1; k <= d1 + 1; k++)
        for (int l = d2 - 1; l <= d2 + 1; l++)
        {   if (kOutOfBounds(d1, k, length)) continue;
			if (lOutOfBounds(d2, l, width)) continue;
            if (GRID_BE[k][l] == '*') continue;
            GRID_FE[k][l] = GRID_BE[k][l];
        }
}

int setStep(int x, int y, int length, int width, int mineAmount, char inputAction, char **GRID_BE, char **GRID_FE, bool *firstStep, bool *dead);

int setStep(int x, int y, int length, int width, int mineAmount, char inputAction, char **GRID_BE, char **GRID_FE, bool *firstStep, bool *dead)
{   bool youAreAlreadyDead = false;
    x--; y--;

    if (x > length - 1 || x < 0 || y > width - 1 || y < 0)
        return 2;

    switch(inputAction)
    {   case 'F':
        if (GRID_FE[x][y] == 'X')
        {   GRID_FE[x][y] = 'F';
            return 0;
        }
        if (GRID_FE[x][y] == 'F')
        {   GRID_FE[x][y] = 'X';
            return 0;
        }
        return 0;
        break;
        
        case '?':
        if (GRID_FE[x][y] == 'X')
        {   GRID_FE[x][y] = '?';
            return 0;
        }
        if (GRID_FE[x][y] == '?')
        {   GRID_FE[x][y] = 'X';
            return 0;
        }
        return 0;
        break;

        case 'O':
        break;

        default:
        return -1;
        break;
    }


    // if (*firstStep)
    // {   *firstStep = false;
    //     int chance = rand() % 100;
    //     //printf("\nchance = %d", chance);
    //     if (chance == 1)
    //     {   youAreAlreadyDead = true;
    //         mineAmount = (length * width) - 1;
    //     }

    //     fillField(length, width, mineAmount, x, y, GRID_BE, youAreAlreadyDead);
    //     GRID_FE[x][y] = GRID_BE[x][y];
    // }
    
    

    switch(GRID_BE[x][y])
    {   case '*':
        *dead = true;
        //updateField();
        break;

        case '0':
        {
        GRID_FE[x][y] = GRID_BE[x][y];

        int du = x - 1, dd = x + 1, dl = y - 1, dr = y + 1;

        bool active[8] = {true, true, true, true, true, true, true, true};

        while(true)
        {   bool limit = true;
            if (checkZeroth(GRID_BE, du, y, length, width, &active[0]) && active[0]) {GRID_FE[du][y] = GRID_BE[du][y]; revealCells(GRID_BE, GRID_FE, du, y, length, width);}
            if (checkZeroth(GRID_BE, dd, y, length, width, &active[1]) && active[1]) {GRID_FE[dd][y] = GRID_BE[dd][y]; revealCells(GRID_BE, GRID_FE, dd, y, length, width);}
            if (checkZeroth(GRID_BE, x, dl, length, width, &active[2]) && active[2]) {GRID_FE[x][dl] = GRID_BE[x][dl]; revealCells(GRID_BE, GRID_FE, x, dl, length, width);}
            if (checkZeroth(GRID_BE, x, dr, length, width, &active[3]) && active[3]) {GRID_FE[x][dr] = GRID_BE[x][dr]; revealCells(GRID_BE, GRID_FE, x, dr, length, width);}
            if (checkZeroth(GRID_BE, du, dl, length, width, &active[4]) && active[4]) {GRID_FE[du][dl] = GRID_BE[du][dl]; revealCells(GRID_BE, GRID_FE, du, dl, length, width);}
            if (checkZeroth(GRID_BE, du, dr, length, width, &active[5]) && active[5]) {GRID_FE[du][dr] = GRID_BE[du][dr]; revealCells(GRID_BE, GRID_FE, du, dr, length, width);}
            if (checkZeroth(GRID_BE, dd, dl, length, width, &active[6]) && active[6]) {GRID_FE[dd][dl] = GRID_BE[dd][dl]; revealCells(GRID_BE, GRID_FE, dd, dl, length, width);}
            if (checkZeroth(GRID_BE, dd, dr, length, width, &active[7]) && active[7]) {GRID_FE[dd][dr] = GRID_BE[dd][dr]; revealCells(GRID_BE, GRID_FE, dd, dr, length, width);}
            du--; dd++; dl--; dr++;
            for (int i = 0; i < 8; i++)
            {   //printf("\nactive[%d] = %d", i, active[i]);
                if (active[i])
                {   limit = false;
                    break;
                }
            }
            if (limit) break;
        }
        //updateField();
        }
        break;

        default:
        {
        GRID_FE[x][y] = GRID_BE[x][y];
        //updateField();
        }
        break;
    }

    return 0;
}