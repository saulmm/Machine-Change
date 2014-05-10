


//
//  main.c
//  Machine_change
//
//  Created by Saúl on 06/05/14.
//  Copyright (c) 2014 Saúl. All rights reserved.
//

#include <stdio.h>
#include "dVector.h"
#include "Coin.h"
#include <stdlib.h>










int main(int argc, const char * argv[]) {
    CoinInfo dolarInfo;
    selectCoin(Dolar, &dolarInfo);
    
    vectorP solutionCoins = NULL;
    createVector(&solutionCoins, 5);

    
    // Getting stock
    printf("\n\nGetting stock: \n");
    int cointSize = 0;
    vectorP stock = NULL;
    getCointSize(dolarInfo, &cointSize);
    
    printf("Vector size %d\n", cointSize);
    createVector(&stock, cointSize);
     readStock(dolarInfo, &stock);
    //printVect(stock);

    float toChange = 1.25;
     changeInf(5, toChange, dolarInfo, &solutionCoins, &stock);
     printf("\nResulting change of %.2f\n\n", toChange);
     printCoins(solutionCoins, dolarInfo);
    
    // printf("\nStock after change\n\n");
    // printVect(stock);
    
    return 0;
}

