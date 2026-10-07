#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long rodCutting(int l, vector<long long>& p) {

    vector<long long> dp(l + 1, 0);



    // l = 5
    // p = [0, 2, 5, 7, 8, 10]
    //      
    // dp = [0,0,0,0,0,0] vector de tamaño l+1


    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], p[j] + dp[i - j]);
        }
    }

    return dp[l];
}

int main() {
    int l;
    cin >> l;

    vector<long long> p(l + 1);

    for (int i = 1; i <= l; i++) {
        cin >> p[i];
    }

    cout << rodCutting(l, p);

    return 0;
}