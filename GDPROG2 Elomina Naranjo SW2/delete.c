#include "delete.h"
#include "colors.h"

void swap(char *first, char *second){
    char temp = *first;
    *first = *second;
    *second = temp;
}

void displayDelete(int *currentRow, int *currentColumn, char (*inventory)[3], int (*playerArea)[3]){
    printf("(this is delete)\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == *currentRow && j == *currentColumn){
                if (inventory[i][j] == 'G') inventory[i][j] = 'g';
                if (inventory[i][j] == 'A') inventory[i][j] = 'a';
                if (inventory[i][j] == 'S') inventory[i][j] = 's';
                if (inventory[i][j] == 'E') inventory[i][j] = 'e';
            }
            else{
                if (inventory[i][j] == 'g') inventory[i][j] = 'G';
                if (inventory[i][j] == 'a') inventory[i][j] = 'A';
                if (inventory[i][j] == 's') inventory[i][j] = 'S';
                if (inventory[i][j] == 'e') inventory[i][j] = 'E';
            }
        }
    }
    printf("► INVENTORY ───────\n");
    printf("\n");

    char item[10];
    char top[16];
    char side[4];
    char bottom[16];
    char color[15];

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 3; j++){

            switch (inventory[i/3][j]) //yes I put 2 switch cases :(
            {
            case 'E':
            case 'e':
                strcpy(item, "   ");
                strcpy(color, COLORSTOP);
                break;
            case 'G':
            case 'g':
                strcpy(item, "█▀█");
                strcpy(color, GHOSTCOLOR);
                break;
            case 'A':
            case 'a':
                strcpy(item, "▀▄▀");
                strcpy(color, ALIENCOLOR);
                break;
            case 'S':
            case 's':
                strcpy(item, "▄█▄");
                strcpy(color, SQUIDCOLOR);
                break;
            default:
                break;
            }

            switch (inventory[i/3][j])
            {
            case 'G':
            case 'A':
            case 'S':
            case 'E':
                strcpy(top, "┌───┐");
                strcpy(side, "│");
                strcpy(bottom, "└───┘");
                strcpy(color, COLORSTOP);
                break;
            case 'g':
            case 'a':
            case 's':
            case 'e':
                strcpy(top, "╔═══╗");
                strcpy(side, "║");
                strcpy(bottom, "╚═══╝");
                break;
            default:
                break;
            }


            if (i % 3 == 0) printf("%s%s%s", color, top, COLORSTOP);
            if (i % 3 == 1) printf("%s%s%s%s%s", color, side, item, side, COLORSTOP);
            if (i % 3 == 2) printf("%s%s%s", color, bottom, COLORSTOP);
        }
        printf("\n");
    }
    printf("\n");
    printf("───────────────────\n");
    printf("[WASD] Move Through Inventory | [E] Delete Item | [Q] Exit\n");
    printf("[INPUT] : ");
}

void processDelete(int *currentRow, int *currentColumn, char *deleteInput, char (*inventory)[3], int (*playerArea)[3]){
    scanf(" %c", deleteInput);
    playerArea[*currentRow][*currentColumn] = 0;
    switch (*deleteInput)
    {
        case 'W':
        case 'w':
            if (*currentRow != 0) (*currentRow)--;
            break;
        case 'A':
        case 'a':
            if (*currentColumn != 0) (*currentColumn)--;
            break;
        case 's':
        case 'S':
            if (*currentRow != 2) (*currentRow)++;
            break;
        case 'D':
        case 'd':
            if (*currentColumn != 2) (*currentColumn)++;
            break;
        case 'E':
        case 'e':
            inventory[*currentRow][*currentColumn] = 'E';
            for (int i = *currentRow; i < 3; i++){
                for (int j = *currentColumn; j < 3; j++){
                    if (j != 2) swap(&inventory[i][j], &inventory[i][j+1]);
                    else if (i != 2) swap(&inventory[i][j], &inventory[i+1][0]);
                }
            }

            break;
        default:
            break;
    }
    playerArea[*currentRow][*currentColumn] = 1;
}

void runDelete(char (*inventory)[3]){
    // Initializations
        int playerArea[3][3] = {
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
        int currentRow = 0;
        int currentColumn = 0;
        char deleteInput = '0';

    do{
        displayDelete(&currentRow, &currentColumn, inventory, playerArea);
        processDelete(&currentRow, &currentColumn, &deleteInput, inventory, playerArea);
    } while(deleteInput != 'q' && deleteInput != 'Q');
}