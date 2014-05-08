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


//const float EURO_COINS [5] = {.01f, .05f, .1f, .2f, .5f};
const float EURO_COINS [5] = {.5f, .2f, .1f, .05f, .01f};
const float YEN_COINS [5] = {5, 10, 50, 100, 500};
//const float DOLAR_COINS [6] = {0.01, 0.05, 0.10, 0.25, 0.50, 1};
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
 
    int i = 0;
    float changeAmount = 0;
    int cointAmount = 0;
    float changeContainer = 0;
 
    while (changeAmount < changeQuantity && i<n) {
        getSpecificCoin(i, coinInfo, &changeContainer);
        
        if (changeAmount + changeContainer <= changeQuantity) {
             cointAmount++;
             assignValue(solutionCoins, i, cointAmount);
             changeAmount += changeContainer;
            printf("Change amount %f\n", changeAmount);
 
        } else {
             cointAmount = 0;
             i++;
        }
    }
 
    if (changeAmount == changeQuantity)
         return 1;
    else
        return 0;
 }



/*int changeInf(int n, int changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins) {
    int i = 0, changeAmount = 0, coinAmount = 0;
    float availabeCoinContainer = 0;
    
    while (changeAmount < changeQuantity && i<n) {
        getSpecificCoin(i, coinInfo, &availabeCoinContainer);
        
        if (changeAmount + availabeCoinContainer <= changeQuantity) {
            coinAmount ++;
            assignValue(solutionCoins, i, coinAmount);
            changeAmount += availabeCoinContainer;
            
        } else {
            i++;
            coinAmount = 0;
        }
    }
    
    if (changeAmount == changeQuantity)
        return 1;
    
    else {
        for (int i=0;i<n;i++)
            assignValue(solutionCoins, i, 0);
        
        return 0;
    }
}*/




