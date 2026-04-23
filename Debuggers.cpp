/* This is the final project of team Debuggers for Programming 
Fundamentals. The team members are Abdullah Arif Roll# BITF25A012,
Shehzada Ather Roll# BITF25A047, Abdul Moiz Roll# BITF25A059
*/

//THIS IS STOCK MANAGEMENT AND BILLING PROGRAM WHICH WILL HELP IN EDITING, 
//MAINTAINING AND CHECKING STOCK AND WILL ALSO GENERATE RECIEPT

#include<iostream>
#include<String>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
    int choice1=0,choiceAdmin=0,choiceUser=0;

    cout<<"Welcome to Stock Management and Billing Program!"<<endl;
    cout<<"Please select your role:"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. User"<<endl;
    cout<<"Enter choice: ";
    cin>>choice1;

    while(choice1>2||choice1<0)
    {
        cout<<"INVALID INPUT! \a "<<endl<<endl;
        cout<<"Please select your role:"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. User"<<endl;
        cout<<"Enter choice: ";
        cin>>choice1;
        cout<<endl;
    }
    if (choice1==2)
    {
        cout<<"Welcome User!"<<endl;


    }
   
}
