
typedef enum {
    Euro,
    Yen,
    Dolar
} CoinType;


typedef struct {
    CoinType coinType;
    short coinCount;
    int stock;
    float * availableCoins;
    char * coinName;
} * CoinInfo;


void selectCoin (CoinType coinType, CoinInfo * userCoin);

void getSpecificCoin (int index, CoinInfo coinInfo, float * coinContainer);

int changeInf(int n, float changeQuantity, CoinInfo coinInfo, vectorP * solutionCoins, vectorP * stock);

void getCointSize (CoinInfo coinInfo, short * cointSize);

void getCoinType (CoinInfo coinInfo, CoinType * coinType) ;

void readStock(CoinInfo coin, vectorP * stock);

void getCoinName (CoinInfo coinInfo, char ** _coinName);

void printCoins(vectorP coins, CoinInfo info);