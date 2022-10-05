#include <bits/stdc++.h>

using namespace std;

/*
Funciona en todos los casos, excepto el 6 y no tengo idea
Runtime error

*/
int main(){
    int n;

    cin >> n;

    //vector<int> nums[n];
    //vector< vector<int> > dp(n, vector<int>(n));

    int nums[n];
    int dp[n][n][2]; //Matriz de estados, [i][j][jugador]

    //Llenamos los numeros a jugar
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //Inicializamos los casos bases (diagonal de la dp)
    for (int i = 0; i < n; i++){
        dp[i][i][0] = nums[i];
        dp[i][i][1] = 0;
    }

    //Rellenamos la dp
    //dif es la diferencia entre i y j
    for (int dif = 1; dif < n; dif++){ //Calcula solo hasta los ultimos 2 casos, el cacho derecho superior no lo calcula
        for (int i = 0; i < n-dif; i++){
            int j = i + dif;

            //Puntaje del primer jugador
            dp[i][j][0] = max(dp[i+1][j][1] + nums[i], dp[i][j-1][1] + nums[j]);

            //Dependiendo de que caso me conviene, el jugador 2 elije
            if (dp[i][j][0] == dp[i+1][j][1] + nums[i]){
                dp[i][j][1] = dp[i+1][j][0];
            } 
            else if (dp[i][j][0] == dp[i][j-1][1] + nums[j]){
                dp[i][j][1] = dp[i][j-1][0];
            }
        }
    }

    //Calcular el ultimo valor independientemente
    dp[0][n-1][0] = max(dp[0+1][n-1][1] + nums[0], dp[0][n-2][1] + nums[n-1]);

    if (dp[0][n-1][0] == dp[0+1][n-1][1] + nums[0]){
        dp[0][n-1][1] = dp[0+1][n-1][0];
    } 
    else if (dp[0][n-1][0] == dp[0][n-2][1] + nums[n-1]){
        dp[0][n-1][1] = dp[0][n-2][0];
    }
    
    cout << dp[0][n-1][0] << "\n";
    return 0;
}