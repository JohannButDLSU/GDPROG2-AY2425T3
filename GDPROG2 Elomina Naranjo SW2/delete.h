#pragma once

void displayDelete(int *currentRow, int *currentColumn, char (*inventory)[3], int (*playerArea)[3]);

void processDelete(int *currentRow, int *currentColumn, char *deleteInput, char (*inventory)[3], int (*playerArea)[3]);

void runDelete(char (*inventory)[3]);