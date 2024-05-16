#include "area.h"

void runArea(){
    char cInput = '0';
    int nCurrentTile = 0;
    int nAreaSize = 7;

    do{
        displayArea(nAreaSize, nCurrentTile);
        scanf(" %c", &cInput);
        processAreaInput(nAreaSize, cInput, &nCurrentTile);
    } while (cInput != '0');
}

void displayArea(int nAreaSize, int nCurrentTile){
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++) printf("┌───┐");
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++) printf("│   │");
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++) printf("└───┘");
    printf("\n");
    printf("\t[PLAYER] : ♥ ♥ ♥\n");
    printf("\n");
    printf("\tCurrent Tile: %d", nCurrentTile);
    printf("\t[INPUT] : ");
}

void processAreaInput(int nAreaSize, char cInput, int* nCurrentTile){
    switch(cInput){
        case 'a':
            if ((*nCurrentTile) > 0) (*nCurrentTile) --;
            break;
        case 'd':
            if ((*nCurrentTile) < nAreaSize) (*nCurrentTile) ++;
        default:
            break;
    }
}