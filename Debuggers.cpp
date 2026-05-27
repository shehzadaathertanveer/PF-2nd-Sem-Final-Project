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
double discountOnWholeBill();
int discountItemsCount();
void inputsFromDiscountItemsFile(string[], double[], int );
int customerRecordCount();
void inputsFromCustomerRecordFile(int[], double[], string[], string[], string[], string[], string[], string[], int);
int adminFileCount();
void inputsFromAdminFile(string[], int[], int);
int StockFileCount();
void inputsFromstockFile(string[], int[], double[], string[], int);
void timeAndDate( string &currentDate, string &exactTime);

int main()
{
    cout <<setw(125) <<"++++++++++++++++++++++++++++++++++++++++" <<endl;
    cout <<setw(122) <<" Stock Management and Billing System" <<endl;
    cout <<setw(125) <<"++++++++++++++++++++++++++++++++++++++++" <<endl;

    cout <<endl <<setw(136) <<"Welcome to Stock Management and Billing Program by Debbugers!" <<endl <<endl;

    char choice1 , choice2 , choice3;
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

            while(choice1 != '0' && choice1 != '1' && choice1 != '2')
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

            if(choice1 == '1')//Admin Permissions
            {
                char choice2;

                do
                {
                    ofstream fout;

                    char choice3, choice4;
                    int adminCount = adminFileCount();
                    int adminPin[adminCount] = {0};
                    string adminname[adminCount];
                    string userName;
                    int userPin = 0, adminNumber = -1;

                    inputsFromAdminFile(adminname, adminPin, adminCount);

                    char againAdmin = 'n';

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
                        
                        while(cin . fail() )
                        {
                            cin . clear();
                            cin . ignore(1000,'\n');

                            cout << endl
                                << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                << endl;
                            cout << endl;

                            cout<< " PIN can only contain intergers (0-9)" <<endl;
                            cout << " Please enter your PIN again: ";
                            cin >> userPin;
                        }

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
                   
                            cout << " Please select an options " << endl;
                            cout << " 0. Exit Program" << endl;
                            cout << " 1. View and manage stock " << endl;
                            cout << " 2. Manage discounts "<<endl;
                            cout << " 3. View customer records " << endl;
                            cout << " 4. Add an Admin" << endl;
                            cout << " 5. Change User Name or PIN " << endl;
                            cout << " 6. Back" << endl;
                            cout << " Please enter your choice: ";
                            cin >> choice2;
                            cin . ignore();

                            while (choice2 != '0' && choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '4' && choice2 != '5' && choice2 != '6')
                            {
                                cout<<endl<<setw(118)<<"-----INVALID INPUT!-----\a "<<endl<<endl;
                                cout << " Please select an options " << endl;
                                cout << " 0. Exit Program" << endl;
                                cout << " 1. View and manage stock " << endl;
                                cout << " 2. Manage discounts "<<endl;
                                cout << " 3. View customer records " << endl;
                                cout << " 4. Add an Admin" << endl;
                                cout << " 5. Change User Name or PIN " << endl;
                                cout << " 6. Back" << endl;
                                cout << " Please enter your choice: ";
                                cin >> choice2;
                                cin . ignore();
                            }

                            if (choice2 == '0')//exit program
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
                            else if (choice2 == '1') //stock updating
                            {
                                char choice = '0';

                                do
                                {
                                    cout <<setw(115) <<"====================" <<endl;
                                    cout . fill('.');
                                    cout <<setw(115) <<"|  MANAGING STOCK  |" <<setw(94) <<"";
                                    cout . fill(' ');
                                    cout <<setw(115) <<"====================" <<endl;
                                    cout <<endl;

                                    choice = '0';

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

                                    while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6')
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

                                    if(choice == '0') //exit program
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
                                    else if (choice == '1') //viewing stock
                                    {  
                                        char continueChoice = 'y';

                                        do
                                        {
                                            int itemCount = StockFileCount();
                                            string itemCode[itemCount];
                                            int itemQuantity[itemCount] = {0};
                                            double itemPrice[itemCount] = {0};
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
                                    else if (choice == '2') //adding new item
                                    {
                                        char choiceAgainAdd;

                                        cout << endl <<setw(119) << "-----ADDING A NEW ITEM-----" << endl <<endl;

                                        int count = StockFileCount();

                                        string itemCodeFile[count];
                                        int itemQuantityFile[count] = {0};
                                        double itemPriceFile[count] = {0};
                                        string itemNameFile[count];

                                        inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                        int newItems;

                                        cout << " Please enter the number of new items you wish to add: ";
                                        cin >> newItems;

                                         while(cin.fail() || newItems <= 0 )
                                        {
                                            cin.clear();
                                            cin.ignore(1000,'\n');

                                            cout << endl
                                            << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                            << endl;
                                            cout << endl;

                                            cout<<" Item Quantity can only contain intergers (0-9) and it must be positive (value > 0) "<<endl;
                                            cout << " Please again enter the number of new items you wish to add: ";
                                            cin >> newItems;
                                        }

                                        cin . ignore();

                                        string newItemCode[newItems];
                                        int newItemQuantity[newItems] = {0};
                                        double newItemPrice[newItems] = {0};
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

                                            while(cin.fail() || newItemQuantity[i] < 0)
                                            {
                                                cin.clear();
                                                cin.ignore(1000,'\n');

                                                cout << endl
                                                << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                << endl;
                                                cout << endl;

                                                cout<<" Item Quantity can only contain intergers (0-9) and value must be positive (value >= 0) "<<endl;
                                                cout << " Enter item's quantity again: ";
                                                cin >> newItemQuantity[i];
                                            }

                                            cin . ignore();

                                            cout << " Enter item's price: ";
                                            cin >> newItemPrice[i];
                                           
                                            while(cin.fail() || newItemPrice[i] < 0)
                                            {
                                                cin.clear();
                                                cin.ignore(1000,'\n');

                                                cout << endl
                                                << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                << endl;
                                                cout << endl;

                                                cout<<" Item Price can only contain intergers (0-9) and value must be positive (value >= 0)"<<endl;
                                                cout << " Enter item's Price again: ";
                                                cin >> newItemPrice[i];
                                            }

                                            cin.ignore();

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
                                        cin >> choiceAgainAdd;
                                        cin . ignore();

                                        while(choiceAgainAdd != 'y' && choiceAgainAdd != 'Y' && choiceAgainAdd != 'n' && choiceAgainAdd!= 'N')
                                        {
                                            cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout << endl <<" Do you wish to add more items? (y/n): ";
                                            cin >> choiceAgainAdd;
                                        }                        
                                    }
                                    else if (choice == '3') //editing quantity of an item
                                    {
                                        cout <<endl <<setw(117) << "-----EDITING QUANTITY-----" << endl <<endl;
                                        char again = 'y';

                                        do 
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            double itemPriceFile[count] = {0};
                                            string itemNameFile[count];
                               
                                            inputsFromstockFile(itemCodeFile,itemQuantityFile,itemPriceFile,itemNameFile,count);

                                            string searchCode;
                                            cout << " Please enter item code of the item : ";
                                            cin >> searchCode;
                                            cin . ignore();

                                            char choiceEdit;

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
                                                cin >> choiceEdit;
                                                cin . ignore();

                                                while(choiceEdit != '+' && choiceEdit!= '-')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Please enter '+' to increase the quantity (or) enter '-' to decrease the quantity of the item: ";
                                                    cin >> choiceEdit;
                                                    cin . ignore();
                                                }

                                                cout << " Please enter change in quantity: ";
                                                cin >> changeQuantity;

                                                while(cin.fail() || changeQuantity<0)
                                                {
                                                    cin.clear();
                                                    cin.ignore(1000,'\n');

                                                    cout << endl
                                                    << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                    << endl;
                                                    cout << endl;

                                                    cout<<" Item Quantity can only contain intergers (0-9) and value must be positive (value >= 0)"<<endl;
                                                    cout << " Please again enter change in quantity: ";
                                                    cin >> changeQuantity;
                                                }

                                                cin . ignore();
                                                
                                                if (choiceEdit == '+')
                                                {
                                                    itemQuantityFile[itemIndex] += changeQuantity;
                                                    itemCheck = 1;
                                                }
                                                else if (choiceEdit == '-')
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
                                    else if (choice == '4') //editing price of an item
                                    {
                                        cout <<endl <<setw(118) << "-----EDITING PRICE-----" << endl <<endl;

                                        char again = 'y';

                                        do 
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            double itemPriceFile[count] = {0};
                                            string itemNameFile[count];
                               
                                            inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                            string searchCode;

                                            cout << " Enter item code: ";
                                            cin >> searchCode;
                                            cin . ignore();

                                            char choiceEdit;
                                            double changePrice = 0;
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
                                                cin >> choiceEdit;
                                                cin . ignore();

                                                while(choiceEdit != '+' && choiceEdit != '-')
                                                {
                                                    cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout << " Please enter '+' to increase the price (or) enter '-' to decrease the price of the item: ";
                                                    cin >> choiceEdit;
                                                    cin . ignore();
                                                }

                                                cout << " Please enter change in price of the item: ";
                                                cin >> changePrice;

                                                while(cin.fail() || changePrice < 0)
                                                {
                                                    cin.clear();
                                                    cin.ignore(1000,'\n');

                                                    cout << endl
                                                    << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                    << endl;
                                                    cout << endl;

                                                    cout<<" Item price can only contain intergers (0-9) and value must be positive (value >= 0)"<<endl;
                                                    cout << " Please again enter change in price of the item: ";
                                                    cin >> changePrice;
                                                }

                                                cin . ignore();

                                                if (choiceEdit == '+')
                                                    {
                                                        itemPriceFile[itemNumber] += changePrice;
                                                        itemCheck = 1;
                                                    }
                                                else if (choiceEdit == '-')
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

                                    else if (choice == '5') // deleting an item
                                    {
                                        cout <<endl <<setw(117) << "-----DELETING ITEM-----" << endl <<endl;

                                        char again = 'y';

                                        do
                                        {
                                            int count = StockFileCount();

                                            string itemCodeFile[count]; 
                                            int itemQuantityFile[count] = {0};
                                            double itemPriceFile[count] = {0};
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
                                }while(choice != '6');
                            }
                            else if(choice2 == '2')//discount management
                            {
                                char discountChoices;

                                do
                                {
                                    cout <<setw(119) <<"=========================" <<endl;
                                    cout . fill('.');
                                    cout <<setw(119) <<"|  MANAGINNG DISCOUNTS  |" <<setw(90) <<"";
                                    cout . fill(' ');
                                    cout <<setw(119) <<"=========================" <<endl;
                                    cout <<endl;


                                    cout <<endl << " Please select one of following:" << endl;
                                    cout << " 0. Exit" << endl;
                                    cout << " 1. Manage Discounts on Items" << endl;
                                    cout << " 2. Manage Discount on bill" << endl;
                                    cout << " 3. Back" << endl;
                                    cout << " Enter choice: ";
                                    cin >> discountChoices;
                                    cin . ignore();

                                    while (discountChoices != '0' && discountChoices != '1' && discountChoices != '2' && discountChoices != '3' )
                                    {
                                        cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout <<endl << " Please select one of following:" << endl;
                                        cout << " 0. Exit" << endl;
                                        cout << " 1. Manage Discounts on Items" << endl;
                                        cout << " 2. Manage Discount on bill" << endl;
                                        cout << " 3. Back" << endl;
                                        cout << " Enter choice: ";
                                        cin >> discountChoices;
                                        cin . ignore();
                                    }

                                    if(discountChoices == '0')//exit
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
                                    else if(discountChoices == '1')//discounts on items
                                    { 
                                        char itemDiscountChoice;
                                        do 
                                        {
                                            cout <<setw(119) <<"=========================" <<endl;
                                            cout . fill('.');
                                            cout <<setw(119) <<"|   DISCOUNT ON ITEMS   |" <<setw(90) <<"";
                                            cout . fill(' ');
                                            cout <<setw(119) <<"=========================" <<endl;
                                            cout <<endl;

                                            cout <<endl << " Please select one of following:" << endl;
                                            cout << " 0. Exit" << endl;
                                            cout << " 1. Add Discount on Items" << endl;
                                            cout << " 2. Delete Discount on Item" << endl;
                                            cout << " 3. Back" << endl;
                                            cout << " Enter choice: ";
                                            cin >> itemDiscountChoice;
                                            cin . ignore();

                                            while (itemDiscountChoice != '0' && itemDiscountChoice != '1' && itemDiscountChoice != '2' && itemDiscountChoice != '3' )
                                            {
                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                cout <<endl << " Please select one of following:" << endl;
                                                cout << " 0. Exit" << endl;
                                                cout << " 1. Add Discount on Items" << endl;
                                                cout << " 2. Delete Discount on Item" << endl;
                                                cout << " 3. Back" << endl;
                                                cout << " Enter choice: ";
                                                cin >> itemDiscountChoice;
                                                cin . ignore();
                                            }

                                            if(itemDiscountChoice == '0')//exit
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
                                            else if(itemDiscountChoice == '1') //adding item discounts
                                            {
                                                cout  <<endl << setw(115) << "-----ADDING DISCOUNTS-----" << endl <<endl;
                                                
                                                int Count = StockFileCount();

                                                string StockItemCodeFile[Count]; 
                                                int StockItemQuantityFile[Count] = {0};
                                                double StockItemPriceFile[Count] = {0};
                                                string StockItemNameFile[Count];
                                                
                                                inputsFromstockFile(StockItemCodeFile, StockItemQuantityFile, StockItemPriceFile, StockItemNameFile, Count);                                                

                                                int discountItemCount = discountItemsCount();
                                                string discountItemCode[discountItemCount];
                                                double discountItemprecentage[discountItemCount]={0};

                                                inputsFromDiscountItemsFile(discountItemCode,discountItemprecentage,discountItemCount);

                                                ofstream fout;

                                                fout.open("DiscountedItems.txt");
                                                
                                                if(!fout.fail())
                                                { 
                                                    char AgainTRY;
                                                    string  itemcodeDIS;
                                                    double itemDIS;
                                                    int DisINDEX,flag1=0;

                                                    do
                                                    {
                                                        flag1 = 0;

                                                        cout<<endl<<" Please enter Item code of the item you wish to add disscount on: ";
                                                        cin>>itemcodeDIS;
                                                        cin.ignore();

                                                        for(int i = 0; i < Count ; i++)
                                                        {
                                                            if( StockItemCodeFile[i] == itemcodeDIS)
                                                            { 
                                                                flag1 = 1;
                                                            }
                                                        }

                                                      
                                                        for(int i = 0; i < discountItemCount ; i++)
                                                        {
                                                            if( discountItemCode[i] == itemcodeDIS)
                                                            { 
                                                                flag1 = -1;
                                                                DisINDEX=i;
                                                            }
                                                        }

                                                        if(flag1 == -1)
                                                        {
                                                            cout<<endl<<"This Item already has a discount of "<<discountItemprecentage[DisINDEX]<<"% Please delete this Item and try again to change it's discount "<<endl<<endl;
                                                            
                                                            cout<<" Do you wish to add discount on another item (y/n)?: ";
                                                            cin>>AgainTRY;
                                                            cin.ignore();

                                                            while(AgainTRY != 'y' && AgainTRY != 'Y' && AgainTRY != 'n' && AgainTRY != 'N')
                                                            {
                                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                                cout<<" Do you wish to add discount on another item (y/n)?: ";
                                                                cin>>AgainTRY;
                                                                cin.ignore();
                                                            }


                                                        }
                                                        else if(flag1 == 1)
                                                        {
                                                            cout<<" Please enter percentage of discount you wish to add on this item: ";
                                                            cin>>itemDIS;
                                                            cin.ignore();

                                                            while(cin.fail()||itemDIS<0)
                                                            {
                                                                cin.clear();
                                                                cin.ignore(1000,'\n');

                                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                                cout<<" Discount Value can not be a letter and It must be Positive (value > 0)"<<endl;
                                                                cout<<" Please enter percentage of discount you wish to add on this item: ";
                                                                cin>>itemDIS;
                                                                cin.ignore();
                                                            }

                                                            fout<<itemcodeDIS<<" "<<itemDIS<<endl;

                                                            cout<<" Do you wish to add discount on another item (y/n)?: ";
                                                            cin>>AgainTRY;
                                                            cin.ignore();

                                                            while(AgainTRY != 'y' && AgainTRY != 'Y' && AgainTRY != 'n' && AgainTRY != 'N')
                                                            {
                                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                                cout<<" Do you wish to add discount on another item (y/n)?: ";
                                                                cin>>AgainTRY;
                                                                cin.ignore();
                                                            }
                                                        }
                                                        else if( flag1 == 0)
                                                        {
                                                            cout<<endl<<" Item not found!"<<endl;
                                                            cout<<" Do you wish to try again (y/n)?: ";
                                                            cin>>AgainTRY;
                                                            cin.ignore();

                                                            while(AgainTRY != 'y' && AgainTRY != 'Y' && AgainTRY != 'n' && AgainTRY != 'N')
                                                            {
                                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                                cout<<" Do you wish to try again (y/n)?: ";
                                                                cin>>AgainTRY;
                                                                cin.ignore();
                                                            }
                                                        }

                                                    }while( AgainTRY != 'n' && AgainTRY != 'N');

                                                    for(int i=0;i<discountItemCount;i++)
                                                    {
                                                        fout<<discountItemCode[i]<<" "<<discountItemprecentage[i]<<endl;
                                                    }

                                                    fout.close();

                                                    cout<<endl<<endl<<" All the Discounts and edits have been saved successfully"<<endl<<endl;
                                                }
                                                else
                                                {
                                                    cout << endl;
                                                    cout << "Error!\a Could not open DiscountedItems.txt file" << endl;   
                                                }

                                            }
                                            else if(itemDiscountChoice == '2') // deleting item discounts 
                                            {
                                                cout  <<endl << setw(115) << "-----DELETING DISCOUNTS-----" << endl <<endl;

                                                ofstream fout;

                                                char AgainTRY;
                                                string  itemcodeDEL;
                                                double itemDEL;
                                                int DELitemIndex=-1 , flag2 = 0;
                                                flag2 = 0;

                                                do
                                                {
                                                    flag2 = 0;;

                                                    int discountItemCount = discountItemsCount();
                                                    string discountItemCode[discountItemCount];
                                                    double discountItemprecentage[discountItemCount]={0};

                                                    inputsFromDiscountItemsFile(discountItemCode,discountItemprecentage,discountItemCount);

                                                    cout<<endl<<" Please enter Item code of the item you wish to delete disscount of: ";
                                                    cin>>itemcodeDEL;

                                                     for(int i=0;i<discountItemCount;i++)
                                                    {
                                                        if( discountItemCode[i]==itemcodeDEL)
                                                        {
                                                            DELitemIndex=i;
                                                            flag2=1;
                                                        }
                                                    }

                                                    if(flag2 == 1)
                                                    {
                                                        fout.open("DiscountedItems.txt");
                                                        
                                                        if(!fout.fail())
                                                        { 
                                                            for(int i=0;i<discountItemCount;i++)
                                                            {
                                                                if( DELitemIndex != i)
                                                                {
                                                                    fout<<discountItemCode[i]<<" "<<discountItemprecentage[i]<<endl;    
                                                                }
                                                            }

                                                            fout.close();
                                                        }
                                                        else
                                                        {
                                                            cout << endl;
                                                            cout << "Error!\a Could not open DiscountedItems.txt file" << endl;   
                                                        }                                                    
                                                    }
                                                    else
                                                    {
                                                        cout<<endl<<" Item not found!"<<endl;
                                                        cout<<" Do you wish to try again (y/n)?: ";
                                                        cin>>AgainTRY;
                                                        cin.ignore();

                                                        while(AgainTRY != 'y' && AgainTRY != 'Y' && AgainTRY != 'n' && AgainTRY != 'N')
                                                        {
                                                            cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                            cout<<" Do you wish to try again (y/n)?: ";
                                                            cin>>AgainTRY;
                                                            cin.ignore();
                                                        }
                                                    }

                                                    cout<<endl<<endl<<" Item Deleted Successfully"<<endl<<endl;

                                                    cout<<" Do you wish to Delete Discount of another item (y/n)?: ";
                                                    cin>>AgainTRY;
                                                    cin.ignore();

                                                    while(AgainTRY != 'y' && AgainTRY != 'Y' && AgainTRY != 'n' && AgainTRY != 'N')
                                                    {
                                                        cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                        cout<<" Do you wish to Delete Discount of another item (y/n)?: ";
                                                        cin>>AgainTRY;
                                                        cin.ignore();
                                                    }
                                                                                                                       
                                                }while(AgainTRY != 'n' && AgainTRY != 'N');
                                            }
                                        }while(itemDiscountChoice != '3');
                                    }
                                    else if(discountChoices == '2')//discount on bill
                                    {
                                        float discountPrecentage = 0;
                                        char EditOption;

                                        cout  <<endl << setw(115) << "-----DISCOUNT ON BILL-----" << endl <<endl;

                                        cout <<" Current Percentage of discount is "<<discountOnWholeBill()<<endl<<endl;

                                        cout<<" Do you wish to edit current discount percentage? (y/n):";
                                        cin>>EditOption;

                                        while( EditOption != 'y' && EditOption != 'Y' && EditOption != 'n' && EditOption != 'N')
                                        {
                                            cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout<<" Do you wish to edit current discount percentage? (y/n):";
                                            cin>>EditOption;

                                        }
                                        
                                        if(EditOption == 'y' ||  EditOption == 'Y')
                                        {
                                            cout<<endl<<" Please enter percentage of discount on whole bill: ";
                                            cin>> discountPrecentage;

                                            while(cin.fail() || discountPrecentage < 0)
                                            {
                                                cin.clear();
                                                cin.ignore(1000,'\n');

                                                cout <<endl <<setw(118)<<"-----INVALID INPUT!-----\a " <<endl <<endl;

                                                cout<<"Percentaeg value can not contain letters and it must be positive (value >= 0)"<<endl;
                                                cout<<" Please enter percentage of discount on whole bill: ";
                                                cin>> discountPrecentage;
                                            }

                                            cin.ignore();
                                            
                                            ofstream fout;

                                            fout.open("DiscountOnBill.txt");
                                            if(!fout.fail())
                                            {
                                                fout<<discountPrecentage;                 
                                                fout.close();
                                            }
                                            else
                                            {
                                                cout << endl;
                                                cout << "Error!\a Could not open DiscountOnBill.txt file" << endl;
                                            }
                                        }
                                    }
                                }while(discountChoices!='3');
                            }
                            else if (choice2 == '2')//customer record management
                            {
                                int billNumber;
                                int customerRcordCount1 = customerRecordCount();

                                int customerBill[customerRcordCount1] = {0};
                                double customerTotal[customerRcordCount1] = {0};

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

                                    while(cin.fail())
                                    {
                                        cin.clear();
                                        cin.ignore(1000,'\n');

                                        cout << endl
                                            << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                            << endl;
                                        cout << endl;

                                        cout<<" Bill Number of the record can only contain intergers (0-9)"<<endl;
                                        cout <<endl<<" Please again enter Bill Number of the record you wish to view: ";
                                        cin >> billNumber;
                                    }

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
                                        cout <<" Bill Number        : " <<customerBill[foundBill] <<endl;
                                        cout <<" Customer Name      : " <<customerName[foundBill] <<endl;
                                        cout <<" Customer Contact   : " <<customerPhone[foundBill] <<endl;
                                        cout <<" Time of Purchase   : " <<billTime[foundBill] <<endl;
                                        cout <<" Date of Purchase   : " <<billDay[foundBill] <<" " <<billMonth[foundBill] <<" " <<billDate[foundBill] <<endl;
                                        cout <<" Amount of bill     : " <<customerTotal[foundBill] <<endl <<endl;

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
                            else if (choice2 == '3') //adding new admin
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
                            else if (choice2 == '4') //editing admin's username or pin
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

                                    while (choice4 != '0' && choice4 != '1' && choice4 != '2' && choice4 != '3' )
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
                                    
                                    if (choice4 == '0') //exit program
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
                                    else if (choice4 == '1') // changing username
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
                                            choice4 = '3';
                                            choice2 = '6';

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
                                    else if (choice4 == '2') // changing pin
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
                                            choice4 = '3';
                                            choice2 = '6';

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
                                } while (choice4 != '3');
                            }
                        } while (choice2 != '6');
                    }
                    else
                    {
                        choice2 = '6';
                    }
                }while (choice2 != '6');
            }
            else if (choice1 == '2') //user work ara
            { 
                cout<<endl <<setw (115) << "-----WELCOME USER-----" << endl <<endl;

                char choice5;

                do
                {

                    cout <<setw(113) <<"===================" <<endl;
                    cout . fill('.');
                    cout <<setw(113) <<"|  USER CONTROLS  |" <<setw(96) <<"";
                    cout . fill(' ');
                    cout <<setw(113) <<"===================" <<endl;
                    cout <<endl;

                    ofstream fout;
                    ifstream fin;

                    cout <<endl <<" Please select one of following:" <<endl;
                    cout <<" 0. Exit Program"<<endl;
                    cout <<" 1. Search an Item from stock" <<endl;
                    cout <<" 2. view discounts" <<endl;
                    cout <<" 3. Generate Bill" <<endl;
                    cout <<" 4. Back" <<endl;
                    cout <<" Enter your choice: ";
                    cin >> choice5;
                    cin . ignore();
                   

                    while( choice5 != '0' && choice5 != '1' && choice5 != '2' && choice5 != '3' && choice5 != '4')
                    { 
                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                        cout <<" PLease select one of following:" <<endl;
                        cout <<" 0. Exit Program" <<endl;
                        cout <<" 1. Search an Item from stock" <<endl;
                        cout <<" 2. view discounts" <<endl;
                        cout <<" 3. Generate Bill" <<endl;
                        cout <<" 4. Back" <<endl;
                        cout <<" Enter your choice: ";
                        cin >> choice5;
                        cin . ignore();
                    }

                    cout<<endl;

                    if( choice5 == '0') //exit program
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
                    else if(choice5 == '1') //searching an item from stock
                    {
                        char continueChoice = 'y';

                        char choice6;

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
                            cin >> choice6;
                            cin . ignore();

                            while(choice6 != '0' && choice6 != '1' && choice6 != '2' && choice6 != '3')
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                
                                cout <<" Please select one of following:" <<endl;
                                cout <<" 0. Exit Program" <<endl;
                                cout <<" 1. Search item by item name" <<endl;
                                cout <<" 2. Search item by item code" <<endl;
                                cout <<" 3. Back" <<endl;
                                cout <<" Enter your choice: ";
                                cin >> choice6;
                                cin . ignore();
                               
                            }

                            cout <<endl;

                            int fileItemCount = StockFileCount();

                            string fileItemCodes[fileItemCount] ;
                            int fileItemQuantity[fileItemCount] = {0};
                            double fileItemPrice[fileItemCount] = {0};
                            string fileItemNames[fileItemCount];

                            inputsFromstockFile(fileItemCodes, fileItemQuantity, fileItemPrice, fileItemNames, fileItemCount);

                            if(choice6 == '0') //exit program
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
                            else if(choice6 == '1') //searching item by name
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
                            else if(choice6 == '2') //searching item by code
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

                        }while(choice6 != '3');
                    }
                    else if (choice5 == '2') // view discounts
                    {
                        char continueDiscount = 'y';
                        char discountViewChoice2;

                        do
                        {
                            cout <<setw(114) <<"=======================" <<endl;
                            cout . fill('.');
                            cout <<setw(113) <<"|  VIEWING DICSOUNTS  |" <<setw(94) <<"";
                            cout . fill(' ');
                            cout <<setw(114) <<"=======================" <<endl;
                            cout <<endl;

                            cout << " Please select one of following:" << endl;
                            cout << " 0. Exit Program" <<endl;
                            cout << " 1. Discount On Whole Bill" << endl;
                            cout << " 2. Discount On Specific Items" << endl;
                            cout << " 3. Back" << endl;
                            cout << " Enter your choice: ";
                            cin >> discountViewChoice2;
                            cin.ignore();

                            while (discountViewChoice2 != '0' && discountViewChoice2 != '1' && discountViewChoice2 != '2' && discountViewChoice2 != '3')
                            {
                                cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                
                                cout << " Please select one of following:" << endl;
                                cout << " 0. Exit Program" <<endl;
                                cout << " 1. Discount On Whole Bill" << endl;
                                cout << " 2. Discount On Specific Items" << endl;
                                cout << " 3. Back" << endl;
                                cout << " Enter your choice: ";
                                cin >> discountViewChoice2;
                                cin.ignore();
                            }
                            if(discountViewChoice2 == '0') //exit program
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
                            else if (discountViewChoice2 == '1') //discount on whole bill
                            {
                                char continueProgramHere1;
                                do
                                {
                                    cout << endl << setw(120) << "-----VIEWING DISCOUNT ON BILL-----" << endl <<endl;

                                    double wholeBillDiscount = discountOnWholeBill();

                                    cout << endl;
                                    cout << " Discount On Whole Bill: " << wholeBillDiscount<< "%" << endl << endl;

                                    cout << " Please enter (y) to continue using the program: ";
                                    cin >> continueProgramHere1;
                                    cin.ignore();

                                    while (continueProgramHere1 != 'y' && continueProgramHere1 != 'Y')
                                    {
                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout << " Please enter (y) to continue using the program: ";
                                        cin >> continueProgramHere1;
                                        cin.ignore();   
                                    }

                                }while(continueProgramHere1 != 'y' && continueProgramHere1 !='Y');
                            }

                            else if (discountViewChoice2 == '2')
                            {
                                char itemChoice;
                                do
                                {
                                    cout <<setw(114) <<"=======================" <<endl;
                                    cout . fill('.');
                                    cout <<setw(113) <<"|  DICSOUNT ON ITEMS  |" <<setw(94) <<"";
                                    cout . fill(' ');
                                    cout <<setw(114) <<"=======================" <<endl;
                                    cout <<endl;

                                    cout << " 0. Exit Program"<<endl;
                                    cout << " 1. Search Discount By Item Name" << endl;
                                    cout << " 2. Search Discount By Item Code" << endl;
                                    cout << " 3. Back "<<endl;
                                    cout << " Enter your choice: ";
                                    cin >> itemChoice;
                                    cin.ignore();

                                    while (itemChoice != '0' && itemChoice != '1' && itemChoice != '2' && itemChoice != '3')
                                    {

                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                        cout << " 0. Exit Program"<<endl;
                                        cout << " 1. Search Discount By Item Name" << endl;
                                        cout << " 2. Search Discount By Item Code" << endl;
                                        cout << " 3. Back "<<endl;
                                        cout << " Enter your choice: ";
                                        cin >> itemChoice;
                                        cin.ignore();
                                    }

                                    int fileItemCount = discountItemsCount();

                                    string fileItemcodes[fileItemCount];
                                    double discountOnItems[fileItemCount];

                                    inputsFromDiscountItemsFile(fileItemcodes, discountOnItems, fileItemCount);

                                    if(itemChoice == '0') //exit program
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
                                    else if (itemChoice == '1') //search discoun by name
                                    {
                                        char doAgain1;
                                        int stockIndex = -1;
                                        int check = 0;

                                        cout << endl << setw(120) << "-----VIEWING DISCOUNT ON ITEMS-----" << endl <<endl;

                                        do
                                        {
                                            stockIndex = -1;
                                            check = 0;

                                            string itemName;
                                            string searchedItemCode ;
                                            int stockItemCount = StockFileCount();

                                            string stockItemCodes[stockItemCount];
                                            int stockItemQuantity[stockItemCount];
                                            double stockItemPrice[stockItemCount];
                                            string stockItemNames[stockItemCount];

                                            inputsFromstockFile(stockItemCodes, stockItemQuantity, stockItemPrice, stockItemNames, stockItemCount);

                                            cout << endl;
                                            cout << " Please enter Item Name: ";
                                            getline(cin, itemName);

                                            for (int i = 0; i < stockItemCount; i++)
                                            {
                                                if (stockItemNames[i] == itemName)
                                                {
                                                    searchedItemCode = stockItemCodes[i];
                                                    stockIndex = i;
                                                }
                                            }

                                            if (stockIndex != -1)
                                            {

                                                for (int i = 0; i < fileItemCount; i++)
                                                {
                                                    if (searchedItemCode == fileItemcodes[i])
                                                    {
                                                        cout << endl;
                                                        cout << " Discount Available At This Item! " << endl <<endl;
                                                        cout << " Item Name: " << itemName << endl;
                                                        cout << " Item Code: " << searchedItemCode << endl;
                                                        cout << " Item Price: " << stockItemPrice[stockIndex] << endl;
                                                        cout << " Discount: " << discountOnItems[i] << "%" << endl;

                                                        check++;

                                                        cout << " Do you wish to check discount for another item? (y/n): ";
                                                        cin >> doAgain1;
                                                        cin . ignore();

                                                        while(doAgain1 != 'y' && doAgain1 != 'Y' && doAgain1 != 'n' && doAgain1 != 'N')
                                                        {
                                                            cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                            cout << " Do you wish to check discount for another item? (y/n): ";
                                                            cin >> doAgain1;
                                                            cin . ignore();
                                                        }
                                                    }
                                                }

                                                if (check == 0)
                                                {
                                                    cout << endl;
                                                    cout << " No Discount Available On This Item"<< endl;
                                                    cout << " Do you wish to check discount for another item? (y/n): ";
                                                    cin >> doAgain1;
                                                    cin . ignore();

                                                    while(doAgain1 != 'y' && doAgain1 != 'Y' && doAgain1 != 'n' && doAgain1 != 'N')
                                                    {
                                                        cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                        cout << " Do you wish to check discount for another item? (y/n): ";
                                                        cin >> doAgain1;
                                                        cin . ignore();
                                                    }
                                                }
                                            }   
                                            else
                                            {
                                                cout << endl;
                                                cout <<" The item you searched does not exist in stock"<<endl
                                                     <<" Try searching again with item name or exact item code"<<endl<<endl;
                                                cout <<" Do you wish to try again? (y/n): ";
                                                cin >> doAgain1;
                                                cin . ignore();

                                                while(doAgain1 != 'y' && doAgain1 != 'Y' && doAgain1 != 'n' && doAgain1 != 'N')
                                                {
                                                    cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<" Do you wish to try again? (y/n): ";
                                                    cin >> doAgain1;
                                                    cin . ignore();
                                                }
                                            }
                                        }while(doAgain1 == 'y' || doAgain1 == 'Y');
                                    }
                                    else if (itemChoice == '2')
                                    {
                                        char doAgainHere;
                                        do
                                        {
                                            string itemCode;
                                            int stockItemCount = StockFileCount();
                                            int itemFound = 0;

                                            string stockItemCodes[stockItemCount];
                                            int stockItemQuantity[stockItemCount];
                                            double stockItemPrice[stockItemCount];
                                            string stockItemNames[stockItemCount];

                                            inputsFromstockFile(stockItemCodes, stockItemQuantity, stockItemPrice, stockItemNames, stockItemCount);

                                            cout << endl;
                                            cout << " Please enter Item Code: ";
                                            cin >> itemCode;
                                            cin.ignore();

                                            for (int i = 0; i < stockItemCount; i++)
                                            {
                                                if (stockItemCodes[i] == itemCode)
                                                {
                                                    itemFound++;

                                                    int check = 0;

                                                    for (int j = 0; j < fileItemCount; j++)
                                                    {
                                                        if (itemCode == fileItemcodes[j])
                                                        {
                                                            cout << endl;
                                                            cout << " Discount Available At This Item! " << endl <<endl;
                                                            cout << " Item Name: " << stockItemNames[i] << endl;
                                                            cout << " Item Code: " << itemCode << endl;
                                                            cout << " Item Price: " << stockItemPrice[i] << endl;
                                                            cout << " Discount: " << discountOnItems[j] << "%" << endl;

                                                            check++;
                                                            
                                                            cout << endl;

                                                            cout <<" Do you wish to check discount for another item? (y/n): ";
                                                            cin >> doAgainHere;
                                                            cin . ignore();

                                                            while(doAgainHere != 'y' && doAgainHere != 'Y' && doAgainHere != 'n' && doAgainHere != 'N')
                                                            {
                                                                cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                                cout <<" Do you wish to check discount for another item? (y/n): ";
                                                                cin >> doAgainHere;
                                                                cin . ignore();
                                                            }
                                                        }
                                                    }

                                                    if (check == 0)
                                                    {
                                                        cout << endl;
                                                        cout << " No Discount Available On This Item" << endl;
                                                        cout << endl;
                                                        cout <<" Do you wish to check discount for another item? (y/n): ";
                                                        cin >> doAgainHere;
                                                        cin . ignore();

                                                        while(doAgainHere != 'y' && doAgainHere != 'Y' && doAgainHere != 'n' && doAgainHere != 'N')
                                                        {
                                                            cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                            cout <<" Do you wish to check discount for another item? (y/n): ";
                                                            cin >> doAgainHere;
                                                            cin . ignore();
                                                       }
                                                    }
                                                }
                                            }

                                            if (itemFound == 0)
                                            {
                                                cout << endl;
                                                cout <<" The item you searched does not exist in stock"<<endl
                                                         <<" Try searching again with item name or exact item code"<<endl<<endl;
                                                cout <<" Do you wish to try again? (y/n): ";
                                                cin >> doAgainHere;
                                                cin . ignore();

                                                while(doAgainHere != 'y' && doAgainHere != 'Y' && doAgainHere != 'n' && doAgainHere != 'N')
                                                {
                                                    cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                                    cout <<" Do you wish to try again? (y/n): ";
                                                    cin >> doAgainHere;
                                                    cin . ignore();
                                                }
                                            }    
                                        }while(doAgainHere == 'y' || doAgainHere == 'Y');
                                    }
                                }while(itemChoice != '3');
                            }
                        }while (discountViewChoice2 != '3');
                    }
                    else if(choice5 == '3') //generating bill
                    {
                        char anotherReceipt = 'y';
                        int donecheck = 0;

                        char discountChoice;

                        do
                        {
                            double boughtItemPrice = 0;
                            int boughtItemCount = 0;
                            double itemTotal = 0;

                            char discountType;

                            do
                            {
                                cout << endl;
                                cout << " Do you wish to give discount? (y/n): ";
                                cin >> discountChoice;
                                cin.ignore();

                                while(discountChoice != 'y' && discountChoice != 'Y' && discountChoice != 'N' && discountChoice != 'n')
                                {
                                    cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                    cout << " Do you wish to give discount? (y/n): " << endl;
                                    cin >> discountChoice;
                                    cin.ignore();
                                }


                                 if (discountChoice == 'y' || discountChoice == 'Y')
                                {
                                    do
                                    {

                                        cout << setw(114) << "====================" << endl;
                                        cout.fill('.');
                                        cout << setw(114) << "| DISCOUNT OPTIONS |" << setw(95) << "";
                                        cout.fill(' ');
                                        cout << setw(114) << "====================" << endl;
                                        cout << endl;

                                        cout << " Please select one of following "<<endl;
                                        cout << " 0. Exit program"<<endl;
                                        cout << " 1. Discount of whole bill" << endl;
                                        cout << " 2. Discount of specific items" << endl;
                                        cout << " 3. Back "<<endl;
                                        cout << " Enter your choice: ";
                                        cin >> discountType;
                                        cin.ignore();

                                        while( discountType != '0' && discountType != '1' && discountType != '2' && discountType != '3')
                                        {
                                            cout<<endl<<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                            cout << " Please select one of following "<<endl;
                                            cout << " 0. Exit program"<<endl;
                                            cout << " 1. Discount of whole bill" << endl;
                                            cout << " 2. Discount of specific items" << endl;
                                            cout << " 3. Back "<<endl;
                                            cout << " Enter your choice: ";
                                            cin >> discountType;
                                            cin.ignore();

                                        }

                                        if(discountType == '0') //exit program
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

                                    }while(  discountType != '1' && discountType != '2' && discountType != '3');
                                }
                            }while(discountChoice != 'n' && discountChoice != 'N' && discountType != '1' && discountType != '2');
                            
                            int itemCount=StockFileCount();

                            int remainingItemQuantity[500]= {0};

                            string boughtItemCodes[500];
                            double boughtItemtotal[500] = {0};
                            double boughtItemPrices[500] = {0};
                            int BoughtItemQuantity[500] = {0};
                            string boughtItemNames[500];

                            double itemDiscountArray[500] = {0};

                            string itemCode[itemCount];
                            int itemQuantity[itemCount] = {0};
                            double itemPrice[itemCount] = {0};
                            string itemName[itemCount];

                            inputsFromstockFile(itemCode, itemQuantity, itemPrice, itemName, itemCount);

                            char viewStockItem;

                            cout <<endl<< " Do you wish to view whole stock for checking items (y/n): ";
                            cin >> viewStockItem;
                            cin.ignore();

                            while(viewStockItem != 'y' && viewStockItem != 'Y' && viewStockItem != 'N' && viewStockItem!= 'n')
                            {
                                cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;
                                cout << " Do you wish to view whole stock for checking items codes (y/n): ";
                                cin >> viewStockItem;
                                cin . ignore();
                            }

                            if(viewStockItem == 'y' || viewStockItem =='Y')
                            {
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
                            }

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

                                    while(cin.fail())
                                    {
                                        cin.clear();
                                        cin.ignore(1000,'\n');

                                        cout <<endl <<setw(118) <<"-----INVALID INPUT!-----\a " <<endl <<endl;

                                        cout<<" This value cannot be a letter please enter an integeral value "<<endl;
                                        cout <<" Please enter the quantity of item: ";
                                        cin >> boughtItemQuantity;
                                        cin . ignore();
                                    }

                                    if(boughtItemQuantity <= itemQuantity[boughtItemNumber])
                                    {
                                        itemQuantity[boughtItemNumber] -= boughtItemQuantity;

                                        boughtItemPrice = itemPrice[boughtItemNumber];
                                        itemTotal = boughtItemPrice * boughtItemQuantity;

                                        double discount=0;

                                        if(discountChoice == 'y' && discountType == '2')
                                        {
                                            int dicsountedItemCount = discountItemsCount();

                                            double ItemDiscounts[dicsountedItemCount];
                                            string DiscountedItemCode[dicsountedItemCount];

                                            inputsFromDiscountItemsFile(DiscountedItemCode,ItemDiscounts,dicsountedItemCount);
                                
                                            discount = 0;

                                            for(int i=0 ;i<dicsountedItemCount; i++)
                                            {
                                                if(boughtItem == DiscountedItemCode[i])
                                                {
                                                    discount = itemTotal * (ItemDiscounts[i] / 100);
                                                }
                                                                         
                                            }
                                        }

                                        itemDiscountArray[boughtItemCount ]= discount;
                                        itemTotal = itemTotal - itemDiscountArray[boughtItemCount];   

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
                            double CustomerTotal[RecordCount] = {0};

                            string customerPhone[RecordCount];
                            string customerName[RecordCount];
                            string customerTime[RecordCount];
                            string customerDate[RecordCount];
                            string customerDateDay[RecordCount];
                            string customerDateMonth[RecordCount];

                            inputsFromCustomerRecordFile(billNo ,CustomerTotal, customerPhone, customerTime, customerDateDay, customerDateMonth, customerDate, customerName, RecordCount);
        
                            double grandTotal = 0;
                            string customername, customerphone;

                            cout <<endl<<endl<<" Please enter coustomer name: ";
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
                                <<setw(15) <<" Item Discount "
                                <<setw(16) <<"Item Total" <<endl <<endl;

                            for(int i=0 ; i < boughtItemCount ; i++)
                            {
                                cout <<" " <<setw(15) <<boughtItemCodes[i]
                                    <<setw(42) <<boughtItemNames[i]
                                    <<setw(15) <<boughtItemPrices[i]
                                    <<setw(15) <<BoughtItemQuantity[i] 
                                    <<setw(15) <<itemDiscountArray[i]
                                    <<setw(16) <<boughtItemtotal[i] <<endl;

                                grandTotal += boughtItemtotal[i];
                            }

                            double totalDiscountOnBill = 0;

                            if (discountChoice == 'y' && discountType == '1')
                            {
                                double discountPercenTage = discountOnWholeBill();

                                totalDiscountOnBill = grandTotal * (discountPercenTage/100);

                                grandTotal -= totalDiscountOnBill;
                                
                            }
                            else
                            {
                                for (int i = 0 ; i < boughtItemCount;i++)
                                {
                                    totalDiscountOnBill += itemDiscountArray[i];
                                }
                            }

                            cout <<endl <<endl<<endl;
                            cout <<" Total: " <<grandTotal+totalDiscountOnBill <<endl;
                            cout <<" Discount: "<<totalDiscountOnBill<<endl;
                            cout <<" Invoice: "<<grandTotal<<endl;
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
                                    <<"Price\tQuantity\tDiscount\tTotal"
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
                                    << boughtItemPrices[i] <<"\t" <<BoughtItemQuantity[i] <<"\t"<<itemDiscountArray[i]<<"\t" << boughtItemtotal[i] <<endl;
                                }
                        
                                for(int i=0 ; i<48 ;i++)
                                {
                                    fout <<"-";
                                }
                                fout <<endl;
                                fout << "Total Value: " <<grandTotal+totalDiscountOnBill <<endl;
                                fout << "Discount Value: " <<totalDiscountOnBill<<endl;
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
                }while(choice5 != '4');
            }
        }while(choice1 != '0'); 

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

void inputsFromCustomerRecordFile(int billNo[], double CustomerTotal[], string customerPhone[], string customerTime[], string customerDateDay[], string customerDateMonth[], string customerDate[], string customerName[], int customerRecordCount)
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

void inputsFromstockFile(string fileItemCodes[], int fileItemQuantity[], double fileItemprice[], string fileitemName[], int fileItemCount)
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

int discountItemsCount() 
{
    string discountItemCode;
    int itemDiscount = 0, discountItemCount = 0;

    ifstream fin;

    fin . open("DiscountedItems.txt");

    if (! fin . fail())
    {
        while (fin >> discountItemCode)
        {
            fin >> itemDiscount;
            discountItemCount++;
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open DiscountedItems.txt" << endl;
    }

    return discountItemCount;

}

void inputsFromDiscountItemsFile(string fileItemcodes[], double discountOnItems [], int fileItemCount)
{
    ifstream fin;

    fin . open("DiscountedItems.txt");

    if ( ! fin . fail())
    {
        for (int i = 0 ; i < fileItemCount ; i++)
        {
            fin >> fileItemcodes[i];
            fin >> discountOnItems[i];
        }

        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open DiscountedItems.txt file" << endl;
    }
}

double discountOnWholeBill()
{
    ifstream fin;
    
    double percentage=0;

    fin . open("DiscountOnBill.txt");

    if ( ! fin . fail())
    {
        fin>>percentage;
        fin . close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open DiscountOnBill.txt file" << endl;
    }
    
    return percentage;

}