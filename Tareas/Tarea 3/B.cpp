#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    //Son t casos, entonces loopeamos t veces
    for (;t>0;t--){
        int n;
        cin>>n;
        int a[n];

        //Lleno la lista
        for (int i = 0; i<n; i++){
            cin >> a[i];
        }

        //Array para guardar los puntajes
        int res[n];

        //Caso base, el ultimo SIEMPRE se pasara, entonces su puntaje siempre es lo que esta en su indice
        res[n-1] = a[n-1];

        for (int i = n-2; i>=0; i--){
            int index = i;
            index += a[i];

            //Si i + a_i se pasó, entonces su valor es lo que está en su indice
            if (index > (n-1)) {
                res[i] = a[i];
            }
            //Si no se pasó, su valor ya fue calculado y es lo que está en su indice + lo que está donde cayó
            else{
                res[i] = a[i] + res[index];
            }
        }

        //Ordenamos los resultados para sacar el maximo
        sort(res,res+n);
        cout << res[n-1] << "\n";
    }

}
