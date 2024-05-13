#include "area.h"

 void displayArea(){
    int nInput = -1;

    printf("\n"); printf("\t╔════════════════════╗ \n");
    printf("\t│ AREA │ \n");
    printf("\t╚════════════════════╝ \n");
    printf("\n");

    nInput = scanf("%d");

    if (nInput == 0) displayMainMenu();

}