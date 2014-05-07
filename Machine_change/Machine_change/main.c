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

/*
int change(int n, int changeQuantity, int availableCoins[],int solutionCoins[]) {
    for (int coinPos = 0; coinPos < n; coinPos++)
        solutionCoins[coinPos] = 0;
    
    int i = 0, changeAmount = 0;
    
    while (changeAmount < changeQuantity && i<n)
        if (changeAmount + availableCoins[i] <= changeQuantity) {
            solutionCoins[i]++;
            changeAmount += availableCoins[i];
            
        } else
            i++;
    
    if (changeAmount == changeQuantity)
        return 1;
    
    else {
        for (int i=0;i<n;i++)
            solutionCoins[i]=0;
        
        return 0;
    }
}
*/

int main(int argc, const char * argv[]) {
    vectorP myVect;
    createVector(&myVect, 30);
    
    assignValue(&myVect, 2, 30);

    
    
    // int valor[5]= {50,25,20,5,1};
    // int solucion[10] = {};
    // change(5, 42, valor, solucion);

    Coin euroCoin;
    selectCoin(Euro, &euroCoin);
    getCoin(0, euroCoin);
    
    return 0;
}

