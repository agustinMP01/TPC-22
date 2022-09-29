#include <iostream>
#include <string>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main(){

    string word;
    cin >> word;

    if (isNumber(word)){return 0;}; 

    int len = word.length();
    string nword = "";



    //Si es grande
    if(len > 10){

        char first = word[0];
        char last = word[len-1];
        string btwn = to_string(len-2);

        nword += first;
        nword += btwn;
        nword += last;

        cout << nword;
        return 0;
    }

    //Si no es grande
    else cout << word; 
    return 0;
}