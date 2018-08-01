#include "../header/Cube.h"
#include "../header/Generator.h"
#include "../header/Converter.h"
#include<bits/stdc++.h>
using namespace std;
//******************FOR ENCRYPTION********************************
void Cube::initValuesEncryption(string cubeNumber)
{
	//objects for converter and generator
	Generator generatorObject;
	Converter converterObject;

	//initializing values for cube [A-Z] [0-9] [random characters]
	for(int i=65;i<=90;i++) tempValueVector.push_back(i);
	for(int i=48;i<=57;i++) tempValueVector.push_back(i);
	//addind ` for space
	tempValueVector.push_back(96);
	//obtaining random ascii values
	randomAsciiVector = generatorObject.randomAsciiGenerator(cubeNumber);
	//inserting everything in sequence to finalValueVector<int>
	finalValueVector.insert(finalValueVector.end(),tempValueVector.begin(),tempValueVector.end());
	finalValueVector.insert(finalValueVector.end(),randomAsciiVector.begin(),randomAsciiVector.end());

	//obtaining char and hex representations as well
	finalValueVectorHex = converterObject.decimalToHex(finalValueVector);	//HEX MATRIX
	//TO BE MADE. NOT AS NEEDED AS YET
	//finalValueVectorChar = converterObject.asciiToChar(finalValueVector);
	
}
vector<string> Cube::generateRubiksCubeEncryption(vector<int> key,string cubeNumber)
{
	int finalValueVectorHexIndex=0;
	initValuesEncryption(cubeNumber);
	keyScramble = key;
	for(int i=0;i<faces;i++)
	{
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			{
				shuffledCubeMatrix[i][j][k]=cubeMatrix[i][j][k] = finalValueVectorHex[finalValueVectorHexIndex]; //Change here for output type(ascii/char/hex)
				finalValueVectorHexIndex++;
			}
		}
	}
	rotateCubeMain(key);
	findFaceValues();
	return faceValueVector;

}
//******************FOR DECRYPTION********************************
void Cube::initValuesDecryption(string cubeNumber,vector<int> randAscii)
{
	//objects for converter and generator
	Generator generatorObject;
	Converter converterObject;

	//initializing values for cube [A-Z] [0-9] [random characters]
	for(int i=65;i<=90;i++) tempValueVector.push_back(i);
	for(int i=48;i<=57;i++) tempValueVector.push_back(i);
	//addind ` for space
	tempValueVector.push_back(96);
	//inserting everything in sequence to finalValueVector<int>
	finalValueVector.insert(finalValueVector.end(),tempValueVector.begin(),tempValueVector.end());
	finalValueVector.insert(finalValueVector.end(),randAscii.begin(),randAscii.end());

	//obtaining char and hex representations as well
	finalValueVectorHex = converterObject.decimalToHex(finalValueVector);	//HEX MATRIX
	//TO BE MADE. NOT AS NEEDED AS YET
	//finalValueVectorChar = converterObject.asciiToChar(finalValueVector);
	
}
vector<string> Cube::generateRubiksCubeDecryption(vector<int> key,string cubeNumber,vector<int> randAscii)
{
	int finalValueVectorHexIndex=0;
	initValuesDecryption(cubeNumber, randAscii);
	keyScramble = key;
	for(int i=0;i<faces;i++)
	{
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			{
				shuffledCubeMatrix[i][j][k]=cubeMatrix[i][j][k] = finalValueVectorHex[finalValueVectorHexIndex]; //Change here for output type(ascii/char/hex)
				finalValueVectorHexIndex++;
			}
		}
	}
	faceValueVector.clear();
	rotateCubeMain(key);		
	findFaceValues();
	return faceValueVector;
}
//******************MAIN FUNCTIONS********************************
void Cube::findFaceValues()
{
	for(int face=0;face<3;face++)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				faceValueVector.push_back(shuffledCubeMatrix[face][i][j]);
			}
		}
	}
	faceValueVector.pop_back();
	faceValueVector.push_back(shuffledCubeMatrix[4][0][0]);

}
/*void Cube::initValuesMain(string cubeNumber,char cipherChoice,const vector<int>& randAscii = vector<int>())
{
	//if(cipherChoice=='E') initValuesEncryption(cubeNumber);
	//else if(cipherChoice=='D') initValuesDecryption(cubeNumber,randAscii);
}
vector<string> Cube::generateRubiksCubeMain(vector<int> key,string cubeNumber,char cipherChoice,const vector<int>& randAscii = vector<int>())
{
	if(cipherChoice=='E') return generateRubiksCubeEncryption(key,cubeNumber);
	else if(cipherChoice=='D') generateRubiksCubeDecryption(key,cubeNumber,randAscii);
}
*/
//*****************************ROTATE FUNCTIONS********************
void Cube::rotateCubeMain(vector<int> key)
{
	//Display displayObject;
	//vector<int> tempKeyScramble={};
	for(const auto& keyValue:key)
	{
		switch(keyValue)
		{
			case 0: rotateRight(); break;
			case 1: rotateRightPrime(); break;
			case 2: rotateUp(); break;
			case 3: rotateUpPrime(); break;
			case 4: rotateFront(); break;
			case 5: rotateFrontPrime(); break;
			case 6: rotateDown(); break;
			case 7: rotateDownPrime(); break;
			case 8: rotateBack(); break;
			case 9: rotateBackPrime(); break;
			case 10: rotateLeft(); break;
			case 11: rotateLeftPrime(); break;
		}
		
		
	}
	//displayObject.displayCube(shuffledCubeMatrix,3);
}
void Cube::rotateUp()
{
	//Display displayObject;
	string temp[3];
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[0][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[0][0][i]=shuffledCubeMatrix[0][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[0][i][0]=shuffledCubeMatrix[0][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[0][2][j]=shuffledCubeMatrix[0][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[0][i][2]=temp[i];

	
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[1][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][2][j]=shuffledCubeMatrix[2][i][2];
	for(int i=size-1;i>=0;i--)
		shuffledCubeMatrix[2][i][2]=shuffledCubeMatrix[3][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][0][i]=shuffledCubeMatrix[4][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[4][i][0]=temp[i];

	

	
}
void Cube::rotateUpPrime()
{
	string temp[3];
	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[0][0][i];
	//cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2];
	/*
	[0][0][0]=[0][0][2];
	[0][0][1]=[0][1][2];
	[0][0][2]=[0][2][2];
	*/
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[0][0][i]=shuffledCubeMatrix[0][i][2];
	/*
	[0][0][2]=[0][2][2];
	[0][1][2]=[0][2][1];
	[0][2][2]=[0][2][0];
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[0][j][2]=shuffledCubeMatrix[0][2][i];
	/*
	[0][2][2]=[0][2][0];
	[0][2][1]=[0][1][0];
	[0][2][0]=[0][0][0];
	*/
	for(int j=size-2;j>=0;j--)
		shuffledCubeMatrix[0][2][j]=shuffledCubeMatrix[0][j][0];
	shuffledCubeMatrix[0][2][0]=temp[0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[0][j][0]=temp[i];

	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[1][2][i];
	/*
	[1][2][0]=[4][0][0]
	[1][2][1]=[4][1][0]
	[1][2][2]=[4][2][0]
	*/
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[1][2][i]=shuffledCubeMatrix[4][i][0];
	/*
	[4][0][0]=[3][0][2];
	[4][1][0]=[3][0][1];
	[4][2][0]=[3][0][0];
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][j][0]=shuffledCubeMatrix[3][0][i];
	/*
	[3][0][2]=[2][2][2];
	[3][0][1]=[2][1][2];
	[3][0][0]=[2][0][2];
	*/
	for(int j=size-1;j>=0;j--)
		shuffledCubeMatrix[3][0][j]=shuffledCubeMatrix[2][j][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][j][2]=temp[i];

}
void Cube::rotateRight()
{
	string temp[3];
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[4][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][0][i]=shuffledCubeMatrix[4][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[4][i][0]=shuffledCubeMatrix[4][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][2][j]=shuffledCubeMatrix[4][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[4][i][2]=temp[i];

	for(int i=0;i<size;i++) 
		temp[i]=shuffledCubeMatrix[5][i][0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][j][0]=shuffledCubeMatrix[1][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[1][i][2]=shuffledCubeMatrix[0][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[0][i][2]=shuffledCubeMatrix[3][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][j][2]=temp[i];
		
//	displayObject.displayCube(shuffledCubeMatrix,3);
}
void Cube::rotateRightPrime()
{
	string temp[3];
	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[4][0][i];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[4][0][i]=shuffledCubeMatrix[4][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][j][2]=shuffledCubeMatrix[4][2][i];
	for(int j=size-2;j>=0;j--)
		shuffledCubeMatrix[4][2][j]=shuffledCubeMatrix[4][j][0];
	shuffledCubeMatrix[4][2][0]=temp[0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][j][0]=temp[i];

	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[0][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[0][i][2]=shuffledCubeMatrix[1][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][j][2]=shuffledCubeMatrix[5][i][0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][i][0]=shuffledCubeMatrix[3][j][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[3][i][2]=temp[i];

	
}
void Cube::rotateFront()
{
	//Display displayObject;
	string temp[3];
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[3][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][0][i]=shuffledCubeMatrix[3][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[3][i][0]=shuffledCubeMatrix[3][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][2][j]=shuffledCubeMatrix[3][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[3][i][2]=temp[i];

	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[0][2][i];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[0][2][i]=shuffledCubeMatrix[2][2][i];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[2][2][i]=shuffledCubeMatrix[5][2][i];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[5][2][i]=shuffledCubeMatrix[4][2][i];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[4][2][i]=temp[i];
	//cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2];

	
}
void Cube::rotateFrontPrime()
{
	string temp[3];
	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[3][0][i];
	
	/*
		[3][0][0]=[3][0][2]
		[3][0][1]=[3][1][2]
		[3][0][2]=[3][2][2]
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][0][j]=shuffledCubeMatrix[3][j][2];
	/*
		[3][0][2]=[3][2][2]
		[3][1][2]=[3][2][1]
		[3][2][2]=[3][2][0]	
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][j][2]=shuffledCubeMatrix[3][2][i];
	/*
		[3][2][2]=[3][2][0]
		[3][2][1]=[3][1][0]
		[3][2][0]=[3][0][0]	
	*/
	for(int i=size-1;i>=0;i--) 
		shuffledCubeMatrix[3][2][i]=shuffledCubeMatrix[3][i][0];	
	
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[3][j][0]=temp[i];

	for(int j=0;j<size;j++) temp[j] = shuffledCubeMatrix[0][2][j];
	

	
	//	[2][2][j++]=[4][2][j++]
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[0][2][j]=shuffledCubeMatrix[4][2][j];
	//[4][2][j++]=[5][2][j++]
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[4][2][j]=shuffledCubeMatrix[5][2][j];
	//[5][2][j++]=[2][2][j++]
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][2][j]=shuffledCubeMatrix[2][2][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[2][2][j]=temp[j];


}
void Cube::rotateLeft()
{
	string temp[3];
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[2][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][0][i]=shuffledCubeMatrix[2][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[2][i][0]=shuffledCubeMatrix[2][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][2][j]=shuffledCubeMatrix[2][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[2][i][2]=temp[i];

	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[0][i][0];
	//shuffledCubeMatrix[0][i][0]=shuffledCubeMatrix[1][i][0]
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[0][i][0]=shuffledCubeMatrix[1][i][0];
	/*
	shuffledCubeMatrix[1][0][0]=shuffledCubeMatrix[5][2][2]
	shuffledCubeMatrix[1][1][0]=shuffledCubeMatrix[5][1][2]
	shuffledCubeMatrix[1][2][0]=shuffledCubeMatrix[5][0][2]
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][j][0]=shuffledCubeMatrix[5][i][2];
	/*
	shuffledCubeMatrix[5][2][2]=shuffledCubeMatrix[3][0][0]
	shuffledCubeMatrix[5][1][2]=shuffledCubeMatrix[3][1][0]
	shuffledCubeMatrix[5][0][2]=shuffledCubeMatrix[3][2][0]
	*/
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][i][2]=shuffledCubeMatrix[3][j][0];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[3][i][0]=temp[i];

}
void Cube::rotateLeftPrime()
{
	string temp[3];
	for(int i=0;i<size;i++)
		temp[i]=shuffledCubeMatrix[2][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][0][i]=shuffledCubeMatrix[2][j][0];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[2][i][0]=shuffledCubeMatrix[2][2][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][2][j]=shuffledCubeMatrix[2][i][2];
	for(int i=0;i<size;i++)
		shuffledCubeMatrix[2][i][2]=temp[i];

	for(int j=0;j<size;j++)
		temp[j]=shuffledCubeMatrix[0][j][0];
	
	//[0][j++][0]=[1][j++][0]
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[0][j][0]=shuffledCubeMatrix[1][j][0];
	//[1][j++][0]=[5][i--][2]
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][j][0]=shuffledCubeMatrix[5][i][2];
	//[5][i--][2]=[3][j++][0]
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][i][2]=shuffledCubeMatrix[3][j][0];
	//[3][j++][0]=temp[j++]
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[3][j][0]=temp[j];

}
void Cube::rotateDown()
{
	string temp[3];
	for(int j=0;j<size;j++)
		temp[j]=shuffledCubeMatrix[5][2][j];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][2][j]=shuffledCubeMatrix[5][i][2];
	for(int i=size-1;i>=0;i--) 
		shuffledCubeMatrix[5][i][2]=shuffledCubeMatrix[5][0][i];
	
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][0][i]=shuffledCubeMatrix[5][j][0];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[5][j][0]=temp[j];

	for(int j=0;j<size;j++) 
		temp[j]=shuffledCubeMatrix[3][2][j];
	for(int j=0;j<size;j++) 
		shuffledCubeMatrix[3][2][j]=shuffledCubeMatrix[2][j][0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][j][0]=shuffledCubeMatrix[1][0][i];
	for(int i=size-1;i>=0;i--)
		shuffledCubeMatrix[1][0][i]=shuffledCubeMatrix[4][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][i][2]=temp[j];

}
void Cube::rotateDownPrime()
{
string temp[3];
	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[5][0][i];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[5][0][i]=shuffledCubeMatrix[5][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][j][2]=shuffledCubeMatrix[5][2][i];
	for(int j=size-2;j>=0;j--)
		shuffledCubeMatrix[5][2][j]=shuffledCubeMatrix[5][j][0];
	shuffledCubeMatrix[5][2][0]=temp[0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[5][j][0]=temp[i];



	for(int j=0;j<size;j++) temp[j]=shuffledCubeMatrix[3][2][j];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++) 
		shuffledCubeMatrix[3][2][j]=shuffledCubeMatrix[4][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[4][i][2]=shuffledCubeMatrix[1][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][0][i]=shuffledCubeMatrix[2][j][0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[2][j][0]=temp[j];



}
void Cube::rotateBack()
{
	string temp[3];
	for(int j=0;j<size;j++)
		temp[j]=shuffledCubeMatrix[1][2][j];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][2][j]=shuffledCubeMatrix[1][i][2];
	for(int i=size-1;i>=0;i--) 
		shuffledCubeMatrix[1][i][2]=shuffledCubeMatrix[1][0][i];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][0][i]=shuffledCubeMatrix[1][j][0];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[1][j][0]=temp[j];

	for(int j=0;j<size;j++) 
		temp[j]=shuffledCubeMatrix[0][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[0][0][j]=shuffledCubeMatrix[4][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[4][0][j]=shuffledCubeMatrix[5][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[5][0][j]=shuffledCubeMatrix[2][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[2][0][j]=temp[j];
}
void Cube::rotateBackPrime()
{
	string temp[3];
	for(int i=0;i<size;i++) temp[i]=shuffledCubeMatrix[1][0][i];
	for(int i=0;i<size;i++) 
		shuffledCubeMatrix[1][0][i]=shuffledCubeMatrix[1][i][2];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][j][2]=shuffledCubeMatrix[1][2][i];
	for(int j=size-2;j>=0;j--)
		shuffledCubeMatrix[1][2][j]=shuffledCubeMatrix[1][j][0];
	shuffledCubeMatrix[1][2][0]=temp[0];
	for(int i=size-1,j=0;i>=0,j<size;i--,j++)
		shuffledCubeMatrix[1][j][0]=temp[i];

	for(int j=0;j<size;j++) 
		temp[j]=shuffledCubeMatrix[0][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[0][0][j]=shuffledCubeMatrix[2][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[2][0][j]=shuffledCubeMatrix[5][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[5][0][j]=shuffledCubeMatrix[4][0][j];
	for(int j=0;j<size;j++)
		shuffledCubeMatrix[4][0][j]=temp[j];

}
