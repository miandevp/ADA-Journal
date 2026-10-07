#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Intervalo {
    int ini, fin;
};

vector<Intervalo> greedy(vector<Intervalo> a) {


    // La decision greedy se encuentra en este sort, ya que 
    // se elige el intervalo que termina primero para maximizar
    // la cantidad de intervalos que se pueden seleccionar.
    sort(a.begin(), a.end(), [](Intervalo a, Intervalo b) {
        return a.fin < b.fin;
    });

    vector<Intervalo> res;
    int fin = -1;

    for (Intervalo x : a) {
        if (x.ini >= fin) {
            res.push_back(x);
            fin = x.fin;
        }
    }

    return res;
}

int main() {
    vector<Intervalo> a = {
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 8},
        {8, 10},
        {9, 11}
    };

    vector<Intervalo> res = greedy(a);

    for (auto x : res)
        cout << "(" << x.ini << ", " << x.fin << ") ";
}