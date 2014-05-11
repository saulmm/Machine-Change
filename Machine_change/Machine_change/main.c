


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


int showTwoOptionsMenu (char* message, char* option1, char* option2) {
    char option;
    
    do {
        printf("%s\n1) %s\n2) %s\n", message, option1, option2);
        printf("\nYour choice:\n> ");
        
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                return 1;
                break;
                
            case '2':
                return 2;
                break;
                
            default:
                printf("Wrong input\n");
        }
    } while (1);
    
    // This never will happen
    return 0;
}


int handleThreeOptionsMenu(char * message, char * option1, char * option2, char * option3) {
    char choice[1];
    
    do {
        printf("\n%s\n1) %s\n2) %s\n3) %s\n", message, option1, option2, option3);
        printf("\nYour chouce:\n> ");
        
        scanf("%s", choice);
        int intOption = atoi(choice);

        if(intOption > 0 && intOption < 4) {
            return intOption;
        
        } else {
            printf("Wrong input\n");
        }
        
    } while (1);
    
    // This never will happen
    return 0;

}



void askForCoinAtGui (CoinInfo * coin) {
    int coinAnswer = handleThreeOptionsMenu(
        "Select the coin that will be used by the machine",
        "Yen", "Dolar", "Euro");
    
    if (coinAnswer == 1) {
        selectCoin(Yen, coin);
    
    } else if (coinAnswer == 2) {
        selectCoin(Dolar, coin);

    } else if (coinAnswer == 3) {
        selectCoin(Euro, coin);
    
    } else {
        printf("Wrong coin\n");
    }
}



void handleMenu () {
    CoinInfo machineCurrentCointInfo = NULL;
    char * coinName = NULL;
    float moneyToChange = 0;
    
    askForCoinAtGui(&machineCurrentCointInfo);
    
    int machineMode = showTwoOptionsMenu("\n\nHow this machine works ?",
        "There is not a stock of coins.",
        "The machine will use a limited stock of coins.");
    
    
    printf("Machine mode: %d\n", machineMode);
    
    printf("Insert the amount of money to change:\n> ");
    scanf("%f",&moneyToChange);
    
    getCoinName(machineCurrentCointInfo, &coinName);
    
    printf("Ready to give the change of: %.2f [%s]\n", moneyToChange, coinName);

    
    vectorP solutionCoins = NULL;
    createVector(&solutionCoins, 5);
    
    if(machineMode == 1) {
        
        // This method gives the change of the moneyToChange value
        changeInf(5, moneyToChange, machineCurrentCointInfo,
            &solutionCoins, NULL);
        
        printCoins(solutionCoins, machineCurrentCointInfo);

    
    } else if (machineMode == 2) {
        short coinCoinsCount = 0;
        vectorP stockVector = NULL;
        
        getCointSize(machineCurrentCointInfo, &coinCoinsCount);
        createVector(&stockVector, (int) coinCoinsCount);
        readStock(machineCurrentCointInfo, &stockVector);
        
        printf("\nCurrent stock of [%s]\n2", coinName);
        printCoins(stockVector, machineCurrentCointInfo);
        
        printf("\nStock after the change operation:\n");
        printCoins(stockVector, machineCurrentCointInfo);
    
    }
}



int main(int argc, const char * argv[]) {
    
    handleMenu();
    
}


/*
int main(int argc, const char * argv[]) {
    CoinInfo dolarInfo;
    selectCoin(Dolar, &dolarInfo);
    

    
    // Getting stock
    printf("\n\nGetting stock: \n");
    int cointSize = 0;
    vectorP stock = NULL;
    
    printf("Vector size %d\n", cointSize);
    createVector(&stock, cointSize);
     readStock(dolarInfo, &stock);
    //printVect(stock);

    float toChange = 1.25;
 
     printf("\nResulting change of %.2f\n\n", toChange);
     printCoins(solutionCoins, dolarInfo);
    
    // printf("\nStock after change\n\n");
    // printVect(stock);
    
    return 0;
}
 */




