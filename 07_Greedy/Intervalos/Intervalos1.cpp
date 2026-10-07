#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Intervalo
{   
    int inicio,fin;
};


vector<Intervalo> greedy(vector<Intervalo> a){

    sort(a.begin(), a.end(), [](Intervalo a,Intervalo b){
        return a.fin < b.fin; 
    });

    vector<Intervalo> res;

    int fin = -1;

    for(auto x:a){
        if(x.inicio >= fin){
            res.push_back(x);
            fin = x.fin;
        }
    }

    return res;
}



int main(){

    vector<Intervalo> A = {{11,12},{2,7},{1,3},{5,8},{5,7},{3,6},{9,10},{4,5},{2,7},{7,8}};

    vector<Intervalo> res = greedy(A);

    for(int i = 0; i < res.size(); i++){
        cout << "( " << res[i].inicio << " , " << res[i].fin << " )";
    }

    return 0;
}