//search stock
#include<iostream>
#include<String>
#include<fstream>
#include<iomanip>

using namespace std;

int StockFileCount();
void inputsFromstockFile(int[], string[], int[], int[], int);

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
        if(choice2==1)
        {
            int choice3;
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

            int fileItemCodes[fileItemCount] ;
            string fileItemNames[fileItemCount];
            int fileItemQuantity[fileItemCount];
            int fileItemPrice[fileItemCount];

            inputsFromstockFile(fileItemCodes,fileItemNames,fileItemQuantity,fileItemPrice,fileItemCount);


            if(choice3==1)
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

                }
                else
                {
                    cout<<endl;
                    cout<<"The item u searched does not exist in stock" 
                    <<" try searching again with item code or exact item name"<<endl;
                }


            }
            else if(choice3==2)
            {
                int userItemCode;
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

                }
                else
                {
                    cout<<endl;
                    cout<<"The item u searched does not exist in stock" 
                    <<" try searching again with item name or exact item code"<<endl;
                }
            }


        }

          

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
        fin.ignore();
        getline(fin,fileItemName);
        fin>>fileItemQuanity;
        fin>>fileItemPrice;
        fin.ignore();
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

void inputsFromstockFile(int fileItemCodes[],string fileitemName[],int fileItemQuantity[],int fileItemprice[],int fileItemCount)
{
   ifstream fin;
  fin.open("stock.txt");
  if(!fin.fail())
  {
    for(int i=0;i<fileItemCount;i++)
    {
      fin >>fileItemCodes[i];
      fin.ignore();
      getline(fin,fileitemName[i]);
      fin >>fileItemQuantity[i];
      fin >>fileItemprice[i];
      fin.ignore();
    }
    fin.close();
  }
   else
  {
    cout<<endl;
    cout<<"Error!\aCould not open stock.txt file"<<endl;
  }
}
