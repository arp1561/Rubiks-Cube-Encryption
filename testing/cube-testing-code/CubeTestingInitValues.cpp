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
	c1.generateRubiksCubeMain(key1,"1",'E');

	/*
	gobj2.keyGeneratorMain("2");
	c1.initValuesMain("2",'E');
	gobj3.keyGeneratorMain("3");
	c1.initValuesMain("3",'E');*/
}