// eidt stock
//hello check.
// check ack 1
#include<iostream>
#include<String>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
   int choice1=0, choice2=0, userPin=0, filePin=0;
   string userName, userName1;
   ifstream fin1;
   cout<<"please enter your choice ";
   cin>>choice2;

    if(choice2 == 1)
    {
        cout<<"Welcome Admin!"<<endl;
        fin1.open("Admin.txt");
        cout<<"Please enter User Name: ";
         cin.ignore();
         getline(cin,userName);
        cout<<"Please enter your PIN: ";
        cin.ignore();
        cin>>userPin;

        if(fin1)
        {
        getline(fin1, userName1);
        fin1.ignore();
        fin1 >> filePin;
        if(userName == userName1 && userPin== filePin )
        {                  
        cout<<"Please select an options "<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Update stock "<<endl;
        cout<<"2. Add Admin"<<endl;
        cout<<"3. Change User Name or PIN "<<endl;
        cout<<"4. Back"<<endl;
    }
    fin1.close();

    int choice3 =0;

    cout<<"Please enter your choice: ";
    cin>> choice3;

    while ( choice3 < 0 || choice3 > 4 )
    {
        cout<<"Invalid Input!"<<endl;
        cout<<"Please select an options "<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Update stock "<<endl;
        cout<<"2. Add Admin"<<endl;
        cout<<"3. Change User Name or PIN "<<endl;
        cout<<"4. Back"<<endl;

     }   

     if (choice3 == 1)
     {
        
     }

     if ( choice3 == 2)
     {

     } 
}
}
}