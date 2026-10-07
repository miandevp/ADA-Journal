    #include<iostream>
    #include<vector>
    using namespace std;



    int MergeContandoInversiones(vector<int>& L, vector<int>& R){

        int i = 0;
        int j = 0;

        int total = 0; // contador de inversiones

        int n1 = L.size();
        int n2 = R.size();

        for(int k = 0; k < n1 + n2; k++){   //por ejemplo tengo dos vectores
                                        // L = 2 3 6 8
                                        // R = 1 5 7

            if(j == n2 ||L[i] <= R[j]){           // 12 comparaciones posibles entre L y R:
                                        // 2 con 1 -> inversión
                                        // 2 con 5 -> no
                                        // 2 con 7 -> no
                                        // 3 con 1 -> inversión
                                        // 3 con 5 -> no
                                        // 3 con 7 -> no
                                        // 6 con 1 -> inversión
                                        // 6 con 5 -> inversión
                                        // 6 con 7 -> no
                                        // 8 con 1 -> inversión
                                        // 8 con 5 -> inversión
                                        // 8 con 7 -> inversión
                                        // Total: 7 inversiones

                                        // Como L y R están ordenados, cuando L[i] <= R[j],
                                        // todos los elementos anteriores de R ya son menores que L[i]
                                        // y ya fueron contados como inversiones.
                                        // Los siguientes elementos de R serán mayores o iguales que L[i],
                                        // por lo que no forman nuevas inversiones con L[i].
                                        // Por eso, en vez de contar una por una, sumamos j,
                                        // que representa la cantidad de elementos anteriores de R.
                i++;
                total += j; // sumamos el número de elementos de R que ya han sido colocados en el arreglo final

                            // Entonces, ¿por qué sumamos j?
                            // Mientras encontramos inversiones, no hacemos total + 1.
                            // Dejamos que j aumente en 1 por cada elemento de R que resulta menor.
                            // Cuando L[i] <= R[j], j ya indica cuántos elementos de R fueron menores.
                            // Para este ejemplo , los valores que vamos sumando son 1 con i = 0, 1 con i =1, 2 con i = 2 y 3 con i = 3.
                            // Por eso obtenemos: 1 + 1 + 2 + 3 = 7 inversiones.
                            // No necesitamos hacer j + 1 porque j ya contiene la cantidad correcta.

            }else{
                j++;
            }

             if(i == n1)
             break;


        }
        return total;
    }

    int main() {

    vector<int> L = {2, 3, 6, 8};
    vector<int> R = {1, 5, 7};

    cout << MergeContandoInversiones(L, R) << endl;

    return 0;
}