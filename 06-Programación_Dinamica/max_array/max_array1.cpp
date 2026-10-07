#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximaSuma(vector<int>& a) {

    int n = a.size();

    vector<int> dp(n);

    dp[0] = a[0];

    for(int i = 1; i < n; i++ ){
        dp[i] = max(a[i], dp[i-1] + a[i]);
    }

    int res = dp[0];
    for(int j = 0; j < n ; j++){
        if(dp[j] > res){
            res = dp[j];
        }
    }

    
    return res;

}

int main() {

    vector<int> a = {
        -2, 1, -3, 4, -1, 2, 1, -5, 4
    };

    cout << "Respuesta: " << maximaSuma(a) << endl;

    return 0;
}