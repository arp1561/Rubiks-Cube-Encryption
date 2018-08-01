#include<bits/stdc++.h>
#include "../header/Converter.h"
using namespace std;
vector<string> Converter::decimalToHex(vector<int> decimal)
{
    vector<string> hexValue;
    for(const auto& dVal:decimal)
    {
        int decimalValue = int(dVal);
        string hexValueTemp="";
        while(decimalValue!=0)      //while number not =0
        {
            int temp=0;
            temp = decimalValue%16;     //find the remainder
            if(temp<10) hexValueTemp+=temp+48; //if remainder <10, keep the number as is
            else hexValueTemp+=temp+55; //if remainder >10 convert to character.
            decimalValue/=16; // keep dividing it
        }
        reverse(hexValueTemp.begin(),hexValueTemp.end()); //reverse the string
        hexValue.push_back(hexValueTemp); //push onto the vector
    }
    
    return hexValue;   //return vector
}
vector<int> Converter::hexToDecimal(vector<string> hexadecimal) 
{
    vector<int> decimalValue;
    for(const auto& hVal:hexadecimal)
    {
        string hexValue = string(hVal);
        int len = hexValue.length();
        
        int base=1;
        int decimalValueTemp =0;
        for(int i=len-1;i>=0;i--) //start from the end
        {
            if(hexValue[i]>='0' and hexValue[i]<='9') //number between 0-9
            {
                decimalValueTemp+=(hexValue[i]-48)*base; //multiply with the base
                base*=16; //increase the value of the base
            } 
            else if(hexValue[i]>='A' and hexValue[i]<='F') //for characters
            { 
                decimalValueTemp+=(hexValue[i]-55)*base; //multiply base
                base*=16; //increase base
            }
        }
        decimalValue.push_back(decimalValueTemp); 
    }
    return decimalValue; //return
}