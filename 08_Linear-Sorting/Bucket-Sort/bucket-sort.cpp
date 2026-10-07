#include<iostream>

using namespace std;

struct Node{
    float valor;
    Node* next;
};


void bucketSort(float Arr[], int n, int numBuck){
    Node* bucket[numBuck];

    for(int i = 0; i < numBuck; i++){
        bucket[i] = nullptr;
    }

    for(int i = 0; i < n; i++){
        int indice = Arr[i]*numBuck;

        Node* nuevo = new Node;

        nuevo->valor = Arr[i];
        nuevo->next = nullptr;

        if(bucket[indice] == nullptr){
            bucket[indice] = nuevo;
        }else if(nuevo->valor < bucket[indice]->valor){
            nuevo->next = bucket[indice];
            bucket[indice] = nuevo;
        }else{
            Node* actual = bucket[indice];

            while(actual->next != nullptr && actual->next->valor < nuevo->valor){
                actual = actual->next;

            }

            nuevo->next = actual->next;
            actual->next = nuevo;

        }
    }

    int k = 0;

    for(int i = 0; i < numBuck; i++){
        Node* actual = bucket[i];

        while(actual != nullptr){
            Arr[k] = actual->valor;
            k++;
            actual = actual->next;
        }
    }


        for(int i = 0; i < numBuck; i++){

        Node* actual = bucket[i];

        while(actual != nullptr){

            Node* siguiente = actual->next;

            delete actual;

            actual = siguiente;
        }
    }
}

void imprimir(float* B, int n){
    for(int i = 0; i < n; i++){
        cout << B[i] << " ";
    }

}

int main(){

    float Arr[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.63};

    int n = 10;
    int numB = 10;

    bucketSort(Arr,n,numB);

    imprimir(Arr,10);

    return 0;
}