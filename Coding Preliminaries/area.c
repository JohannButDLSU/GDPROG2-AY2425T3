#include "area.h"

void runArea(){
    char cInput = '0';
    int nCurrentTile = 0;
    int nAreaSize = 5;
    int nArea[nAreaSize];
    // Set a starting tile
    printf("Where is your starting tile?\n");
    printf("[Input a number from 0-%d]", nAreaSize-1);
    scanf(" %d", &nCurrentTile);

    // Initialize all elements to be 0 and current tile to be 1
    for (int i = 0; i < nAreaSize; i++){
        nArea[i] = 0;
        if (i == nCurrentTile) nArea[i] = 1;
    }

    do{
        displayArea(nAreaSize, nCurrentTile);
        scanf(" %c", &cInput);
        processAreaInput(cInput, &nCurrentTile, nAreaSize, nArea);
    } while (cInput != '0');
}

void displayArea(int nAreaSize, int nCurrentTile){
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++){
        if (i != nCurrentTile) printf("┌───┐");
        if (i == nCurrentTile) printf("╔═══╗");
    }
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++){
        if (i != nCurrentTile) printf("│   │");
        if (i == nCurrentTile) printf("║ ■ ║");
    }
    printf("\n");
    printf("\t");
    for (int i = 0; i < nAreaSize; i++){
        if (i != nCurrentTile) printf("└───┘");
        if (i == nCurrentTile) printf("╚═══╝");
    }
    printf("\n");
    printf("\t[PLAYER] : ♥ ♥ ♥\n");
    printf("\n");
    printf("\tCurrent Tile: %d", nCurrentTile);
    printf("\t[INPUT] : ");
}

void processAreaInput(char cInput, int* nCurrentTile, int nAreaSize, int nArea[nAreaSize]){
    switch(cInput){
        case 'a':
        case 'A':
            if ((*nCurrentTile) > 0){
                nArea[*nCurrentTile] = 0;
                (*nCurrentTile) --;
            }
            break;
        case 'd':
        case 'D':
            if ((*nCurrentTile) < nAreaSize-1){
                nArea[*nCurrentTile] = 0;
                (*nCurrentTile) ++;
            }
        default:
            break;
    }
    nArea[*nCurrentTile] = 1;
    // Debug print
    for(int i = 0; i < nAreaSize; i++) printf("%d", nArea[i]);
}