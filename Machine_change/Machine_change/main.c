


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
    
    vectorP solutionCoins = NULL;
    createVector(&solutionCoins, 5);

    
    // Getting stock
    printf("\n\nGetting stock: \n");
    int cointSize = 0;
    vectorP stock = NULL;
    getCointSize(dolarInfo, &cointSize);
    
    createVector(&stock, cointSize);
    readStockFile(dolarInfo, &stock);
    printVect(stock);

    
    changeInf(5, 1.25, dolarInfo, &solutionCoins, &stock);
    printf("\nResulting change\n\n");
    printVect(solutionCoins);
    
    printf("\nStock after change\n\n");
    printVect(stock);
    

    
    printf("\n%d",Yen);
    return 0;
}

