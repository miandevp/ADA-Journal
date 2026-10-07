#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> mochilaIlimitada(
    vector<int>& valores,
    vector<int>& pesos,
    int W,
    int n
) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // 1. Calcular DP
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (pesos[i - 1] <= w) {

                dp[i][w] = max(
                    dp[i - 1][w],
                    valores[i - 1] + dp[i][w - pesos[i - 1]]
                );

            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 2. Reconstruir los objetos elegidos
    vector<int> secuencia;

    int i = n;
    int w = W;

    while (i > 0 && w > 0) {

        // Si el valor viene de arriba,
        // no usamos el objeto i
        if (dp[i][w] == dp[i - 1][w]) {
            i--;
        }
        else {
            // Usamos el objeto i
            secuencia.push_back(i);

            // Como es ilimitada, seguimos en la misma fila
            w -= pesos[i - 1];
        }
    }

    return {dp[n][W], secuencia};
}

int main() {

    vector<int> pesos = {1, 2};
    vector<int> valores = {7, 50};

    int W = 7;

    auto resultado = mochilaIlimitada(
        valores,
        pesos,
        W,
        pesos.size()
    );

    cout << "Valor maximo: " << resultado.first << endl;

    cout << "Indices elegidos: ";

    for (int indice : resultado.second) {
        cout << indice << " ";
    }

    return 0;
}