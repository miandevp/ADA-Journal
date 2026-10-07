#include<iostream>
#include<vector>
#include<math.h>
#include<climits>

using namespace std;


// EJEMPLO
// l     q     r
// 8 3 6 2 7 1 5     array
// 0 1 2 3 4 5 6     posiciones

// Q = 2 en posicion 3 


int Inversiones_centrada(vector<int>& A, int l ,int q,int r){
    
    int n1 = q - l + 1; // valores de l a q
    int n2 = r - q;     // valores de q+1 a r

    vector<int> L(n1);  // vector de tamaño n1
    vector<int> R(n2);  // vector de tamaño n2

    // Copiamos los valores de A a L  
    for (int i = 0; i < n1; i++) {    // Ejmplo: n1 = 4, i = 0,1,2,3
        L[i] = A[l + i];
    }

    // Copiamos los valores de A a R
    for (int j = 0; j < n2; j++) {    // Ejemplo: n2 = 3, j = 0,1,2
        R[j] = A[q + 1 + j];
    }
    

    // agregamo un centinela al final de cada vector para evitar desbordamiento
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    // reiniciamos contadores de los vectores L y R
    int i = 0;
    int j = 0;

    int total = 0; // contador de inversiones

    // vamos a recorrer el vector A desde l hasta r para ir comparando los valores de L y R
    // Ejmplo 
    // L(N1+1) = 8 3 6 2 
    // L0  es 8
    // R(N2+1) = 7 1 5
    // R0  es 7
    // comparamos L0 y R0, como L0 <= R0 


    // Recordemos que una inversión cumple dos condiciones:
    // i < j y A[i] > A[j]
    // Como L pertenece a la mitad izquierda y R a la derecha, i < j ya se cumple.
    // Solo debemos comparar los valores de L[i] y R[j].


    // L y R ya están ordenados.
    // Por eso no contamos cada inversión una por una:
    // aprovechamos el orden para contar varias inversiones de una vez.
    // guardmas el indice de L y el índice de R, y cuando encontramos que L[i] > R[j],
    // sabemos que todos los elementos restantes en L (desde i hasta n1) son mayores que R[j], 
    // por lo que podemos contar todas esas inversiones de una vez.

    for(int k = l ; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;                           // Si L[i] <= R[j], colocamos L[i].
            total += j ;               // Los elementos anteriores de R son menores que L[i] y forman inversiones.
                                           // Como usamos índices desde 0, hay j + 1 elementos anteriores.

        }else{
            
            A[k] = R[j];
            j++;
        }


    }

    return total;



}


int Inversiones(vector<int>& A, int l , int r){

    if (l == r) {
        return 0;
    }

    int q = floor(l+r)/2;

    int inv1 = Inversiones(A, l, q);
    int inv2 = Inversiones(A, q+1, r);
    int inv3 = Inversiones_centrada(A, l, q, r);

    return inv1 + inv2 + inv3;
}


vector<int> W = {8,3,6,2,7,1,5};

int main(){
    
    int n = W.size()-1;
    cout << Inversiones(W, 0, n) << endl;


}