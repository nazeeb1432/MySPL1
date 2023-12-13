#include<bits/stdc++.h>
using namespace std;
#include<conio.h>

pair<string,string> pr;
pair<int,int>p1={10,12};

int main(){
    //     int a=1;
//    for(int i=1400;i<=1452;i++){
//     cout<<"bsse"<<i<<"@nazeeb.com"<<" "<<a<<endl;
//    }


    //available account file theke read kore vector e store kortesi
    //     vector<pair<pair<string,string>,string>> vec;

    //     string username,firstname,hashvalue;

    //     ifstream input;
    //     input.open("temptest.txt");

    //     while(input>>username>>firstname>>hashvalue){
    //             vec.push_back({{username,firstname},hashvalue});
    //     }

    //     for(auto &x:vec){
    //         cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    //     }
    // input.close();

   //Available accounts file read kore,input er shathe match kore bool ke 0 baniye dao

    char command[1024],buffer[1024];
    // string str;
    // fgets(command,1023,stdin);
    // buffer[strlen(command)] = '\0';
    // cout<<strlen(command)<<endl;

    //  fgets(buffer, 1024, stdin);
    //  buffer[strlen(buffer)] = '\0';//hudai
    //  cout<<buffer<<endl;
    //  cout<<strlen(buffer)<<endl;
    // string str=buffer;
    // str=str.substr(0,str.length()-1);
    // cout<<str<<endl;
    // cout<<str.length()<<endl;

    pr={"bangladesh","dhaka"};
    // cout<<"Before,pr is:";
    // cout<<pr.first<<" "<<pr.second<<endl;
    // func();
    // cout<<"After,pr is:";
    // cout<<pr.first<<" "<<pr.second<<endl;

    string username,password;
    char ch;
    
    string realpassword="nazeeb";

    cout<<"\nusername: ";
    cin>>username;
    cout<<"\npassword: ";
    bool flag=true;
    ch=getch();//username's \n 
    while(flag){
        ch=getch();
        while(ch!='\n'){
            if(ch==127){
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
        if(realpassword==password){
            flag=false;
            cout<<"\nLog in successfully."<<endl;
        }
        else{
            password.clear();
            cout<<"\nWrong password!\nPlease try again."<<endl;
            cout<<"Password: ";
        }
    }

}