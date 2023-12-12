/* myclient.cpp 

Protocol structure for SEND, LIST, READ, DEL, QUIT -> implemented as specified
Missing:  LDAP integration, Locking clients on incorrect login"

*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "myhelper/myhelper.cpp"
#include "mysocket/mysocket.cpp"
#include "validate_signup.cpp"

#define BUF 1024

using namespace std;

pair<string,string> pairloggedInUser;//logined user's corresponding firstname;
pair<pair<string,string>,string> pairloggedInUserRecord;

vector<pair<pair<string,string>,string>> vectUserRecord;//({{username,firstname},hasvalue})



bool checkIfReceiverIsRegisteredOrNot(string str){
      ifstream in;
      in.open("Accounts.txt");
      if(in.fail()){
         return false;
      }

      string user,userFirstName,hashedvalue;
      while(in>>user>>userFirstName>>hashedvalue){
            vectUserRecord.push_back({{user,userFirstName},hashedvalue});
      }

      in.close();

      for(auto &x:vectUserRecord){
         if(str==x.first.first){
            vectUserRecord.clear();
            return true;
         }
      }

      return false;
}

bool checkIfUserIsInLoggedInPairOrNot(string str){
      if(str==pairloggedInUser.first){
         return true;
      }
      else {
         return false;
      }
}




bool checkIfUsernameExistsInServerOrNot(string str){
      ifstream in;
      in.open("Accounts.txt");
      if(in.fail()){
         return false;
      }

      string user,userFirstName,hashedvalue;
      while(in>>user>>userFirstName>>hashedvalue){
            vectUserRecord.push_back({{user,userFirstName},hashedvalue});
      }

      in.close();

      for(auto &x:vectUserRecord){
         if(str==x.first.first){
            pairloggedInUser={x.first.first,x.first.second};
            pairloggedInUserRecord={{x.first.first,x.first.second},x.second};
            vectUserRecord.clear();//jehetu global
            return true;
         }
      }

      return false;
      

      
}

bool login_helper(){
   string usernameInput, passwordInput;
   bool bolean=0;
   cout<<"Enter username:"<<endl;
   cin>>usernameInput;
   bolean=checkIfUsernameExistsInServerOrNot(usernameInput);

   if(bolean){        
      cout<<"Enter password:"<<endl;
      cin>>passwordInput;
      if(Hash(passwordInput)==pairloggedInUserRecord.second){
         cout<<"login successful!"<<endl;
         return true;
      }
      else{
         cout<<"Improper password,logIn failed"<<endl;//later add do-while loop
         return false;
      }
   }
   else{
      cout<<"Username does not exist"<<endl;
      return false;
   }

}



int main(int argc, char *argv[])
{
   MyHelper helper;
   helper.checkClientArguments(argc, argv);

   MySocket clientSocket(argv[1], stoi(argv[2]));
   clientSocket.createSocket();
   clientSocket.connectSocket();

   char buffer[BUF], command[BUF];

   cout << clientSocket.recvMessage() << endl;

   
   while(1){
      g2:
      int choice;     
      cout<<"---------------------------------------------------------------\n";
      cout<<"1.SignUp"<<endl;
      cout<<"2.Login"<<endl;
      cout<<"3.Exit"<<endl;
      cout<<"---------------------------------------------------------------\n";
      cout<<"Enter your choice:";
      cin>>choice;
      cout<<"---------------------------------------------------------------\n";
      if(choice==3) break;
      if(choice==1){
         signUpHelper();
      }
      if(choice==2)
      {
         //after login operations
         bool loginFlag;
         loginFlag=login_helper();
         if(!loginFlag) goto g2;

            while (1)
            {
               
               g3:

               cout<<"Give the commands SEND,LIST,READ or DEL for operations:\n";
               //after successful login,show list of operations
               fgets(command, BUF, stdin);
               buffer[strlen(command)] = '\0';
               clientSocket.sendMessage(command);

               if (strcmp(command, "SEND\n\0") == 0)
               {
                  // sender, reveiver, subject
                  // for (int i = 0; i < 4; i++)
                  // {
                  //    fgets(buffer, BUF, stdin);
                  //    buffer[strlen(buffer)] = '\0';
                  //    clientSocket.sendMessage(buffer);
                  // }

                  string sender,receiver;
                  bool senderFlag,receiverFlag;
                  //sender

                  S:
                  cout<<"Sender mailID:";
                  fgets(buffer, BUF, stdin);//sender email address
                  buffer[strlen(buffer)] = '\0';
                  sender=buffer;
                  sender=sender.substr(0,sender.length()-1);//remove the \n character

                  senderFlag=checkIfUserIsInLoggedInPairOrNot(sender);
                  if(!senderFlag){
                     cout<<"\nusername not same as logged in username,try again"<<endl;
                     goto S;
                  }
                  clientSocket.sendMessage(buffer);

                  //receiver
                  R:
                  cout<<"receiver mailID:";
                  fgets(buffer, BUF, stdin);//sender email address
                  buffer[strlen(buffer)] = '\0';
                  receiver=buffer;
                  receiver=receiver.substr(0,receiver.length()-1);
                  receiverFlag=checkIfReceiverIsRegisteredOrNot(receiver);
                  if(!receiverFlag){
                     cout<<"\nreceiver is not registered in server,try giving another one"<<endl;
                     goto R;
                  }
                  clientSocket.sendMessage(buffer);

                  //subject
                  cout<<"subject:";
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  //message:
                  cout<<"message(type .\n to terminate):";
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);
                  // email message
                  do
                  {
                     fgets(buffer, BUF, stdin);
                     if (strncmp(buffer, ".\n", 2) == 0)
                     {
                        buffer[strlen(buffer)] = '\0';
                     }
                     clientSocket.sendMessage(buffer);
                  } while (strcmp(buffer, ".\n\0") != 0);
                  cout << clientSocket.recvMessage() << endl;
               }

               else if (strcmp(command, "LIST\n\0") == 0)
               {
                  // user
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  string mailSubject, numberOfMails;
                  numberOfMails = clientSocket.recvMessage();
                  cout << numberOfMails;

                  int mailAmount = stoi(numberOfMails.substr(0, numberOfMails.find(' ')).c_str());
                  if (mailAmount > 0)
                  {
                     for (int i = 1; i <= mailAmount; i++)
                     {
                        // tell the server to start sending the list of mails
                        clientSocket.sendMessage("OK\0");
                        mailSubject = clientSocket.recvMessage();
                        mailSubject = mailSubject.substr(mailSubject.find('_') + 1, mailSubject.length()) + ' ' + to_string(i);
                        cout << mailSubject << endl;
                     }
                  }
               }

               else if (strcmp(command, "READ\n\0") == 0)
               {
                  // user
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  // mail number
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  string mailOutput;
                  string resp = clientSocket.recvMessage();
                  cout << resp << endl;

                  if (resp == "OK")
                  {
                     while (1)
                     {
                        // send Server the ok to start receiving the mail
                        clientSocket.sendMessage("OK\0");
                        mailOutput = clientSocket.recvMessage();
                        if (mailOutput == ".\n")
                        {
                           break;
                        }
                        cout << mailOutput;
                     }
                  }
               }

               else if (strcmp(command, "DEL\n\0") == 0)
               {
                  // user
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  // mail number
                  fgets(buffer, BUF, stdin);
                  buffer[strlen(buffer)] = '\0';
                  clientSocket.sendMessage(buffer);

                  cout << clientSocket.recvMessage() << endl;
               }

               else if (strcmp(command, "QUIT\n\0") == 0)
               {
                  break;
               }

               else
               {
                  cout << "Unknown command!" << endl;
               }
            }
      }
   }
   return EXIT_SUCCESS;
}