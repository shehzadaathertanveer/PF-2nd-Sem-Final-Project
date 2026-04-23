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

int StockFileCount();
void inputsFromstockFile(int[], string[], int[], int[], int);

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

int StockFileCount()
{
  string fileItemName;
  int fileItemCode=0,fileItemPrice=0,fileItemCount=0,fileItemQuanity=0;
  ofstream fout;
  ifstream fin;
  fin.open("stock.txt");
  if (!fin.fail())
  {
     while(fin>>fileItemCode)
      {
        getline(fin,fileItemName);
        fin>>fileItemQuanity;
        fin>>fileItemPrice;
        fileItemCount++;
        fin>>fileItemCode;
      }

     fin.close();
  }
  else
  {
    cout<<endl;
    cout<<"Error!\aCould not open stock.txt file"<<endl;
  }
   return fileItemCount;
}

void inputsFromstockFile(int fileItemCodes[],string fileitemName[],int fileItemQuantity[],int fileItemprice[],int fileItemCount)
{
   ifstream fin;
  fin.open("stock.txt");
  if(!fin.fail())
  {
    for(int i=0;i<fileItemCount;i++)
    {
      fin >> fileItemCodes[i];
      getline(fin,fileitemName[i]);
      fin >> fileItemQuantity[i];
      fin >> fileItemprice[i];
    }
    fin.close();
  }
   else
  {
    cout<<endl;
    cout<<"Error!\aCould not open stock.txt file"<<endl;
  }
}
