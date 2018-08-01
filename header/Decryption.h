#ifndef DECRYPTION_H
#define DECRYPTION_H
#include<bits/stdc++.h>
using namespace std;
class Decryption
{
	vector<int> keyDecimal1,keyDecimal2,keyDecimal3;
	vector<int> randomAsciiSetDecimal1,randomAsciiSetDecimal2,randomAsciiSetDecimal3;
	vector<string> randomCubeSelectionVector,cipherTextVector;
	vector<string> faceValues1,faceValues2,faceValues3;
	vector<string> plainTextVector;
public:
	void readFiles();
	void initializeFaceValues();
	vector<int> generateRandomCubeSelectionSeqenceLine(string sequence);
	vector<string> generateCipherTextLine(string cipherString);
	char mapValues(int index);
	void decrypt();
	void tester();
};
#endif