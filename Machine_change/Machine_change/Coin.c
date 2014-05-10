//
//  Coin.c
//  Machine_change
//
//  Created by Saúl on 07/05/14.
//  Copyright (c) 2014 Saúl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "dVector.h"



const float EURO_COINS [8] = {2, 1, .5f, .2f, .1f, .05f, .02f, .01f};
const float YEN_COINS [5] = {500, 100, 50, 10, 5};
const float DOLAR_COINS [6] = {1, .5, .25, .1, .05, .01};


typedef enum {
    Euro,
    Yen,
    Dolar
    
} CoinType;


typedef struct {
    CoinType coinType;
    short coinCount;
    int stock;
    float * availableCoins;
    char * coinName;

} * CoinInfo;


void remove_newline_ch(char *line) {
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}


void selectCoin (CoinType coinType, CoinInfo* userCoin) {
    *userCoin = (CoinInfo) malloc(sizeof(CoinInfo));
    
    switch (coinType) {
        case Euro:
            printf("The selected coin is: [EURO]\n");
            (*userCoin) -> coinType = Euro;
            (*userCoin) -> availableCoins = (float*) &EURO_COINS;
            (*userCoin) -> coinCount = 8;
            
            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Euro";
            break;
            
        case Yen:
            printf("The selected coin is: [YEN]\n");
            (*userCoin) -> coinType = Yen;
            (*userCoin) -> availableCoins = (float*) &YEN_COINS;
            (*userCoin) -> coinCount = 5;

            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Yen";
            break;
            
        case Dolar:
            printf("The selected coin is: [DOLAR]\n");
            (*userCoin) -> coinType = Dolar;
            (*userCoin) -> availableCoins = (float*) &DOLAR_COINS;
            (*userCoin) -> coinCount = 6;
            
            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Dolar";
            break;
            
        default:
            printf("That coin doesn't exists\n");
            break;
    }
}


void getSpecificCoin (int index, CoinInfo coinInfo, float * coinContainer) {
    *(coinContainer) = *((coinInfo) -> availableCoins + index);
}


void getCoinType (CoinInfo coinInfo, CoinType * coinType) {
    *(coinType) = ((coinInfo) -> coinType);
}


void getCointSize (CoinInfo coinInfo, short * cointSize) {
    *(cointSize) = ((coinInfo) -> coinCount);
}


void getCoinName (CoinInfo coinInfo, char ** _coinName) {
    *_coinName = ((coinInfo) -> coinName);
}


int changeInf(int maxIterations, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins, vectorP * stock) {
    float changeAmount = 0, changeContainer = 0;
    int i = 1;
    
    while (changeAmount < changeQuantity && i < maxIterations) {
        getSpecificCoin(i, coinInfo, &changeContainer);
        
        if (changeAmount + changeContainer <= changeQuantity) {
            incrementVect(solutionCoins, i);
            
            if(stock != NULL) {
                decrementVect(stock, i);
            }
            
            changeAmount += changeContainer;
 
        } else {
            i++;
        }
    }
 
     if (changeAmount == changeQuantity)
         return 1;
    
    return 0;
 }


void printCoins(vectorP coins, CoinInfo info) {
    float currentCoin = 0;
    
    if (coins != NULL) {
        for (int i = 0; i < getSize(coins); i++) {
            getSpecificCoin(i, info, &currentCoin);
            printf("%d Coins x [%.2f]\n", getValue(coins, i), currentCoin);
        }
        
    } else {
        printf("[ERROR] The vector is not initialized.");
    }
}



void readStock(CoinInfo coin, vectorP * stock) {
    int correctCoinFlag = 0;
    
    char * line = NULL;
    char * selectedCoin = NULL;
    char * parseIntegerError = NULL;
    
    FILE * fp;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen("/Users/wtf/Desktop/stock2.txt", "r");
    getCoinName(coin, &selectedCoin);
    int coinPosition = 0;
    
    printf("Getting stock of: %s\n", selectedCoin);
    
    if(fp != NULL) {
        
        // Read line by line
        while ((read = getline(&line, &len, fp)) != -1) {
            
            parseIntegerError = NULL;
            remove_newline_ch(line);
            
            // parses the string into number, if fails, the report is stored at parseIntegerError.
            int coinQuantity = (int) strtol(line, &parseIntegerError,10);
            
            if (* parseIntegerError) {
                
                // Scans if the column coin is the same that the stored at 'coin' parameter
                if(strcmp(selectedCoin, parseIntegerError) == 0) {
                    correctCoinFlag = 1;
                    printf("Flag setted\n");
                    
                } else {
                    if(correctCoinFlag == 1) {
                        return;
                        
                    } else {
                        correctCoinFlag = 0;
                    }
                }
                
                printf("Coin: %s\n", parseIntegerError);
                
            } else {
                if(correctCoinFlag == 1) {
                    printf("Coin [%d]: %d\n",coinPosition, coinQuantity);
                    assignValue(stock, coinPosition, coinQuantity);
                    coinPosition ++;
                }
            }
            
        }
    }

    
}
