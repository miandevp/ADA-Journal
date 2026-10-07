#include<iostream>
#include<vector>


using namespace std;

// ejmplo
// 1 2 3 4 5 6 8 9 10
// 0 1 2 3 4 5 6 7 8     aqui n = 8

// buscamo el menor valor entero qu eno aparezca en A, es decir valores_de_(A) < 10 para este caso


int BuscarMenorFaltante(vector<int> A, int l, int r){
    if (l>r){
        return -1;
    }

    int q = (l+r)/2;

    if(q == 0 && A[q] != 1){
    return 1;
    }

    if(A[q] - A[q-1] > 1){
        return A[q-1] + 1;
    }

    if(A[q] == q+1){
        return BuscarMenorFaltante(A,q+1,r);
    }else{
        return BuscarMenorFaltante(A,l,q-1);
    }
}


int main(){

    
    vector<int> A ={1,2,3,4,5,6,8,9,10};

    cout << BuscarMenorFaltante(A,0,8)<<endl;
}