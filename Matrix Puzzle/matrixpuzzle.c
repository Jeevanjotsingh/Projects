#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int arr[4][4], j = 0;
void check(int a[], int num) // checking whether the element is present in the array
{
    for (int i = 0; i < j; i++)
    {
        if (num == a[i])
        {
            return;
        }
    }
    a[j++] = num;
    return;
}
void createarray() // creating matrix
{
    int a[16];
    int lower = 1, upper = 15;
    int i, count = 15;
    while (j < 15)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        check(a, num);
    }
    a[15] = 0;
    int k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            arr[i][j] = a[k++];
    }
}

int stop = 1;
void display() // Display screen
{
    system("cls");
    printf("\033[0;32m");
    printf("\t\t\t\t\t\tMatrix Puzzle");
    printf("\033[0;31m");
    printf("\n\n\t\t\tRULES OF THIS GAME: ");
    printf("\n\n\t\t1.You can only move 1 step at a time using arrow keys: ");
    printf("\033[0;34m");
    printf("\n\t\t\t\t-To move up- Use upward arrow key.");
    printf("\n\t\t\t\t-To move down- Use downward arrow key.");
    printf("\n\t\t\t\t-To move left- Use leftward arrow key.");
    printf("\n\t\t\t\t-To move right- Use rightward arrow key.");
    printf("\033[0;31m");
    printf("\n\n\t\t2.You can move numbers at empty position only.");
    printf("\n\n\n\t\t3.Winning situation: Number in a 4*4 matrix should be in order from 1 to 15.");
    printf("\033[0;34m");
    printf("\n\t\t\tWINNING SITUATION:");
    printf("\n\033[0;33m");
    printf("\n\t-------------");
    printf("\n\t| 1| 2| 3| 4|");
    printf("\n\t| 5| 6| 7| 8|");
    printf("\n\t| 9|10|11|12|");
    printf("\n\t|13|14|15|  |");
    printf("\n\t-------------");
    printf("\n\033[0;31m");
    printf("\t\t5. You can exit the game anytime by pressing 'E' or 'e' key.");
    printf("\n\033[0;36m");
    printf("\n\n\tPress enter key to start....: ");
    getchar();
}
void print()
{
    printf("\033[0;36m");
    printf("\n-------------\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                printf("|  ");
            else if (arr[i][j] > 9)
                printf("|%d", arr[i][j]);
            else
                printf("| %d", arr[i][j]);
            if (j == 3 || j == 6 || j == 9 || j == 12)
                printf("|");
        }
        printf("\n");
    }
    printf("-------------");
}
int readEnteredKey() // it checks which arrow key did user press
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();

    return c;
}
void swap(int *val1, int *val2) // for moving the elements
{
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
void arrowup() // for up arrow key
{
    int i, j;
    for (i = 0; i < 4 && stop; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                stop = 0;
                break;
            }
        }
    }
    i--;
    if (i == 0)
    {
        system("cls");
        print();
        printf("\033[1;31m");
        printf("\nInvalid move");
        printf("\npress enter key...");
        getchar();
    }
    else
    {
        swap(&arr[i][j], &arr[i - 1][j]);
    }
    system("cls");
}
void arrowdown() // for down arrow key
{
    int i, j;
    for (i = 0; i < 4 && stop; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                stop = 0;
                break;
            }
        }
    }
    i--;
    if (i == 3)
    {
        system("cls");
        print();
        printf("\033[1;31m");
        printf("\nInvalid move");
        printf("\npress enter key...");
        getchar();
    }
    else
    {
        swap(&arr[i][j], &arr[i + 1][j]);
    }
    system("cls");
}
void arrowleft() // for left arrow key
{
    int i, j;
    for (i = 0; i < 4 && stop; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                stop = 0;
                break;
            }
        }
    }
    i--;
    if (j == 0)
    {
        system("cls");
        print();
        printf("\033[1;31m");
        printf("\nInvalid move");
        printf("\npress enter key...");
        getchar();
    }
    else
    {
        swap(&arr[i][j], &arr[i][j - 1]);
    }
    system("cls");
}
void arrowright() // for right arrow key
{
    int i, j;
    for (i = 0; i < 4 && stop; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                stop = 0;
                break;
            }
        }
    }
    i--;
    if (j == 3)
    {
        system("cls");

        print();
        printf("\033[1;31m");
        printf("\nInvalid move");
        printf("\npress enter key...");
        getchar();
    }
    else
    {
        swap(&arr[i][j], &arr[i][j + 1]);
    }
    system("cls");
}
int win_matrix() // matrix should be equal to this matrix inorder to win
{
    int i, j;
    int win[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (win[i][j] != arr[i][j])
                return 0;
        }
    }
    return 1;
}

void main()
{
    createarray();
    display();
    char name[20];
    printf("\033[0;33m");
    printf("\n\n\tEnter player name: ");
    fflush(stdin);
    scanf("%[^\n]s", name);
    printf("%s", name);
    printf("\033[0;35m");
    printf("\t\t\n\nALL THE BEST!");
    printf("\033[0;30m");
    system("cls");
    int choice;
    while (1)
    {
        if (win_matrix())
        {
            printf("\n\n\n\n\n\t\t\tCONGRATULATIONS\n\n\t\t\tYou won!  press enter key to exit: ");
            getchar();
            exit(0);
        }

        else
        {
            printf("\033[0;33m");
            printf("      \n\nPlayer name: %s\n\n", name);
            print();
            fflush(stdin);
            printf("\033[0;35m");
            printf("\n\n\tEnter your choice: ");
            choice = readEnteredKey(); // takes arrow key input from user
            switch (choice)
            {
            case 69:
            case 101:
                printf("\033[1;31m");
                system("cls");
                printf("\n\n\n\n\t\t\t     Thanks for Playing ! \n\a");
                printf("\n\n\n\n\n\t\t\t Hit 'Enter' to exit the game \n");
                getchar();
                exit(0);
            case 72:
                print();
                arrowup();
                stop = 1;
                break;
            case 80:
                print();
                arrowdown();
                stop = 1;
                break;
            case 75:
                print();
                arrowleft();
                stop = 1;
                break;
            case 77:

                print();
                arrowright();
                stop = 1;
                break;
            default:
                print();
                printf("\033[1;31m");
                printf("\nInvalid move");
                printf("\npress enter key...");
                break;
            }
        }
    }
}