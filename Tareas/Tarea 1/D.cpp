#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        int n;
        cin >> n;

        //Guardo los guardias
        int guards[n];
        for (int i = 0; i < n; ++i){
            cin >> guards[i];
        }

        //No es par, entonces no podemos ordenar
        if(n%2 != 0){
            cout << "NO"<< "\n";
            t--;
            continue;
        }

        //Ahora, estamos seguros que es par
        sort(guards,guards+n);

        int nGuards[n];
        //Creamos un nuevo array con los guardias en orden
        int even = true;
        for (int i = 0; i < n; ++i){
            if(even){
                nGuards[i] = guards[i/2];
                even = false;
            }
            else{
                nGuards[i] = guards[n/2 + i/2];
                even = true;
            }
        }

        int pass = true;
        for (int i = 0; i < n-1; ++i) {
            if(i%2 == 0){
                if(nGuards[i]>=nGuards[(i+1)]){
                    cout << "NO" << "\n";
                    pass = false;
                    break;
                }
            }
            else{
                if(nGuards[i]<=nGuards[(i+1)]){
                    cout << "NO" << "\n";
                    pass = false;
                    break;
                }
            }
        }
        if(!pass){
            t--;
            continue;
        }

        cout << "YES" << "\n";
        for (int i = 0; i < n; ++i){
            cout << nGuards[i] << " ";
        }
        t--;
    }

    return 0;
}