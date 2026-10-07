#include<iostream>
#include<vector>


using namespace std;

struct Edge{
    char a;
    char b;
    int valor;
};

// 1. (A,D) peso 1
// 2. (D,C) peso 2
// 3. (B,C) peso 3
// 4. (A,B) peso 4
// 5. (A,E) peso 5

vector<Edge> Kruskal(vector<Edge> G){
    for (int i  = 0; i < G.size(); i++){
            
    }


}


int main(){
    vector<Edge> m = {{'A','D',1},{'D','C',2},{'B','C',3},{'A','B',4},{'A','E',5}};


    return 0;
}