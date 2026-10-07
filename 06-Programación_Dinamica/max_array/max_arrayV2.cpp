#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximaSuma(vector<int>& A) {
    int n = A.size();

    vector<int> dp(n);

    dp[0] = max(A[0], 0);

    for(int i = 1; i < n; i++) {
        dp[i] = max(A[i] + dp[i-1], 0);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {

    vector<int> A = {-2, 3, -1, 5, -4};

    cout << "Respuesta: " << maximaSuma(A) << endl;

    return 0;
}