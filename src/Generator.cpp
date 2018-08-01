#include "../header/Generator.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> Generator::randomAsciiGenerator(string cubeNumber)
{
	//init the universal set vector.
	vector<int> asciiUniversalSet,randomSetDecimal;
	set<int> randomSet;
	int i=0;

	//create a partial string of chars whose ascii is not known.
	string asciiCharsTemp = "!\"#$%&()+*-/;:<>=?@[]{}";
	//saving partial chars as int to universal set.
	for(const auto&p:asciiCharsTemp)
		asciiUniversalSet.push_back(int(p));
	//adding other characters as ascii directly.
	for(int i=128;i<=159;i++)
		asciiUniversalSet.push_back(i);


	//shuffle universal set
	random_shuffle(asciiUniversalSet.begin(),asciiUniversalSet.end());

	//initializing the random functions and choosing the range of input [0,11]
    const int range_from=0;
    const int range_to=asciiUniversalSet.size()-1;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distr(range_from, range_to);

	while(randomSet.size()!=17)
	{
		int random = distr(generator);
		int x = asciiUniversalSet[random];
		randomSet.insert(x);
	}

	//copying set to vector int
	for(const auto& p:randomSet) randomSetDecimal.push_back(p);

	//shuffling the array one last time
	random_shuffle(randomSetDecimal.begin(),randomSetDecimal.end());

	//saving the file according to the cube number.
	ofstream out("output/random-ascii-values/randomAsciiValues"+cubeNumber+".txt");
	ostream_iterator<int> output_iterator(out, "\n");
	copy(randomSetDecimal.begin(), randomSetDecimal.end(), output_iterator);

	//return the vector
	return randomSetDecimal;


}
vector<string> Generator::mapSelectedMovesIntToChar(vector<int> selectedMovesInt) //function for mapping char key to int.
{
    vector<string> selectedMovesChar;
    for(const auto& p:selectedMovesInt)
    {
        switch(p)
        {
            case 0: selectedMovesChar.push_back("R"); break;
            case 1: selectedMovesChar.push_back("R'"); break;
            case 2: selectedMovesChar.push_back("U"); break;
            case 3: selectedMovesChar.push_back("U'"); break;
            case 4: selectedMovesChar.push_back("F"); break;
            case 5: selectedMovesChar.push_back("F'"); break;
            case 6: selectedMovesChar.push_back("D"); break;
            case 7: selectedMovesChar.push_back("D'"); break;
            case 8: selectedMovesChar.push_back("B"); break;
            case 9: selectedMovesChar.push_back("B'"); break;
            case 10: selectedMovesChar.push_back("L"); break;
            case 11: selectedMovesChar.push_back("L'"); break;
            
        }
    }
    return selectedMovesChar;
}
vector<int> Generator::keyGeneratorMain(string cubeNumber)
{
	//initializing universal set of moves and final storing vectors.
	vector<int> universalMoves={0,1,2,3,4,5,6,7,8,9,10,11};
    vector<int> selectedMovesInt,temp;
    int count=0;

    //initializing the random functions and choosing the range of input [0,11]
    const int range_from=0;
    const int range_to=11;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distr(range_from, range_to);

    //generating 10x10 iterations.
    for(int i=1;i<=100;i++)
    {
    	int random = distr(generator);
    	selectedMovesInt.push_back(universalMoves[random]);
    
    }
    	
	//randomly shuffling the selected moves vector one last time.
	random_shuffle(selectedMovesInt.begin(),selectedMovesInt.end());
	//converting int moves to actual notations of rubik's cube
	vector<string> selectedMovesChar = mapSelectedMovesIntToChar(selectedMovesInt);
	/*Uncomment to output the actual cube notations mapped from the key
	for(const auto& p:selectedMovesChar) cout<<p<<" "; cout<<endl;*/

	//saving the file according to the cube number.
	ofstream out("output/keys/key"+cubeNumber+".txt");
	ostream_iterator<int> output_iterator(out, "\n");
	copy(selectedMovesInt.begin(), selectedMovesInt.end(), output_iterator);

	return selectedMovesInt;
}