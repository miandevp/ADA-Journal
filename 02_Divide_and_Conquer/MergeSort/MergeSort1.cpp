#include<iostream>
#include<vector>


using namespace std;

void Merge(vector<int> &A, int p, int q, int r){

    int n1 = q - p + 1;
    int n2 = r - q;

    
    vector<int> L(n1+1);
    vector<int> R(n2+1);

    for(int i = 0; i < n1 ; i++){
        L[i] = A[p+i];
    }
    for(int j = 0; j < n1 ; j++){
        R[j] = A[q+1+j];
    }

    L[n1] = 999999999;
    R[n2] = 999999999;


    int i = 0;
    int j = 0;

    for(int k = p; k <= r ; k++){
        if(L[i] <= R[j]){

            A[k] = L[i];
            i++;

        }else{
            A[k] = R[j];
            j++;
     }
    }


}

void Merge_Sort(vector<int> &A, int p,int r){

    if( p < r){
        int q  = (p + r)/2;

        Merge_Sort(A,p, q);
        Merge_Sort(A,q+1, r);
        Merge(A,p,q,r);

    }
}



int main(){

    vector<int> A = {2,6,9,3,1,7,10};

    Merge_Sort(A,0,A.size()-1);

    for(int  i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }

}