#include<iostream>
#include<vector>

using namespace std;


int Partition(vector<int> & A,int l ,int r){
    int pivote = A[r];
    int i = l-1;

    for(int j = l; j < r;  j++){
        if(A[j] <= pivote){
            i++;
            swap(A[i],A[j]);
        }

    }

    swap(A[i+1],A[r]);
    return i+1;
}


void Quicksort(vector<int> & A, int l , int r){

    if(l<r){
        int q  = Partition(A,l,r);

        Quicksort(A,l,q-1);
        Quicksort(A,q+1,r);

    }
}

int main(){

    vector<int> A = {2,6,3,4,8,5,9};

    Quicksort(A,0,A.size()-1);

    for(int i = 0;i< A.size();i++){
        cout << A[i] << endl;
    }

}