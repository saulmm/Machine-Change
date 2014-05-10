


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
        printf("\nYour chouce:\n> ");
        
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                return 1;
                break;
                
            case '2':
                return 0;
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
    
    switch (coinAnswer) {
        case Dolar:
            selectCoin(Dolar, coin);
            break;
            
        case Euro:
            selectCoin(Euro, coin);
            break;
            
        case Yen:
            selectCoin(Yen, coin);
            break;
            
        default:
            printf("Wrong coin\n");
            break;
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
    
    
    printf("Insert the amount of money to change:\n> ");
    scanf("%f",&moneyToChange);
    
    getCoinName(machineCurrentCointInfo, &coinName);
    
    printf("Ready to give the change of: %.2f [%s]\n", moneyToChange, coinName);
    
    
    if(machineMode == 1) {
        printf("\nNo coins limitation mode selected...\n");
    
    } else if (machineMode == 2) {
        printf("\nCoins stock limitation selected...\n");
    
    }
}



int main(int argc, const char * argv[]) {
    
    handleMenu();
    
}


/*
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
 */




