#ifndef GENERATOR_H
#define GENERATOR_H
#include<bits/stdc++.h>
using namespace std;
class Generator
{
public:
	vector<int> randomAsciiGenerator(string cubeNumber);
	vector<string> mapSelectedMovesIntToChar(vector<int> selectedMovesInt);
	vector<int> keyGeneratorMain(string cubeNumber);
};
#endif