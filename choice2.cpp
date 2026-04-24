//search stock
#include<iostream>
#include<String>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
    int choice1=2,choice2;
    ofstream fout;
    ifstream fin;

    if (choice1==2)
    {
        cout<<"Welcome User!"<<endl;
        cout<<"PLease select one from below:"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Stock search"<<endl;
        cout<<"2. Billing"<<endl;
        cout<<"3. Back"<<endl;
        cout<<"enter your choice: ";
        cin>>choice2;
        cout<<endl;

        while( choice2<0||choice2>3)
        {
            cout<<"INVALID INPUT! \a "<<endl<<endl;
            cout<<"PLease select one from below:"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<"1. Stock search."<<endl;
            cout<<"2. Billing."<<endl;
            cout<<"3. Back"<<endl;
            cout<<"enter your choice: ";
            cin>>choice2;
            cout<<endl;
        }
        if(choice2==2)
        {
            int choice3;
            cout<<"PLease select one from below:"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<"1. Search by item name"<<endl;
            cout<<"2. Search by item code"<<endl;
            cout<<"3. Back"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice2;
            cout<<endl;

            while( choice2<0||choice2>3)
            {
               cout<<"INVALID INPUT! \a "<<endl<<endl;
               cout<<"PLease select one from below:"<<endl;
               cout<<"0. Exit"<<endl;
               cout<<"1. Search by item name"<<endl;
               cout<<"2. Search by item code"<<endl;
               cout<<"3. Back"<<endl;
               cout<<"Enter your choice: ";
               cin>>choice2;
               cout<<endl;
            }

            if(choice3==1)
            {
                string userItemName;

                cout<<"Please enter item name";
                getline(cin,userItemName);


            }


        }

          

    }
}