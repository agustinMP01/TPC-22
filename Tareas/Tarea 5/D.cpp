#include<bits/stdc++.h>

using namespace std;

void LPS(string pat, int M, int* lps);
 
void KMP(string pat, string txt) {
    int M = pat.size();
    int N = txt.size();
 
    int lps[M];
 
    LPS(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("%d\n", i - j);
            j = lps[j - 1];
        }
 
        else if (i < N && pat[j] != txt[i]) {

            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}
 
void LPS(string pat, int M, int* lps) {
    int len = 0;
 
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            }else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    int len;
    while(cin >> len) {
 
    string pat;
    cin >> pat;

    string txt;
    cin >> txt;

    KMP(pat, txt);
    cout << " \n";
    }
    return 0;
}