#pragma once

void displayShop(int currentTile, char *shopArea);

void processShop(char *shopInput, int *currentTile, char *shopArea, char (*inventory)[3]);

void runShop();

// Initialize shop.c Values

int currentTile = 0;
char shopArea[3] = {'G', 'A', 'S'};
int playerArea[3] = {1, 0, 0};