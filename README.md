### Requirements

The student has to develop a program that retruns a given quantity of money, focusing to minimize the number of coins to return.

The progam will allow this operation modes:

- __Infinite coins__, where is supposed to not be a limitation in the number of coins to return.

- __Limited coins__, where there is a limited number of coins of each type

### Steps to take

This program supports three diferent types of coins, yens, euros and dolar. The user will be asked by the program to choose one of this coins.

The program will ask for the operation mode, after that, the program will be asking quantities to return, (the user will introduce a 0 to exit), and the program will be showing the number of coins of each type to return.

For the case of 'infinite return coins' will be implemented by the next function:

```c
int change(int x, int value[n],int solution[n]) {
  for (int i=0;i<n;i++) 
    solution[i]=0;
  
  int i=0, sum=0;
  
  while (sum<x && i<n)
    if (sum + value[i] <= x) {
      solution[i]++; 
      sum += value[i]; 
  
    } else {
      i++;
    }

    if (sum==x) {
      return 1; 
    
    } else {
      for (int i=0; i < n; i++) {
        solution[i] = 0;
        return 0;
      }
    }
}
```

For the case of 'limited coins', the program has to manage the stock of available coins tn the machine, to manage that:

 At the start of the program, after the 'limited coins' operation mode has been selected, the program will read of a **file** the number of coins availabes of each type. 
 
 In this case, after show to the user the amount of coins at the change, will be shown information about the stage of the stock of the selected type of coin (euro/yen/dolar), after the change operation.
 
 In the main menu will be an option to update the stock by the user always that the 'limited coins' mode is selected, in this option, the user will be asked to insert the number of coins to insert in stock, i.e: How many coins of 2€, How many coins of 1€ and so on...
 
 
 ** Remember that is a greedy strategy, that means that there is not always the best solution.
 
