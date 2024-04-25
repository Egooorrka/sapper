int checkFirstStep(int length, int width, int *mineAmount, bool *firstStep, bool *youAreAlreadyDead);

int checkFirstStep(int length, int width, int *mineAmount, bool *firstStep, bool *youAreAlreadyDead)
{   if (*firstStep)
    {   *firstStep = false;
        int chance = rand() % 100;
        //printf("\nchance = %d", chance);
        if (chance == 1)
        {   *youAreAlreadyDead = true;
            *mineAmount = (length * width) - 1;
        }
    return 1;
        // fillField(length, width, mineAmount, x, y, GRID_BE, youAreAlreadyDead);
        // GRID_FE[x][y] = GRID_BE[x][y];
    }

    return 0;
}