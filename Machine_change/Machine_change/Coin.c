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


const float EURO_COINS [5] = {.01f, .05f, .1f, .2f, .5f};
const float YEN_COINS [5] = {5, 10, 50, 100, 500};
const float DOLAR_COINS [6] = {0.01, 0.05, 0.10, 0.25, 0.50, 1};


typedef enum {
    Euro,
    Yen,
    Dolar
} CoinType;


typedef struct {
    CoinType coinType;
    float * availableCoins;
} *Coin;


void selectCoin (CoinType coinType, Coin* userCoin) {
    *userCoin = (Coin) malloc(sizeof(Coin));
    
    switch (coinType) {
        case Euro:
            printf("You selected euro...\n");
            (*userCoin) -> availableCoins = (float*) &EURO_COINS;
            break;
            
        case Yen:
            printf("You selected yen...\n");
            break;
            
        case Dolar:
            printf("You selected dolar...\n");
            break;
            
        default:
            printf("That coin doesn't exists\n");
            break;
    }
}

void getCoin (int index, Coin coinInfo) {
    float coinValue = *((coinInfo) -> availableCoins + index);
    printf("Value of: %f\n", coinValue);
}