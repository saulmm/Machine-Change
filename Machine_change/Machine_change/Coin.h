
typedef enum {
    Euro,
    Yen,
    Dolar
} CoinType;


typedef struct {
    CoinType coinType;
    short coinCount;
    float* availableCoins;
    
} * CoinInfo;


void selectCoin (CoinType coinType, CoinInfo * userCoin);

void getSpecificCoin (int index, CoinInfo coinInfo, float * coinContainer);

int changeInf(int n, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins);
