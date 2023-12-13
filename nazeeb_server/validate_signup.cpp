#include<bits/stdc++.h>
using namespace std;
#include<regex>
#include "SHA-Algo/sha.h"
#include<conio.h>




bool checkID_and_signup(string str){

    vector<pair<string,bool>> viki;
    vector<pair<pair<string,string>,string>> vec;

    ifstream input;
    input.open("uniqueMailID.txt");

    string userID;
    bool b;

    
    while(input>>userID>>b){
        viki.push_back({userID,b});
    }

    // for(auto x:viki){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    input.close();

    ofstream output,output2;
    output.open("Accounts.txt",ios::app);

    output2.open("uniqueMailID.txt");

    char ch;

    for(auto &x:viki){
        if(x.first==str){
            if(x.second==1){//means id available
                string firstname,password,hashedPassword;
                cout<<"Enter firstname:";
                cin>>firstname;
                cout<<"Enter password:";
                //making changes
                // cin>>password;
                ch=getch();//discards \n of username
                ch=getch();//for first character of password
                while(ch!='\n'){
                    if(ch==127){//127 is backspace
                        if(password.size()!=0){
                            password.pop_back();
                        }
                    }
                    else{
                        password.push_back(ch);
                        cout<<'*';
                    }
                    // cout<<password<<endl;
                    ch=getch();
                }
                //change finished

                hashedPassword=Hash(password);
                vec.push_back({{str,firstname},hashedPassword});
                //NOW APPEND THE RECORD TO ACCOUNTS.TXT
                for(auto m:vec){
                    output<<m.first.first<<" "<<m.first.second<<" "<<m.second<<endl;        
                }
                output.close();
                x.second=0;//make it unavailable
                //rewrite to uniqueMailID.txt
                for(auto& y:viki){
                    output2<<y.first<<" "<<y.second<<endl;
                }
                output2.close();

                return true;

            }
        }
    }

    return false;

}

void signUpHelper(){
           
            string str;
            bool flag=0,exists;
            g1:
            cout<<"\nCreate your Email Address (bsse+4digits+@+nazeeb.com): ";
            cin>>str;

             regex pattern("bsse\\d{4}@nazeeb\\.com");

            if (regex_match(str, pattern)) {
                flag=1;
            } else {
                cout<<"\nInvalid email format,try again.";
                goto g1;
            }

            if(flag){
                bool signedUp=checkID_and_signup(str);

                if(signedUp){
                    cout<<"\nsigned up successfully!\n";
                }

                else{
                    cout<<"ID not available,so try again!\n";
                    goto g1;
                }
            }

    
}
