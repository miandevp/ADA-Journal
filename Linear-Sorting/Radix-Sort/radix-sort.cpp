#include<iostream>


using namespace std;

// couting sort modificado para radix con exp
int* countingSort(int A[], int n, int exp){
    int k = 9;
    int* B = new int[n];
    int* C = new int[k+1];

    for(int i = 0; i < k+1; i++){
        C[i] = 0; 
    }

    // asi en ves de tener [802,34,1234] tedriamos con 
    // exp = 1 [2,4,4]
    // exp = 10 [0,3,3]
    // exp = 100 [8,0,2]
    // exp = 1000 [0,0,1]
    // cabe recalcar que si es 0 tmabien se agregan por el modulo de 8%10 es = 0
    for(int j = 0; j < n; j++){
        int digito = (A[j]/exp)%10;
        C[digito]++;
    }

    for(int l = 1 ; l < k+1; l++){
        C[l] = C[l] + C[l-1];
    }

    // aqui modificamos par adevolver no un arry ordenador  [2,4,4] sino ya valores 
    //ordenados como el A[m] = [34,802,1234]

    for(int m = n-1 ; m >= 0 ; m--){
        int digito = (A[m]/exp)%10;
        B[C[digito]-1] = A[m];
        C[digito]--; 
    }

    return B;

}

void radixSort(int Arr[], int n){ 

    int max = Arr[0];

    // metemos en max el numero mas grande y por lo tanto con mas digitos
    for(int i = 0; i < n; i++){
        if (Arr[i] > max){
            max = Arr[i];
        }
    }

    int d = 0;
    // guardamos en la cantidad de digitos que tine este numero 
    while(max > 0){
        d++;
        max /= 10;
    }

    // inicio de algoritmo de radix
    int exp = 1;

    for(int j = 0; j < d; j++){
        int* B = countingSort(Arr,n,exp);
        exp *= 10;
    
        for(int k = 0; k < n ; k++){
            Arr[k] = B[k];
        }

    }

}

void imprimir(int* B, int n){
    for(int i = 0; i < n; i++){
        cout << B[i] << " ";
    }

}

int main(){

    int Arr[] = {170,45,75,90,802,24,2,66};
    
    radixSort(Arr,8);
    imprimir(Arr,8);


    return 0;
}
