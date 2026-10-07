#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(int n, vector<int>& monedas, int m) {

    vector<int> dp(n + 1, 1000000000);

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {

        for(int j = 0; j < m; j++) {

            if(monedas[j] <= i) {
                dp[i] = min(dp[i],
                             1 + dp[i - monedas[j]]);
            }
        }
    }

    return dp[n];
}

int main() {

    int n = 55;
    int m = 4;

    vector<int> monedas = {1, 5, 10, 50};

    cout << "Respuesta: "
         << coinChange(n, monedas, m)
         << endl;

    return 0;
}