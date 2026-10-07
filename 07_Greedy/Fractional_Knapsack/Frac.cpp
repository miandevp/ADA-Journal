#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
    int valor, peso;
};

double greedy(vector<Objeto> a, int capacidad) {

    // La decision greedy se encuentra en este sort, ya que
    // se elige el objeto con mayor valor por unidad de peso
    // para maximizar el valor total que se puede llevar en la mochila.
    sort(a.begin(), a.end(), [](Objeto a, Objeto b) {
        return (double)a.valor / a.peso > (double)b.valor / b.peso;
    });

    double res = 0;

    for (Objeto x : a) {
        if (capacidad >= x.peso) {
            res += x.valor;
            capacidad -= x.peso;
        } else {
            res += (double)x.valor / x.peso * capacidad;
            break;
        }
    }

    return res;
}

int main() {
    vector<Objeto> a = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    cout << greedy(a, 50);
}