/*
Dulces:
    dp[i] = max(dp[i+1], dp[i+2] + a_i) -> dp para cada fila individual

    De ahi, tenemos soluciones intercaladas

    dp sobre la dp anterior

    dp[n] = dp[n+1] = 0

    Se ve de atras hacia delante
*/ 
#include <bits/stdc++.h>

using namespace std;


int main(){
    int N, M;
    while(cin >> N >> M, N != 0){
        
        int dp_fila[M+2];
        int dp_final[N];
        int dulces[N][M];
        int final[N];

        //Lleno los dulces
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> dulces[i][j];
            }
        }

        //cout << "Me llené\n";
        
        dp_fila[M+1] = 0;
        dp_fila[M] = 0;

        for (int i = 0; i < N; i++){
            for (int j = M-1; j >= 0; j--){
                dp_fila[j] = max(dp_fila[j+1], dp_fila[j+2] + dulces[i][j]);
            }
            final[i] = *max_element(dp_fila,dp_fila+M+2);
        }

        for (int i = 0; i < N; i++){
            dp_final[i] = max(dp_fila[i+1], dp_fila[i+2] + final[i]);
        }
        

        cout << *max_element(dp_final,dp_final+N) << "\n";

    }
    return 0;
}