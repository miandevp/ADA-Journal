#include<iostream>
#include<vector>

using namespace std;


// buscamo el k esimo elemnto de un array ordenado sin tneenr qu eordenarlo
// usando quicksort ya que si q del pivote no inidca en que posisicon quedari aal final
// y usamos la de busqueda binaria

int Partition(vector<int>& A, int l ,int r){

    int pivote = A[r];
    int i = l-1;

    for (int j = l; j < r; j++){
        if(A[j] <= pivote){
            i = i + 1;
            swap(A[i],A[j]);
        }
    }

    swap(A[i+1],A[r]);

    return i + 1;

}



int Quickselect(vector<int>& A, int l,int r, int k){

    int indice = k - 1;

    if(l==r){
        return A[l];
    }

    int q = Partition(A,l,r);

    if(q == indice){
        return A[q];
    }

    if (indice < q){
        return Quickselect(A,l,q-1,k);
    }else{
        return Quickselect(A,q+1,r,k);
    }
    


}


int main(){

    vector<int> A = {2,7,8,1,3,9,10};

    cout << Quickselect(A,0,6,4);
    
    return 0;
}