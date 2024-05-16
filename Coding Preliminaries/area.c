#include "area.h"

void runArea(){
    char cInput = '0';
    int nCurrentTile = 1;

    do{
        displayArea(nCurrentTile);
        scanf(" %c", &cInput);
        processAreaInput(cInput, &nCurrentTile);
    } while (cInput != '0');
}

void displayArea(int nCurrentTile){
    printf("\n");
    printf("\t╔═══╗┌───┐┌───┐┌───┐\n");
    printf("\t║ ■ ║│   ││   ││   │\n");
    printf("\t╚═══╝└───┘└───┘└───┘\n");
    printf("\t[PLAYER] : ♥ ♥ ♥\n");
    printf("\n");
    printf("\tCurrent Tile: %d", nCurrentTile);
    printf("\t[INPUT] : ");
}

void processAreaInput(char cInput, int* nCurrentTile){
    switch(cInput){
        case 'a':
            (*nCurrentTile) --;
            break;
        case 'd':
            (*nCurrentTile) ++;
        default:
            break;
    }
}