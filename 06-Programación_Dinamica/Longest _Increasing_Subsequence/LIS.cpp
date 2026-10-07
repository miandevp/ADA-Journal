#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> A) {

    int n = A.size();

    vector<int> L(n, 1);

    for (int k = 0; k < n; k++) {

        for (int i = 0; i < k; i++) {

            if (A[i] < A[k]) {
                L[k] = max(L[k], L[i] + 1);
            }
        }
    }

    // Buscar el máximo con un for
    int respuesta = 0;

    for (int k = 0; k < n; k++) {
        if (L[k] > respuesta) {
            respuesta = L[k];
        }
    }

    return respuesta;
}

int main() {

    vector<int> A = {10, 22, 9, 33, 21, 50, 41, 60};

    cout << "LIS = " << LIS(A) << endl;

    return 0;
}