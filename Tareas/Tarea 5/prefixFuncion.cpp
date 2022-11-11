#include<bits/stdc++.h>

using namespace std;

template<class T>
std::vector<int> prefixFunction(T &s){
	int n = s.size();
	std::vector<int> pi(n);
	for (int i = 1; i < n; i ++){
		int k = pi[i - 1];
		while(k > 0 and s[i] != s[k]) k = pi[k - 1];
		if (s[i] == s[k]) k ++;
		pi[i] = k;
	}
	return pi;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	string s;
	cin >> s;
	vector<int> prefix = prefixFunction(s);
	return 0;
}