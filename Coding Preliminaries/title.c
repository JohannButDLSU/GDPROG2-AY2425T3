#include "title.h"

void runTitle(){
    int nInput = -1;

    do{
        displayTitle();
        scanf("%d", &nInput);
        processTitleInput(nInput);
    } while (nInput != 0);
}

void displayTitle(){
  printf("\n");
    printf("\t╔════════════════════╗\n");
    printf("\t│        Title       │\n");
    printf("\t╚════════════════════╝\n");
    printf("\t[1] Yeah\n");
    printf("\n");
}

void processTitleInput(int nInput){
    switch(nInput){
        case 1:
            runArea();
            break;
    }
}