
typedef enum {
    Euro,
    Yen,
    Dolar
} CoinType;


typedef struct {
    CoinType coinType;
    float* availableCoins;
} *Coin;


void selectCoin (CoinType coinType, Coin* userCoin);

void getCoin (int index, Coin coinInfo);