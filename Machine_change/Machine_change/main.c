


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
        printf("\nYour choice:\n> ");
        
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

void askForMachineMode(short * machineMode) {
    *machineMode = showTwoOptionsMenu("\n\nHow this machine works ?",
        "There is not a stock of coins.",
        "The machine will use a limited stock of coins.");
    }


void askForChangeAmount (float * changeAmount, char * coinName) {
    char preChangeAmount[5];
    printf("\n Insert the amount of %s to change:\n> ", coinName);
    scanf("%f", changeAmount);
}


void handleMenu () {
    short machineMode = 0;
    float moneyToChange = 0;
    char * coinName = NULL;
    short coinCount = 0;
    
    CoinInfo machineCurrentCointInfo = NULL;
    vectorP solutionCoins = NULL;
    
    askForCoinAtGui(&machineCurrentCointInfo);
    getCoinName(machineCurrentCointInfo, &coinName);
    getCointSize(machineCurrentCointInfo, &coinCount);
    
    askForMachineMode(&machineMode);
    askForChangeAmount(&moneyToChange, coinName);
    

    createVector(&solutionCoins, coinCount);
    
    
    printf("\nReady to give the change of: %.2f [%s]\n", moneyToChange, coinName);
    
    if(machineMode == 1) {
        // This method gives the change of the moneyToChange value
        changeInf(1000, moneyToChange, machineCurrentCointInfo,
            &solutionCoins, NULL);
        
        printCoins(solutionCoins, machineCurrentCointInfo);

    
    } else if (machineMode == 2) {
        short coinCoinsCount = 0;
        vectorP stockVector = NULL;
        
        getCointSize(machineCurrentCointInfo, &coinCoinsCount);
        createVector(&stockVector, (int) coinCoinsCount);
        handleStock(machineCurrentCointInfo, &stockVector, GET_STOCK);
        
        printf("\nCurrent stock of [%s]\n", coinName);
        printCoins(stockVector, machineCurrentCointInfo);
        
        changeInf(1000, moneyToChange, machineCurrentCointInfo,
                  &solutionCoins, &stockVector);
        
        printf("\n\nChange of %.2f on [%s]\n", moneyToChange, coinName);
        printCoins(solutionCoins, machineCurrentCointInfo);
        
        printf("\nStock after the change operation:\n");
        printCoins(stockVector, machineCurrentCointInfo);
    
    }
}



int main(int argc, const char * argv[]) {
    handleMenu();
}



