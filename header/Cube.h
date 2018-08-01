#ifndef CUBE_H
#define CUBE_H
#include<bits/stdc++.h>
using namespace std;
class Cube
{
	int faces=6,size=3;
	string cubeMatrix[6][3][3],shuffledCubeMatrix[6][3][3];
	vector<int> keyScramble,tempValueVector,randomAsciiVector,finalValueVector;
	vector<char> finalValueVectorChar;
	vector<string> finalValueVectorHex,faceValueVector;

public:
	//*************MAIN FUNCTIONS***************************
	void findFaceValues();
	//*************ENCRYPTION*******************************
	void initValuesEncryption(string cubeNumber);
	vector<string> generateRubiksCubeEncryption(vector<int> key,string cubeNumber);
	//*************DECRYPTION*******************************
	void initValuesDecryption(string cubeNumber,vector<int> randAscii);
	vector<string> generateRubiksCubeDecryption(vector<int> key,string cubeNumber,vector<int> randAscii);
	//*************ROTATIONS*******************************
	void rotateCubeMain(vector<int> key);
	void rotateUp();
	void rotateUpPrime();
	void rotateRight();
	void rotateRightPrime();
	void rotateFront();
	void rotateFrontPrime();
	void rotateLeft();
	void rotateLeftPrime();
	void rotateDown();
	void rotateDownPrime();
	void rotateBack();
	void rotateBackPrime();
};
#endif