#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, u;
    while(cin >> n >> u, n != -1){
        int cityList[n];

        for (int i = 0; i < n; ++i){ //Lleno la lista de ciudades
            cin >> cityList[i];
        }
        //cout << "Me llené\n";

        sort(cityList, cityList + n);

        int l = 1;
        int r = cityList[n-1];

        while(l < r){
            //cout << "Mi rango es: " << l << " - " << r << "\n";
            int cand = 0;
            int mid = l + (r-l)/2;
            //cout << "mid: " << mid << "\n";
            for (int i = 0; i < n; ++i){
                cand += (cityList[i]+ mid-1)/mid;
            }

            //cout << "cand:  " << cand << "\n";

            if(cand >u) {
                l = mid+1;
            }
            else if(cand<=u){
                r = mid;
            }
        }
        cout << l << "\n";
    }

    return 0;
}