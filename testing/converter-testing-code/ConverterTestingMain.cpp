#include "../header/Converter.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	Converter converterObject;
	vector<int> decimal;
	vector<string> hexadecimal;
	for(int i=0;i<20;i++) decimal.push_back(i);
	cout<<"Decimal array :";
	for(const auto& p:decimal) cout<<p<<" "; cout<<endl;
	hexadecimal = converterObject.decimalToHex(decimal);
	cout<<"Hexadecimal Vector : ";
	for(const auto& p:hexadecimal) cout<<p<<" "; cout<<endl;
	decimal = converterObject.hexToDecimal(hexadecimal);
	cout<<"Converter decimal :";
	for(const auto& p:decimal) cout<<p<<" "; cout<<endl;

}