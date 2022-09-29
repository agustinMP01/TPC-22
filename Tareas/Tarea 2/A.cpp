#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;
    //cout << "Recibi el largo";
    int q; //numeros a consultar
    cin >> q;
   // cout << "Recibi las consultas";


    int num[n];
    //Lleno el array
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    //cout << "Me llene";

    while (q>0) { //Se repite q veces
        int lf;
        cin >> lf;
        int r = n-1;
        int l = 0;
        int cur = (r/2);

        while (l < r) {
            cur = l + (r-l)/2;
            if (num[cur] >= lf) {
                r = cur;
            }
            else{
                l = cur+1;
            }
        }
        if(num[l] != lf){
            cout << -1<< "\n";
        }
        else{
            cout << l << "\n";
        }
        q--;
    }
    return 0;
}
