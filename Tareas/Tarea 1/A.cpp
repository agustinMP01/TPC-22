#include <bits/stdc++.h>

using namespace std;
int main(){

    int t;
    cin >> t;
    int n;

    for(t; t>0; t--){
        cin >> n;
        int die[n];
        int dcc[n];


        //Ciclo for die
        //Inicializa el array die con los puntos obtenidos
        for (int i = 0; i < n; i++){
            cin >> die[i];
        }
        //Ciclo for dcc
        //Inicializa el array dcc con los puntos obtenidos
        for (int i = 0; i < n; i++){
            cin >> dcc[i];
        }

        //Sorteamos de menor a mayor
        sort(die, die+n);
        sort(dcc, dcc+n);

        //Reverse
        reverse(die, die+n);
        reverse(dcc, dcc+n);

        //Guardamos sus puntos totales en la ronda actual
        int sumDcc = 0;
        int sumDie = 0;
        for (int i = 0; i < n-(n/4); i++){
            sumDcc += dcc[i];
            sumDie += die[i];
        }
        //Simulamos las rondas nuevas
        int counter = 0;
        int currentSum = n-(n/4);

        while(sumDie < sumDcc){
            counter++;
            sumDie += 100;

            int _currentSum = (n+counter) - ((n+counter)/4);

            //Si la ronda simulada actual es multiplo de 4, afecta la regla de eliminacion.
            if(( (n+counter)%4) == 0){
                //Si todavia hay numeros en el arreglo
                if (currentSum >= 1) {
                    sumDie -= die[currentSum - 1];
                    currentSum--;
                }
                //Aqui todo el arreglo original fue eliminado, solo tenemos 100's
                else{
                    sumDie -= 100;
                }
            }
            //Para el dcc, como rellenamos con 0's, cada ronda debe reemplazarse el menor borrado con un 0 de ser posible
            else {
                if (_currentSum <= n){
                    sumDcc += dcc[_currentSum - 1];
                }
            }
        }

        cout << counter << "\n";

    }    
    return 0;
}