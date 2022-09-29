#include <bits/stdc++.h>

using namespace std;

int main(){

    typedef long long ll;


    ll max;
    ll hay;

    cin >> max; //Capacidad del granero
    cin >> hay; //Granos que llegan al dia

    ll l = hay; //Minimo necesito 'hay' dias para vaciar
    ll r = 2e9 + hay; //A lo más necesito 'max' dias para vaciar

    while(l<r){
        ll mid = l + (r-l)/2; //Mid para BB

        ll cur = max - hay - ((mid-hay)*(mid-hay-1))/2; //Son los granos que quedan al empezar el dia TIRA OVREFLOW

        cur += hay; //Al inicio del dia, llegan granos


        if (cur>max){ //Si sobrepasa la capacidad, solamente se llena y los demas desaparecen
            cur = max;
        }

        cur -= mid; //Cada dia llegan 'mid' palomas, pues es el dia 'mid'

        if(cur>0){
            l = mid+1;
            //cout << "Subi el piso a " << l << "\n";
        }
        else if(cur<=0){
            r=mid;
            //cout << "Baje el techo a " << r << "\n";
        }
    }
    cout << r << "\n";


    return 0;
}