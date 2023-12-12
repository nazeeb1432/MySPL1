#include<bits/stdc++.h>
using namespace std;

class User{

    private:
    string userId;
    string firstName;
    string password;
    string hashedPassword;
    string portNumber;
    string argDir="";

    public:

    User(string userId, string firstName,string password){
        this->userId = userId;
        this->firstName = firstName;
        this->password=password;
        hashedPassword=password+"ab123";
        portNumber=generatePortNumber();
    }

    string generatePortNumber(){
        string roll=userId.substr(4,8);
        int port=stoi(roll)+1000;
        string portString=to_string(port);
        return portString;
    }

    string getUserId(){
        return userId;
    }
    string getFirstName(){
        return firstName;
    }
    string getPassword(){
        return password;
    }
    string getHashedPassword(){
        return hashedPassword;
    }

};
