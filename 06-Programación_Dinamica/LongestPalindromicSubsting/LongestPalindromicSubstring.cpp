#include<string>
#include<vector>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();

    vector<vector<int>> DP(n, vector<int>(n, 0));

    int inicio = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        DP[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len - 1 < n; i++) {

            int j = i + len - 1;

            
            if (len == 2) {
                if (s[i] == s[j]) {
                    DP[i][j] = 1;
                }
            }

            else {
                if (s[i] == s[j] && DP[i + 1][j - 1]) {
                    DP[i][j] = 1;
                }
            }

            if (DP[i][j] && len > maxLen) {
                maxLen = len;
                inicio = i;
            }
        }
    }

    return s.substr(inicio, maxLen);
}