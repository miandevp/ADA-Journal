#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximaSuma(vector<int>& a) {

    // entra a = [-2,1-3,4,-1,2,1,-5,4]


    // DP:
    // dp[i] = máxima suma de un subarray
    //         que termina exactamente en la posición i.
    int n = a.size(); // n = cantidad de elementos

    vector<int> dp(n); // me genera el dp = [0,1,2,3,4,...,n-1]

    // Primer estado; el primero elemento es 0 en  dp = [0,0,0,0,...,0]
    dp[0] = a[0];

    // Calculamos todos los estados DP
    for (int i = 1; i < n; i++) {

        // Podemos:
        // 1. Empezar un nuevo subarray en a[i]
        // 2. Continuar el subarray que terminaba en i-1
        dp[i] = max(a[i], dp[i - 1] + a[i]);

        // entra a = [-2,1-3,4,-1,2,1,-5,4]

        // i = 1  ,   max(1,-1)    ->    dp = [-2,1,0,0,...,0] 
        // i = 2  ,   max(-3,-2)    ->    dp = [-2,1,-2,0,...,0] 
        // i = 3  ,   max(4,2)    ->    dp = [-2,1,-2,4,...,0] 
        // i = 4  ,   max(-1,3)    ->    dp = [-2,1,-2,4,3,...,0] 
        // i = 5  ,   max(2,5)    ->    dp = [-2,1,-2,4,3,5,...,0] 
        // i = 6  ,   max(1,6)    ->    dp = [-2,1,-2,4,3,5,6,...,0] 
        // i = 7  ,   max(-5,1)    ->    dp = [-2,1,-2,4,3,5,6,...,0] 
        // i = 8  ,   max(4,5)    ->    dp = [-2,1,-2,4,3,5,6,5,0]
    }

    // Buscamos el máximo de todos los estados DP
    int mejor = dp[0];

    for (int i = 1; i < dp.size(); i++) {
        mejor = max(mejor, dp[i]);
    }

    return mejor;
}

int main() {

    // Nuestro array de ejemplo
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Respuesta: " << maximaSuma(a) << endl;

    return 0;
}