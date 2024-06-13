#include "shop.h"
#include "colors.h"

void displayShop(int currentTile, char *shopArea){
    char gacha[6];
    char color[20];
    
    switch (currentTile)
    {
    case 0:
        strcpy(gacha, "GHOST");
        strcpy(color, GHOSTCOLOR);
        break;
    case 1:
        strcpy(gacha, "ALIEN");
        strcpy(color, ALIENCOLOR);
        break;
    case 2:
        strcpy(gacha, "SQUID");
        strcpy(color, SQUIDCOLOR);
        break;
    default:
        break;
    }

    // printf("\x1b[38;5;200m");
    // printf("\x1b[48;5;180m");

    printf("\n");
    printf("► SHOP ────────────\n");
    printf("\n");
    printf("     %s┌%s═══════%s┐%s\n", color, COLORSTOP, color, COLORSTOP); // I know I don't have to stop it every line
    printf("     %s├───────┤%s\n", color, COLORSTOP);                       // but I kinda prefer it that way, more clean 2 me
    printf("     %s│ %s │%s\n", color, gacha, COLORSTOP);
    printf("     %s├───────┤%s\n", color, COLORSTOP);
    printf("     %s└%s═╤═══╤═%s┘%s\n", color, COLORSTOP, color, COLORSTOP);
    printf("      %s╔┴█──┤%s\n", color, COLORSTOP);
    printf("      %s╚┬───┤%s\n", color, COLORSTOP);
    printf("       %s└─%s│%s─┘%s\n", color, COLORSTOP, color, COLORSTOP);
    printf("       ┌─│─┐\n");
    printf("       │   │\n");
    printf("───────╨───╨───────\n");
    printf("[A/D] Change Gacha | [E] Buy Gacha | [I] Inventory | [0] Exit\n");
    printf("[INPUT] : ");
}

void processShop(char *shopInput, int *currentTile, char *shopArea, char (*inventory)[3]){
    scanf(" %c", shopInput);
    switch (*shopInput)
    {
        case 'd':
        case 'D':
            if (*currentTile != 2){
                (*currentTile) ++;
            }
            break;
        case 'a':
        case 'A':
            if (*currentTile != 0){
                (*currentTile) --;
            }
            break;
        case 'e':
        case 'E':
            runItem(shopArea[*currentTile], inventory);
            break;
        case 'i':
        case 'I':
            printf("\n");
            runInventory(shopArea[*currentTile], inventory);
            break;
        default:
            break;
    }
}

void runShop(){
    char shopInput = '0';
    char inventory[3][3]={
    {'E', 'E', 'E'},
    {'E', 'E', 'E'},
    {'E', 'E', 'E'}
};
    do{
        displayShop(currentTile, shopArea);
        processShop(&shopInput, &currentTile, shopArea, inventory);
    } while(shopInput != '0');

}