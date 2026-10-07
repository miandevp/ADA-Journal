#include<iostream>
#include<vector>

using namespace std;


// Este algoritmo es de O(log n)
// por que debemos buscar en la mitad,  el valor a buscar 
// va a ser entre el rango de 1 y n 
// entonces asegura que el valor a buscar se encuentra en la mitad del rango,
// o al final del arreglo


//EJMPLO
// 1 2 3 0 1 2 3 4            podemos elegir ente valor 1 a 4 para ecntonrar
int BuscarSemiCompacto(vector<int> A, int l, int r,int x){

    // base si el tamaño del arreglo es 0, no hay nada que buscar
    if(l>r){
        return -1;
    }

    // com prioridad es buscar en la mitad
    int q = (l+r)/2;

    // x = 3
    // 1 2 3 0 1 2 3 4
    // 0 1 2 3 4 5 6 7
    // l     q       r
    // q = 3 

    if(A[q] == x){
        return q;
    }

    if(A[q] > x){

        return BuscarSemiCompacto(A,l,q-1,x);
    }
    else{
        return BuscarSemiCompacto(A,q+1,r,x);
    }

    
}

int main(){

    vector<int> A = {1,2,3,0,1,2,3,4};

    cout << BuscarSemiCompacto(A,0,7,3) << endl;

    return 0;

}
