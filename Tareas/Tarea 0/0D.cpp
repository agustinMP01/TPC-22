#include <iostream>

using namespace std;

int main(){

    int many, height;
    cin >> many >> height;
    int width = 0;
    int ppl;

    for (int i = 0; i < many; i++){
    
        cin >> ppl;

        if (ppl > height){ 
            width += 2;
        }

        else width += 1;

    }

    cout << width;

    return 0;
}