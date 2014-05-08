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
} *CoinInfo;


void selectCoin (CoinType coinType, CoinInfo* userCoin) {
    *userCoin = (CoinInfo) malloc(sizeof(CoinInfo));
    
    switch (coinType) {
        case Euro:
            printf("You selected euro...\n");
            (*userCoin) -> availableCoins = (float*) &EURO_COINS;
            (*userCoin) -> coinCount = 5;
            break;
            
        case Yen:
            printf("You selected yen...\n");
            (*userCoin) -> availableCoins = (float*) &YEN_COINS;
            (*userCoin) -> coinCount = 5;
            break;
            
        case Dolar:
            printf("You selected dolar...\n");
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


int changeInf(int n, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins) {
    int i = 0, cointAmount = 0;
    float changeAmount = 0, changeContainer = 0;
 
    while (changeAmount < changeQuantity && i<n) {
        getSpecificCoin(i, coinInfo, &changeContainer);
        
        if (changeAmount + changeContainer <= changeQuantity) {
            cointAmount++;

            assignValue(solutionCoins, i, cointAmount);
            changeAmount += changeContainer;
 
        } else {
             cointAmount = 0;
             i++;
        }
    }
 
     if (changeAmount == changeQuantity)
         return 1;

    return 0;
 }