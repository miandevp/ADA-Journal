#include<iostream>
#include<vector>

using namespace std;

// Tengo un arreglo de tamaño n, con valores del 1 al n, pero falta un valor.
// Por ejemplo, si n = 5, el arreglo puede ser: 1 2 4 5, y el valor faltante es 3.
// La idea es usar la técnica de Divide y Vencerás para encontrar el valor faltante

// 1 2 3 4 5 6 8 9 10
// 0 1 2 3 4 5 6 7 8

int Buscar_Faltante(vector<int> A, int l, int r){

    // caso base
    if(l>r){
        return -1;
    }

    int q  =(l+r)/2;

    // primera
    // 1 2 3 4 5 6 8 9 10
    // l       q       r
    // 0 1 2 3 4 5 6 7 8

    //segunda
    // 6 8 9 10
    // l q    r
    // 5 6 7 8

    // tercera
    //  6 8
    // lq r
    //  5 6

    if ((A[q+1] - A[q] ) > 1 ){
        return A[q]+1;
    }

    if(A[q] == q + 1){
        return Buscar_Faltante(A,q+1,r);
    }else{
        return Buscar_Faltante(A,l,q-1);
    }

}

int main(){

    vector<int> A = {1,2,3,4,5,6,8,9,10};

    cout << Buscar_Faltante(A,0,8) << endl;

    return 0;
}