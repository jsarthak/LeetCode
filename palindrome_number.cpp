#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPalindorme(int x){
	if (x < 0){
		return false;
	}
	if (x < 10){
		return true;
	}
	int a = x;
	ll reversed = 0;
	while (x > 0){
		reversed = reversed*10 + x%10;
		x /=10;
	}
	return a == reversed;
}

int main(){
	int n;
	cin >> n;
	cout << isPalindorme(n);
	return 1;
}