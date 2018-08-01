#include<bits/stdc++.h>
#include "../header/Decryption.h"
#include "../header/Cube.h"
using namespace std;
void Decryption::readFiles()
{
	string line;
	ifstream key1("output/keys/key1.txt"),key2("output/keys/key2.txt"),key3("output/keys/key3.txt");
	for(line;getline(key1,line);) keyDecimal1.push_back(stoi(line));
	for(line;getline(key2,line);) keyDecimal2.push_back(stoi(line));
	for(line;getline(key3,line);) keyDecimal3.push_back(stoi(line));

/*	OUTPUT KEYS BY UNCOMMENTING THIS
	cout<<keyDecimal1.size()<<endl;
	for(const auto& p:keyDecimal1) cout<<p<<"\n";

	cout<<endl;
	cout<<keyDecimal2.size()<<endl;
	for(const auto& p:keyDecimal2) cout<<p<<" ";
	cout<<endl;
	cout<<keyDecimal3.size()<<endl;
	for(const auto& p:keyDecimal3) cout<<p<<" ";
	cout<<endl;
*/
	ifstream randomAsciiSet1("output/random-ascii-values/randomAsciiValues1.txt");
	ifstream randomAsciiSet2("output/random-ascii-values/randomAsciiValues2.txt");
	ifstream randomAsciiSet3("output/random-ascii-values/randomAsciiValues3.txt");
	for(line;getline(randomAsciiSet1,line);) randomAsciiSetDecimal1.push_back(stoi(line));
	for(line;getline(randomAsciiSet2,line);) randomAsciiSetDecimal2.push_back(stoi(line));
	for(line;getline(randomAsciiSet3,line);) randomAsciiSetDecimal3.push_back(stoi(line));	

	/*	OUTPUT ASCII VALUES BY UNCOMMENTING THIS
	cout<<randomAsciiSetDecimal1.size()<<endl;
	for(const auto& p:randomAsciiSetDecimal1) cout<<p<<"\n";
	cout<<endl;
	cout<<randomAsciiSetDecimal2.size()<<endl;
	for(const auto& p:randomAsciiSetDecimal2) cout<<p<<" ";
	cout<<endl;
	cout<<randomAsciiSetDecimal3.size()<<endl;
	for(const auto& p:randomAsciiSetDecimal3) cout<<p<<" ";
	cout<<endl;*/
	

	ifstream randomCubeSequence("output/cube-selection-sequence/sequence.txt");
	for(line;getline(randomCubeSequence,line);) randomCubeSelectionVector.push_back(line);		

	/*UNCOMMENT FOR CUBE SEQUENCE OUTPUT
	cout<<randomCubeSelectionSequenceSet.size()<<endl;
	for(const auto& p:randomCubeSelectionSequenceSet) cout<<p<<" ";*/
	

	ifstream CT("output/ciphertext/cipherText.txt");
	for(line;getline(CT,line);) cipherTextVector.push_back(line);

	/*UNCOMMENT FOR CT OUTPUT IN HEX
	cout<<cipherTextVector.size()<<endl;
	for(const auto& p:cipherTextVector) cout<<p<<"\n";
	cout<<endl;*/
	
}
void Decryption::initializeFaceValues()
{
	Cube c1,c2,c3;
	faceValues1 = c1.generateRubiksCubeDecryption(keyDecimal1,"1",randomAsciiSetDecimal1);
	faceValues2 = c2.generateRubiksCubeDecryption(keyDecimal2,"2",randomAsciiSetDecimal2);
	faceValues3 = c3.generateRubiksCubeDecryption(keyDecimal3,"3",randomAsciiSetDecimal3);
	/*UNCOMMENT TO VIEW FACE VALUES AFTER SHUFFLE
	for(const auto& p:faceValues1) cout<<p<<" ";
	cout<<endl;
	for(const auto& p:faceValues2) cout<<p<<" ";
	cout<<endl;
	for(const auto& p:faceValues3) cout<<p<<" ";
	cout<<endl;*/
}
vector<int> Decryption::generateRandomCubeSelectionSeqenceLine(string sequence)
{
	vector<int> randomCubeSelectionSequence;
	for(int i=0;i<sequence.length();i++) randomCubeSelectionSequence.push_back(sequence[i]-'0');
	return randomCubeSelectionSequence;
}
vector<string> Decryption::generateCipherTextLine(string cipherString)
{
	stringstream ss(cipherString);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> cipherTextLine(begin,end);
	//for(const auto& p:cipherTextLine) cout<<p<<"+";
	return cipherTextLine; 
}
char Decryption::mapValues(int index)
{
	if(index==26) return ' ';
	return char(97+index);
}
void Decryption::decrypt()
{
	initializeFaceValues();
	ofstream plainTextOutput("output/plaintext/plainText.txt");
	for(int mainIndex=0;mainIndex<cipherTextVector.size();mainIndex++)
	{
		string plainTextLine="";
		string cipherString = cipherTextVector[mainIndex]; cipherString.pop_back();
		string sequence  = randomCubeSelectionVector[mainIndex];
		vector<int> randomCubeSelectionSequence = generateRandomCubeSelectionSeqenceLine(sequence);
		vector<string> cipherTextLine = generateCipherTextLine(cipherString);
		for(int i=0;i<cipherTextLine.size();i++)
		{
			string CT = cipherTextLine[i];
			int seq = randomCubeSelectionSequence[i];
			if(seq==0)
			{
				auto loc = distance(faceValues1.begin(), find(faceValues1.begin(),faceValues1.end(),CT));
				plainTextLine+=mapValues(loc);
			}
			else if(seq==1)
			{
				auto loc = distance(faceValues2.begin(), find(faceValues2.begin(),faceValues2.end(),CT));
				plainTextLine+=mapValues(loc);
			}
			else if(seq==2)
			{
				auto loc = distance(faceValues3.begin(), find(faceValues3.begin(),faceValues3.end(),CT));
				plainTextLine+=mapValues(loc);		
			}
		}
		plainTextOutput<<plainTextLine<<endl;
		plainTextVector.push_back(plainTextLine);
	}

}
void Decryption::tester()
{
	

	for(int i=0;i<cipherTextVector.size();i++)
	{
		string cipherString = cipherTextVector[i]; cipherString.pop_back();
		string sequence  = randomCubeSelectionVector[i];
		vector<int> randomCubeSelectionSequence = generateRandomCubeSelectionSeqenceLine(sequence);
		vector<string> cipherTextLine = generateCipherTextLine(cipherString);
		for(int i=0;i<cipherTextLine.size();i++)
		{
			string CT = cipherTextLine[i];
			int seq = randomCubeSelectionSequence[i];
			cout<<seq<<" "<<CT<<" ";
			if(seq==0)
			{
				cout<<"Calling for 0 ";
				auto loc = distance(faceValues1.begin(), find(faceValues1.begin(),faceValues1.end(),CT));
				cout<<loc<<" ";
				cout<<mapValues(loc);
			}
			else if(seq==1)
			{
				cout<<"Calling for 1 ";
				auto loc = distance(faceValues2.begin(), find(faceValues2.begin(),faceValues2.end(),CT));
				cout<<loc<<" ";
				cout<<mapValues(loc);
			}
			else if(seq==2)
			{
				cout<<"Calling for 2 ";
				auto loc = distance(faceValues3.begin(), find(faceValues3.begin(),faceValues3.end(),CT));
				cout<<loc<<" ";
				cout<<mapValues(loc);
			}
			cout<<endl;
		}
		cout<<endl;
	}

}	
