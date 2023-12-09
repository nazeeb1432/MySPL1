/*
An E-mail Verifier which accepts the email address from the user.
Depending upon the input given by user display appropriate results.
have used the following concepts in the Project : Constructor,new, delete, ex-ceptional handling, string handling functions, etc.
*/
#include<iostream>
#include<cstring>
#include<stdlib.h>
// #include "huffman_prac.cpp"
#include<regex>
#include "SHA-Algo/sha.h"
// #include "SHA-Algo/sha256().h"

using namespace std;

struct box
{
    string msg,from;
    box *nxt;
};
struct box *de=NULL;
class mail
{
public:
  string a,pass,name,birth,gen;//a->email address
  string hashedPassword;
  long mobile;
  mail *next;
  box *inb=NULL;
  mail* create_node()
  {
      mail *temp=new mail;
      return temp;
  }



int count=0;//to store account link list e koto number mail
      void signup();
     void login();
     void show();
	void valid();


};
mail *head=NULL,*star=NULL,*nam=NULL;

class b//mail operations
{
public:
    void compose();
    void inbox();
    void deletemsg();
    void sendFile();
};

void mail::signup()
{
    int i=0,g;
    string b;

    mail *temp1,*temp2;int flag,flag1,flag2,flag3,flag4;

    temp1=create_node();
    cout<<"\nEnter your name: ";
    // cin>>temp1->name;
    cin.ignore();
    getline(cin,temp1->name);
    

    x:
    cout<<"\nCreate your Email Address (bsse+4digits+@+nazeeb.com): "<<endl;
    cin>>temp1->a;//here gonna add parsing
    printf("\n");

    // for(i=0;i<temp1->a.length();i++)
    //     b[i]=temp1->a[i];
    // int j=0;

    regex pattern("bsse\\d{4}@nazeeb\\.com");

    if (regex_match(temp1->a, pattern)) {
        flag=1;
        std::cout << "Email account created successfully!!\n" << std::endl;
    } else {
        flag=0;
        // std::cout << "Invalid email format." << std::endl;
    }

    // while(b[j]!='\0')//check to see if the email address is valid or not,later add algorithm and cases
    // {
    //     if(b[j]!='@')
    //         {flag=0;j++;}
    //     else
    //         {
    //             flag=1;
    //             break;
    //         }

    // }


    if(flag==0)
    {
      cout<<"\nRe-Enter email id:(in the required format) ";
      goto x;
    }

    cout<<"\nEnter birthdate(dd/mm/yy)"<<endl;

    cin>>temp1->birth;

    ge: cout<<"\nEnter Your Gender\n1.Male\n2.Female\n(Enter option no.):";
    cin>>g;

    switch(g)
    {
    case 1:
        temp1->gen={"Male"};
        break;
    case 2:
        temp1->gen={"Female"};
        break;
    default:
        cout<<"\nPlease Enter correct number";
        goto ge;
        break;
    }


    cout<<"\nCreate your Password:  ";
    cin>>temp1->pass;
    temp1->hashedPassword=Hash(temp1->pass);//Hashing the password

    cout<<"\nEnter your Mobile no: "<<endl;
    cin>>temp1->mobile;//later add condition of 11 digits

    //process of adding to LL
    temp1->next=NULL;

    if(head==NULL)
    {
        head=temp1;
        count++;
    }
    else
    {
        temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
            count++;
        }
        temp2->next=temp1;
        count++;
    }

}

void mail::valid()//to find
{
if(head==NULL)//case for empty LL
		cout<<"\nNO mail Id Found";
else
{
	int j;//j is a flag
	string ver;
	mail *verify;
	verify=head;
	cout<<"\nEnter Email ID to Verify"<<endl;
	cin>>ver;
	
		
		if(verify->next==NULL && verify->a==ver)//only one email in LL
		{		cout<<"\nYour Email Id is verfied and it is Correct"<<endl;
				j=1;
                goto b;
		}
		else
			j=0;
		while(verify->next!=NULL)
		{
			if(verify->a==ver)
			{
				cout<<"\nYour Email Id is verfied and it is Correct"<<endl;
				j=1;
                goto b;
			}
			else
			{
				j=0;
			}
			verify=verify->next;
		}
			if(verify->a==ver)//checking the last element
			{
				cout<<"\nYour Email Id is verfied and it is Correct"<<endl;
				j=1;
			}
            b:
            cout<<"";
		if(j==0)
		{	
			cout<<"\nException Found\nYour Email Id is not matching";
		}
}

}

