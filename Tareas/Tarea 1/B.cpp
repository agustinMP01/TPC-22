#include <bits/stdc++.h>

using namespace std;

/*
Cada numero me entrega un rango de posibilidades, pues necesito un piso e implicitamente se logra el rango
ej: [0,2,1,2] implicitamente es [1/n,2/a,3/b,4/c] y debemos encontrar n, a, b, c.

La idea es armar un vector con los rangos y ordenar, al ordenar un vector de tuplas queda de la forma
 <[i,n],[i+1,5],[i+5,7]>, es decir, ordena segun el inicio del rango.

 Debemos ademas guardar el indice de su rango, es decir (3,4,1) guarda el (inicio,fin,indice) es decir, el rango 
 [3,4] es para la posición 1 del vector de divisiones piso.

Si tenemos mas de una opcion, ocupamos la de menor distancia, ej: al pasar de 1 a 2, [1,8] es peor opcion que [2,3]

La idea es guardar los finales de rangos en un set, para comparar y encontrar el rango mas pequeño. Los meto al set
-> saco el mas pequeño -> limpio el set -> agrego los del siguiente rango (Si metí los [1,algo], ahora meto los 
[1,algo] sobrantes y meto los [2,algo]) -> elijo el mas pequeño...
*/


int main(){

    return 0;
}