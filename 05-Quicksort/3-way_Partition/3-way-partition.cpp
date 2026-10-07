#include<iostream>
#include<vector>

using namespace std;


void Partition3Way(vector<int>& A, int l, int r, int& lt, int& gt) {

    int pivot = A[r];

    lt = l;
    int i = l;
    gt = r;

    while (i <= gt) {

        // A = {3,6,1,2,9,6,4}

        // lt = 0
        // i = 0
        // gt = r

        // i = 0; A[i] = 3   -------------  3,6,1,2,9,6,4

        // lt = 1,i = 1,gt = 6

        // i = 1 ; A[i] = 6   ---------------  3,4,1,2,9,6,6 
        // lt = 1, i=1, gt = 5
    
        // i = 1; A[i] = 4 --------------    3,4,1,2,9,6,6
        // i = 2,lt = 1, gt = 5

        // i = 2 ; A[i] = 1 -------------  3,1,4,2,9,6,6
        // i=3 ; lt = 2 ; gt = 5
        
        // i = 3 ; A[i] = 2 ------------- 3,1,2,4,9,6,6
        // i = 4 ; lt = 3; gt = 5 

        // i = 4 ; A[i] = 9 --------------- 3,1,2,4,6,9,6
        // i = 4 ; lt = 3; gt = 4

        // i = 4 ; A[i] = 6 --------------- 3,1,2,4,6,9,6
        // i = 4 ; lt = 3 ; gt = 3


        if (A[i] < pivot) {
            swap(A[lt], A[i]);
            lt++;
            i++;
        }
        else if (A[i] == pivot) {
            i++;
        }
        else {
            swap(A[i], A[gt]);
            gt--;
        }
    }
}

void Quicksort(vector<int>& A, int l, int r) {

    if (l >= r)
        return;

    int lt, gt;

    Partition3Way(A, l, r, lt, gt);

    Quicksort(A, l, lt - 1);
    Quicksort(A, gt + 1, r);
}

int main(){

    vector<int> A= {3,6,1,2,9,6,4};

    Quicksort(A,0,A.size()-1);

    for(int i = 0 ; i< A.size(); i++){
        cout << A[i] << endl;
    }

    return 0;
}