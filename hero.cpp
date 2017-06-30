 #include<iostream>
 #include<conio.h>
 #include<fstream>
 #include<string.h>
 #include<stdio.h>
 #include<process.h>
 #include<stdlib.h>
 using namespace std;
 class TTCalgrthm
 {
     public:
	    int lp,li,a,b;
	     void encrypt(char *inp,char *out,char key[20]);
	     void decrypt(char *inp,char *out,char key[20]);
	     void readText(char *inp);
 };
 void TTCalgrthm::encrypt(char *inp,char *out,char key[20])
 {
     a=0;
     ifstream input;
     ofstream output;
     char buf;
     input.open(inp,ios_base::binary);
     output.open(out,ios_base::binary);
     buf=input.get();
     lp=strlen(key);
     li=strlen(inp);
     while(!input.eof())
     {
	 b=a%lp;
	 if(lp%2==0)
	 buf+=key[b];
	 else
	 buf-=key[b];
	 li=strlen(inp);
	 output.put(buf);
	 buf=input.get();
	 a++;
     }
     input.close();
     output.close();
     readText(inp);
     readText(out);
 }
 void TTCalgrthm::decrypt(char *inp,char *out,char key[20])
 {
     a=0;
     ifstream input;
     ofstream output;
     char buf;
     input.open(inp,ios_base::binary);
     output.open(out,ios_base::binary);
     buf=input.get();
     lp=strlen(key);
     li=strlen(inp);
     while(!input.eof())
     {
	  b=a%lp;

	 if(lp%2==0)
	 buf-=key[b];
	 else
	 buf+=key[b];
	 output.put(buf);
	 buf=input.get();
	  a++;
     }
     input.close();
     output.close();
     readText(inp);
     readText(out);
 }
 void TTCalgrthm::readText(char *inp)
 {
     ifstream input;
     char buf;
     input.open(inp,ios_base::binary);
     while(!input.eof())
     {
	 buf=input.get();
     }
     input.close();
 }
 int main()
 {
     TTCalgrthm a;
     int choice; char click;
     char key[20];
     char inp[30],out[30];
     start:
system("cls");
	 cout<<"\n\t\t\t    Techtocore DigiVault";
	 cout<<"\n\n Enter input file: ";
	 cin>>inp;
	 cout<<"\n Enter output file: ";
	 cin>>out;
	 cout<<"\n Enter key: ";
	 cin>>key;
     cout<<"\n\n 1. Encrypt\n 2. Decrypt\n\n Select choice(1 or 2): ";
     cin>>choice;
     if(choice==1)
	 a.encrypt(inp,out,key);
     else if(choice==2)
	 a.decrypt(inp,out,key);
     else  cout<<"\n\n Unknown choice";
     cout<<"\n\nProcessing successfully complete \n Click 'a' to process a file once again; \n 'e' to exit; \n or 'c' to view credits";
     cin>>click;
     if (click=='a')
        goto start;
     else if (click=='e')
            exit(0);
     else system("credits");
     getch();
     return 0;
 }
