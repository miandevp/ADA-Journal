#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int mochila(vector<int> &v, vector<int> &wi, int W,int n){

    vector<vector<int>> dp(n+1, vector<int> (W+1,0));

    for(int i =1; i<= n;i++){
        for(int w = 0; w <= W; w++){
            if(wi[i-1] <= w){
                dp[i][w] = max(dp[i-1][w],v[i-1]+ dp[i-1][w-wi[i-1]]);
            }else{
                dp[i][w] = dp[i-1][w];

            }

        }
    }

    return dp[n][W];


}


int main() {

    vector<int> pesos = {
        2, 3, 4, 5, 6, 7, 8, 9
    };

    vector<int> valores = {
        6, 10, 12, 15, 18, 20, 22, 25
    };

    int W = 20;

    int resultado = mochila(
        valores,
        pesos,
        W,
        pesos.size()
    );

    cout << resultado;


    return 0;
}