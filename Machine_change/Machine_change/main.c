


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



int main(int argc, const char * argv[]) {

    
    CoinInfo dolarInfo;
    selectCoin(Dolar, &dolarInfo);
    
    float container = 0;
    printf("Get specific coin: %f\n\n", container);
    
    vectorP solutionCoins = NULL;
    createVector(&solutionCoins, 5);
    
    
    changeInf(5, 0.75, dolarInfo, &solutionCoins);
    printVect(solutionCoins);
    
    return 0;
}

