#include "character_creation.h"

void runCharacterCreation(){
    int nInput = -1;

    do{
        displayCharacterCreation();
        scanf("%d", &nInput);
        processCharacterCreation(nInput);
    } while (nInput != 0);
}

void displayCharacterCreation(){
    printf("\n");
    printf("\t╔════════════════════╗\n");
    printf("\t│        Chara       │\n");
    printf("\t╚════════════════════╝\n");
    printf("\t[1] Yeah\n");
    printf("\n");
}

void processCharacterCreation(int nInput){
    switch(nInput){
        case 1:
            runCharacterCreation();
            break;
    }
}