#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int rodCutting(vector<int> A, int l){

    int n = A.size()-1;

    vector<int> T(n+1);

    T[0] = 0;

    for(int k = 1 ; k <= n; k++){
        int max = INT_MIN;
        for(int i = 0; i <= k; i++){
            if(A[i] + T[k-i] > max){
                max = A[i] + T[k-i];
            }

        }

        T[k] = max;
    }

    return T[l];
}

int main(){

    vector<int> A = {1,5,8,9};

    int q = rodCutting(A,3);
    
    cout << q;

    return 0;
}