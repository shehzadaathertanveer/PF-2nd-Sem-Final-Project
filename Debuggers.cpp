/* This is the final project of team Debuggers for Programming 
Fundamentals. The team members are Abdullah Arif Roll# BITF25A012,
Shehzada Ather Roll# BITF25A047, Abdul Moiz Roll# BITF25A059
*/

//THIS IS STOCK MANAGEMENT AND BILLING PROGRAM WHICH WILL HELP IN EDITING, 
//MAINTAINING AND CHECKING STOCK AND WILL ALSO GENERATE RECIEPT

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int customerRecordCount();
void inputsFromCustomerRecord(string[], int[], int[],string[], int);
int adminFileCount();
void inputsFromAdminFile(string[], int[], int);
int StockFileCount();
void inputsFromstockFile(string[], int[], int[],string[], int);

int main()
{
    int choice1,choice2,choice3;
    do
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t---------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t     Stock Management and Billing System"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t---------------------------------------------"<<endl;

       cout<<endl<<"\t\t\t\t\t\t Welcome to Stock Management and Billing Program by Debbugers!"<<endl<<endl;
       cout<<"\t\t\t\t\t\t\t\t\t\t\t   ________________________"<<endl;
       cout<<"\t\t\t\t\t\t\t\t\t\t\t   |                      |"<<endl;
       cout<<"...........................................................................................|   Introductive part  |..........................................................................................."<<endl;
       cout<<"\t\t\t\t\t\t\t\t\t\t\t   |______________________|"<<endl;
    
       
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
            cout<<"----INVALID INPUT!-----\a "<<endl<<endl;
            cout<<"Please select your role:"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<"1. Admin"<<endl;
            cout<<"2. User"<<endl;
            cout<<"Enter choice: ";
            cin>>choice1;
            cin.ignore();
            cout<<endl;
        }

        if(choice1 ==1)//Admin Permissions
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

            char againAdmin='y';

            againAdmin = 'n'; 

            do
            {
                adminNumber = -1;

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

                if (adminNumber == -1 || userPin != adminPin[adminNumber])
                {
                    cout << endl << "Invalid credentials!\a Do you wish to try again (y/n): ";
                    cin >> againAdmin;
                    cin.ignore();
                }
                else
                {
                    againAdmin = 'n';
                    cout << "Access Granted." << endl;
                }

            } while (againAdmin == 'y' || againAdmin == 'Y');

            if (adminNumber != -1 && userPin == adminPin[adminNumber])
            {
                cout<<endl << "----Welcome Admin!-----" << endl<<endl;
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
                        cout << endl << "----Invalid Input!-----\a" << endl;
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
                        cout << endl << "Thank you for using the program" << endl;
                        return 0;
                    }
                    else if (choice2 == 1)
                    {
                        int choice = 0;
                        do
                        {
                            choice = 0;

                            cout << "which type of  update you want " << endl;
                            cout << "1. Add item" << endl;
                            cout << "2. increase/ decrease quantity of an item" << endl;
                            cout << "3. increase/ decrease price of an item" << endl;
                            cout << "4. delete item" << endl;
                            cout << "5. back"<<endl;
                            cout << "Please enter your choice: ";
                            cin >> choice;

                            while (choice < 1 && choice > 5)
                            {
                                cout << "Invalid input" << endl << endl;
                                cout << "which type of  update you want " << endl;
                                cout << "1. Add item" << endl;
                                cout << "2. increase/ decrease quantity of an item" << endl;
                                cout << "3. increase/ decrease price of an item" << endl;
                                cout << "4. delete item" << endl;
                                cout << "5. back"<<endl;
                                cout << "Please enter your choice: ";
                                cin >> choice;
                            }

                            if (choice == 1)

                            {
                                int count = StockFileCount();
                            
                                string itemCodeFile[count]; 
                                int itemQuantityFile[count];
                                int itemPriceFile[count];
                                string itemNameFile[count];
                               
                                inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                int newItems;

                                cout << "How many new items: ";
                                cin >> newItems;
                                cin.ignore();

                                string newItemCode[newItems]; 
                                int newItemQuantity[newItems];
                                int newItemPrice[newItems];
                                string newItemName[newItems];

                                ofstream fout;
                                fout.open("stock.txt");

                                if(!fout.fail())
                                {  

                                    for (int i = 0; i < newItems; i++)
                                    {
                                        int j=i;
                                        cout<<endl<<"please enter for item "<<j+1<<": "<<endl;

                                        cout << "Enter item code: ";
                                        cin >> newItemCode[i];
                                        fout << newItemCode[i]<<" ";     

                                        cout << "Enter quantity: ";                                            
                                        cin >> newItemQuantity[i];
                                        fout << newItemQuantity[i]<<" ";

                                        cout << "Enter price: ";
                                        cin >> newItemPrice[i];
                                        fout << newItemPrice[i] <<" ";

                                        cin.ignore();
                                        cout << "Enter item name: ";
                                        getline(cin, newItemName[i]);
                                        fout <<newItemName[i]<<endl;
                                    }
                
                                    for (int i = 0; i < count; i++)
                                    {
                                        fout << itemCodeFile[i] << " " 
                                        << itemQuantityFile[i] << " "
                                        << itemPriceFile[i] << " " 
                                        << itemNameFile[i] << endl;
                                    }
                                    fout.close();
                                    cout << "All items saved successfully!" << endl;
                                }
                                else
                                {
                                    cout<<endl<<"Error\a in editing stock file "<<endl;
                                }
                            }
                            else if (choice == 2)
                            {
                                char again='y';
                                do 
                                {
                                    int count = StockFileCount();

                                    string itemCodeFile[count]; 
                                    int itemQuantityFile[count];
                                    int itemPriceFile[count];
                                    string itemNameFile[count];
                               
                                    inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                    string searchCode;
                                    cout << "Enter item code: ";
                                    cin >> searchCode;

                                    char choice;
                                    int changeQuantity;

                                    cout << "Enter '+' to increase or '-' to decrease quantity: ";
                                    cin >> choice;

                                    while(choice!='+'&&choice!='-')
                                    {
                                        cout<<endl<<"----Invalid input!----"<<endl;
                                        cout << "Enter '+' to increase or '-' to decrease quantity: ";
                                        cin >> choice;
                                    }

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
                                                    again='y';
                                                }
                                            }
                                        }
                                    }
                                
                                    if (found == 0)
                                    {
                                        cout << "Item not found!.Try again." << endl;
                                        again='y';
                                    }

                                    ofstream outStockfile("stock.txt");

                                    for (int i = 0; i < count; i++)
                                    {
                                        outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                    }
                                    outStockfile.close();

                                    cout << "Quantity updated successfully!" << endl;
                                    cout<<endl<<"Do you want to update another item? (Y/N): ";
                                    cin>>again;

                                }while(again!='n'&&again!='N'); 
                            }   
                            else if (choice == 3)
                            {
                                char again='y';
                                do 
                                {
                                    int count = StockFileCount();

                                    string itemCodeFile[count]; 
                                    int itemQuantityFile[count];
                                    int itemPriceFile[count];
                                    string itemNameFile[count];
                               
                                    inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                    string searchCode;
                                    cout << "Enter item code: ";
                                    cin >> searchCode;

                                    char choice;
                                    int changePrice;

                                    cout << "Enter '+' to increase or '-' to decrease price: ";
                                    cin >> choice;

                                    while(choice!='+'&&choice!='-')
                                    {
                                        cout<<endl<<"----Invalid input!----"<<endl;
                                        cout << "Enter '+' to increase or '-' to decrease price: ";
                                        cin >> choice;
                                    }

                                    cout << "Enter price change: ";
                                    cin >> changePrice;

                                    int found = 0;

                                    for (int i = 0; i < count; i++)
                                    {
                                        if (itemCodeFile[i] == searchCode)
                                        {
                                            found = 1;

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
                                                    cout << "Not enough price!" << endl;
                                                    again='y';
                                                }
                                            }
                                        }
                                    }
                                
                                    if (found == 0)
                                    {
                                        cout << "Item not found!.Try again." << endl;
                                        again='y';
                                    }

                                    ofstream outStockfile("stock.txt");

                                    for (int i = 0; i < count; i++)
                                    {
                                        outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                    }
                                    outStockfile.close();

                                    cout << "Quantity updated successfully!" << endl;
                                    cout<<endl<<"Do you want to update another item? (Y/N): ";
                                    cin>>again;

                                }while(again!='n'&&again!='N'); 
                            }

                            else if (choice == 4)
                            {
                                char again='y';
                                do
                                {
                                    int count = StockFileCount();

                                    string itemCodeFile[count]; 
                                    int itemQuantityFile[count];
                                    int itemPriceFile[count];
                                    string itemNameFile[count];
                               
                                    inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                    string deleteCode;
                                    cout << "Enter item code to delete: ";
                                    cin >> deleteCode;

                                    ofstream fout("stock.txt");

                                    int i;
                                    for (i = 0; i < count; i++)
                                    {
                                        if (itemCodeFile[i] != deleteCode)
                                        {

                                            fout << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                        }
                                    }

                                    fout.close();

                                    for (i = 0; i < count; i++)
                                    {
                                        if (itemCodeFile[i] == deleteCode)
                                        {
                                            cout << "Item deleted successfully!" << endl;
                                            cout<<endl<<"Do you want to delete another item? (Y/N): ";
                                            cin>>again;
                                            break;
                                        }
                                    }

                                    if (i == count)
                                    {
                                        cout << "Item not found! try again." << endl;
                                        again='y';
                                    }
                               }while (again != 'n' && again != 'N');
                             
                               
                            }   
                        }while(choice!=5);
                    }
                    else if (choice2 == 2)
                    {
                        char TryAgain='n';
                        int adminCheck=0;
                        int newAdminPin;
                        string newAdminName;

                        do
                        {
                            adminCheck=0;
                            TryAgain='n';

                            cout << "Please enter new admin user name: ";
                            getline(cin, newAdminName);

                            for(int i=0;i<adminCount;i++)
                            {
                                if(newAdminName==adminname[i])
                                {
                                    adminCheck=-1;
                                }
                            }
                            if(adminCheck==0)
                            {
                                cout << "please enter new admin Pin: ";
                                cin >> newAdminPin;
                                cin.ignore();
                            }
                            else
                            {
                                cout<<endl<<"Admin with this username already exists! do you want to try again(y/n): ";
                                cin>>TryAgain;
                                cin.ignore();
                            }
                        }while(TryAgain=='y'||TryAgain=='Y');

                        if(adminCheck==0)
                        {
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
                    }
                    else if (choice2 == 3)
                    {
                        char newUserTryAgain='n';

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
                                    
                                        int newUserCheck=0;
                                        string newUserName;
                                        do
                                        {
                                            newUserTryAgain='n';
                                            newUserCheck=0;

                                            cout << "Please enter the new username: ";
                                            getline(cin, newUserName);
                                
                                          for(int i=0;i<adminCount;i++)
                                            {
                                                if(newUserName==adminname[i])
                                                {
                                                    newUserCheck=-1;
                                                }
                                            }
                                    
                                            if(newUserCheck==-1)
                                            {
                                                cout<<endl<<"Admin with this username already exists! do you want to try again(y/n): ";
                                                cin>>newUserTryAgain;
                                                cin.ignore();
                                            }
                                            else
                                            {
                                                newUserCheck=0;
                                                newUserTryAgain='n';
                                            }
                                        }while(newUserCheck==-1&&(newUserTryAgain=='y'||newUserTryAgain=='Y'));
                                
                                       if(newUserCheck==0&&(newUserTryAgain=='n')||newUserTryAgain=='N')
                                        {
                                            choice4 = 3;
                                            choice2 = 4;

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
                                                cout << endl << "Admin username updated successfully! Please login again with the new username." << endl<<endl;
                                            }
                                            else
                                            {
                                                cout << endl;
                                                cout << "Error!\aCould not open Admin.txt file for editing admin's username" << endl;
                                            }
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
                                        cout << endl << "Admin Pin updated successfully! Please login again with the new Pin." << endl<<endl;
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
                    char anotherReceipt='y';
                    do
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

                        int RecordCount=customerRecordCount();
                        
                        int billNo[RecordCount];
                        int CustomerTotal[RecordCount];
                        string customerPhone[RecordCount];
                        string customerName[RecordCount];

                        void inputsFromCustomerRecordFile(int billNo[],int CustomerTotal[],string customerPhone[],string customerName[],int RecordCount);
        
                        int grandTotal=0;
                        string customername,customerphone;

                        cout<<"Please enter coustomer name: ";
                        cin.ignore();
                        getline(cin,customername);
                        cout<<"Please enter coustomer phone number: ";
                        getline(cin,customerphone);

                        int customerBillNo=RecordCount+1;

                        cout<<endl<<"--------------Reciept-------------"<<endl;
                        cout<<left;
                        cout<<setw(17)<<"Bill No: "<<customerBillNo<<endl;
                        cout<<"coustomer: "<<customername<<endl;
                        cout<<"phone: "<<customerphone<<endl<<endl;
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
                        cout<<endl<<"Would you like to generate another receipt? (Y/N): ";
                        cin>>anotherReceipt;
                        
                        ofstream fout;
                        fout.open("customerRecord.txt");

                        if(!fout.fail())
                        {
                        
                            fout<<customerBillNo<<" "<<grandTotal<<" "<<customerphone<<" "<<customername<<endl;

                            for(int i=0;i<RecordCount;i++)
                            {
                                fout<<billNo[i]<<" "<<CustomerTotal[i]<<" "<<customerPhone[i]<<" "<<customerName[i]<<endl;
                            }
                            fout.close();
                        }
                        else
                        {
                            cout<<endl<<"Error\a could not update customer record file after generating receipt"<<endl;
                        }

                        fout.open("reciept.txt");
                        if(!fout.fail())
                        {
                            fout<<left;
                            fout<<"Bill no: "<<customerBillNo<<endl;
                            fout<<"Coustomer name: "<<customername<<endl;
                            fout<<"Coustomer phone: "<<customerphone<<endl;
                            fout<<setw(17)<<"Item name "
                                <<setw(6)<<"item Quantity"
                                <<setw(6)<<" item proce "
                                <<setw(8)<<"Item total";
                            fout<<endl<<endl;

                            for(int i=0;i<boughtItemCount;i++)
                            {
                                fout<<setw(17)<<boughtItemNames[i] 
                                    <<setw(6)<<BoughtItemQuantity[i]
                                    <<setw(6)<<boughtItemPrices[i]
                                    <<setw(8)<<boughtItemtotal[i];
                                fout<<endl;
                            }

                            fout<<"grand Total: "<<grandTotal;
                        }
                        else
                        {
                            cout<<endl<<"Error!\a in generating reciept file."<<endl;
                        }

                    }while(anotherReceipt!='n'&&anotherReceipt!='N');
                }
            }while(choice2 !=3);
         }
    }while(choice1!=0); 

    cout<<"Thank you for using our program!"<<endl;
    return 0;
}

int customerRecordCount()
{
    string coustomerName,customerPhone;
    int customerRecordCount=0,billNo,total;
    ifstream fin;
    fin.open("customerRecord.txt");
    if (!fin.fail())
    {
        while (fin>>billNo)
        {
            fin>>total;
            fin>>customerPhone;
            fin.ignore();
            getline(fin, coustomerName);
            customerRecordCount++;
        }
        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open customerRecord.txt file" << endl;
    }
    return customerRecordCount;
}

void inputsFromCustomerRecordFile(int billNo[],int CustomerTotal[],string customerPhone[],string customerName[],int customerRecordCount)
{
    ifstream fin;
    fin.open("customerRecord.txt");

    if (!fin.fail())
    {
        for (int i = 0; i < customerRecordCount; i++)
        {
            fin >> billNo[i];
            fin >> CustomerTotal[i];
            fin>>customerPhone[i];
            fin.ignore();
            getline(fin, customerName[i]);
        }
        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open customerRecord.txt file" << endl;
    }
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