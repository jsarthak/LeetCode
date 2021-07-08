#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
	bool neg = false;
	if (x < 0 && x > INT_MIN && x < INT_MAX){
		neg = true;
		x = -1*x;
	}
	int reverse = 0;
	while (x > 0){
		if (reverse > INT_MAX/10 || reverse < INT_MIN/10){
			return 0;
		} else {
			reverse = reverse * 10 + x%10;
			x /= 10;
		}
	}
	return neg ? -1*reverse : reverse;
}

int main(){

	int num;
	cin >> num;

	cout << reverse(num);

	return 1;
}