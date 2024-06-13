#include "inventory.h"
#include "colors.h"

void displayInventory(char (*inventory)[3]){
    printf("(this is inventory)\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) printf("[%c]", inventory[i][j]);
        printf("\n");
    }

    printf("► INVENTORY ───────\n");
    printf("\n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 3; j++){
            char item[10];
            char color[15];
            switch (inventory[i/3][j])
            {
            case 'E':
                strcpy(item, "   ");
                strcpy(color, COLORSTOP);
                break;
            case 'G':
                strcpy(item, "█▀█");
                strcpy(color, GHOSTCOLOR);
                break;
            case 'A':
                strcpy(item, "▀▄▀");
                strcpy(color, ALIENCOLOR);
                break;
            case 'S':
                strcpy(item, "▄█▄");
                strcpy(color, SQUIDCOLOR);
                break;
            default:
                break;
            }

            if (i % 3 == 0) printf("%s┌───┐%s", color, COLORSTOP);
            if (i % 3 == 1) printf("%s│%s│%s", color, item, COLORSTOP);
            if (i % 3 == 2) printf("%s└───┘%s", color, COLORSTOP);
        }
        printf("\n");
    }
    printf("\n");
    printf("───────────────────\n");
    printf("[D] Delete Items | [Q] Exit\n");
    printf("[INPUT] : ");
}

void processInventory(char *inventoryInput, char (*inventory)[3]){
    scanf(" %c", inventoryInput);
    if (*inventoryInput == 'd' || *inventoryInput == 'D'){
        runDelete(inventory);
    }
}

void runInventory(char item, char (*inventory)[3]){
    char inventoryInput = '0';
    do{
        displayInventory(inventory);
        processInventory(&inventoryInput, inventory);
    } while(inventoryInput != 'q' && inventoryInput != 'Q');
}
