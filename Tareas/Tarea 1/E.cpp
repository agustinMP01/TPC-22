#include <bits/stdc++.h>

using namespace std;

/*
Co-primos.

Existe la funcion gcd() complejidad O(logn)

(5,9,2,10,15) comparamos 5,9 -> eliminamos 9 -> counter de eliminadas ++ -> comparamos 2,10... -> printeamos 
los eliminados en orden.

Usamos sets para guardar los "pares malos" adyacentes, por ej (5,9),(9,2). Ojo que si eliminamos un numero
el set de pares malos puede cambiar.

Debemos revisar si, luego de eliminar un numero en set, el nuevo par (5,2) es malo. Si lo es, lo agregamos al set 
de malos. Otro caso es que un numero del set esté en otro par, debemos revisar si el par (9,algo) esta en el set
y borrarlo pues el 9 fue usado en (5,9), para esto usamos myset.find(9) o myset.count(9). 

Notar que el set no trabaja con el par en si, si no con su indice (5,9) -> (0,1).

Si acabamos de borrar un par malo (a,b), ahora tenemos que encontrar cual es el siguiente par malo a borrar.
El sgte. par malo será set.lower_bound((a+1,0)) (un par mayor o igual a (a+1,0)). RECOMENDADO!!!

Obs: si set.lower_bound() retorna set.end() entonces no existe ningun par mayor o igual, por lo que debemos
hacer set.lower_bound() = set.begin().

Paramos de eliminar cuando el set de pares malos sea vacio -> while(set.size>0).
*/


int main(){

    return 0;
}