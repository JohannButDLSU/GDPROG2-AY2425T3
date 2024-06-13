#include "item.h"
#include "colors.h"

void displayItem(char item){
    char itemName[6];
    char displayLine1[18];
    char displayLine2[18];
    char displayLine3[18];

    char color[20];

    switch (item)
    {
        case 'G':
            strcpy(itemName, "GHOST");
            strcpy(displayLine1, " ▄███▄ ");
            strcpy(displayLine2, " █ █ █ ");
            strcpy(displayLine3, " █▀█▀█ ");
            strcpy(color, GHOSTCOLOR);
            break;
        case 'A':
            strcpy(itemName, "ALIEN");
            strcpy(displayLine1, " ▀▄▄▄▀ ");
            strcpy(displayLine2, "▄█ █ █▄");
            strcpy(displayLine3, " █▀▀▀█ ");
            strcpy(color, ALIENCOLOR);
            break;
        case 'S':
            strcpy(itemName, "SQUID");
            strcpy(displayLine1, "  ▄█▄  ");
            strcpy(displayLine2, "▄█ █ █▄");
            strcpy(displayLine3, " ▄▀▀▀▄ ");
            strcpy(color, SQUIDCOLOR);
            break;
        default:
            break;
    }

    printf("► ITEM ────────────\n");
    printf("\n");
    printf("\n");
    printf("     ┌── %s ──┐\n", itemName);
    printf("     │ %s╔═══════╗%s │\n", color, COLORSTOP);
    printf("     │ %s║%s║%s │\n", color, displayLine1, COLORSTOP);
    printf("     │ %s║%s║%s │\n", color, displayLine2, COLORSTOP);
    printf("     │ %s║%s║%s │\n", color, displayLine3, COLORSTOP);
    printf("     │ %s╚═══════╝%s │ \n", color, COLORSTOP);
    printf("     └───────────┘ \n");
    printf("YOU GOT %s!\n", itemName);
    printf("───────────────────\n");
    printf("[Q] Exit");
    printf("[INPUT] : ");
}

void processItem(char item, char *itemInput, char (*inventory)[3]){
    scanf(" %c", itemInput);
    if (*itemInput == 'q' || *itemInput == 'Q'){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (inventory[i][j] == 'E'){
                    inventory[i][j] = item;
                    i = 3;
                    j = 3;
                }
            }
        }
    }
}

void runItem(char item, char (*inventory)[3]){
    char itemInput;
    do{
        displayItem(item);
        processItem(item, &itemInput, inventory);
    } while(itemInput != 'q' && itemInput != 'Q');
}