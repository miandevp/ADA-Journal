#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {

    
    // Tu solución aquí+
    int n = nums.size();

    vector<int> dp(n);

    dp[0] = nums[0];

    for(int i = 1; i < n; i++){

        dp[i] = max(nums[i], dp[i-1] + nums[i] );

    }

    int max_ = dp[0];

    for(int i = 1 ; i < n ;i++){
        max_ = max(max_,dp[i]);

    }

    return max_;
}



int main() {

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums) << endl;

    return 0;
}