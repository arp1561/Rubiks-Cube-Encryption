#include "../header/Generator.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	Generator generatorObject;
	vector<int> a,b,c;

	a=generatorObject.randomAsciiGenerator(1);
	b=generatorObject.randomAsciiGenerator(2);
	c=generatorObject.randomAsciiGenerator(3);

	for(const auto& p:a) cout<<p<<" "; cout<<endl;
	for(const auto& p:b) cout<<p<<" "; cout<<endl;
	for(const auto& p:c) cout<<p<<" "; cout<<endl;

}