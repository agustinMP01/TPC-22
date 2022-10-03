/*
Dulces:
    dp[i] = max(dp[i+1], dp[i+2] + a_i) -> dp para cada fila individual

    De ahi, tenemos soluciones intercaladas

    dp sobre la dp anterior

    dp[n] = dp[n+1] = 0

    Se ve de atras hacia delante
*/