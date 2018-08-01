#ifndef CONVERTER_H
#define CONVERTER_H
#include<bits/stdc++.h>
using namespace std;
class Converter
{
public:
	vector<string> decimalToHex(vector<int> decimal);
	vector<int> hexToDecimal(vector<string> hexadecimal);
};
#endif