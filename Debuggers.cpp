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
#include<ctime>

using namespace std;

//function prototypes

int customerRecordCount();
void inputsFromCustomerRecordFile(int[], int[], string[], string[], string[], string[], string[], string[], int);
int adminFileCount();
void inputsFromAdminFile(string[], int[], int);
int StockFileCount();
void inputsFromstockFile(string[], int[], int[], string[], int);
void timeAndDate( string &currentDate, string &exactTime);

int main()
{
    cout <<setw(125) <<"++++++++++++++++++++++++++++++++++++++++" <<endl;
    cout <<setw(122) <<" Stock Management and Billing System" <<endl;
    cout <<setw(125) <<"++++++++++++++++++++++++++++++++++++++++" <<endl;

    cout <<endl <<setw(136) <<"Welcome to Stock Management and Billing Program by Debbugers!" <<endl <<endl;

    int choice1 , choice2 , choice3;
    char firstTimeExit = 'n';

    do
    {
        do
        {
            cout <<setw(118) << "============================" <<endl;
            cout . fill('.');
            cout <<setw(118) <<"|  SYSTEM ACCESS CONTROLS  |" <<setw(91)<<"";
            cout . fill(' ');
            cout <<setw(118) <<"============================" <<endl;
       
            cout <<endl <<" Please select your role:" <<endl;
            cout <<" 0. Exit program" <<endl;
            cout <<" 1. Admin Login" <<endl;
            cout <<" 2. User Login" <<endl;
            cout <<" Enter your choice: ";
            cin >> choice1;
            cin . ignore();
            cout << endl;

            while(choice1 > 2 || choice1 < 0)
            {
                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                cout <<" Please select your role:" <<endl;
                cout <<" 0. Exit Program" <<endl;
                cout <<" 1. Admin Login" <<endl;
                cout <<" 2. User Login" <<endl;
                cout <<" Enter your choice: ";
                cin >> choice1;
                cin . ignore();
                cout <<endl;
            }

            if(choice1 == 1)//Admin Permissions
            {
                int choice2;

                do
                {
                    ofstream fout;

                    int choice3, choice4;
                    int adminCount = adminFileCount();
                    int adminPin[adminCount] = {0};
                    string adminname[adminCount];
                    string userName;
                    int userPin = 0, adminNumber = -1;

                    inputsFromAdminFile(adminname, adminPin, adminCount);

                    char againAdmin = 'y';

                    againAdmin = 'n'; 

                    cout<<setw(118)<<"-----ADMIN CREDENTIALS-----"<<endl;

                    do
                    {
                        adminNumber = -1;

                        cout <<endl<< " Please enter your User Name: ";
                        getline(cin, userName);

                        for (int i = 0 ; i < adminCount ; i++)
                        {
                            if (adminname[i] == userName) 
                            {
                                adminNumber = i;
                            }
                        }

                        cout << " Please enter your PIN: ";
                        cin >> userPin;
                        cin . ignore(); 

                        if (adminNumber == -1 || userPin != adminPin[adminNumber])
                        { 
                            cout << endl << " Invalid credentials!\a Do you wish to try again (y/n): ";
                            cin >> againAdmin;
                            cin . ignore();

                            while(againAdmin != 'y' && againAdmin != 'Y' && againAdmin != 'n' && againAdmin != 'N')
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                cout << endl << " Invalid credentials!\a Do you wish to try again (y/n): ";
                                cin >> againAdmin;
                                cin . ignore();
                            }
                        }
                        else
                        {
                            againAdmin = 'n';
                        }

                    } while (againAdmin == 'y' || againAdmin == 'Y');

                    if (adminNumber != -1 && userPin == adminPin[adminNumber]) //admin acess givenn
                    {
                        cout << endl << " Access Granted." << endl <<endl;
                        cout <<endl <<endl <<setw(117) << "-----WELCOME ADMIN!-----" <<endl <<endl;

                        do
                        { 
                            cout <<setw(115) <<"====================" <<endl;
                            cout . fill('.');
                            cout <<setw(115) <<"|  ADMIN CONTROLS  |" <<setw(94) <<"";
                            cout . fill(' ');
                            cout <<setw(115) <<"====================" <<endl <<endl;
                   
                            cout <<endl << " Please select an option " << endl;
                            cout << " 0. Exit Program" << endl;
                            cout << " 1. View and manage stock " << endl;
                            cout << " 2. View customer records " << endl;
                            cout << " 3. Add an Admin" << endl;
                            cout << " 4. Change User Name or PIN " << endl;
                            cout << " 5. Back" << endl;
                            cout << " Enter your choice: ";
                            cin >> choice2;
                            cin . ignore();

                            while (choice2 < 0 || choice2 > 5)
                            {
                                cout<<endl<<setw(118)<<"-----INVALID INPUT!-----\a "<<endl<<endl;
                                cout << " Please select an options " << endl;
                                cout << " 0. Exit Program" << endl;
                                cout << " 1. View and manage stock " << endl;
                                cout << " 2. View customer records " << endl;
                                cout << " 3. Add an Admin" << endl;
                                cout << " 4. Change User Name or PIN " << endl;
                                cout << " 5. Back" << endl;
                                cout << " Please enter your choice: ";
                                cin >> choice2;
                                cin . ignore();
                            }

                            if (choice2 == 0)//exit program
                            {
                                char exit='n';

                                do                
                                {
                                    cout <<endl <<" Do you really wish to exit program (y/n): ";
                                    cin >> exit;
                                    cin . ignore();

                                    while(exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
                                    {
                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout <<endl <<" Do you really wish to exit program (y/n): ";
                                        cin >> exit;
                                        cin . ignore();
                                    }

                                    if(exit=='y' ||exit=='Y')
                                    {   
                                        cout << endl << " Thank you for using the program" << endl;
                                        return 0;
                                    }

                                }while (exit == 'y'|| exit == 'Y');
                            }
                            else if (choice2 == 1) //stock updating
                            {
                                int choice = 0;

                                do
                                {
                                    cout <<setw(115) <<"====================" <<endl;
                                    cout . fill('.');
                                    cout <<setw(115) <<"|  MANAGING STOCK  |" <<setw(94) <<"";
                                    cout . fill(' ');
                                    cout <<setw(115) <<"====================" <<endl;
                                    cout <<endl;

                                    choice = 0;

                                    cout <<endl << " Please select one of following " << endl;
                                    cout << " 0. Exit Program" << endl;
                                    cout << " 1. View stock " << endl;
                                    cout << " 2. Add an item" << endl;
                                    cout << " 3. increase (or) decrease quantity of an item" << endl;
                                    cout << " 4. increase (or) decrease price of an item" << endl;
                                    cout << " 5. delete an item" << endl;
                                    cout << " 6. back" <<endl;
                                    cout << " Enter your choice: ";
                                    cin >> choice;
                                    cin . ignore();

                                    while (choice < 0 || choice > 6)
                                    {
                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout << " Please select one of following " << endl; 
                                        cout << " 0. Exit Program" << endl;
                                        cout << " 1. View stock " << endl;
                                        cout << " 2. Add an item" << endl;
                                        cout << " 3. increase (or) decrease quantity of an item" << endl;
                                        cout << " 4. increase (or) decrease price of an item" << endl;
                                        cout << " 5. delete an item" << endl;
                                        cout << " 6. back" <<endl;
                                        cout << " Enter your choice: ";
                                        cin >> choice;
                                        cin . ignore();
                                    }

                                    if(choice==0) //exit program
                                    {
                                        char exit='n';

                                        do
                                        {
                                            cout <<" Do you really wish to exit program (y/n): ";
                                            cin >> exit;
                                            cin . ignore();

                                            while(exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
                                            {
                                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout <<endl <<" Do you really wish to exit program (y/n): ";
                                                cin >> exit;
                                                cin . ignore();
                                            }   

                                            if(exit == 'y' || exit == 'Y')
                                            {
                                                cout << endl << " Thank you for using the program" << endl;
                                                return 0;
                                            }

                                        } while (exit == 'y' || exit == 'Y');
                                    }
                                    else if (choice == 1) //viewing stock
                                    {  
                                        char continueChoice = 'y';

                                        do
                                        {
                                            int itemCount = StockFileCount();
                                            string itemCode[itemCount];
                                            int itemQuantity[itemCount] = {0};
                                            int itemPrice[itemCount] = {0};
                                            string itemName[itemCount];

                                            inputsFromstockFile(itemCode, itemQuantity, itemPrice, itemName, itemCount);

                                            cout <<setw(115) <<"====================" <<endl;
                                            cout . fill('.');
                                            cout <<setw(115) <<"|  AVAILBLE STOCK  |" <<setw(94) <<"";
                                            cout . fill(' ');
                                            cout <<setw(115) <<"====================" <<endl;
                                            cout <<endl;
                        
                                            cout <<left;

                                            cout <<" " 
                                                <<setw(14) <<"Item Code "
                                                <<setw(42) <<"Item Name "
                                                <<setw(15) <<"Item Price"
                                                <<setw(16) <<"Item Quantity " <<endl <<endl;

                                            for(int i = 0 ; i < itemCount ; i++)
                                            {
                                                if(itemQuantity[i]==0)
                                                {
                                                    cout <<left;

                                                    cout <<" " <<setw(15) <<itemCode[i]
                                                    <<setw(41) <<itemName[i]
                                                    <<setw(16) <<itemPrice[i]
                                                    <<setw(16) <<"Out of Stock" <<endl;
                                                }
                                                else
                                                {
                                                    cout <<left;

                                                    cout <<" " <<setw(15) <<itemCode[i]
                                                    <<setw(41) <<itemName[i]
                                                    <<setw(16) <<itemPrice[i]
                                                    <<setw(16) <<itemQuantity[i] <<endl;
                                                }
                                            }
                                            cout <<endl <<endl;

                                            cout<<right;

                                            for(int i = 0 ; i < 209 ; i++)
                                            {
                                                cout <<"-";
                                            }

                                            cout <<endl <<endl <<"Please enter (y) to continue using program: ";
                                            cin >> continueChoice;
                                            cin . ignore();

                                            while (continueChoice != 'y' && continueChoice != 'Y')
                                            {
                                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout <<endl <<endl <<"Please enter (y) to continue using program: ";
                                                cin >> continueChoice;
                                                cin . ignore();
                                            }

                                        }while(continueChoice != 'y' && continueChoice != 'Y');
                                    }
                                    else if (choice == 2) //adding new item
                                    {
                                        char choice;

                                        cout << endl <<setw(119) << "-----ADDING A NEW ITEM-----" << endl <<endl;

                                        int count = StockFileCount();

                                        string itemCodeFile[count];
                                        int itemQuantityFile[count] = {0};
                                        int itemPriceFile[count] = {0};
                                        string itemNameFile[count];

                                        inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                        int newItems;

                                        cout << " Please enter the number of new items you wish to add: ";
                                        cin >> newItems;
                                        cin . ignore();

                                        while(newItems <= 0)
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout << " Please enter a valid number of new items you wish to add (value > 0): ";
                                            cin >> newItems;
                                            cin . ignore();
                                        }

                                        string newItemCode[newItems];
                                        int newItemQuantity[newItems] = {0};
                                        int newItemPrice[newItems] = {0};
                                        string newItemName[newItems];

                                        for (int i = 0 ; i < newItems ; i++)
                                        {
                                            int j = i;
                                            int found;

                                            do
                                            {
                                                found = 0;

                                                cout <<endl <<" Please enter for item number " << j + 1 << ": " << endl;

                                                cout << " Enter item code: ";
                                                cin >> newItemCode[i];
                                                cin . ignore();

                                                for (int k = 0 ; k < count ; k++)
                                                {
                                                    if (newItemCode[i] == itemCodeFile[k])
                                                    {
                                                        cout <<endl <<" This item code already exists! Please enter another one" <<endl;
                                                        found = 1;
                                                    }
                                                }

                                                for (int k = 0 ; k < i ; k++)
                                                {
                                                    if (newItemCode[i] == newItemCode[k])
                                                    {
                                                        cout <<endl <<" You have already entered this item code before! Please enter another one" <<endl;
                                                        found = 1;
                                                    }
                                                }

                                            } while (found == 1);

                                            cout << " Enter item's quantity: ";
                                            cin >> newItemQuantity[i];
                                            cin . ignore();

                                            while (newItemQuantity[i] < 0)
                                            {
                                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout << " Value can not be negative! Enter a valid quantity of the item : ";
                                                cin >> newItemQuantity[i];
                                                cin . ignore();
                                            }

                                            cout << " Enter item's price: ";
                                            cin >> newItemPrice[i];
                                            cin . ignore();

                                            while(newItemPrice[i] < 0)
                                            {
                                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout << " Value can not be negative! Enter a valid price of the item : ";
                                                cin >> newItemPrice[i];
                                                cin . ignore();
                                            }

                                            do
                                            {
                                                found = 0;

                                                cout << " Enter item name: ";
                                                getline(cin, newItemName[i]);

                                                for (int k = 0 ; k < count ; k++)
                                                {
                                                    if (newItemName[i] == itemNameFile[k])
                                                    {
                                                        cout <<endl <<" This item name already exists! Please enter another one" <<endl;
                                                        found = 1;
                                                    }
                                                }

                                                for (int k = 0 ; k < i ; k++)
                                                {
                                                    if (newItemName[i] == newItemName[k])
                                                    {
                                                        cout <<endl <<" You have already entered this item name before! Please enter another one" <<endl;
                                                        found = 1;
                                                    }
                                                }

                                            } while (found == 1);
                                        }

                                        ofstream fout;

                                        fout . open("stock.txt");

                                        if (! fout . fail())
                                        {
                                            for (int i = 0 ; i < newItems ; i++)
                                            {
                                                fout << newItemCode[i] << " "
                                                     << newItemQuantity[i] << " "
                                                     << newItemPrice[i] << " "
                                                     << newItemName[i] << endl;
                                            }

                                            for (int i = 0 ; i < count ; i++)
                                            {
                                                fout << itemCodeFile[i] << " "
                                                     << itemQuantityFile[i] << " "
                                                     << itemPriceFile[i] << " "
                                                     << itemNameFile[i] << endl;
                                            }

                                            fout . close();
                                            cout <<endl <<" All items are saved successfully!" << endl;
                                        }
                                        else
                                        {
                                            cout << endl <<" Error in editing stock.txt file " << endl;
                                        }

                                        cout << endl <<" Do you wish to add more items? (y/n): ";
                                        cin >> choice;
                                        cin . ignore();

                                        while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout << endl <<" Do you wish to add more items? (y/n): ";
                                            cin >> choice;
                                        }                        
                                    }
                                    else if (choice == 3) //editing quantity of an item
                                    {
                                        cout <<endl <<setw(117) << "-----EDITING QUANTITY-----" << endl <<endl;
                                        char again = 'y';

                                        do 
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            int itemPriceFile[count] = {0};
                                            string itemNameFile[count];
                               
                                            inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                            string searchCode;
                                            cout << " Please enter item code of the item : ";
                                            cin >> searchCode;
                                            cin . ignore();

                                            char choice;
                                            int changeQuantity = 0;
                                            int found = 0, itemIndex = 0 ,itemCheck = 0 ;

                                            for (int i = 0 ; i < count ; i++)
                                            {
                                                if (itemCodeFile[i] == searchCode)
                                                {
                                                    found = 1;
                                                    itemIndex = i;
                                                }
                                            }

                                            if(found==1)
                                            {
                                                cout << " Please enter '+' to increase the quantity (or) enter '-' to decrease the quantity of the item: ";
                                                cin >> choice;
                                                cin . ignore();

                                                while(choice != '+' && choice != '-')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Please enter '+' to increase the quantity (or) enter '-' to decrease the quantity of the item: ";
                                                    cin >> choice;
                                                    cin . ignore();
                                                }

                                                cout << " Please enter change in quantity: ";
                                                cin >> changeQuantity;
                                                cin . ignore();

                                                while (changeQuantity<0)
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Value can not be negative! Please enter a valid change in quantity: ";
                                                    cin >> changeQuantity;
                                                    cin . ignore();
                                                }
 
                                                if (choice == '+')
                                                {
                                                    itemQuantityFile[itemIndex] += changeQuantity;
                                                    itemCheck = 1;
                                                }
                                                else if (choice == '-')
                                                {
                                                    if (itemQuantityFile[itemIndex] >= changeQuantity)
                                                    {
                                                        itemQuantityFile[itemIndex] -= changeQuantity;
                                                        itemCheck = 1;
                                                    }
                                                    else
                                                    {                                               
                                                        cout <<endl << " Not enough stock to decrease from! Do you wish to try again? (y/n): ";
                                                        cin >> again;
                                                        cin . ignore();

                                                        while( again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                        {
                                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                            cout <<endl<< " Not enough stock to decrease from! Do you wish to try again? (y/n): ";
                                                            cin >> again;
                                                            cin . ignore();
                                                        }

                                                        itemCheck = 0;
                                                    }
                                                }                                        
                                            }    
                                            else if(found == 0)
                                            {
                                                cout <<endl<< " Item not found! Do you wish to try again with correct item code? (y/n): ";
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl<< " Item not found! Do you wish to try again with correct item code? (y/n): ";
                                                    cin >> again;
                                                    cin . ignore();
                                                }
                                            }
                                    
                                            if(itemCheck == 1)
                                            {   
                                                ofstream fout;

                                                fout . open("stock.txt");

                                                for (int i = 0 ; i < count ; i++)
                                                {
                                                    fout << itemCodeFile[i] << " " 
                                                        << itemQuantityFile[i] << " "
                                                        << itemPriceFile[i] << " " 
                                                        << itemNameFile[i] << endl;
                                                }

                                                fout . close();

                                                cout << " Quantity updated successfully!" << endl;
                                                cout <<endl <<" Do you wish to update another item? (y/n): ";
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl <<" Do you wish to update another item? (y/n): ";
                                                    cin >> again;
                                                    cin . ignore();
                                                }
                                            }
                                        } while (again != 'n' && again != 'N'); 
                                    }   
                                    else if (choice == 4) //editing price of an item
                                    {
                                        cout <<endl <<setw(118) << "-----EDITING PRICE-----" << endl <<endl;

                                        char again = 'y';

                                        do 
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            int itemPriceFile[count] = {0};
                                            string itemNameFile[count];
                               
                                            inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                            string searchCode;
                                            cout << " Enter item code: ";
                                            cin >> searchCode;
                                            cin . ignore();

                                            char choice;
                                            int changePrice = 0;
                                            int found = 0 , itemNumber = 0 , itemCheck = 0;

                                            for (int i = 0 ; i < count ; i++)
                                            {
                                                if (itemCodeFile[i] == searchCode)
                                                {
                                                    found = 1;
                                                    itemNumber = i;
                                                }
                                            }
                                            
                                            if(found==1)
                                            {
                                                cout << " Please enter '+' to increase the price (or) enter '-' to decrease the price of the item: ";
                                                cin >> choice;
                                                cin . ignore();

                                                while(choice != '+' && choice != '-')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Please enter '+' to increase the price (or) enter '-' to decrease the price of the item: ";
                                                    cin >> choice;
                                                    cin . ignore();
                                                }

                                                cout << " Please enter change in price of the item: ";
                                                cin >> changePrice;
                                                cin . ignore();

                                                while (changePrice < 0)
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Value can not be negative! Please enter a valid change in price of the item: ";
                                                    cin >> changePrice;
                                                    cin . ignore();
                                                }

                                                if (choice == '+')
                                                    {
                                                        itemPriceFile[itemNumber] += changePrice;
                                                        itemCheck = 1;
                                                    }
                                                else if (choice == '-')
                                                {
                                                    if (itemPriceFile[itemNumber] >= changePrice)
                                                    {
                                                        itemPriceFile[itemNumber] -= changePrice;
                                                        itemCheck = 1;
                                                    }
                                                    else
                                                    {
                                                        cout << " Not enough price to decrease from! Do you wish to try again? (y/n): ";
                                                        cin >> again;
                                                        cin . ignore();

                                                        while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                        {
                                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                            cout << " Not enough price to decrease from! Do you wish to try again? (y/n): ";
                                                            cin >> again;
                                                            cin . ignore();
                                                        }

                                                        itemCheck=0;
                                                    }
                                                }
                                            }
                                            else if (found == 0)
                                            {
                                                cout <<endl<< " Item not found! Do you wish to try again with correct item code? (y/n): ";
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl<< " Item not found! Do you wish to try again with correct item code? (y/n): ";
                                                    cin >> again;
                                                    cin . ignore();
                                                }
                                            }

                                            if(itemCheck == 1)
                                            {
                                                ofstream fout;

                                                fout . open("stock.txt");

                                                for (int i = 0; i < count; i++)
                                                {
                                                    fout << itemCodeFile[i] << " " 
                                                        << itemQuantityFile[i] << " " 
                                                        << itemPriceFile[i] << " " 
                                                        << itemNameFile[i] << endl;
                                                }

                                                fout . close();

                                                cout <<endl << " Price updated successfully!" << endl;
                                                cout <<endl <<" Do you wish to update another item's price? (y/n): ";
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout<<endl<<" Do you wish to update another item's price? (y/n): ";
                                                    cin>>again;
                                                    cin . ignore();
                                                }
                                            }   

                                        }while(again != 'n' && again != 'N'); 
                                    }

                                    else if (choice == 5) // deleting an item
                                    {
                                        cout <<endl <<setw(117) << "-----DELETING ITEM-----" << endl <<endl;

                                        char again = 'y';

                                        do
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            int itemPriceFile[count] = {0};
                                            string itemNameFile[count];
                               
                                            inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                            string deleteCode;
                                            cout << " Please enter item code for item to delete: ";
                                            cin >> deleteCode;
                                            cin . ignore();

                                            int itemCheck = 0, itemIndex = 0;

                                            for (int i = 0 ; i < count ; i++)
                                            {
                                                if (itemCodeFile[i] == deleteCode)
                                                {
                                                    itemCheck = 1;
                                                    itemIndex = i;
                                            
                                                }
                                            }

                                            if(itemCheck == 1)
                                            {
                                                ofstream fout;

                                                fout.open("stock.txt");

                                                for ( int i = 0 ; i < count ; i++)
                                                {
                                                    if (i != itemIndex)
                                                    {
                                                        fout << itemCodeFile[i] << " " 
                                                            << itemQuantityFile[i] << " " 
                                                            << itemPriceFile[i] << " " 
                                                            << itemNameFile[i] << endl;
                                                    }
                                                }
                                                fout . close();

                                                cout <<endl << " Item deleted successfully!" << endl;
                                                cout <<endl <<" Do you wish to delete another item? (y/n): ";
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl <<" Do you wish to delete another item? (y/n): ";
                                                    cin >> again;
                                                    cin . ignore();
                                                }
                                            }
                                            else if (itemCheck == 0)
                                            {
                                                cout <<endl << " Item not found! Do you wish to try again with correct item code? (y/n): " ;
                                                cin >> again;
                                                cin . ignore();

                                                while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl <<" Item not found! Do you wish to try again with correct item code? (y/n): ";
                                                    cin >> again;
                                                    cin . ignore();
                                                }
                                            }

                                       }while (again != 'n' && again != 'N');
                                    }   
                                }while(choice != 6);
                            }   
                            else if (choice2 == 2)//customer record management
                            {
                                int billNumber;
                                int customerRcordCount1 = customerRecordCount();

                                int customerBill[customerRcordCount1] = {0};
                                int customerTotal[customerRcordCount1] = {0};

                                string customerPhone[customerRcordCount1];
                                string billTime[customerRcordCount1];
                                string billDay[customerRcordCount1];
                                string billMonth[customerRcordCount1];
                                string billDate[customerRcordCount1];
                                string customerName[customerRcordCount1];

                                inputsFromCustomerRecordFile(customerBill, customerTotal, customerPhone,billTime,billDay,billMonth,billDate, customerName, customerRcordCount1);

                                cout  <<endl << setw(115) << "-----CUSTOMER RECORD-----" << endl <<endl;

                                int found = 0;
                                char continueChoice = 'y';

                                do
                                {
                                    found = 0;
                                    int foundBill = 0;
                        
                                    cout <<endl<<" Please enter Bill Number of the record you wish to view: ";
                                    cin >> billNumber;
                                    cin . ignore();

                                    for(int i=0 ; i<customerRcordCount1 ; i++)
                                    {
                                        if(customerBill[i] == billNumber)
                                        {
                                            found = 1;
                                            foundBill = i;
                                        }
                                    }

                                    if(found == 1)
                                    {
                                        cout <<endl <<" Record found!" << endl <<endl;
                                        cout <<" Bill number             : " <<customerBill[foundBill] <<endl;
                                        cout <<" Customer name           : " <<customerName[foundBill] <<endl;
                                        cout <<" Customer phone number   : " <<customerPhone[foundBill] <<endl;
                                        cout <<" Time of bill generation : " <<billTime[foundBill] <<endl;
                                        cout <<" Date of bill generation : " <<billDay[foundBill] <<" " <<billMonth[foundBill] <<" " <<billDate[foundBill] <<endl;
                                        cout <<" Total amount of bill    : " <<customerTotal[foundBill] <<endl <<endl;

                                        cout << endl <<" Do you wish to view another record? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();

                                        while (continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<endl <<" Do you wish to view another record? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }
                                    }
                                    else if(found == 0)
                                    {
                                        cout <<endl <<" Record with this bill number not found! Please try again with correct bill number." << endl;
                                        cout <<endl <<" Do you wish to try again? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();

                                        while(continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout << " Do you wish to try again? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }
                                    }

                                }while(continueChoice == 'y' || continueChoice == 'Y');
                            }
                            else if (choice2 == 3) //adding new admin
                            {
                                cout <<endl <<setw(118) << "-----ADDING NEW ADMIN-----" << endl <<endl;

                                char TryAgain = 'n';
                                int adminCheck = 0;
                                int newAdminPin = 0;
                                string newAdminName;

                                do
                                {
                                    adminCheck = 0;
                                    TryAgain = 'n';

                                    cout << " Please enter new admin user name: ";
                                    getline (cin, newAdminName);

                                    for(int i=0 ; i < adminCount ; i++)
                                    {
                                        if(newAdminName == adminname[i])
                                        {
                                            adminCheck = 1;
                                        }
                                    }

                                    if(adminCheck == 0)
                                    {
                                        cout << " Please enter new admin Pin: ";
                                        cin >> newAdminPin;
                                        cin . ignore();
                                    }
                                    else if (adminCheck == 1)                            
                                    {
                                        cout <<endl <<" Admin with this username already exists! do you wish to try again(y/n): ";
                                        cin >> TryAgain;
                                        cin . ignore();

                                        while(TryAgain != 'y' && TryAgain != 'Y' && TryAgain != 'n' && TryAgain != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<endl <<" Admin with this username already exists! do you wish to try again(y/n): ";
                                            cin >> TryAgain;
                                            cin . ignore();
                                        }
                                    }
                                }while(TryAgain == 'y' || TryAgain == 'Y');

                                if(adminCheck == 0) 
                                {
                                    fout . open("Admin.txt");

                                    if (! fout . fail())
                                    {
                                        fout << newAdminPin << " " << newAdminName << endl;
                                        for (int i = 0 ; i < adminCount ; i++)
                                        {
                                            fout << adminPin[i] << " " << adminname[i] << endl;
                                        }

                                        fout . close();

                                        cout <<endl <<endl <<" New admin added successfully!" << endl;
                                    }
                                    else
                                    {
                                        cout << endl;
                                        cout << " Error!\aCould not open Admin.txt file for adding a new admin" << endl;
                                    }
                                }
                            }
                            else if (choice2 == 4) //editing admin's username or pin
                            {
                                char newUserTryAgain = 'n';

                                do
                                {
                                    cout <<setw(119) <<"=========================" <<endl;
                                    cout . fill('.');
                                    cout <<setw(119) <<"|  EDITING CREDENTIALS  |" <<setw(90) <<"";
                                    cout . fill(' ');
                                    cout <<setw(119) <<"=========================" <<endl;
                                    cout <<endl;

                                    cout <<endl << " Please select one of following:" << endl;
                                    cout << " 0. Exit" << endl;
                                    cout << " 1. Change username" << endl;
                                    cout << " 2. Change Pin" << endl;
                                    cout << " 3. Back" << endl;
                                    cout << " Enter choice: ";
                                    cin >> choice4;
                                    cin . ignore();

                                    while (choice4 < 0 || choice4 > 3)
                                    {
                                        cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout <<endl<< " Please select one of following:" << endl;
                                        cout << " 0. Exit" << endl;
                                        cout << " 1. Change username" << endl;
                                        cout << " 2. Change Pin" << endl;
                                        cout << " 3. Back" << endl;
                                        cout << " Enter choice: ";
                                        cin >> choice4;
                                        cin . ignore();
                                    }
                                    
                                    if (choice4 == 0) //exit program
                                    {
                                         char exit = 'n';
                                        do                
                                        {
                                            cout <<" Do you really wish to exit program (y/n): ";
                                            cin >> exit;
                                            cin . ignore();

                                            while (exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
                                            {
                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout <<" Do you really wish to exit program (y/n): ";
                                                cin >> exit;
                                                cin . ignore();
                                            }
                                    
                                           if(exit == 'y' || exit == 'Y')
                                            {   
                                                cout << endl << " Thank you for using the program" << endl;
                                                return 0;
                                            }

                                        }while(exit == 'y' || exit == 'Y');                        
                                    }
                                    else if (choice4 == 1) // changing username
                                    { 
                                        cout <<endl <<setw(117) << "-----CHANGING USERNAME-----" << endl <<endl;
                                        
                                        int newUserCheck = 0;
                                        string newUserName;

                                        do
                                        {
                                            newUserTryAgain = 'n';                                            
                                            newUserCheck = 0;

                                            cout << " Please enter your new username: ";
                                            getline (cin, newUserName);
                                            
                                            for(int i = 0 ; i < adminCount ; i++)
                                            {
                                                if(newUserName == adminname[i])                                                
                                                {
                                                    newUserCheck = -1;
                                                }
                                            }
                                            
                                            if(newUserCheck == -1)
                                            {
                                                cout <<endl <<" Admin with this username already exists! do you wish to try again(y/n): ";
                                                cin >> newUserTryAgain;
                                                cin . ignore();

                                                while(newUserTryAgain != 'y' && newUserTryAgain != 'Y' && newUserTryAgain != 'n' && newUserTryAgain != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<endl<<" Admin with this username already exists! do you wish to try again(y/n): ";
                                                    cin >> newUserTryAgain;
                                                    cin . ignore();
                                                }
                                            }
                                            else
                                            {
                                                newUserCheck = 0;
                                                newUserTryAgain = 'n';
                                            }   

                                        }while(newUserCheck == -1 && (newUserTryAgain == 'y' || newUserTryAgain == 'Y'));
                                        
                                        if(newUserCheck == 0 && (newUserTryAgain == 'n' || newUserTryAgain == 'N'))
                                        {
                                            choice4 = 3;
                                            choice2 = 5;

                                            fout . open("Admin.txt");

                                            if ( ! fout . fail())
                                            {
                                                for (int i = 0 ; i < adminCount ; i++)
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

                                                fout . close();

                                                cout << endl << " Admin's username is updated successfully! Please login again with your new username." << endl<<endl;
                                            }
                                            else
                                            {
                                                cout << endl;
                                                cout << " Error!\aCould not open Admin.txt file for editing admin's username" << endl;
                                            }
                                        }
                                    }
                                    else if (choice4 == 2) // changing pin
                                    {
                                        cout << endl <<setw(117) << "-----CHANGING PIN-----" << endl <<endl;

                                        int newUserPin = 0;
                                        int adminNumber = 0;
                                        int newUserCheck = 0;
                                        
                                        do
                                        {
                                            adminNumber = 0;
                                            
                                            cout <<endl << " Please enter your new Pin: ";
                                            cin >> newUserPin;
                                            cin . ignore();

                                            for(int i = 0 ; i < adminCount ; i++)
                                            {
                                                if(userName == adminname[i])                                                
                                                {
                                                    adminNumber = i;
                                                }
                                            }
                                    
                                            if(newUserPin == adminPin[adminNumber])
                                            {
                                                cout <<endl <<" The Pin you entered is already saved as your current Pin. Please enter a different Pin"<<endl<<endl; 
                                                cout <<"Do you wish to try again(y/n): ";
                                                cin >> newUserTryAgain;
                                                cin . ignore();

                                                while(newUserTryAgain != 'y' && newUserTryAgain != 'Y' && newUserTryAgain != 'n' && newUserTryAgain != 'N')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<" Do you wish to try again(y/n): ";
                                                    cin >> newUserTryAgain;
                                                    cin . ignore();
                                                }

                                                newUserCheck = 1;
                                            }
                                            else
                                            {
                                                newUserCheck = 0;
                                                newUserTryAgain = 'n';
                                            }
                                
                                        }while(newUserCheck == 1 && (newUserTryAgain == 'y'|| newUserTryAgain == 'Y'));
                                        
                                        if( newUserCheck == 0 && (newUserTryAgain == 'n'|| newUserTryAgain == 'N'))
                                        {                                        
                                            choice4 = 3;
                                            choice2 = 5;

                                            fout . open("Admin.txt");

                                            if ( ! fout . fail())
                                            {
                                                for (int i = 0 ; i < adminCount ; i++)
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

                                                fout . close();

                                                cout << endl << " Admin's Pin is updated successfully! Please login again with your new Pin." << endl<<endl;                                   
                                            }
                                            else
                                            {
                                                cout << endl;
                                                cout << " Error!\aCould not open Admin.txt file for editing admin's Pin" << endl;
                                            }
                                        }
                                    }
                                } while (choice4 != 3);
                            }
                        } while (choice2 != 5);
                    }
                    else
                    {
                        choice2 = 5;
                    }
                }while (choice2 != 5);
            }
            else if (choice1 == 2) //user work ara
            { 
                cout<<endl <<setw (115) << "-----WELCOME USER-----" << endl <<endl;

                do
                {

                    cout <<setw(113) <<"===================" <<endl;
                    cout . fill('.');
                    cout <<setw(113) <<"|  USER CONTROLS  |" <<setw(96) <<"";
                    cout . fill(' ');
                    cout <<setw(113) <<"===================" <<endl;
                    cout <<endl;

                    int choice3;
                    ofstream fout;
                    ifstream fin;

                    cout <<endl <<" Please select one of following:" <<endl;
                    cout <<" 0. Exit Program"<<endl;
                    cout <<" 1. Search an Item from stock" <<endl;
                    cout <<" 2. Generate Bill" <<endl;
                    cout <<" 3. Back" <<endl;
                    cout <<" Enter your choice: ";
                    cin >> choice2;
                    cin . ignore();
                   

                    while( choice2 < 0 || choice2 > 3)
                    { 
                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                        cout <<" PLease select one of following:" <<endl;
                        cout <<" 0. Exit Program" <<endl;
                        cout <<" 1. Search an Item from stock" <<endl;
                        cout <<" 2. Generate Bill" <<endl;
                        cout <<" 3. Back" <<endl;
                        cout <<" Enter your choice: ";
                        cin >> choice2;
                        cin . ignore();
                    }

                    cout<<endl;

                    if( choice2 == 0) //exit program
                    {
                        char exit = 'n';

                        do                
                        {
                            cout <<endl <<" Do you really wish to exit program (y/n): ";
                            cin >> exit;
                            cin . ignore();

                            while(exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                cout <<" Do you really wish to exit program (y/n): ";
                                cin >> exit;
                                cin . ignore();
                            }

                            if(exit == 'y' || exit == 'Y')                                
                            {   
                                cout << endl << " Thank you for using the program" << endl;
                                return 0;
                            }

                        }while(exit == 'y' || exit == 'Y'); 
                    }
                    else if(choice2 == 1) //searching an item from stock
                    {
                        char continueChoice = 'y';

                        do
                        {
                            cout <<setw(114) <<"====================" <<endl;
                            cout . fill('.');
                            cout <<setw(114) <<"|  SEARCHING ITEM  |" <<setw(95) <<"";
                            cout . fill(' ');
                            cout <<setw(114) <<"====================" <<endl;
                            cout <<endl;

                            cout << " Please select one of following:" <<endl;
                            cout <<" 0. Exit Program" <<endl;
                            cout <<" 1. Search item by item name" <<endl;
                            cout <<" 2. Search item by item code" <<endl;
                            cout <<" 3. Back"<<endl;
                            cout <<" Enter your choice: ";
                            cin >> choice3;
                            cin . ignore();

                            while( choice3 < 0 || choice3 > 3)
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                
                                cout <<" Please select one of following:" <<endl;
                                cout <<" 0. Exit Program" <<endl;
                                cout <<" 1. Search item by item name" <<endl;
                                cout <<" 2. Search item by item code" <<endl;
                                cout <<" 3. Back" <<endl;
                                cout <<" Enter your choice: ";
                                cin >> choice3;
                                cin . ignore();
                               
                            }

                            cout <<endl;

                            int fileItemCount = StockFileCount();

                            string fileItemCodes[fileItemCount] ;
                            int fileItemQuantity[fileItemCount] = {0};
                            int fileItemPrice[fileItemCount] = {0};
                            string fileItemNames[fileItemCount];

                            inputsFromstockFile(fileItemCodes, fileItemQuantity, fileItemPrice, fileItemNames, fileItemCount);

                            if(choice3 == 0) //exit program
                            {
                                char exit = 'n';

                                do                
                                {
                                    cout <<" Do you really wish to exit program (y/n): ";
                                    cin >> exit;
                                    cin . ignore();

                                    while(exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
                                    {
                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout <<" Do you really wish to exit program (y/n): ";
                                        cin >> exit;
                                        cin . ignore();
                                    }

                                    if(exit == 'y' || exit == 'Y')
                                    {   
                                        cout << endl << " Thank you for using the program" << endl;
                                        return 0;
                                    }

                                }while (exit == 'y' || exit == 'Y'); 
                            }
                            else if(choice3 == 1) //searching item by name
                            {  
                                cout << endl <<setw(120) << "-----SEARCHING ITEM BY NAME-----" << endl <<endl;
                                
                                do
                                {
                                    string userItemName;
                                    int searchedItemNumber = -1;

                                    cout <<endl <<" Please enter item name: ";
                                    getline (cin,userItemName);
                                    
                                    for(int i=0 ; i < fileItemCount; i++ )
                                    {
                                        if(fileItemNames[i] == userItemName)
                                        {
                                            searchedItemNumber = i;
                                        }
                                    }
                        
                                    if(searchedItemNumber != -1)
                                    {
                                        if(fileItemQuantity[searchedItemNumber] == 0)
                                        {
                                            cout <<endl <<" The Item you Searched :" <<endl <<endl;
                                            cout <<" Item Code: " <<fileItemCodes[searchedItemNumber] <<endl;
                                            cout <<" Item Name: " <<fileItemNames[searchedItemNumber] <<endl;
                                            cout <<" Item Quantity: " <<"Out of Stock"<<endl;
                                            cout <<" Item Price: " <<fileItemPrice[searchedItemNumber] <<endl;
                                            cout <<endl <<endl; 
                                        }
                                        else
                                        {
                                            cout <<endl <<" The Item you Searched :" <<endl <<endl;
                                            cout <<" Item Code: " <<fileItemCodes[searchedItemNumber] <<endl;
                                            cout <<" Item Name: " <<fileItemNames[searchedItemNumber] <<endl;
                                            cout <<" Item Quantity: " <<fileItemQuantity[searchedItemNumber] <<endl;
                                            cout <<" Item Price: " <<fileItemPrice[searchedItemNumber] <<endl;
                                            cout <<endl <<endl;
                                        }

                                        cout << " Do you wish to search for another item? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();


                                        while(continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<" Do you wish to search for another item? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }        
                                    }
                                    else
                                    {
                                        cout << endl;
                                        cout <<" The item you searched does not exist in stock"<<endl
                                             <<" Try searching again with item code or exact item name"<<endl<<endl;
                                        cout <<" Do you wish to try again? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();

                                        while(continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<" Do you wish to try again? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }
                                    }

                                }while(continueChoice == 'y' || continueChoice == 'Y');
                            }
                            else if(choice3==2) //searching item by code
                            {
                                cout << endl << setw(120) << "-----SEARCHING ITEM BY CODE-----" << endl <<endl;

                                do
                                {
                                    string userItemCode;
                                    int searchedItemNumber = -1;

                                    cout <<endl <<" Please enter item code: ";
                                    cin >> userItemCode;
                                    cin . ignore();
                
                                    for(int i = 0 ; i < fileItemCount ; i++ )
                                    {
                                        if(fileItemCodes[i] == userItemCode)
                                        {
                                            searchedItemNumber = i;
                                        }
                                    }

                                    if(searchedItemNumber != -1)
                                    {
                                        if(fileItemQuantity[searchedItemNumber] == 0)
                                        {
                                            cout <<endl <<" The Item you Searched :" <<endl <<endl;
                                            cout <<" Item Code: " <<fileItemCodes[searchedItemNumber] <<endl;
                                            cout <<" Item Name: " <<fileItemNames[searchedItemNumber] <<endl;
                                            cout <<" Item Quantity: " <<"Out of Stock"<<endl;
                                            cout <<" Item Price: " <<fileItemPrice[searchedItemNumber] <<endl;
                                            cout <<endl <<endl; 
                                        }
                                        else
                                        {
                                            cout <<endl <<" The Item you Searched :" <<endl <<endl;
                                            cout <<" Item Code: " <<fileItemCodes[searchedItemNumber] <<endl;
                                            cout <<" Item Name: " <<fileItemNames[searchedItemNumber] <<endl;
                                            cout <<" Item Quantity: " <<fileItemQuantity[searchedItemNumber] <<endl;
                                            cout <<" Item Price: " <<fileItemPrice[searchedItemNumber] <<endl;
                                            cout <<endl <<endl;
                                        }

                                        cout <<" Do you wish to search for another item? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();

                                        while(continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<" Do you wish to search for another item? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }
                                    }
                                    else
                                    {
                                        cout << endl;
                                        cout <<" The item you searched does not exist in stock"<<endl
                                             <<" Try searching again with item name or exact item code"<<endl<<endl;
                                        cout <<" Do you wish to try again? (y/n): ";
                                        cin >> continueChoice;
                                        cin . ignore();

                                        while(continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N')
                                        {
                                            cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<" Do you wish to try again? (y/n): ";
                                            cin >> continueChoice;
                                            cin . ignore();
                                        }
                                    }

                               }while(continueChoice == 'y' || continueChoice == 'Y');
                            }

                        }while(choice3 != 3);
                    }
                    else if(choice2 == 2) //generating bill
                    {
                        char anotherReceipt = 'y';
                        int donecheck = 0;
                        do
                        {
                            int boughtItemPrice = 0;
                            int boughtItemCount = 0;
                            int itemTotal = 0;

                            int choice2 = 2 , choice3;

                            int itemCount=StockFileCount();

                            int remainingItemQuantity[500]= {0};

                            string boughtItemCodes[500];
                            int boughtItemtotal[500] = {0};
                            int boughtItemPrices[500] = {0};
                            int BoughtItemQuantity[500] = {0};
                            string boughtItemNames[500];

                            string itemCode[itemCount];
                            int itemQuantity[itemCount] = {0};
                            int itemPrice[itemCount] = {0};
                            string itemName[itemCount];

                            inputsFromstockFile(itemCode, itemQuantity, itemPrice, itemName, itemCount);

                            cout <<setw(114) <<"===================" <<endl;
                            cout . fill('.');
                            cout <<setw(114) <<"| AVAILBLE STOCK  |" <<setw(95) <<"";
                            cout . fill(' ');
                            cout <<setw(114) <<"===================" <<endl;
                            cout <<endl;
                        
                            cout << left;

                            cout <<" " <<setw(14) <<"Item Code "
                                <<setw(43) <<"Item Name "
                                <<setw(15) <<"Item Price"
                                <<setw(16) <<" Item Quantity " <<endl <<endl;

                            for(int i = 0 ; i < itemCount ; i++)
                            {

                                if(itemQuantity[i]==0)
                                {
                                    cout <<" " <<setw(15) <<itemCode[i]
                                    <<setw(43) <<itemName[i]
                                    <<setw(16) <<itemPrice[i]
                                    <<setw(16) <<"Out of Stock" <<endl;
                                }
                                else
                                {
                                cout <<" " <<setw(15) <<itemCode[i]
                                    <<setw(43) <<itemName[i]
                                    <<setw(15) <<itemPrice[i]
                                    <<setw(16) <<itemQuantity[i] <<endl;
                                }
                            }

                            cout <<endl <<endl;

                            cout<<right;

                            cout <<setw(111) <<"=============" <<endl;
                            cout . fill('.');
                            cout <<setw(111) <<"|  BILLING  |" <<setw(98) <<"";
                            cout . fill(' ');
                            cout <<setw(111) <<"=============" <<endl;
                            cout <<endl;

                            cout <<endl <<endl;
                            char again = 'y';
                            string boughtItem;
                            int boughtItemNumber = -1, boughtItemQuantity = 0;

                            do
                            {
                                boughtItemNumber = -1;
                                cout <<" Please enter item code of the item: ";
                                cin >> boughtItem;
                                cin . ignore();

                                for(int i=0 ; i < itemCount ; i++)
                                {
                                    if(boughtItem == itemCode[i])
                                    {
                                        boughtItemNumber = i;
                                    }
                                }                        

                                if(boughtItemNumber != -1)
                                {
                                    cout <<" Please enter the quantity of item: ";
                                    cin >> boughtItemQuantity;
                                    cin . ignore();

                                    if(boughtItemQuantity <= itemQuantity[boughtItemNumber])
                                    {
                                        itemQuantity[boughtItemNumber] -= boughtItemQuantity;

                                        boughtItemPrice = itemPrice[boughtItemNumber];
                                        itemTotal = boughtItemPrice * boughtItemQuantity;

                                        boughtItemCodes[boughtItemCount] = boughtItem;
                                        boughtItemNames[boughtItemCount] = itemName[boughtItemNumber];
                                        boughtItemPrices[boughtItemCount] = itemPrice[boughtItemNumber];
                                        boughtItemtotal[boughtItemCount] = itemTotal;
                                        BoughtItemQuantity[boughtItemCount] = boughtItemQuantity;

                                        boughtItemCount++;
         

                                            cout <<endl <<" Do you wish to purchase another Item (y/n): ";
                                            cin >> again;
                                            cin . ignore();

                                            while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                            {
                                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout <<" Do you wish to purchase another Item (y/n): ";
                                                cin >> again;
                                                cin . ignore();
                                                cout <<endl;
                                            }
                                            donecheck =0;
                                       
                                    }
                                    else
                                    {
                                        cout <<" The quantity u entered " <<boughtItemQuantity
                                            <<" is greater than availble quantity "
                                            <<itemQuantity[boughtItemNumber] <<endl;

                                        cout <<endl <<" Do you wish to try again? (y/n): ";
                                        cin >> again;
                                        cin . ignore();

                                        while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout <<" Do you wish to try again? (y/n): ";
                                            cin >> again;
                                            cin . ignore();
                                        }
                                        donecheck = 1;
                                    }
                                }
                                else
                                {
                                    cout <<endl <<endl<<" Invalid\aInput The item code does not exist "<<endl;
                                    cout <<endl<<" Do you wish to try again? (y/n): ";
                                    cin >> again;
                                    cin . ignore();

                                    while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
                                    {
                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout <<" Do you wish to try again? (y/n): ";
                                        cin >> again;
                                        cin . ignore();
                                    }
                                    donecheck = 1;
                                }                            
                            } while(again != 'n' && again != 'N');

                            
                            string time, date;

                            timeAndDate(date,time);

                            int RecordCount = customerRecordCount();
                            
                            int billNo[RecordCount] = {0};
                            int CustomerTotal[RecordCount] = {0};

                            string customerPhone[RecordCount];
                            string customerName[RecordCount];
                            string customerTime[RecordCount];
                            string customerDate[RecordCount];
                            string customerDateDay[RecordCount];
                            string customerDateMonth[RecordCount];

                            inputsFromCustomerRecordFile(billNo ,CustomerTotal, customerPhone, customerTime, customerDateDay, customerDateMonth, customerDate, customerName, RecordCount);
        
                            int grandTotal = 0;
                            string customername, customerphone;

                            cout <<" Please enter coustomer name: ";
                            getline (cin,customername);

                            cout<<" Please enter coustomer phone number: ";
                            getline (cin,customerphone);

                            int customerBillNo = RecordCount + 1;

                            cout << right;
                             
                            cout << setw(111)<<"=============" <<endl;
                            cout . fill('.');
                            cout << setw(111)<<"|  RECIEPT  |" <<setw(98) <<"";
                            cout . fill(' ');
                            cout << setw(111)<<"=============" <<endl;

                            cout << endl;

                            cout << left;

                            cout <<" Date          : " <<date <<endl;
                            cout <<" Time          : " <<time <<endl;
                            cout <<" Bill Number   : " <<customerBillNo <<endl;
                            cout <<" Customer Name : " <<customername <<endl;
                            cout <<" Phone Number  : " <<customerphone <<endl <<endl;
                        
                            cout <<" " <<setw(14) <<"Item Code "
                                <<setw(42) <<"Item Name "
                                <<setw(15) <<"Item Price"
                                <<setw(15) <<" Item Quantity "
                                <<setw(16) <<"Item Total" <<endl <<endl;

                            for(int i=0 ; i < boughtItemCount ; i++)
                            {
                                cout <<" " <<setw(15) <<boughtItemCodes[i]
                                    <<setw(42) <<boughtItemNames[i]
                                    <<setw(15) <<boughtItemPrices[i]
                                    <<setw(15) <<BoughtItemQuantity[i] 
                                    <<setw(16) <<boughtItemtotal[i] <<endl;

                                grandTotal += boughtItemtotal[i];
                            }

                            cout <<endl <<endl;
                            cout <<endl <<" Grand total: " <<grandTotal <<endl;

                            cout << right;

                            for(int i = 0 ; i < 209 ; i++)
                            {
                                cout <<"-";
                            }

                            cout << endl;

                            ofstream fout;

                            fout . open("customerRecord.txt");

                            if( ! fout . fail())
                            {
                                
                                fout <<customerBillNo <<" "
                                    <<grandTotal <<" "
                                    <<customerphone <<" "
                                    <<time <<" "
                                    <<date <<" "
                                    <<customername;

                                for(int i = 0 ; i < RecordCount ; i++)
                                {
                                    fout <<endl << billNo[i] <<" "
                                        <<CustomerTotal[i] <<" "
                                        <<customerPhone[i] <<" "
                                        <<customerTime[i] <<" "
                                        <<customerDateDay[i] <<" "
                                        <<customerDateMonth[i] <<" "
                                        <<customerDate[i] <<" "
                                        <<customerName[i];
                                }

                                fout . close();
                            }
                            else
                            {
                                cout <<endl <<" Error\a could not update customer record file after generating receipt"<<endl;
                            }

                            fout . open("receipt.txt");

                            if( ! fout . fail())
                            {
                                fout <<left;

                                fout <<"Date: " <<date <<endl;
                                fout <<"Time: " <<time <<endl;
                                fout <<"Bill Number: " <<customerBillNo <<endl;
                                fout <<"Customer Name: " <<customername <<endl;
                                fout <<"Phone Number: " <<customerphone <<endl;

                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }
                                
                                fout<<endl<<"                        Original Bill "<<endl;

                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }
                                fout<<endl <<"Product Details: " <<endl
                                    <<"Code\tPrice\tQuantity\tTotal"
                                    <<endl;

                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }

                                fout<<endl<<"                          Sales Items "<<endl;

                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }
                                fout<<endl;

                                for(int i = 0 ; i < boughtItemCount ; i++)
                                {
                                    fout<< boughtItemNames[i] <<endl 
                                    <<boughtItemCodes[i] <<"\t" << boughtItemPrices[i] <<"\t" <<BoughtItemQuantity[i] <<"\t" << boughtItemtotal[i] <<endl;
                                }
                        
                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }
                                fout <<endl;
                                fout << "Invoice Value: " <<grandTotal <<endl;

                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }

                                fout <<endl;


                                fout.close();

                                cout <<endl <<" Receipt is generated successfully! Please check receipt.txt file."<<endl;                         
                            }
                            else
                            {
                                cout <<endl <<" Error!\a in generating receipt file."<<endl;
                            }

                            if(donecheck == 0)
                            {
                               ofstream fout;

                                fout . open("stock.txt");

                                if( ! fout . fail())
                                {
                                    for(int i = 0 ; i < itemCount ; i++)
                                    {
                                        fout <<itemCode[i] <<" ";
                                        fout <<itemQuantity[i] <<" ";
                                        fout <<itemPrice[i] <<" ";
                                        fout <<itemName[i] <<endl;
                                    }

                                    fout . close();
                                }   
                                else
                                {
                                    cout <<endl <<" Error!\a Could not open stock.txt file for updating stock after generating bill" << endl;
                                }
                            }
                            cout<<endl<<"Stock is updated successfully after generating bill!"<<endl;

                            cout <<endl <<" Do you wish to generate another receipt? (Y/N): ";
                            cin >> anotherReceipt;
                            cin . ignore();

                            while(anotherReceipt != 'y' && anotherReceipt != 'Y' && anotherReceipt != 'n' && anotherReceipt != 'N')
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                cout <<" Do you wish to generate another receipt? (Y/N): ";
                                cin >> anotherReceipt;
                                cin . ignore();
                            }                           
                        } while(anotherReceipt != 'n' && anotherReceipt != 'N');
                    }
                }while(choice2 != 3);
            }
        }while(choice1 != 0); 

        cout << " Do you really wish to exit program (y/n): ";
        cin >> firstTimeExit;
        cin . ignore();

        while(firstTimeExit != 'y' && firstTimeExit != 'Y' && firstTimeExit != 'n' && firstTimeExit != 'N')
        {
            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
            cout <<" Do you really wish to exit program (y/n): ";
            cin >> firstTimeExit;
            cin . ignore();
        }

        if(firstTimeExit == 'y' || firstTimeExit == 'Y')
        {   
            cout << endl << " Thank you for using the program" << endl;                            
            return 0;
        }
    }while(firstTimeExit == 'n' || firstTimeExit == 'N'); 
}

