#include<bits/stdc++.h>
using namespace std;

int main(){

    string str="hello world";
    string str2[10];

    // ofstream out("sample.txt");
    // out<<str;

    // ifstream in("sample.txt");
    //or
    ifstream in;
    in.open("sample.txt");
    int i=0;
    while(in.eof()==0){
        getline(in,str2[i]);
        cout<<str2[i]<<endl;
        i++;
    }
    str2[i]="shesh";

   
   
}