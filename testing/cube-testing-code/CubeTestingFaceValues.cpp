#include "../header/Cube.h"
#include "../header/Generator.h"
#include<iostream>
using namespace std;
int main()
{
	Cube c1,c2,c3;
	Generator gobj1,gobj2,gobj3;
	vector<int> key1 = gobj1.keyGeneratorMain("1");
	c1.initValuesMain("1",'E');
	vector<string> faceValues = c1.generateRubiksCubeMain(key1,"1",'E');
	for(const auto& p:faceValues) cout<<p<<" ";
}