//
//  main.c
//  Machine_change
//
//  Created by Saúl on 06/05/14.
//  Copyright (c) 2014 Saúl. All rights reserved.
//

#include <stdio.h>

int cambio(int n, int x, int valor[],int solucion[]) {
    for (int i=0;i<n;i++)
        solucion[i] = 0;
    
    int i = 0, suma = 0;
    
    while (suma<x && i<n)
        if (suma + valor[i] <= x) {
            solucion[i]++;
            suma+=valor[i];
            
        } else
            i++;
    
    if (suma==x)
        return 1;
    
    else {
        for (int i=0;i<n;i++)
            solucion[i]=0;
        
        return 0;
    }
}


int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    
    int valor[5]= {50,25,20,5,1};
    int solucion[10] = {};
    
    cambio(5, 42, valor, solucion);

    
    for (int j = 0; j < 10; j++) {
        printf("Coin : %d\n", solucion[j]);
    }
    
    return 0;
}