//functions

int customerRecordCount()
{
    string coustomerName, customerPhone ,Day, Month, Date, Time;
    int customerRecordCount = 0, billNo = 0, total = 0;

    ifstream fin;

    fin.open("customerRecord.txt");

    if ( ! fin . fail())
    {
        while (fin >> billNo)
        {
            fin >>total;
            fin >>customerPhone;
            fin >>Time;
            fin >>Day;
            fin >>Month;
            fin >>Date;
            fin . ignore();
            getline (fin, coustomerName);

            customerRecordCount++;
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open customerRecord.txt file" << endl;
    }

    return customerRecordCount;
}

void inputsFromCustomerRecordFile(int billNo[], int CustomerTotal[], string customerPhone[], string customerTime[], string customerDateDay[], string customerDateMonth[], string customerDate[], string customerName[], int customerRecordCount)
{
    ifstream fin;

    fin . open("customerRecord.txt");

    if ( ! fin . fail())
    {
        for (int i = 0 ; i < customerRecordCount ; i++)
        {
            fin >> billNo[i];
            fin >> CustomerTotal[i];
            fin >> customerPhone[i];
            fin >> customerTime[i];
            fin >> customerDateDay[i];
            fin >> customerDateMonth[i];
            fin >> customerDate[i];
            fin . ignore();

            getline (fin, customerName[i]);
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open customerRecord.txt file" << endl;
    }
}

int StockFileCount()
{
    string fileItemName, fileItemCode;
    int fileItemPrice = 0, fileItemCount = 0, fileItemQuanity = 0;

    ofstream fout;
    ifstream fin;

    fin . open("stock.txt");

    if ( ! fin . fail())
    {
        while(fin >> fileItemCode)
        {
            fin >> fileItemQuanity;
            fin >> fileItemPrice;
            fin . ignore();

            getline (fin,fileItemName);
       
            fileItemCount++;    
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open stock.txt file"<<endl;
    }

    return fileItemCount;
}

void inputsFromstockFile(string fileItemCodes[], int fileItemQuantity[], int fileItemprice[], string fileitemName[], int fileItemCount)
{
    ifstream fin;

    fin . open("stock.txt");

    if( ! fin . fail())
    {
        for(int i = 0 ; i < fileItemCount ; i++)
        {
            fin >> fileItemCodes[i];
            fin >> fileItemQuantity[i];
            fin >> fileItemprice[i];
            fin . ignore();

            getline (fin,fileitemName[i]);
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open stock.txt file"<<endl;
    }
}

int adminFileCount()
{
    string fileAdminName;
    int fileAdminPin = 0, fileAdminCount = 0;

    ifstream fin;

    fin . open("Admin.txt");

    if (! fin . fail())
    {
        while (fin >> fileAdminPin)
        {
            fin . ignore();

            getline (fin, fileAdminName);

            fileAdminCount++;
        }

        fin . close();
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

    fin . open("Admin.txt");

    if ( ! fin . fail())
    {
        for (int i = 0 ; i < fileAdminCount ; i++)
        {
            fin >> fileAdminPins[i];
            fin . ignore();

            getline (fin, fileAdminNames[i]);
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open Admin.txt file" << endl;
    }
}

void timeAndDate( string &currentDate, string &exactTime)
{
    time_t now = time(0);
   string fulltime = ctime(&now);
    currentDate = fulltime.substr(0, 10);
    exactTime = fulltime.substr(11, 8);
}
