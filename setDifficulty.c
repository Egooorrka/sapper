int setDifficulty(int input, int *length, int *width, int *mineAmount);

int setDifficulty(int input, int *length, int *width, int *mineAmount)
{   
    switch (input)
    {   case 1:
        *length = 10; *width = 10;
        *mineAmount = (*length) * (*width) * 0.14;
        break;
        case 2:
        *length = 15; *width = 15;
        *mineAmount = (*length) * (*width) * 0.14;
        break;
        case 3:
        *length = 30; *width = 30;
        *mineAmount = (*length) * (*width) * 0.14;
        break;
        case 666:
        *length = 30; *width = 30;
        *mineAmount = (*length) * (*width) * 0.667 + 66;
        break;
        default:
        exit(1);
        break;
    }

    return 0;
}