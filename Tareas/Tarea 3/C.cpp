/*
Tortuga:
    dp[posicion en la linea][posicion en el string][caracteres cambiados][direccion]: Representa estados
    queremos buscar cual es la distancia maxima que podemos alcanzar dado que estamos en este estado

    Tengo 3 opciones, hacer caso al string: me muevo en el string
                      cambiar caracter: 
                      cambiar 2 veces el caracter y no hacer nada
    
    casos bordes dp[x][|s|][n][y] = abs(x)
                 dp[x][|s|][z<n][y] = no nos sirve -1000

    maximo entre las 3 opciones

    recursion para cada caso, o sea, tenemos que llenar nuestra DP usando recursión.
    Para cada posicion calcularle sus 3 casos posibles, calcular el maximo y ese maximo se queda en la dp
    if(s[posicion string] = T)
        dp[i][j+1][k][l^1]
    else
        if(l=0)
            dp[i+1][j+1][k][l]
        else
            dp[i-1][j+1][k][l]
    if(k>=2)
        dp[i][j][k-2][l]                             
*/