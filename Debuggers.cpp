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
void inputsFromstockFile(string[], int[], int[],string[], int);

int main()
{
    int choice1,choice2,choice3;

    do
    {
       cout<<"Welcome to Stock Management and Billing Program!"<<endl;
       cout<<"Please select your role:"<<endl;
       cout<<"0. Exit"<<endl;
       cout<<"1. Admin"<<endl;
       cout<<"2. User"<<endl;
       cout<<"Enter choice: ";
       cin>>choice1;
       cout<<endl;

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

        if(choice1 ==1)
        {
            do
            {
                
            }while (choice1!=1);
            
        
        }

        else if (choice1==2)
        { 
           do
            {
                int choice3;
                ofstream fout;
                ifstream fin;

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

                if( choice2==0)
                {
                cout<<"Thank you for using our program!"<<endl;
                return 0;
                }
                else if(choice2==1)
                {
                    char continueChoice ='y';

                    do
                    {
                        cout<<"PLease select one from below:"<<endl;
                        cout<<"0. Exit"<<endl;
                        cout<<"1. Search by item name"<<endl;
                        cout<<"2. Search by item code"<<endl;
                        cout<<"3. Back"<<endl;
                        cout<<"Enter your choice: ";
                        cin>>choice3;
                        cout<<endl;

                        while( choice3<0||choice3>3)
                        {
                            cout<<"INVALID INPUT! \a "<<endl<<endl;
                            cout<<"PLease select one from below:"<<endl;
                            cout<<"0. Exit"<<endl;
                            cout<<"1. Search by item name"<<endl;
                            cout<<"2. Search by item code"<<endl;
                            cout<<"3. Back"<<endl;
                            cout<<"Enter your choice: ";
                            cin>>choice3;
                            cout<<endl;
                        }

                        int fileItemCount = StockFileCount();

                        string fileItemCodes[fileItemCount] ;
                        int fileItemQuantity[fileItemCount];
                        int fileItemPrice[fileItemCount];
                        string fileItemNames[fileItemCount];

                        inputsFromstockFile(fileItemCodes,fileItemQuantity,fileItemPrice,fileItemNames,fileItemCount);

                        if(choice3==0)
                        {
                            cout<<"Thank you for using our program!"<<endl;
                            return 0;
                        }
                        else if(choice3==1)
                        {    
                            do
                            {
                                string userItemName;
                                int searchedItemNumber=-1;

                                cout<<"Please enter item name: ";
                                cin.ignore();
                                getline(cin,userItemName);
                
                                for(int i=0 ; i < fileItemCount; i++ )
                                {
                                    if(fileItemNames[i]==userItemName)
                                    {
                                        searchedItemNumber = i;
                                    }
                                }
                        

                                if(searchedItemNumber !=-1)
                                {
                                    cout<<"The Item you Searched:"<<endl;
                                    cout<<fileItemCodes[searchedItemNumber] <<" "
                                    <<fileItemNames[searchedItemNumber]<<" "
                                    <<fileItemQuantity[searchedItemNumber]<<" "
                                    <<fileItemPrice[searchedItemNumber];
                                    cout<<endl<<endl;
                                    cout<<"Do you wish to search for another item? (Y/N): ";
                                    cin>>continueChoice;

                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"The item u searched does not exist in stock" 
                                    <<" try searching again with item code or exact item name"<<endl;
                                    cout<<"Do you wish to try again? (Y/N): ";
                                    cin>>continueChoice;
                                }
                            }while(continueChoice=='y'||continueChoice=='Y');
                        }
                        else if(choice3==2)
                        {
                            do
                            {
                                string userItemCode;
                                int searchedItemNumber=-1;

                                cout<<"Please enter item code: ";
                                cin>>userItemCode;
                
                                for(int i=0 ; i < fileItemCount; i++ )
                                {
                                    if(fileItemCodes[i]==userItemCode)
                                    {
                                        searchedItemNumber = i;
                                    }
                                }

                                if(searchedItemNumber !=-1)
                                {
                                    cout<<"The Item you Searched:"<<endl;
                                    cout<<fileItemCodes[searchedItemNumber] <<" "
                                    <<fileItemNames[searchedItemNumber]<<" "
                                    <<fileItemQuantity[searchedItemNumber]<<" "
                                    <<fileItemPrice[searchedItemNumber];
                                    cout<<endl<<endl;
                                    cout<<"Do you wish to search for another item? (Y/N): ";
                                    cin>>continueChoice;
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"The item u searched does not exist in stock" 
                                    <<" try searching again with item name or exact item code"<<endl<<endl;
                                    cout<<"Do you wish to try again? (Y/N): ";
                                    cin>>continueChoice;
                                }
                            }while(continueChoice=='y'||continueChoice=='Y');
                        }
                    }while(choice3!=3);
                }
                else if(choice2==2)
                {
                    cout<<"Billing is under construction! Please check back later!"<<endl;
                }
            }while(choice2 !=3);
         }
    }while(choice1!=0); 

    cout<<"Thank you for using our program!"<<endl;
    return 0;
}

   


int StockFileCount()
{
  string fileItemName,fileItemCode;
  int fileItemPrice=0,fileItemCount=0,fileItemQuanity=0;
  ofstream fout;
  ifstream fin;

  fin.open("stock.txt");
  if (!fin.fail())
  {
     while(fin>>fileItemCode)
      {
        fin>>fileItemQuanity;
        fin>>fileItemPrice;
        fin.ignore();
        getline(fin,fileItemName);
       
        fileItemCount++;
        
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

void inputsFromstockFile(string fileItemCodes[],int fileItemQuantity[],int fileItemprice[],string fileitemName[],int fileItemCount)
{
  ifstream fin;
  fin.open("stock.txt");

  if(!fin.fail())
  {
    for(int i=0;i<fileItemCount;i++)
    {
      fin >>fileItemCodes[i];
      fin >>fileItemQuantity[i];
      fin >>fileItemprice[i];
      fin.ignore();
      getline(fin,fileitemName[i]);
     
    }
    fin.close();
  }
   else
  {
    cout<<endl;
    cout<<"Error!\aCould not open stock.txt file"<<endl;
  }
}
