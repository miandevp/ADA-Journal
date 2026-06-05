#include<iostream>


using namespace std;


int* countingSort(int A[], int n){
    int k = 5;
    int* B = new int[n];
    int* C = new int[k+1];

    for(int i = 0; i < k+1; i++){
        C[i] = 0; 
    }

    for(int j = 0; j < n; j++){
        C[A[j]]++;
    }

    for(int l = 1 ; l < k+1; l++){
        C[l] = C[l] + C[l-1];
    }

    for(int m = n-1 ; m >= 0 ; m--){
        B[C[A[m]]-1] = A[m];
        C[A[m]]--; 
    }

    return B;
}

void imprimir(int* B, int n){
    for(int i = 0; i < n; i++){
        cout << B[i] << " ";
    }

}

int main(){

    int Arr[] = {2,4,5,3,1,2,3,5};

    int* B;

    B = countingSort(Arr, 8);
    
    imprimir(B,8);


    return 0;
}
