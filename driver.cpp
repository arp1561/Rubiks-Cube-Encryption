#include<bits/stdc++.h>
#include "header/Decryption.h"
#include "header/Encryption.h"
#include "header/Cube.h"
#include "header/Generator.h"
#include "header/Converter.h"
using namespace std;
int main()
{
	int choice;
	cout<<"1. Encrypt\n2. Decrypt\nEnter option :";
	cin>>choice;
	if(choice==1)
	{
		string answer;
		cout<<"NOTE - MAKE SURE YOU HAVE ADDED THE PLAIN TEXT IN THE PLAINTEXT FILE(testing/input/plainText.txt).\nDo you want to continue?(yes/no) :";
		cin>>answer;
		if(answer=="y" or answer=="yes")
		{
			Encryption e;
			e.encryptDriver();
			cout<<"[+] Completed.";
			
		}
		else cout<<"WRONG";
	}
	else if(choice==2)
	{
		string answer;
		cout<<"Do you want to continue?(yes/no) :";
		cin>>answer;
		cout<<answer;
		if(answer=="y" or answer=="yes")
		{
			Decryption d;
			d.decrypt();
			cout<<"[+] Completed";
			exit(0);
		}
		else exit(0);

	}
}
