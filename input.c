void input_coords(int *x, int *y, char *inputAction);

void input_coords(int *x, int *y, char *inputAction)
{   printf("\nEnter the coordinates[x, y] and action(F for flag, O for open, ? for \"not sure\")\n>>>");
    if (scanf("%d%d", x, y) != 2)
    {   printf("ERROR!");
        exit(1);
    }
    getchar();
    if (scanf("%c", inputAction) != 1)
    {   printf("ERROR!");
        exit(1);
    }
}