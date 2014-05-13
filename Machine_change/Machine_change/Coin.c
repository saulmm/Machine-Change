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



const float EURO_COINS [8] = {2, 1, .5f, .2f, .1f, .05f, .02f, .01f};
const float YEN_COINS [5] = {500, 100, 50, 10, 5};
const float DOLAR_COINS [6] = {1, .5, .25, .1, .05, .01};


typedef enum {
    Euro,
    Yen,
    Dolar
    
} CoinType;

typedef enum {
    GET_STOCK,
    UPDATE_STOCK,
    CREATE_STOCK
    
} StockMode;


typedef struct {
    CoinType coinType;
    short coinCount;
    int stock;
    float * availableCoins;
    char * coinName;
    
} * CoinInfo;


void remove_newline_ch(char *line) {
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}


void selectCoin (CoinType coinType, CoinInfo* userCoin) {
    *userCoin = (CoinInfo) malloc(sizeof(CoinInfo));
    
    switch (coinType) {
        case Euro:
            (*userCoin) -> coinType = Euro;
            (*userCoin) -> availableCoins = (float*) &EURO_COINS;
            (*userCoin) -> coinCount = 8;
            
            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Euro";
            break;
            
        case Yen:
            (*userCoin) -> coinType = Yen;
            (*userCoin) -> availableCoins = (float*) &YEN_COINS;
            (*userCoin) -> coinCount = 5;
            
            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Yen";
            break;
            
        case Dolar:
            (*userCoin) -> coinType = Dolar;
            (*userCoin) -> availableCoins = (float*) &DOLAR_COINS;
            (*userCoin) -> coinCount = 6;
            
            (*userCoin) -> coinName = malloc(10 * sizeof(char));
            (*userCoin) -> coinName = "Dolar";
            break;
            
        default:
            printf("That coin doesn't exists\n");
            break;
    }
    
    printf("\nThe selected coin is: [%s]\n", (*userCoin) -> coinName);
}


void getSpecificCoin (int index, CoinInfo coinInfo, float * coinContainer) {
    *(coinContainer) = *((coinInfo) -> availableCoins + index);
}


void getCoinType (CoinInfo coinInfo, CoinType * coinType) {
    *(coinType) = ((coinInfo) -> coinType);
}


void getCointSize (CoinInfo coinInfo, short * cointSize) {
    *(cointSize) = ((coinInfo) -> coinCount);
}


void getCoinName (CoinInfo coinInfo, char ** _coinName) {
    *_coinName = ((coinInfo) -> coinName);
}


void getStock(CoinInfo coinInfo, vectorP * stock, StockMode stockManagement) {
    FILE * stockFile = NULL;
    
    char * currentLine = NULL;
    char * parseIntegerError = NULL;
    char * selectedCoinName = NULL;
    char * stockFileName = "/Users/wtf/Desktop/stock2.txt";
    
    int isReadingFlag = 0;
    int currentCoinStock = 0;
    int currentCoinPosition = 0;
    int correctCurrencyFlag = 0;
    
    int readAt = 0;
    int writeAt = 0;
    
    size_t lineLength = 0;
    
    stockFile = fopen(stockFileName, "r+");
    getCoinName(coinInfo, &selectedCoinName);
    
    
    if(stockFile != NULL) {
        // Read the stock file line by line
        while (isReadingFlag != -1) {
            
            // Only if theres is the UPDATE_STOCK mode activated the method will
            // store the current file cursor given by ftell at writeAt to seek before overwrite
            // the selected currency
            if(stockManagement == UPDATE_STOCK) {
                writeAt = (int) ftell(stockFile);
            }
            
            parseIntegerError = NULL;
            
            // Current line of the stock file
            isReadingFlag = (int) getline(&currentLine, &lineLength, stockFile);
            remove_newline_ch(currentLine);
            
            // parse the string into number, if fails, the error reason (string) is stored at parseIntegerError.
            currentCoinStock = (int) strtol(currentLine, &parseIntegerError, 10);
            
            // if there has been a problem trying to read the stock of the current currency means that
            // we are reading a currency name, if not means that is the current coin stock of the selected currency
            if (*parseIntegerError) {
                
                // if the comparaison is successfull i.e (Searching stock of Dolar)
                if(strcmp(selectedCoinName, parseIntegerError) == 0) {
                    correctCurrencyFlag = 1;
                    currentCoinStock = 0;
                    
                } else {
                    // if we reach2ed the correct currency return on GET_STOCK mode, if not continues reading the file
                    if (correctCurrencyFlag == 1) {
                        
                        if(stockManagement == GET_STOCK) {
                            return;
                            
                        } else {
                            correctCurrencyFlag = 0;
                        }
                    }
                }
                
                // This else means that we reading a coin quantity
            } else {
                if(correctCurrencyFlag == 1) {
                    if (stockManagement == UPDATE_STOCK) {
                        // Seek the cursor file to the last cursor position before read
                        fseek(stockFile, writeAt, SEEK_SET);
                        int stockValue= getValue(*stock, currentCoinPosition);
                        
                        // Overwrite the value
                        if(stockValue < 100 && stockValue > 10) {
                            fprintf(stockFile, "0%d\n", stockValue);
                     
                        } else if (stockValue < 10) {
                            fprintf(stockFile, "00%d\n", stockValue);
                     
                        } else {
                            fprintf(stockFile, "%d\n", stockValue);
                        }
                    }
                    
                    assignValue(stock, currentCoinPosition, currentCoinStock);
                    
                    // this integer stores the position of the current coin at the current currency, a.k.a number of line
                    // after a currency name.
                    currentCoinPosition ++;
                }
            }
        }
        printVect(stock);
    }
}


void printCoins(vectorP coins, CoinInfo info) {
    float currentCoin = 0;
    
    if (coins != NULL) {
        for (int i = 0; i < getSize(coins); i++) {
            getSpecificCoin(i, info, &currentCoin);
            printf("%d Coins x [%.2f]\n", getValue(coins, i), currentCoin);
        }
        
    } else {
        printf("[ERROR] The vector is not initialized.");
    }
}


int changeInf(int maxIterations, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins, vectorP * stock) {
    float changeAmount = 0, changeContainer = 0;
    int i = 0;
    short coinSize;
    
    getCointSize(coinInfo, &coinSize);
    
    while (changeAmount < changeQuantity && i < maxIterations) {
        if (i < coinSize)
            getSpecificCoin(i, coinInfo, &changeContainer);
        
        if (changeAmount + changeContainer <= changeQuantity) {
            incrementVect(solutionCoins, i);
            
            if(stock != NULL) {
                decrementVect(stock, i);
            }
            
            changeAmount += changeContainer;
            
        } else {
            i++;
        }
    }
    
    if(stock != NULL) {
        getStock(coinInfo, stock, UPDATE_STOCK);
    }
    
    return 0;
}

