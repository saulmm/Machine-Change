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



const float EURO_COINS [5] = {.5f, .2f, .1f, .05f, .01f};
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
    float * availableCoins;
    int stock;
    
} * CoinInfo;


void selectCoin (CoinType coinType, CoinInfo* userCoin) {
    *userCoin = (CoinInfo) malloc(sizeof(CoinInfo));
    
    switch (coinType) {
        case Euro:
            printf("The selected coin is: [EURO]\n");
            (*userCoin) -> coinType = Euro;
            (*userCoin) -> availableCoins = (float*) &EURO_COINS;
            (*userCoin) -> coinCount = 5;
            break;
            
        case Yen:
            printf("The selected coin is: [YEN]\n");
            (*userCoin) -> coinType = Yen;
            (*userCoin) -> availableCoins = (float*) &YEN_COINS;
            (*userCoin) -> coinCount = 5;
            break;
            
        case Dolar:
            printf("The selected coin is: [DOLAR]\n");
            (*userCoin) -> coinType = Dolar;
            (*userCoin) -> availableCoins = (float*) &DOLAR_COINS;
            (*userCoin) -> coinCount = 6;
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


int changeInf(int maxIterations, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins, vectorP * stock) {
    float changeAmount = 0, changeContainer = 0;
    int i = 1;
    
    while (changeAmount < changeQuantity && i < maxIterations) {
        getSpecificCoin(i, coinInfo, &changeContainer);
        
        if (changeAmount + changeContainer <= changeQuantity) {
            incrementVect(solutionCoins, i);
            
            changeAmount += changeContainer;
 
        } else {
            i++;
        }
    }
 
     if (changeAmount == changeQuantity)
         return 1;

    return 0;
 }


void readStockFile(CoinInfo coin, vectorP * stock) {
    char * line = NULL;
    
    FILE * fp;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen("/Users/wtf/Desktop/stock.txt", "r");
    
    if(fp != NULL) {
        short cointSize = 0, counter = 0;

        const char delimiter[2] = ",";
        
        // size_t is an unsigned data type. This type is used to represent the size of an object.
        // ssize_t is used to represent the sizes of blocks that can be read or written in a single operation.
        while ((read = getline(&line, &len, fp)) != -1) {
            char * coinStock;
            
            CoinType selectedCoin;
            short cointCount = 0;
            
            getCoinType(coin ,&selectedCoin);
            getCointSize(coin, &cointCount);

            if (counter == selectedCoin) {
                coinStock = strtok(line, delimiter);
                int coinCounter = 0;
                
                while(coinStock != NULL ) {
                    assignValue(stock, coinCounter, atoi(coinStock));
                    coinStock = strtok(NULL, delimiter);
                    coinCounter++;
                }
                
                return;
            }
        
            counter++;
        }
    
    } else {
        printf("The file it's null\n");
        return;
    }
    

    
}
