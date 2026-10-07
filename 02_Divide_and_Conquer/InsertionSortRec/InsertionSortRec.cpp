#include <iostream>

using namespace std;

// InsertionSortBasico sin recurisvidad 
// LEER README PARA ENTENDER FUNIONALIDADES DE AMBOS NORMAL Y RECURSIVO
void InsertionSort(int A[] , int n){
    
    for (int i =2 ; i<= n; i++){

        int key = A[i];
        int j = i-1;


        while(j>0 && A[j]>key){

            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

    return;
}

void InsertionSortRec(int A[], int n){



    
    return;
}