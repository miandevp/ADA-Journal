#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mochilaInversa(vector<int>& valores, vector<int>& pesos, int n, int W) {

    int maxValor = 0;

    for(int i = 0 ; i < n; i++){
        maxValor += valores[i];
    }

    vector<vector<int>> dp(n+1, vector<int>( maxValor + 1,1000000000));

    for(int i = 0; i <= n; i++){

        dp[i][0] = 0;

    }

    for(int i = 1; i <= n ; i++){
        for(int v = 0; v <= maxValor; v++){

            dp[i][v] = dp[i-1][v];

            if(valores[i-1] <= v){

                dp[i][v] = min(dp[i-1][v], pesos[i-1] + dp[i-1][v-valores[i-1]] );
            }


        }
    }

    int res = 0;

    for(int v  = 0; v<= maxValor; v++){
        if(dp[n][v] <= W ){
            res = v;
        }

    }

    return res;


}


int main() {

    vector<int> valores = {
        4, 5, 2, 8
    };

    vector<int> pesos = {
        2, 2, 1, 3
    };

    int n = valores.size();
    int W = 5;

    cout << "Respuesta: "
         << mochilaInversa(valores, pesos, n, W)
         << endl;

    return 0;
}
