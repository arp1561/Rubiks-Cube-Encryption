#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include<bits/stdc++.h>
#include "../header/Cube.h"
using namespace std;
class Encryption
{
	vector<int> keyDecimal1,keyDecimal2,keyDecimal3,randomCubeSelectionSequence;
	vector<string> plainTextVector,cipherTextVector,faceValues1,faceValues2,faceValues3;
public:
	void keyGeneration();
	void readFile();
	void generateRandomCubeSelectionSequence(string plainTextIteration);
	string mapValues1(char c);
	string mapValues2(char c);
	string mapValues3(char c);
	void mapPlainText(string plainTextIteration);
	void encryptLine(string line);
	void encryptDriver();
	void encrypt();


};
#endif