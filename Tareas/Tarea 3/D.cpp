/*
Sapo y sepo:
    Si los extremos son iguales, los pasos para resolver lo de dentro es lo mismo que la solucion de todo
        1 323 1 es lo mismo que 323

    Tomar extremos, y revisar el intervalo de dentro
        1234554321 no sumo pasos
        23455432 no sumo pasos
        345543 no sumo pasos
        4554 no sumo pasos
        55 sumo 1 paso

        Si tengo segmento de tamaño 1 se elimina en 1 paso
        Si tengo segmento de tamaño 2 se comparan  


    Separar por "zonas" [][       ] -> [ ][      ] -> [   ][    ] -> ... ciclo for
    Posibles soluciones de DP:
        dp[i][j] = min(dp[i][i+1] + dp[i+2][j],
                        ... ciclo for,
                        dp[i][j-2] + dp[j-1][j])  
        en el caso a[i]==a[j]:  
            dp[i][j] = min(dp[i][j], dp[i+1][j-1])         

    CACHANDO PICO               
*/      