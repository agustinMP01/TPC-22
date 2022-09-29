#include <bits/stdc++.h>

using namespace std;

/*Buscar posiciones malas, si hay alguna mala instantaneamente intercambiar, pues si no se puede con un cambio,
no se podrá nunca.

Buscar 2 posiciones erroneas e intercambiarlas, si aun asi no es correcto, no se puede.

Tomar la grilla y ordenando por filas, luego comparamos cada fila con us fila ordenada (En este caso, no se encontró
la segunda posicion erronea)

Recorremos la columna i e INTERCAMBIAMOS las posiciones a y b (A[i][a] <-> A[i][b])

Conviene ordenar con un sort y guardar la grilla ordenada para comparar despues.

Una vez cambio columnas, debo volver a revisar para checkear si todo está bien.

Una fila con mas de 3 erroneos nunca se podrá ordenar.
*/ 

//Aux que checkea elemento x elemento si 2 matrices son iguales
//Fallo al declarar los arg
/* int equals(int A[n][m], int B[n][m]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(A[i][j] != B[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
//Aux que printea un arrray 2d
//Fallo al declarar los arg

*/

int main(){

    int t;

    cin >> t;

    while(t>0){
        int n;
        int m;

        cin >> n;
        cin >> m;

        int A[n][m];
        int cA[n][m];

        //Llenamos la matriz
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j <  m; ++j){
                cin >> A[i][j];
                cA[i][j] = A[i][j];
            }
        }

        //Sorteamos la matriz copia.
        for(int i = 0; i < n ; ++i) {
            sort(cA[i],cA[i] + m);
        }


        bool found = false;
        bool done = false;

       //Buscamos los 2 primeros errores comparando con cA y swapeamos
        int error1 = 0;
        int error2 = 0;
        for (int i = 0; i < n; ++i) {

            if (done){
                break;
            }
            else for (int j = 0; j < m; ++j) {
                if(A[i][j] != cA[i][j] && !found){
                    error1 = j;
                    found = true;
                }
                else if (A[i][j] != cA[i][j] && found){
                    error2 = j;
                    done = true;
                    break;
                }
            }
        }
        if(done){
            for (int i = 0; i < n; ++i){
                swap(A[i][error1],A[i][error2]);
            }
        }

        /*Print de array.
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < m; ++j) {
                cout << A[i][j];
            }
        }
*/
        //Checkeo que sean iguales
        bool equals = true;
        for (int i = 0; i < n; ++i) {

            if(!equals){
                break;
            }
            for (int j = 0; j < m; ++j) {
                if (A[i][j] != cA[i][j]){
                    cout << -1 << "\n";
                    equals = false;
                    break;
                }
            }
        }

        if (equals){
            cout << error1 + 1 << " " << error2 + 1 << "\n";
        }
    t--;
    }
    return 0;
}