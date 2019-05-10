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
	// cout<<"111. Encrypt\n2. Decrypt\nEnter option :";
	cout<<"[+] Encrypting then decrypting..";
	Encryption e;
	e.encryptDriver();
	cout<<"[+] Encryption Completed.";
	Decryption d;
	d.decrypt();
	cout<<"[+] Decryption Completed";
	exit(0);
	
}
