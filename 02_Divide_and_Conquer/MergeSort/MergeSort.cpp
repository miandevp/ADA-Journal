#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    L[n1] = 999999999;
    R[n2] = 999999999;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {

        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& A, int p, int r) {

    if (p < r) {

        int q = (p + r) / 2;

        mergeSort(A, p, q);

        mergeSort(A, q + 1, r);

        merge(A, p, q, r);
    }
}

int main() {

    vector<int> A = {5, 2, 8, 1, 3, 7};

    mergeSort(A, 0, A.size() - 1);

    for (int x : A)
        cout << x << " ";

    return 0;
}