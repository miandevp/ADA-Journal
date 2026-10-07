#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int rod(vector<int> &p, int n){

    vector<int> dp(n+1);

    dp[0] = 0;

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], p[j-1] + dp[i-j]);
        }
    }

    return dp[n];
    
}

int main() {

    vector<int> p = {2, 5, 7, 8, 10};


    int q = rod(p,p.size());

    cout << q;

    return 0;
}