void mail::login()
{
   	 if(head==NULL)
        	cout<<"\nNo Accounts are Created";
    else
	{
    		b m;
		    mail* start;

	    int f,c;
	    string eml,pa;

	   nn: cout<<"\nEnter Your Email ID"<<endl;

	    cin>>eml;

	    cout<<"\nEnter Password"<<endl;
    		cin>>pa;
	    start=head;
	    while(1)
		{
		    while(start->next!=NULL)
		    {
        		if(start->a==eml && start->hashedPassword==Hash(pa))
        		{
        		    cout<<"\nYou Have Successfully Login to Your Account"<<endl;
                    f=1;
        		    nam=start;
        		    cout<<"\nEnter Your Choice\n1.Compose\n2.Inbox\n3.Logout"<<endl;
        		    cin>>c;
        		    star=start;
        		    switch(c)
        		    {
        			    case 1:
        			        m.compose();break;
        			    case 2:
        			        m.inbox();break;
        			    case 3:
        			        goto km;break;//later do m.logout(),can close file
        			    default:
			                cout<<"\nInvalid Choice ";break;


            		}
            			break;
        		}
                else
                {
                    f=0;//could not find (searched except last mail account)
                }
		        start=start->next;
    		}
		    if(start->a==eml && start->hashedPassword==Hash(pa) && start->next==NULL)
    			{
			         cout<<"\nYou Have Successfully Login to Your Account"<<endl;f=1;
			         while(1)
         			{
                        d:
			            cout<<"\nEnter Your Choice\n1.Compose\n2.Inbox\n3.Logout"<<endl;
			            cin>>c;
			            nam=start;
			            star=start;
			            switch(c)
            				{
				            case 1:
				                m.compose();break;

				            case 2:	
				                m.inbox();break;
				            case 3:
               					 goto km;
				            default:
				                cout<<"\nInvalid Choice,try again";
                                goto d;
                                break;


            				}
            				break;
    				}
			}
			if(f==0)
			{	cout<<"\nPlease Enter Correct Emailid or Password to Login";
				goto nn;
			}
		}
	

  }km:
    cout<<"";

}

void b::compose()
{
	int k;
    mail *start;
    string id;
    cout<<"\nEnter Email ID to send Mail: ";
    cin>>id;
    cin.ignore();
    start=head;
    
    while(start->next!=NULL)
    {
        if(start->a==id)
        {
            struct box *temp,*t,*p;
            temp=new box;
            cout<<"\nWrite a Message: ";
            cin.ignore();
            // cin>>temp->msg;

            getline(cin, temp->msg);

            temp->from=nam->name;//nam is the sender
            temp->nxt=NULL;
            if(start->inb==NULL)//start is here receiver
            {
                start->inb=temp;//sent!!
            }
            else
            {
                t=start->inb;
                while(t->nxt!=NULL)
                {
                    t=t->nxt;
                }
                t->nxt=temp;
            }
            cout<<"\n Your Message Has been send";k=1;//k is a flag,need to do proper naming

        }
        else
        {
		k=0;
        }
        start=start->next;
    }
    if(start->next==NULL && start->a==id)
    {
        struct box *temp,*t,*p=NULL;
            temp=new box;
            cout<<"\nWrite a Message:";//condition add later that if double enter then only can send message
            cin.ignore();
            // cin>>temp->msg;
            getline(cin, temp->msg);

            temp->from=nam->name;
            temp->nxt=NULL;
            if(start->inb==NULL)
                start->inb=temp;
            else
            {
                p=start->inb;
            while(p->nxt!=NULL)
                {
                    p=p->nxt;
                }
            p->nxt=temp;
            }cout<<"\nYour Message has been send";k=1;
    }
	if(k==0)
		cout<<"\nAccount Not Found"<<endl;
}
void b::inbox()
{
    b v;
    int d;
    struct box *p;
    if(star->inb==NULL)
        cout<<"\nInbox is Empty";
    else
    {
        // p=star->inb;
        de=star->inb;

        int option;
        op://goto
        cout<<"\n1.see all messages\n2.see recent message\n"<<endl;
        cout<<"(enter 1 or 2):";
        cin>>option;

        if(option!=1 && option!=2) {
            cout<<"Wrong choice,enter again"<<endl;
            goto op;
        }
        
        if(option==1){
            p=star->inb;
            while(p->nxt!=NULL)//see all messages,later check if p!=NULL
            {
                cout<<"\nYou Have a New Message from :- "<<p->from<<endl;
                cout<<p->msg<<"\n\n";
                p=p->nxt;
            }
        }
        if(option==2){
            p=star->inb;
            while(p->nxt!=NULL){
                p=p->nxt;
            }
            cout<<"\nYou Have a New Message from :- "<<p->from<<endl;
            cout<<p->msg;
        }
        
    }
}
void mail::show()//shows all the accounts
{
   if(head==NULL)
        cout<<"\nNO New Accounts Found";
   else
    {
    mail *start;
    start=head;
	cout<<"\nEmail ID"<<"\t"<<"Name"<<"\t"<<"Mobile No."<<"\t"<<"BirthDate"<<"\t"<<"Gender"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------\n"<<endl;
    while(start->next!=NULL)
    {
	
        cout<<start->a<<"\t"<<start->name<<"\t"<<start->mobile<<"\t"<<start->birth<<"\t"<<start->gen<<"\n\n";
        start=start->next;
    }
    cout<<start->a<<"\t"<<start->name<<"\t"<<start->mobile<<"\t"<<start->birth<<"\t"<<start->gen<<"\n\n";
    }
}

int main()
{
	char y;
    mail email;
    box b1;
    int n;
    while(1)
    {
        cout<<"\nEnter Your Choice\n1.Signup\n2.Login\n3.Show all Accounts\n4.Verify Email ID\n5.Exit\n";
        cin>>n;
        switch(n)
        {

            case 1:
                email.signup();
                break;
            case 2:
                email.login();
                break;
            case 3:
                email.show();
                break;
            case 4:
                email.valid();
                break;
            case 5:
                exit(0);//terminate programme
            default:
                cout<<"\nWrong Choice";
                break;

        }qq:cout<<"\nPress Y to continue: ";
	cin>>y;
	if(y=='y'|| y=='Y'){
        continue;
    }		
	else
		goto qq;
        
    }

return 0;
}