#include<bits/stdc++.h>
using namespace std;


string intToRoman(int num){
	vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	vector<string> hndrs = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	vector<string> thnds = {"", "M", "MM", "MMM"};

	return thnds[num/1000] + hndrs[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}


int main(){
	int n;
	cin >> n;
	cout << intToRoman(n);
	return 1;
}