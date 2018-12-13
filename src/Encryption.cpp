#include<bits/stdc++.h>
#include <chrono>
#include "../header/Encryption.h"
#include "../header/Generator.h"
#include "../header/Cube.h"
using namespace std;
using namespace std::chrono;

ofstream outputCubeSelSeq("output/cube-selection-sequence/sequence.txt");
void Encryption::keyGeneration()
{
	Generator genObj1,genObj2,genObj3;
	keyDecimal1 = genObj1.keyGeneratorMain("1");
	keyDecimal2 = genObj2.keyGeneratorMain("2");
	keyDecimal3 = genObj3.keyGeneratorMain("3");
	
	/*UNCOMMENT FOR DISPLAYING THE KEYS
	for(const auto& p:keyDecimal1) cout<<p<<" "; cout<<endl;
	for(const auto& p:keyDecimal2) cout<<p<<" "; cout<<endl;
	for(const auto& p:keyDecimal3) cout<<p<<" "; cout<<endl;*/		
}
void Encryption::readFile()
{
	ifstream in("input/plainText.txt");
	string line;
	for(line;getline(in,line);)
	{

		plainTextVector.push_back(line);
	}
}
void Encryption::generateRandomCubeSelectionSequence(string plainTextIteration)
{
	int prev=-1;
	const int range_from = 0;
	const int range_to = 2;
	random_device	rand_dev;
	mt19937	generator(rand_dev());
	uniform_int_distribution<int> distr(range_from, range_to);
	while(randomCubeSelectionSequence.size()!=plainTextIteration.length())
	{
		int random = distr(generator);
		//if(prev!=-1 and random!=prev) 
		randomCubeSelectionSequence.push_back(random);
		//prev=random;
	}

	//uncomment to view the random selection sequence 
	//for(const auto& p:randomCubeSelectionSequence) cout<<p<<" ";

	//write sequence to file
	random_shuffle(randomCubeSelectionSequence.begin(),randomCubeSelectionSequence.end());
	cout<<"Writing random sequence to file\n";
	for(const auto& p:randomCubeSelectionSequence) outputCubeSelSeq<<p;
	outputCubeSelSeq<<endl;
	cout<<"Written sequence to file\n";
}
string Encryption::mapValues1(char c)
{
	if(int(c)==96) return faceValues1[26];
	return faceValues1[int(c)-65];
}
string Encryption::mapValues2(char c)
{
	if(int(c)==96) return faceValues2[26];
	return faceValues2[int(c)-65];
}
string Encryption::mapValues3(char c)
{
	if(int(c)==96) return faceValues3[26];
	return faceValues3[int(c)-65];
}
void Encryption::mapPlainText(string plainTextIteration)
{

	vector<string> cipherTextIteration;
	string cipherChar="";
	for(int i=0;i<plainTextIteration.length();i++)
	{
		int choice = randomCubeSelectionSequence[i];
		if(choice==0)
		{
			cipherChar = mapValues1(plainTextIteration[i]);

		}
		else if(choice==1)
		{
			cipherChar = mapValues2(plainTextIteration[i]);
		}
		else if(choice==2)
		{
			cipherChar = mapValues3(plainTextIteration[i]);	
		}
		cipherTextIteration.push_back(cipherChar);
		
	}
	cipherTextVector = cipherTextIteration;
}
void Encryption::encryptLine(string plaintTextLine)
{
	string plainTextIteration="";
	for(int i=0;i<plaintTextLine.length();i++)
		(plaintTextLine[i]!=' ')?plainTextIteration+=toupper(plaintTextLine[i]):plainTextIteration+='`';
	
	//uncomment to view modified plaintext
	//cout<<plainTextIteration<<endl;
	generateRandomCubeSelectionSequence(plainTextIteration);
	mapPlainText(plainTextIteration);
}
void Encryption::encryptDriver()
{
	//READS FILES AND STORES TO VECTOR<STRING> plainText
	keyGeneration();
	readFile(); 

	Cube c1,c2,c3;
	faceValues1 = c1.generateRubiksCubeEncryption(keyDecimal1,"1");
	faceValues2 = c2.generateRubiksCubeEncryption(keyDecimal2,"2");
	faceValues3 = c3.generateRubiksCubeEncryption(keyDecimal3,"3");
	/*uncomment to output plainText
	//for(const auto& p:plainText) cout<<p<<"\n"; 
	for(const auto& p:faceValues1) cout<<p<<" ";
	cout<<endl;
	for(const auto& p:faceValues2) cout<<p<<" ";
	cout<<endl;
	for(const auto& p:faceValues3) cout<<p<<" ";
	cout<<endl;
	*/
	ofstream out("output/ciphertext/cipherText.txt");
	for(const auto& p:plainTextVector) 
	{
		encryptLine(p); 
		randomCubeSelectionSequence.clear();
		
		for(const auto& j:cipherTextVector) out<<j<<" ";
		out<<endl;
		cipherTextVector.clear();
	}
	
}
void Encryption::encrypt()
{	
	encryptDriver(); //calls driver function
	outputCubeSelSeq.close();
}
