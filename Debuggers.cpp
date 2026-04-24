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

int adminFileCount();
void inputsFromAdminFile(string[], int[], int);
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
       cin.ignore();
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
            cin.ignore();
            cout<<endl;
        }

        if(choice1 ==1)
        {
            int choice2;
        do
        {
            ofstream fout;

            int choice3, choice4;
            int adminCount = adminFileCount();
            int adminPin[adminCount];
            string adminname[adminCount];
            string userName;
            int userPin, adminNumber = -1;

            inputsFromAdminFile(adminname, adminPin, adminCount);

            cout << "Welcome Admin!" << endl;

            cout << "Please enter User Name: ";
            getline(cin, userName);

            for (int i = 0; i < adminCount; i++)
            {
                if (adminname[i] == userName)
                {
                    adminNumber = i;
                }
            }
            cout << "Please enter your PIN: ";
            cin >> userPin;
            cin.ignore();

            if (adminNumber != -1 && userPin == adminPin[adminNumber])
            {
                do
                {
                    cout << "Please select an options " << endl;
                    cout << "0. Exit" << endl;
                    cout << "1. Update stock " << endl;
                    cout << "2. Add Admin" << endl;
                    cout << "3. Change User Name or PIN " << endl;
                    cout << "4. Back" << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice2;
                    cin.ignore();

                    while (choice2 < 0 || choice2 > 4)
                    {
                        cout << endl << "Invalid Input!" << endl;
                        cout << "Please select an options " << endl;
                        cout << "0. Exit" << endl;
                        cout << "1. Update stock " << endl;
                        cout << "2. Add Admin" << endl;
                        cout << "3. Change User Name or PIN " << endl;
                        cout << "4. Back" << endl;
                        cout << "Please enter your choice: ";
                        cin >> choice2;
                        cin.ignore();
                    }

                    if (choice2 == 0)
                    {
                        cout << "thank you for using the program";
                        return 0;
                    }
                    else if (choice2 == 1)
                    {
                        int choice = 0;

                        cout << "which type of  update you want " << endl;
                        cout << "1. Add item" << endl;
                        cout << "2. increase/ decrease quantity of an item" << endl;
                        cout << "3. increase/ decrease price of an item" << endl;
                        cout << "4. delete item" << endl;
                        cout << "Please enter your choice: ";
                        cin >> choice;

                        while (choice < 1 && choice > 4)
                        {
                            cout << "Invalid input";
                            cout << "which type of  update you want " << endl;
                            cout << "1. Add item" << endl;
                            cout << "2. increase/ decrease quantity of an item" << endl;
                            cout << "3. increase/ decrease price of an item" << endl;
                            cout << "4. delete item" << endl;
                            cout << "Please enter your choice: ";
                            cin >> choice;
                        }

                        if (choice == 1)

                        {

                            int itemCodeFile[100], itemQuantityFile[100];
                            int itemPriceFile[100];
                            string itemNameFile[100];
                            int count = 0;
                            ifstream stockFile("stock.txt");

                            while (stockFile >> itemCodeFile[count] >> itemQuantityFile[count] >> itemPriceFile[count])
                            {
                                stockFile.ignore();
                                getline(stockFile, itemNameFile[count]);
                                count++;
                            }
                            stockFile.close();

                            int newItems;
                            cout << "How many new items: ";
                            cin >> newItems;
                            cin.ignore();

                            for (int i = 0; i < newItems; i++)
                            {
                                cout << "Enter item code: ";
                                cin >> itemCodeFile[count];
                                cout << "Enter quantity: ";
                                cin >> itemQuantityFile[count];
                                cout << "Enter price: ";
                                cin >> itemPriceFile[count];
                                cin.ignore();
                                cout << "Enter item name: ";
                                getline(cin, itemNameFile[count]);
                                count++;
                            }

                            ofstream outStockfile("stock.txt");

                            for (int i = 0; i < count; i++)
                            {
                                outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                            }
                            outStockfile.close();
                            cout << "All items saved successfully!" << endl;
                        }
                        
                        else if (choice == 2)
                        {

                            int itemCodeFile[100], itemQuantityFile[100];
                            int itemPriceFile[100];
                            string itemNameFile[100];
                            int count = 0;
                            ifstream stockFile("stock.txt");

                            while (stockFile >> itemCodeFile[count] >> itemQuantityFile[count] >> itemPriceFile[count])
                            {
                                stockFile.ignore();
                                getline(stockFile, itemNameFile[count]);
                                count++;
                            }
                            stockFile.close();

                            int searchCode;
                            cout << "Enter item code: ";
                            cin >> searchCode;

                            char choice;
                            int changeQuantity;

                            cout << "Enter '+' to increase or '-' to decrease: ";
                            cin >> choice;

                            cout << "Enter quantity change: ";
                            cin >> changeQuantity;

                            int found = 0;

                            for (int i = 0; i < count; i++)
                            {
                                if (itemCodeFile[i] == searchCode)
                                {
                                    found = 1;

                                    if (choice == '+')
                                    {
                                        itemQuantityFile[i] = itemQuantityFile[i] + changeQuantity;
                                    }
                                    else if (choice == '-')
                                    {
                                        if (itemQuantityFile[i] >= changeQuantity)
                                        {
                                            itemQuantityFile[i] = itemQuantityFile[i] - changeQuantity;
                                        }
                                        else
                                        {
                                            cout << "Not enough stock!" << endl;
                                        }
                                    }
                                    break;
                                }
                            }

                            if (found == 0)
                            {
                                cout << "Item not found!" << endl;
                            }

                            ofstream outStockfile("stock.txt");

                            for (int i = 0; i < count; i++)
                            {
                                outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                            }
                            outStockfile.close();

                            cout << "Quantity updated successfully!" << endl;
                        }

                        else if (choice == 3)
                        {

                            int itemCodeFile[100], itemQuantityFile[100];
                            int itemPriceFile[100];
                            string itemnameFile[100];

                            int count = 0;
                            ifstream stockFile("stock.txt");

                            while (stockFile >> itemCodeFile[count] >> itemQuantityFile[count] >> itemPriceFile[count])
                            {
                                stockFile.ignore();
                                getline(stockFile, itemnameFile[count]);
                                count++;
                            }

                            stockFile.close();

                            int searchCode;
                            cout << "Enter item code: ";
                            cin >> searchCode;

                            char choice;
                            float changePrice;

                            cout << "Enter '+' to increase price or '-' to decrease: ";
                            cin >> choice;

                            cout << "Enter price change: ";
                            cin >> changePrice;
                            int i;
                            for (i = 0; i < count; i++)
                            {
                                if (itemCodeFile[i] == searchCode)
                                {

                                    if (choice == '+')
                                    {
                                        itemPriceFile[i] = itemPriceFile[i] + changePrice;
                                    }
                                    else if (choice == '-')
                                    {
                                        if (itemPriceFile[i] >= changePrice)
                                        {
                                            itemPriceFile[i] = itemPriceFile[i] - changePrice;
                                        }
                                        else
                                        {
                                            cout << "Error: Price cannot be negative!" << endl;
                                        }
                                    }

                                    break;
                                }
                            }

                            if (i == count)
                            {
                                cout << "Item not found!" << endl;
                            }

                            ofstream outStockfile("stock.txt");

                            for (int j = 0; j < count; j++)
                            {
                                outStockfile << itemCodeFile[j] << " " << itemQuantityFile[j] << " " << itemPriceFile[j] << " " << itemnameFile[j] << endl;
                            }

                            outStockfile.close();

                            cout << "Price updated successfully!" << endl;
                        }

                        else if (choice == 4)
                        {

                            int itemCodeFile[100], itemQuantityFile[100];
                            int itemPriceFile[100];
                            string itemNameFile[100];
                            int count = 0;
                            ifstream StockFile("stock.txt");

                            while (StockFile >> itemCodeFile[count] >> itemQuantityFile[count] >> itemPriceFile[count])
                            {
                                StockFile.ignore();
                                getline(StockFile, itemNameFile[count]);
                                count++;
                            }
                            StockFile.close();

                            int deleteCode;
                            cout << "Enter item code to delete: ";
                            cin >> deleteCode;

                            ofstream outStockFile("stock.txt");

                            int i;
                            for (i = 0; i < count; i++)
                            {
                                if (itemCodeFile[i] != deleteCode)
                                {

                                    outStockFile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                }
                            }

                            outStockFile.close();

                            for (i = 0; i < count; i++)
                            {
                                if (itemCodeFile[i] == deleteCode)
                                {
                                    cout << "Item deleted successfully!" << endl;
                                    break;
                                }
                            }

                            if (i == count)
                            {
                                cout << "Item not found!" << endl;
                            }
                        }
                    
                    }
                    else if (choice2 == 2)
                    {
                        int newAdminPin;
                        string newAdminName;

                        cout << "Please enter new admin user name: ";
                        getline(cin, newAdminName);
                        cout << "please enter new admin Pin: ";
                        cin >> newAdminPin;
                        cin.ignore();

                        fout.open("Admin.txt");

                        if (!fout.fail())
                        {
                            fout << newAdminPin << " " << newAdminName << endl;
                            for (int i = 0; i < adminCount; i++)
                            {
                                fout << adminPin[i] << " " << adminname[i] << endl;
                            }
                            fout.close();
                        }
                        else
                        {
                            cout << endl;
                            cout << "Error!\aCould not open Admin.txt file for adding a new admin" << endl;
                        }

                    }
                    else if (choice2 == 3)
                    {
                        do
                        {
                            cout << "Please select one of following:" << endl;
                            cout << "0. Exit" << endl;
                            cout << "1. Change username" << endl;
                            cout << "2. Change Pin" << endl;
                            cout << "3. Back" << endl;
                            cout << "Enter choice: ";
                            cin >> choice4;
                            cin.ignore();

                            while (choice4 < 0 || choice4 > 3)
                            {
                                cout << endl << "Invalid Input!" << endl;
                                cout << "Please select one of following:" << endl;
                                cout << "0. Exit" << endl;
                                cout << "1. Change username" << endl;
                                cout << "2. Change Pin" << endl;
                                cout << "3. Back" << endl;
                                cout << "Enter choice: ";
                                cin >> choice4;
                                cin.ignore();
                            }

                            if (choice4 == 0)
                            {
                                cout << endl << "Thank you for using the program " << endl;
                                return 0;
                            }
                            else if (choice4 == 1)
                            {
                                choice4 = 3;
                                choice2 = 4;
                                string newUserName;
                                cout << "Please enter the new username: ";
                                getline(cin, newUserName);

                                fout.open("Admin.txt");

                                if (!fout.fail())
                                {
                                    for (int i = 0; i < adminCount; i++)
                                    {
                                        if (i == adminNumber)
                                        {
                                            fout << adminPin[i] << " " << newUserName << endl;
                                        }
                                        else
                                        {
                                            fout << adminPin[i] << " " << adminname[i] << endl;
                                        }
                                    }
                                    fout.close();
                                }
                                else
                                {
                                    cout << endl;
                                    cout << "Error!\aCould not open Admin.txt file for editing admin's username" << endl;
                                }
                            }
                            else if (choice4 == 2)
                            {
                                choice4 = 3;
                                choice2 = 4;
                                int newUserPin;
                                cout << "Please enter the new Pin: ";
                                cin >> newUserPin;
                                cin.ignore();

                                fout.open("Admin.txt");

                                if (!fout.fail())
                                {
                                    for (int i = 0; i < adminCount; i++)
                                    {
                                        if (i == adminNumber)
                                        {
                                            fout << newUserPin << " " << adminname[i] << endl;
                                        }
                                        else
                                        {
                                            fout << adminPin[i] << " " << adminname[i] << endl;
                                        }
                                    }
                                    fout.close();
                                }
                                else
                                {
                                    cout << endl;
                                    cout << "Error!\aCould not open Admin.txt file for editing admin's Pin" << endl;
                                }
                            }
                        } while (choice4 != 3);
                    }
                } while (choice2 != 4);
            }
            else
            {
                cout << endl << "Invalid credentials!\aplease try again " << endl;
                choice2 = 4;
            }
        }while (choice2 != 4);
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
                cin.ignore();
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
                    cin.ignore();
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
                        cin.ignore();
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
                            cin.ignore();
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
                                    cin.ignore();

                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"The item u searched does not exist in stock" 
                                    <<" try searching again with item code or exact item name"<<endl;
                                    cout<<"Do you wish to try again? (Y/N): ";
                                    cin>>continueChoice;
                                    cin.ignore();
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
                                cin.ignore();
                
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
                                    cin.ignore();
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"The item u searched does not exist in stock" 
                                    <<" try searching again with item name or exact item code"<<endl<<endl;
                                    cout<<"Do you wish to try again? (Y/N): ";
                                    cin>>continueChoice;
                                    cin.ignore();
                                }
                            }while(continueChoice=='y'||continueChoice=='Y');
                        }
                    }while(choice3!=3);
                }
                else if(choice2==2)
                {
                    int boughtItemCount=0;
                    int itemTotal;

                    int choice2=2,choice3;
                    int itemCount=StockFileCount();

                    string boughtItemCodes[500];
                    int boughtItemtotal[500];
                    int boughtItemPrices[500];
                    int BoughtItemQuantity[500];
                    string boughtItemNames[500];

                    string itemCode[itemCount];
                    int itemQuantity[itemCount];
                    int itemPrice[itemCount];
                    string itemName[itemCount];

                    inputsFromstockFile(itemCode,itemQuantity,itemPrice,itemName,itemCount);

                    cout<<endl<<"----------------------stock---------------------------"<<endl;
                    cout<<left;
                    cout<<setw(6)<<"Item code "<<setw(15)<<"Item name "<<setw(6)<<" ItemPrice"<<setw(6)<<" item quantity "<<endl<<endl;

                    for(int i=0;i<itemCount;i++)
                    {
                        cout<<setw(6)<<itemCode[i]
                        <<setw(25)<<itemName[i]
                        <<setw(6)<<itemPrice[i]
                        <<setw(6)<<itemQuantity[i]<<endl;
                    }

                    cout<<endl<<endl;
                    char again='y';
                    string boughtItem;
                    int boughtItemNumber=-1,boughtItemQuantity=0,boughtItemPrice=0;
                    do
                    {
                        boughtItemNumber=-1;
                        cout<<"Please enter item code of the item: ";
                        cin>>boughtItem;


                        for(int i=0;i<itemCount;i++)
                        {
                            if(boughtItem==itemCode[i])
                            {
                                boughtItemNumber=i;
                            }
                        }

                        if(boughtItemNumber!=-1)
                        {
                            cout<<"Please enter the quantity of item ";
                            cin>>boughtItemQuantity;

                            if(boughtItemQuantity<itemQuantity[boughtItemNumber])
                            {
                                int boughtItemPrice=itemPrice[boughtItemNumber];
                                int remainingItemQuantity=itemQuantity[boughtItemNumber]-boughtItemQuantity;
                                itemTotal=boughtItemPrice*boughtItemQuantity;
                                itemQuantity[boughtItemNumber] -= boughtItemQuantity;
         
                                ofstream fout;
                                fout.open("stock.txt");
                                if(!fout.fail())
                                {
                                    for(int i=0;i<itemCount;i++)
                                    {
                                        if(boughtItem==itemCode[i])
                                        {
                                            fout<<itemCode[i]<<" ";
                                            fout<<remainingItemQuantity<<" ";
                                            fout<<itemPrice[i]<<" ";
                                            fout<<itemName[i]<<endl;

                                        }
                                        else
                                        {
                                            fout<<itemCode[i]<<" ";
                                            fout<<itemQuantity[i]<<" ";
                                            fout<<itemPrice[i]<<" ";
                                            fout<<itemName[i]<<endl;
                                        }
                                    }

                                    cout<<endl<<"would you like to purchase another Item (Y/N): ";
                                    cin>>again;
                                    cin.ignore();
                                    fout.close();
                                }
                                else
                                {
                                    cout<<endl<<"Error\a could not update stock file after purchasing"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"the quantity u entered "<<boughtItemQuantity
                                <<" is greater than availble quantity "
                                <<itemQuantity[boughtItemNumber]<<" please try again";
                                again='y';
                            }

                            boughtItemCodes[boughtItemCount]=boughtItem;
                            boughtItemNames[boughtItemCount]=itemName[boughtItemNumber];
                            boughtItemPrices[boughtItemCount]=itemPrice[boughtItemNumber];
                            boughtItemtotal[boughtItemCount]=itemTotal;
                            BoughtItemQuantity[boughtItemCount]=boughtItemQuantity;

                            boughtItemCount++;
                        }
                        else
                        {
                            cout<<endl<<"Invalid\aInput The item code does not exist Please try again"<<endl;
                            again='y';
                        }
                    } while(again!='n'&&again!='N');
        
                    int grandTotal=0;
                    string customername,customerphone;

                    cout<<"Please enter coustomer name: ";
                    cin.ignore(1000,'\n');
                    getline(cin,customername);
                    cout<<"Please enter coustomer phone number: ";
                    getline(cin,customerphone);

                    cout<<endl<<"--------------Reciept-------------"<<endl;
                    cout<<customername<<endl;
                    cout<<customerphone<<endl<<endl;
                    cout<<setw(17)<<"Item name "
                    <<setw(6)<<"item Quantity"
                    <<setw(6)<<" item proce "
                    <<setw(8)<<"Item total";
                    cout<<endl;

                    for(int i=0;i<boughtItemCount;i++)
                    {
                        cout<<setw(17)<<boughtItemNames[i] 
                        <<setw(6)<<BoughtItemQuantity[i]
                        <<setw(6)<<boughtItemPrices[i]
                        <<setw(8)<<boughtItemtotal[i];
                        grandTotal=grandTotal+boughtItemtotal[i];
                        cout<<endl;
                    }
                    cout<<endl<<"Grand total: "<<grandTotal<<endl;
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
    cout<<"Error!\a Could not open stock.txt file"<<endl;
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
    cout<<"Error!\a Could not open stock.txt file"<<endl;
  }
}

int adminFileCount()
{
    string fileAdminName;
    int fileAdminPin = 0, fileAdminCount = 0;
    ifstream fin;

    fin.open("Admin.txt");
    if (!fin.fail())
    {
        while (fin >> fileAdminPin)
        {
            fin.ignore();
            getline(fin, fileAdminName);
            fileAdminCount++;
        }
        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open Admin.txt file" << endl;
    }
    return fileAdminCount;
}

void inputsFromAdminFile(string fileAdminNames[], int fileAdminPins[], int fileAdminCount)
{
    ifstream fin;
    fin.open("Admin.txt");

    if (!fin.fail())
    {
        for (int i = 0; i < fileAdminCount; i++)
        {
            fin >> fileAdminPins[i];
            fin.ignore();
            getline(fin, fileAdminNames[i]);
        }
        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open Admin.txt file" << endl;
    }
}