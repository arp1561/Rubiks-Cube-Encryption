#include "../header/Generator.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	Generator generatorObject;
	vector<int> key = generatorObject.keyGeneratorMain("1");
	cout<<"Size of key = "<<key.size(); cout<<endl;
	for(const auto& p:key) cout<<p<<" "; cout<<endl;
}