#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool Interleaving(string X, string Y, string Z) {

    int n = X.size();
    int m = Y.size();

    // Si los tamaños no coinciden, es imposible
    if (n + m != Z.size())
        return false;

    // dp[i][j]:
    // ¿Los primeros i caracteres de X
    // y los primeros j caracteres de Y
    // pueden formar los primeros i+j caracteres de Z?
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    // X = "abc";
    // Y = "def";
    // Z = "adbcef";
    // dp = [[0,0,0,0],
    //       [0,0,0,0]    
    //       [0,0,0,0]    
    //       [0,0,0,0]    
    //      ]

    // Caso base
    dp[0][0] = true;

    // dp = [[1,0,0,0],
    //       [0,0,0,0]    
    //       [0,0,0,0]    
    //       [0,0,0,0]    
    //      ]


    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= m; j++) {

            int k = i + j - 1;

            // Tomar el carácter de X
            if (i > 0 && X[i - 1] == Z[k]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }

            // Tomar el carácter de Y
            if (j > 0 && Y[j - 1] == Z[k]) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }

            // i = 0
            // con X = "" y Y = d , e,f,
            // X = "abc";
            // Y = "def";
            // Z = "adbcef"; aqui z es a po rende con ningun y dale en 0,j 
            // dp = [[1,0,0,0], quedaria todo 0
            //       [0,0,0,0]    
            //       [0,0,0,0]    
            //       [0,0,0,0]    
            //      ]


            // i = 1
            // con X = "a" , Y = d,de,def
            // X = "abc";
            // Y = "def";
            // Z = "adbcef"; aqui z es a po rende con ningun y dale en 0,j 
            // dp = [[1,0,0,0], 
            //       [1,1,0,0]  estamos aqui
            //       [0,1,0,0]    
            //       [0,0,0,0]    
            //      ]

            // i = 2
            // con X = "ab" , Y = d,de,def
            // X = "abc";
            // Y = "def";
            // Z = "adbcef"; aqui z es a po rende con ningun y dale en 0,j 
            // dp = [[1,0,0,0], 
            //       [1,1,0,0]  
            //       [0,1,0,0]  estamos aqui  
            //       [0,0,0,0]    
            //      ]

            // i = 3
            // con X = "ab" , Y = d,de,def
            // X = "abc";
            // Y = "def";
            // Z = "adbcef"; aqui z es a po rende con ningun y dale en 0,j 
            // dp = [[1,0,0,0], 
            //       [1,1,0,0]  
            //       [0,1,0,0]  estamos aqui  
            //       [0,1,1,1]    
            //      ]


        
            // X = "";
            // Y = "d";
            // Z = "d";?
            // aunqu eel Z que busco sea = "adbcef"?



    }

    return dp[n][m];
}

int main() {

    string X = "abc";
    string Y = "def";
    string Z = "adbcef";

    cout << Interleaving(X, Y, Z) << endl;

    return 0;
}