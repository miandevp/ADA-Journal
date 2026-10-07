#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mochila(vector<int>& valores, vector<int>& pesos, int n, int W) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    //  
    //   n = 4;
    //   w = 5;
    //   vi = [4,5,2,8];
    //   wi = [2,2,1,3];
    //           0 1 2 3 4 5   == capacidades de la tbaal desde peso 0 a peso w
    //    dp = [[0,0,0,0,0,0]  -> articulo 0
    //          [0,0,0,0,0,0]  -> articulo 1
    //          [0,0,0,0,0,0]  -> articulo 2
    //          [0,0,0,0,0,0]  -> articulo 3
    //          [0,0,0,0,0,0]] -> articulo 4
    //
    //          
    //
    //
    //
    //
    //
    //
    //
    //


    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (pesos[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    valores[i - 1] + dp[i - 1][w - pesos[i - 1]]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

    //    i = 1
    //   vi = [4,5,2,8];
    //   wi = [2,2,1,3];
    //           0 1 2 3 4 5   == capacidades de la tabla desde peso 0 a peso w
    //    dp = [[0,0,0,0,0,0]  -> articulo 0 --- no usado
    //          [0,0,4,4,4,4]  -> articulo 1   aquiestamos con un articulo que se puede meter una es pues solo podemos meter cunado la capidad nos lo pida y su vlaor es 4
    //          [0,0,0,0,0,0]  -> articulo 2   
    //          [0,0,0,0,0,0]  -> articulo 3
    //          [0,0,0,0,0,0]] -> articulo 4



        //    i = 2
    //   vi = [4,5,2,8];
    //   wi = [2,2,1,3];
    //           0 1 2 3 4 5   == capacidades de la tabla desde peso 0 a peso w
    //    dp = [[0,0,0,0,0,0]  -> articulo 0 --- no usado
    //          [0,0,4,4,4,4]  -> articulo 1   
    //          [0,0,5,5,9.,9]  -> articulo 2   aqui estamos,    
    //          [0,0,0,0,0,0]  -> articulo 3
    //          [0,0,0,0,0,0]] -> articulo 4

    //    i = 3
    //   vi = [4,5,2,8];
    //   wi = [2,2,1,3];
    //           0 1 2 3 4 5   == capacidades de la tabla desde peso 0 a peso w
    //    dp = [[0,0,0,0,0,0]  -> articulo 0 --- no usado
    //          [0,0,4,4,4,4]  -> articulo 1   
    //          [0,0,5,5,9,9]  -> articulo 2   aqui estamos,    
    //          [0,2,5,7,9,11]  -> articulo 3
    //          [0,0,0,0,0,0]] -> articulo 4

        //    i = 4
    //   vi = [4,5,2,8];
    //   wi = [2,2,1,3];
    //           0 1 2 3 4 5   == capacidades de la tabla desde peso 0 a peso w
    //    dp = [[0,0,0,0,0,0]  -> articulo 0 --- no usado
    //          [0,0,4,4,4,4]  -> articulo 1   
    //          [0,0,5,5,9,9]  -> articulo 2   aqui estamos,    
    //          [0,2,5,7,9,11]  -> articulo 3
    //          [0,2,5,8,10,13]] -> articulo 4



int main() {
    int n, W;
    cin >> n >> W;

    vector<int> valores(n);
    vector<int> pesos(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i] >> pesos[i];
    }

    cout << mochila(valores, pesos, n, W) << endl;

    return 0;
}