#include <iostream>

using namespace std;

int main(){

    //int matrix[5][5];}
    int number;
    int steps = 0;
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){

            cin >> number;
            if (number == 1){
                steps += abs(j-2) + abs(i-2);
            }
        }
    }
    cout << steps;
    return 0;
}