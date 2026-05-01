/* This is the final project of team Debuggers for Programming
Fundamentals. The team members are Abdullah Arif Roll# BITF25A012,
Shehzada Ather Roll# BITF25A047, Abdul Moiz Roll# BITF25A059
*/

// THIS IS STOCK MANAGEMENT AND BILLING PROGRAM WHICH WILL HELP IN EDITING,
// MAINTAINING AND CHECKING STOCK AND WILL ALSO GENERATE RECIEPT

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int customerRecordCount();
void inputsFromCustomerRecordFile(int[], int[], string[], string[], int);
int adminFileCount();
void inputsFromAdminFile(string[], int[], int);
int StockFileCount();
void inputsFromstockFile(string[], int[], int[], string[], int);

int main()
{
    cout << setw(125) << "++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << setw(122) << " Stock Management and Billing System" << endl;
    cout << setw(125) << "++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << endl
         << setw(136) << "Welcome to Stock Management and Billing Program by Debbugers!" << endl
         << endl;

    int choice1, choice2, choice3;
    do
    {
        cout << setw(118) << "============================" << endl;
        cout.fill('.');
        cout << setw(118) << "|  SYSTEM ACCESS CONTROLS  |" << setw(91) << "";
        cout.fill(' ');
        cout << setw(118) << "============================" << endl;

        cout << endl
             << " Please select your role:" << endl;
        cout << " 0. Exit program" << endl;
        cout << " 1. Admin Login" << endl;
        cout << " 2. User Login" << endl;
        cout << " Enter your choice: ";
        cin >> choice1;
        cin.ignore();
        cout << endl;

        while (choice1 > 2 || choice1 < 0)
        {
            cout << endl
                 << setw(118) << "-----INVALID INPUT!-----\a " << endl
                 << endl;
            cout << " Please select your role:" << endl;
            cout << " 0. Exit Program" << endl;
            cout << " 1. Admin Login" << endl;
            cout << " 2. User Login" << endl;
            cout << " Enter your choice: ";
            cin >> choice1;
            cin.ignore();
            cout << endl;
        }

        if (choice1 == 1) // Admin Permissions
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
                int userPin = 0, adminNumber = -1;

                inputsFromAdminFile(adminname, adminPin, adminCount);

                char againAdmin = 'y';

                againAdmin = 'n';
                cout << setw(118) << "-----ADMIN CREDENTIALS-----" << endl;

                do
                {
                    adminNumber = -1;

                    cout << endl
                         << " Please enter your User Name: ";
                    getline(cin, userName);

                    for (int i = 0; i < adminCount; i++)
                    {
                        if (adminname[i] == userName)
                        {
                            adminNumber = i;
                        }
                    }

                    cout << " Please enter your PIN: ";
                    cin >> userPin;
                    cin.ignore();

                    if (adminNumber == -1 || userPin != adminPin[adminNumber])
                    {
                        cout << endl
                             << " Invalid credentials!\a Do you wish to try again (y/n): ";
                        cin >> againAdmin;
                        cin.ignore();
                    }
                    else
                    {
                        againAdmin = 'n';
                    }

                } while (againAdmin == 'y' || againAdmin == 'Y');

                if (adminNumber != -1 && userPin == adminPin[adminNumber]) // admin acess givenn
                {
                    cout << endl
                         << " Access Granted." << endl;
                    cout << endl;
                    cout << endl
                         << endl
                         << setw(117) << "-----WELCOME ADMIN!-----" << endl
                         << endl;

                    do
                    {
                        cout << setw(115) << "====================" << endl;
                        cout.fill('.');
                        cout << setw(115) << "|  ADMIN CONTROLS  |" << setw(94) << "";
                        cout.fill(' ');
                        cout << setw(115) << "====================" << endl;
                        cout << endl;

                        cout << endl
                             << " Please select an option " << endl;
                        cout << " 0. Exit Program" << endl;
                        cout << " 1. View stock " << endl;
                        cout << " 2. Update stock" << endl;
                        cout << " 3. Add an Admin" << endl;
                        cout << " 4. Change User Name or PIN " << endl;
                        cout << " 5. View Customer Record" << endl;
                        cout << " 6. Back " << endl;
                        cout << " Enter your choice: ";
                        cin >> choice2;
                        cin.ignore();

                        while (choice2 < 0 || choice2 > 6)
                        {
                            cout << endl
                                 << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                 << endl;
                            cout << " Please select an options " << endl;
                            cout << " 0. Exit Program" << endl;
                            cout << " 1. View stock " << endl;
                            cout << " 2. Update Stock " << endl;
                            cout << " 3. Add an Admin" << endl;
                            cout << " 4. Change User Name or PIN " << endl;
                            cout << " 5. View Customer Record " << endl;
                            cout << " 6. back " << endl;
                            cout << " Please enter your choice: ";
                            cin >> choice2;
                            cin.ignore();
                        }

                        if (choice2 == 0) // exit program
                        {
                            char exit = 'n';
                            do
                            {
                                cout << endl
                                     << " Do you really wish to exit program (y/n): ";
                                cin >> exit;
                                cin.ignore();
                                if (exit == 'y' || exit == 'y')
                                {
                                    cout << endl
                                         << " Thank you for using the program" << endl;
                                    return 0;
                                }
                            } while (exit == 'y' || exit == 'Y');
                        }

                        else if (choice2 == 1) // view stock
                        {
                            int itemCount = StockFileCount();
                            string itemCode[itemCount];
                            int itemQuantity[itemCount] = {0};
                            int itemPrice[itemCount] = {0};
                            string itemName[itemCount];

                            inputsFromstockFile(itemCode, itemQuantity, itemPrice, itemName, itemCount);
                            cout << endl
                                 << setw(115) << "-----AVALIBLE STOCK-----" << endl
                                 << endl;
                            cout << left;
                            cout << setw(6) << "Item code " << setw(15) << "Item name " << setw(6) << " ItemPrice" << setw(6) << " item quantity " << endl
                                 << endl;

                            for (int i = 0; i < itemCount; i++)
                            {
                                cout << setw(6) << itemCode[i]
                                     << setw(25) << itemName[i]
                                     << setw(6) << itemPrice[i]
                                     << setw(6) << itemQuantity[i] << endl;
                            }

                            cout << endl
                                 << endl;
                        }

                        else if (choice2 == 2) // stock updating
                        {

                            int choice = 0;
                            do
                            {
                                cout << setw(115) << "====================" << endl;
                                cout.fill('.');
                                cout << setw(115) << "|  STOCK UPDATING  |" << setw(94) << "";
                                cout.fill(' ');
                                cout << setw(115) << "====================" << endl;
                                cout << endl;

                                choice = 0;

                                cout << endl
                                     << " Please select one of following " << endl;
                                cout << " 0. Exit Program" << endl;
                                cout << " 1. Add an item" << endl;
                                cout << " 2. increase (or) decrease quantity of an item" << endl;
                                cout << " 3. increase (or) decrease price of an item" << endl;
                                cout << " 4. delete an item" << endl;
                                cout << " 5. back" << endl;
                                cout << " Enter your choice: ";
                                cin >> choice;

                                while (choice < 0 || choice > 5)
                                {
                                    cout << endl
                                         << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                         << endl;
                                    cout << " Please select one of following " << endl;
                                    cout << " 0. Exit Program" << endl;
                                    cout << " 1. Add an item" << endl;
                                    cout << " 2. increase (or) decrease quantity of an item" << endl;
                                    cout << " 3. increase (or) decrease price of an item" << endl;
                                    cout << " 4. delete an item" << endl;
                                    cout << " 5. back" << endl;
                                    cout << " Enter your choice: ";
                                    cin >> choice;
                                    cin.ignore();
                                }
                                if (choice == 0) // exit program
                                {
                                    char exit = 'n';
                                    do
                                    {
                                        cout << " Do you really wish to exit program (y/n): ";
                                        cin >> exit;
                                        cin.ignore();
                                        if (exit == 'y' || exit == 'y')
                                        {
                                            cout << endl
                                                 << " Thank you for using the program" << endl;
                                            return 0;
                                        }
                                    } while (exit == 'y' || exit == 'Y');
                                }
                                else if (choice == 1) // adding new item
                                {
                                    char choice;

                                    do
                                    {
                                        cout << endl
                                             << setw(119) << "-----ADDING A NEW ITEM-----" << endl
                                             << endl;

                                        int count = StockFileCount();

                                        string itemCodeFile[count];
                                        int itemQuantityFile[count] = {0};
                                        int itemPriceFile[count] = {0};
                                        string itemNameFile[count];

                                        inputsFromstockFile(itemCodeFile, itemQuantityFile, itemPriceFile, itemNameFile, count);

                                        int newItems;

                                        cout << " Please enter the number of new items you wish to add: ";
                                        cin >> newItems;
                                        cin.ignore();

                                        string newItemCode[newItems];
                                        int newItemQuantity[newItems] = {0};
                                        int newItemPrice[newItems] = {0};
                                        string newItemName[newItems];

                                        for (int i = 0; i < newItems; i++)
                                        {
                                            int j = i;
                                            int found;

                                            do
                                            {
                                                found = 0;

                                                cout << endl
                                                     << " Please enter for item number " << j + 1 << ": " << endl;

                                                cout << " Enter item code: ";
                                                cin >> newItemCode[i];

                                                for (int k = 0; k < count; k++)
                                                {
                                                    if (newItemCode[i] == itemCodeFile[k])
                                                    {
                                                        cout << " This item code already exists. Enter another one."<<endl;
                                                        found = 1;
                                                    }
                                                }

                                                for (int k = 0; k < i; k++)
                                                {
                                                    if (newItemCode[i] == newItemCode[k])
                                                    {
                                                        cout << " You already entered this item code before. Enter another one."<<endl;
                                                        found = 1;
                                                    }
                                                }

                                            } while (found == 1);

                                            cout << " Enter item's quantity: ";
                                            cin >> newItemQuantity[i];

                                            cout << " Enter item's price: ";
                                            cin >> newItemPrice[i];

                                            cin.ignore();

                                            do
                                            {
                                                found = 0;

                                                cout << " Enter item name: ";
                                                getline(cin, newItemName[i]);

                                                for (int k = 0; k < count; k++)
                                                {
                                                    if (newItemName[i] == itemNameFile[k])
                                                    {
                                                        cout << " This item name alrady exists. Enter another one."<<endl;
                                                        found = 1;
                                                    }
                                                }

                                                for (int k = 0; k < i; k++)
                                                {
                                                    if (newItemName[i] == newItemName[k])
                                                    {
                                                        cout << " You already entred this item name before. Enter another one."<<endl;
                                                        found = 1;
                                                    }
                                                }

                                            } while (found == 1);
                                        }

                                        ofstream fout;
                                        fout.open("stock.txt");

                                        if (!fout.fail())
                                        {
                                            for (int i = 0; i < newItems; i++)
                                            {
                                                fout << newItemCode[i] << " "
                                                     << newItemQuantity[i] << " "
                                                     << newItemPrice[i] << " "
                                                     << newItemName[i] << endl;
                                            }

                                            for (int i = 0; i < count; i++)
                                            {
                                                fout << itemCodeFile[i] << " "
                                                     << itemQuantityFile[i] << " "
                                                     << itemPriceFile[i] << " "
                                                     << itemNameFile[i] << endl;
                                            }

                                            fout.close();
                                            cout << endl
                                                 << " All items are saved successfully!" << endl;
                                        }
                                        else
                                        {
                                            cout << endl
                                                 << " Error in editing stock.txt file " << endl;
                                        }

                                        cout << endl
                                             << " Do you wish to add more items? (y/n): ";
                                        cin >> choice;

                                    } while (choice == 'y' || choice == 'Y');
                                }
                                else if (choice == 2) // editing quantity of an item
                                {
                                    cout << endl
                                         << setw(118) << "-----EDITING QUANTITY-----" << endl
                                         << endl;
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
                                        cout << " Please enter item code of the item : ";
                                        cin >> searchCode;

                                        char choice;
                                        int changeQuantity = 0;

                                        cout << " Please enter '+' to increase the quantity (or) enter '-' to decrease the quantity of the item: ";
                                        cin >> choice;

                                        while (choice != '+' && choice != '-')
                                        {
                                            cout << endl
                                                 << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                 << endl;
                                            cout << " Please enter '+' to increase the quantity (or) enter '-' to decrease the quantity of the item: ";
                                            cin >> choice;
                                        }

                                        cout << " Please enter change in quantity: ";
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
                                                        cout << endl
                                                             << " Not enough stock to decrease from! please try again" << endl;
                                                        again = 'y';
                                                    }
                                                }
                                            }
                                        }

                                        if (found == 0)
                                        {
                                            cout << endl
                                                 << " Item not found! Please Try again with correct item code." << endl;
                                            again = 'y';
                                        }

                                        ofstream outStockfile("stock.txt");

                                        for (int i = 0; i < count; i++)
                                        {
                                            outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                        }
                                        outStockfile.close();

                                        cout << " Quantity updated successfully!" << endl;
                                        cout << endl
                                             << " Do you wish to update another item? (y/n): ";
                                        cin >> again;

                                    } while (again != 'n' && again != 'N');
                                }
                                else if (choice == 3) // editing price of an item
                                {
                                    cout << endl
                                         << setw(118) << "-----EDITING PRICE-----" << endl
                                         << endl;
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

                                        char choice;
                                        int changePrice = 0;

                                        cout << " Please enter '+' to increase the price (or) enter '-' to decrease the price of the item: ";
                                        cin >> choice;

                                        while (choice != '+' && choice != '-')
                                        {
                                            cout << endl
                                                 << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                                 << endl;
                                            cout << " Please enter '+' to increase the price (or) enter '-' to decrease the price of the item: ";
                                            cin >> choice;
                                        }

                                        cout << " Please enter change in price of the item: ";
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
                                                        cout << " Not enough price to decrease from! please try again" << endl;
                                                        again = 'y';
                                                    }
                                                }
                                            }
                                        }

                                        if (found == 0)
                                        {
                                            cout << endl
                                                 << " Item not found! Please Try again with correct item code." << endl;
                                            again = 'y';
                                        }

                                        ofstream outStockfile("stock.txt");

                                        for (int i = 0; i < count; i++)
                                        {
                                            outStockfile << itemCodeFile[i] << " " << itemQuantityFile[i] << " " << itemPriceFile[i] << " " << itemNameFile[i] << endl;
                                        }
                                        outStockfile.close();

                                        cout << endl
                                             << " Price updated successfully!" << endl;
                                        cout << endl
                                             << " Do you wish to update another item's price? (y/n): ";
                                        cin >> again;

                                    } while (again != 'n' && again != 'N');
                                }

                                else if (choice == 4) // deleting an item
                                {
                                    cout << endl
                                         << setw(117) << "-----DELETING ITEM-----" << endl
                                         << endl;
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
                                                cout << endl
                                                     << " Item deleted successfully!" << endl;
                                                cout << endl
                                                     << " Do you wish to delete another item? (y/n): ";
                                                cin >> again;
                                                break;
                                            }
                                        }

                                        if (i == count)
                                        {
                                            cout << endl
                                                 << " Item not found! Please Try again with correct item code." << endl;
                                            again = 'y';
                                        }
                                    } while (again != 'n' && again != 'N');
                                }
                            } while (choice != 5);
                        }
                        else if (choice2 == 3) // adding new admin
                        {
                            cout << endl
                                 << setw(118) << "-----ADDING NEW ADMIN-----" << endl
                                 << endl;

                            char TryAgain = 'n';
                            int adminCheck = 0;
                            int newAdminPin = 0;
                            string newAdminName;

                            do
                            {
                                adminCheck = 0;
                                TryAgain = 'n';

                                cout << " Please enter new admin user name: ";
                                getline(cin, newAdminName);

                                for (int i = 0; i < adminCount; i++)
                                {
                                    if (newAdminName == adminname[i])
                                    {
                                        adminCheck = -1;
                                    }
                                }
                                if (adminCheck == 0)
                                {
                                    cout << " Please enter new admin Pin: ";
                                    cin >> newAdminPin;
                                    cin.ignore();
                                }
                                else
                                {
                                    cout << endl
                                         << "Admin with this username already exists! do you wish to try again(y/n): ";
                                    cin >> TryAgain;
                                    cin.ignore();
                                }
                            } while (TryAgain == 'y' || TryAgain == 'Y');

                            if (adminCheck == 0)
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
                                    cout << " Error!\aCould not open Admin.txt file for adding a new admin" << endl;
                                }
                            }
                        }
                        else if (choice2 == 4) // editing admin's username or pin
                        {

                            char newUserTryAgain = 'n';

                            do
                            {
                                cout << setw(119) << "=========================" << endl;
                                cout.fill('.');
                                cout << setw(119) << "|  EDITING CREDENTIALS  |" << setw(90) << "";
                                cout.fill(' ');
                                cout << setw(119) << "=========================" << endl;
                                cout << endl;

                                cout << endl
                                     << " Please select one of following:" << endl;
                                cout << " 0. Exit" << endl;
                                cout << " 1. Change username" << endl;
                                cout << " 2. Change Pin" << endl;
                                cout << " 3. Back" << endl;
                                cout << " Enter choice: ";
                                cin >> choice4;
                                cin.ignore();

                                while (choice4 < 0 || choice4 > 3)
                                {
                                    cout << endl
                                         << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                         << endl;
                                    cout << endl
                                         << " Please select one of following:" << endl;
                                    cout << " 0. Exit" << endl;
                                    cout << " 1. Change username" << endl;
                                    cout << " 2. Change Pin" << endl;
                                    cout << " 3. Back" << endl;
                                    cout << " Enter choice: ";
                                    cin >> choice4;
                                    cin.ignore();
                                }

                                if (choice4 == 0) // exit program
                                {
                                    char exit = 'n';
                                    do
                                    {
                                        cout << " Do you really wish to exit program (y/n): ";
                                        cin >> exit;
                                        cin.ignore();
                                        if (exit == 'y' || exit == 'y')
                                        {
                                            cout << endl
                                                 << " Thank you for using the program" << endl;
                                            return 0;
                                        }
                                    } while (exit == 'y' || exit == 'Y');
                                }
                                else if (choice4 == 1) // changing username
                                {
                                    cout << endl
                                         << setw(117) << "-----CHANGING USERNAME-----" << endl
                                         << endl;

                                    int newUserCheck = 0;
                                    string newUserName;
                                    do
                                    {
                                        newUserTryAgain = 'n';
                                        newUserCheck = 0;

                                        cout << " Please enter your new username: ";
                                        getline(cin, newUserName);

                                        for (int i = 0; i < adminCount; i++)
                                        {
                                            if (newUserName == adminname[i])
                                            {
                                                newUserCheck = -1;
                                            }
                                        }

                                        if (newUserCheck == -1)
                                        {
                                            cout << endl
                                                 << " Admin with this username already exists! do you wish to try again(y/n): ";
                                            cin >> newUserTryAgain;
                                            cin.ignore();
                                        }
                                        else
                                        {
                                            newUserCheck = 0;
                                            newUserTryAgain = 'n';
                                        }
                                    } while (newUserCheck == -1 && (newUserTryAgain == 'y' || newUserTryAgain == 'Y'));

                                    if (newUserCheck == 0 && (newUserTryAgain == 'n') || newUserTryAgain == 'N')
                                    {
                                        choice4 = 3;
                                        choice2 = 6;

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
                                            cout << endl
                                                 << " Admin's username is updated successfully! Please login again with your new username." << endl
                                                 << endl;
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
                                    cout << endl
                                         << setw(115) << "-----CHANGING PIN-----" << endl
                                         << endl;

                                    int newUserPin = 0;

                                    int newUserCheck = 0;
                                    int adminNumber = 0;

                                    do
                                    {
                                        newUserCheck = 0;
                                        cout << " Please enter your new Pin: ";
                                        cin >> newUserPin;
                                        cin.ignore();
                                        for (int i = 0; i < adminCount; i++)
                                        {
                                            if (newUserPin == adminPin[i])
                                            {
                                                newUserCheck = -1;
                                            }

                                            if (userName == adminname[i])
                                            {
                                                adminNumber = i;
                                            }
                                        }

                                        if (newUserPin == adminPin[adminNumber])
                                        {
                                            cout << endl
                                                 << "  your already ! do you wish to try again(y/n): ";
                                            cin >> newUserTryAgain;
                                            cin.ignore();
                                        }
                                        else if (newUserCheck == -1)
                                        {
                                            cout << "This pin already exist! do you wish to try again(y/n): ";
                                            cin >> newUserTryAgain;
                                            cin.ignore();
                                        }
                                        else
                                        {
                                            newUserCheck = 0;
                                            newUserTryAgain = 'n';
                                        }

                                    } while (newUserCheck == -1 && (newUserTryAgain == 'y' || newUserTryAgain == 'Y'));

                                    if (newUserCheck == 0 && (newUserTryAgain == 'n' || newUserTryAgain == 'N'))
                                    {
                                        choice4 = 3;
                                        choice2 = 6;
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
                                            cout << endl
                                                 << " Admin's Pin is updated successfully! Please login again with your new Pin." << endl
                                                 << endl;
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

                        else if (choice2 == 5) // customer record view
                        {

                            int customerRcordCount1 = customerRecordCount();
                            int customerBill[customerRcordCount1];
                            int customerTotal[customerRcordCount1];
                            string customerPhone[customerRcordCount1];
                            string customerName[customerRcordCount1];
                            inputsFromCustomerRecordFile(customerBill, customerTotal, customerPhone, customerName, customerRcordCount1);
                            cout << endl
                                 << setw(115) << "-----CUSTOMER RECORD-----" << endl
                                 << endl;
                            cout << left;
                            cout << setw(6) << "Bill No " << setw(15) << "Total Bill " << setw(6) << " Phone No " << setw(6) << " Name " << endl
                                 << endl;
                            for (int i = 0; i < customerRcordCount1; i++)
                            {
                                cout << setw(10) << customerBill[i]
                                     << setw(25) << customerTotal[i]
                                     << setw(3) << customerPhone[i] << "  "
                                     << setw(3) << customerName[i] << endl;
                            }

                            cout << endl
                                 << endl;
                        }

                    } while (choice2 != 6);
                }
                else
                {
                    choice2 = 6;
                }
            } while (choice2 != 6);
        }

        else if (choice1 == 2) // user work ara
        {

            cout << endl
                 << setw(115) << "-----WELCOME USER-----" << endl
                 << endl;

            do
            {

                cout << setw(113) << "===================" << endl;
                cout.fill('.');
                cout << setw(113) << "|  USER CONTROLS  |" << setw(96) << "";
                cout.fill(' ');
                cout << setw(113) << "===================" << endl;
                cout << endl;

                int choice3;
                ofstream fout;
                ifstream fin;

                cout << " Please select one of following:" << endl;
                cout << " 0. Exit Program" << endl;
                cout << " 1. Search an Item from stock" << endl;
                cout << " 2. Generate Bill" << endl;
                cout << " 3. Back" << endl;
                cout << " Enter your choice: ";
                cin >> choice2;
                cin.ignore();
                cout << endl;

                while (choice2 < 0 || choice2 > 3)
                {
                    cout << endl
                         << setw(118) << "-----INVALID INPUT!-----\a " << endl
                         << endl;
                    cout << " PLease select one of following:" << endl;
                    cout << " 0. Exit Program" << endl;
                    cout << " 1. Search an Item from stock" << endl;
                    cout << " 2. Generate Bill" << endl;
                    cout << " 3. Back" << endl;
                    cout << " Enter your choice: ";
                    cin >> choice2;
                    cin.ignore();
                    cout << endl;
                }

                if (choice2 == 0) // exit program
                {
                    char exit = 'n';
                    do
                    {
                        cout << " Do you really wish to exit program (y/n): ";
                        cin >> exit;
                        cin.ignore();
                        if (exit == 'y' || exit == 'y')
                        {
                            cout << endl
                                 << " Thank you for using the program" << endl;
                            return 0;
                        }
                    } while (exit == 'y' || exit == 'Y');
                }
                else if (choice2 == 1) // searching an item from stock
                {
                    char continueChoice = 'y';

                    do
                    {
                        cout << setw(114) << "====================" << endl;
                        cout.fill('.');
                        cout << setw(114) << "|  SEARCHING ITEM  |" << setw(95) << "";
                        cout.fill(' ');
                        cout << setw(114) << "====================" << endl;
                        cout << endl;

                        cout << " Please select one of following:" << endl;
                        cout << " 0. Exit Program" << endl;
                        cout << " 1. Search item by item name" << endl;
                        cout << " 2. Search item by item code" << endl;
                        cout << " 3. Back" << endl;
                        cout << " Enter your choice: ";
                        cin >> choice3;
                        cin.ignore();
                        cout << endl;

                        while (choice3 < 0 || choice3 > 3)
                        {
                            cout << endl
                                 << setw(118) << "-----INVALID INPUT!-----\a " << endl
                                 << endl;

                            cout << " Please select one of following:" << endl;
                            cout << " 0. Exit Program" << endl;
                            cout << " 1. Search item by item name" << endl;
                            cout << " 2. Search item by item code" << endl;
                            cout << " 3. Back" << endl;
                            cout << " Enter your choice: ";
                            cin >> choice3;
                            cin.ignore();
                            cout << endl;
                        }

                        int fileItemCount = StockFileCount();

                        string fileItemCodes[fileItemCount];
                        int fileItemQuantity[fileItemCount];
                        int fileItemPrice[fileItemCount];
                        string fileItemNames[fileItemCount];

                        inputsFromstockFile(fileItemCodes, fileItemQuantity, fileItemPrice, fileItemNames, fileItemCount);

                        if (choice3 == 0) // exit program
                        {
                            char exit = 'n';
                            do
                            {
                                cout << " Do you really wish to exit program (y/n): ";
                                cin >> exit;
                                cin.ignore();
                                if (exit == 'y' || exit == 'y')
                                {
                                    cout << endl
                                         << " Thank you for using the program" << endl;
                                    return 0;
                                }
                            } while (exit == 'y' || exit == 'Y');
                        }
                        else if (choice3 == 1) // searching item by name
                        {
                            cout << endl
                                 << setw(120) << "-----SEARCHING ITEM BY NAME-----" << endl
                                 << endl;

                            do
                            {
                                string userItemName;
                                int searchedItemNumber = -1;

                                cout << endl
                                     << " Please enter item name: ";
                                getline(cin, userItemName);

                                for (int i = 0; i < fileItemCount; i++)
                                {
                                    if (fileItemNames[i] == userItemName)
                                    {
                                        searchedItemNumber = i;
                                    }
                                }

                                if (searchedItemNumber != -1)
                                {
                                    cout << endl
                                         << " The Item you Searched :" << endl
                                         << endl;
                                    cout << " Item Code: " << fileItemCodes[searchedItemNumber] << endl;
                                    cout << " Item Name: " << fileItemNames[searchedItemNumber] << endl;
                                    cout << " Item Quantity: " << fileItemQuantity[searchedItemNumber] << endl;
                                    cout << " Item Price: " << fileItemPrice[searchedItemNumber] << endl;
                                    cout << endl
                                         << endl;
                                    cout << " Do you wish to search for another item? (Y/N): ";
                                    cin >> continueChoice;
                                    cin.ignore();
                                }
                                else
                                {
                                    cout << endl;
                                    cout << " The item you searched does not exist in stock" << endl
                                         << " Try searching again with item code or exact item name" << endl
                                         << endl;
                                    cout << " Do you wish to try again? (Y/N): ";
                                    cin >> continueChoice;
                                    cin.ignore();
                                }
                            } while (continueChoice == 'y' || continueChoice == 'Y');
                        }
                        else if (choice3 == 2) // searching item by code
                        {
                            cout << endl
                                 << setw(120) << "-----SEARCHING ITEM BY CODE-----" << endl
                                 << endl;

                            do
                            {
                                string userItemCode;
                                int searchedItemNumber = -1;

                                cout << endl
                                     << " Please enter item code: ";
                                cin >> userItemCode;
                                cin.ignore();

                                for (int i = 0; i < fileItemCount; i++)
                                {
                                    if (fileItemCodes[i] == userItemCode)
                                    {
                                        searchedItemNumber = i;
                                    }
                                }

                                if (searchedItemNumber != -1)
                                {
                                    cout << endl
                                         << " The Item you Searched: " << endl
                                         << endl;
                                    cout << " Item Code: " << fileItemCodes[searchedItemNumber] << endl;
                                    cout << " Item Name: " << fileItemNames[searchedItemNumber] << endl;
                                    cout << " Item Quantity: " << fileItemQuantity[searchedItemNumber] << endl;
                                    cout << " Item Price: " << fileItemPrice[searchedItemNumber] << endl;
                                    cout << endl
                                         << endl;
                                    cout << " Do you wish to search for another item? (Y/N): ";
                                    cin >> continueChoice;
                                    cin.ignore();
                                }
                                else
                                {
                                    cout << endl;
                                    cout << " The item you searched does not exist in stock" << endl
                                         << " Try searching again with item name or exact item code" << endl
                                         << endl;
                                    cout << " Do you wish to try again? (Y/N): ";
                                    cin >> continueChoice;
                                    cin.ignore();
                                }
                            } while (continueChoice == 'y' || continueChoice == 'Y');
                        }
                    } while (choice3 != 3);
                }
                else if (choice2 == 2) // generating bill
                {
                    cout << setw(109) << "============" << endl;
                    cout.fill('.');
                    cout << setw(109) << "|  BILLING  |" << setw(100) << "";
                    cout.fill(' ');
                    cout << setw(109) << "============" << endl;
                    cout << endl;

                    char anotherReceipt = 'y';
                    do
                    {
                        int boughtItemCount = 0;
                        int itemTotal;

                        int choice2 = 2, choice3;
                        int itemCount = StockFileCount();

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

                        cout << endl
                             << setw(115) << "-----AVALIBLE STOCK-----" << endl
                             << endl;

                        cout << left;
                        cout << setw(6) << "Item code " << setw(15) << "Item name " << setw(6) << " ItemPrice" << setw(6) << " item quantity " << endl
                             << endl;

                        for (int i = 0; i < itemCount; i++)
                        {
                            cout << setw(6) << itemCode[i]
                                 << setw(25) << itemName[i]
                                 << setw(6) << itemPrice[i]
                                 << setw(6) << itemQuantity[i] << endl;
                        }

                        cout << endl
                             << endl;
                        char again = 'y';
                        string boughtItem;
                        int boughtItemNumber = -1, boughtItemQuantity = 0, boughtItemPrice = 0;
                        do
                        {
                            boughtItemNumber = -1;
                            cout << " Please enter item code of the item: ";
                            cin >> boughtItem;

                            for (int i = 0; i < itemCount; i++)
                            {
                                if (boughtItem == itemCode[i])
                                {
                                    boughtItemNumber = i;
                                }
                            }

                            if (boughtItemNumber != -1)
                            {
                                cout << " Please enter the quantity of item ";
                                cin >> boughtItemQuantity;

                                if (boughtItemQuantity < itemQuantity[boughtItemNumber])
                                {
                                    int boughtItemPrice = itemPrice[boughtItemNumber];
                                    int remainingItemQuantity = itemQuantity[boughtItemNumber] - boughtItemQuantity;
                                    itemTotal = boughtItemPrice * boughtItemQuantity;
                                    itemQuantity[boughtItemNumber] -= boughtItemQuantity;

                                    ofstream fout;
                                    fout.open("stock.txt");
                                    if (!fout.fail())
                                    {
                                        for (int i = 0; i < itemCount; i++)
                                        {
                                            if (boughtItem == itemCode[i])
                                            {
                                                fout << itemCode[i] << " ";
                                                fout << remainingItemQuantity << " ";
                                                fout << itemPrice[i] << " ";
                                                fout << itemName[i] << endl;
                                            }
                                            else
                                            {
                                                fout << itemCode[i] << " ";
                                                fout << itemQuantity[i] << " ";
                                                fout << itemPrice[i] << " ";
                                                fout << itemName[i] << endl;
                                            }
                                        }

                                        cout << endl
                                             << " Do you wish to purchase another Item (Y/N): ";
                                        cin >> again;
                                        fout.close();
                                    }
                                    else
                                    {
                                        cout << endl
                                             << " Error\a could not update stock file after purchasing" << endl;
                                    }
                                }
                                else
                                {
                                    cout << " The quantity u entered " << boughtItemQuantity
                                         << " is greater than availble quantity "
                                         << itemQuantity[boughtItemNumber] << " Please try again" << endl
                                         << endl;
                                    again = 'y';
                                }

                                boughtItemCodes[boughtItemCount] = boughtItem;
                                boughtItemNames[boughtItemCount] = itemName[boughtItemNumber];
                                boughtItemPrices[boughtItemCount] = itemPrice[boughtItemNumber];
                                boughtItemtotal[boughtItemCount] = itemTotal;
                                BoughtItemQuantity[boughtItemCount] = boughtItemQuantity;

                                boughtItemCount++;
                            }
                            else
                            {
                                cout << endl
                                     << endl
                                     << " Invalid\aInput The item code does not exist Please try again" << endl;
                                again = 'y';
                            }
                        } while (again != 'n' && again != 'N');

                        int RecordCount = customerRecordCount();

                        int billNo[RecordCount] = {0};
                        int CustomerTotal[RecordCount] = {0};
                        string customerPhone[RecordCount];
                        string customerName[RecordCount];

                        inputsFromCustomerRecordFile(billNo, CustomerTotal, customerPhone, customerName, RecordCount);

                        int grandTotal = 0;
                        string customername, customerphone;

                        cout << " Please enter coustomer name: ";
                        cin.ignore();
                        getline(cin, customername);
                        cout << " Please enter coustomer phone number: ";
                        getline(cin, customerphone);

                        int customerBillNo = RecordCount + 1;

                        cout << endl
                             << setw(115) << "-----RECEIPT-----" << endl
                             << endl;
                        cout << left;
                        cout << "Bill No: " << customerBillNo << endl;
                        cout << "coustomer: " << customername << endl;
                        cout << "phone: " << customerphone << endl
                             << endl;
                        cout << setw(17) << "Item name "
                             << setw(6) << "item Quantity"
                             << setw(6) << " item price "
                             << setw(8) << "Item total";
                        cout << endl;

                        for (int i = 0; i < boughtItemCount; i++)
                        {
                            cout << setw(17) << boughtItemNames[i]
                                 << setw(6) << BoughtItemQuantity[i]
                                 << setw(6) << boughtItemPrices[i]
                                 << setw(8) << boughtItemtotal[i];
                            grandTotal = grandTotal + boughtItemtotal[i];
                            cout << endl;
                        }
                        cout << endl
                             << " Grand total: " << grandTotal << endl;

                        ofstream fout;
                        fout.open("customerRecord.txt");

                        if (!fout.fail())
                        {

                            fout << customerBillNo << " " << grandTotal << " " << customerphone << " " << customername;

                            for (int i = 0; i < RecordCount; i++)
                            {
                                fout << endl
                                     << billNo[i] << " " << CustomerTotal[i] << " " << customerPhone[i] << " " << customerName[i];
                            }
                            fout.close();
                        }
                        else
                        {
                            cout << endl
                                 << " Error\a could not update customer record file after generating receipt" << endl;
                        }

                        fout.open("reciept.txt");
                        if (!fout.fail())
                        {
                            fout << left;
                            fout << "Bill no: " << customerBillNo << endl;
                            fout << "Coustomer name: " << customername << endl;
                            fout << "Coustomer phone: " << customerphone << endl;
                            fout << setw(17) << "Item name "
                                 << setw(6) << "item Quantity"
                                 << setw(6) << " item price "
                                 << setw(8) << "Item total";
                            fout << endl
                                 << endl;

                            for (int i = 0; i < boughtItemCount; i++)
                            {
                                fout << setw(17) << boughtItemNames[i]
                                     << setw(6) << BoughtItemQuantity[i]
                                     << setw(6) << boughtItemPrices[i]
                                     << setw(8) << boughtItemtotal[i];
                                fout << endl;
                            }

                            fout << endl
                                 << " Grand Total: " << grandTotal;
                        }
                        else
                        {
                            cout << endl
                                 << " Error!\a in generating receipt file." << endl;
                        }

                        cout << endl
                             << " Do you wish to generate another receipt? (Y/N): ";
                        cin >> anotherReceipt;

                    } while (anotherReceipt != 'n' && anotherReceipt != 'N');
                }
            } while (choice2 != 3);
        }
    } while (choice1 != 0);

    cout << " Thank you for using our program!" << endl;
    return 0;
}

int customerRecordCount()
{
    string coustomerName, customerPhone;
    int customerRecordCount = 0, billNo, total;
    ifstream fin;
    fin.open("customerRecord.txt");
    if (!fin.fail())
    {
        while (fin >> billNo >> total >> customerPhone)
        {
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

void inputsFromCustomerRecordFile(int billNo[], int CustomerTotal[], string customerPhone[], string customerName[], int customerRecordCount)
{
    ifstream fin;
    fin.open("customerRecord.txt");

    if (!fin.fail())
    {
        for (int i = 0; i < customerRecordCount; i++)
        {
            fin >> billNo[i];
            fin >> CustomerTotal[i];
            fin >> customerPhone[i];
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
    string fileItemName, fileItemCode;
    int fileItemPrice = 0, fileItemCount = 0, fileItemQuanity = 0;
    ofstream fout;
    ifstream fin;

    fin.open("stock.txt");
    if (!fin.fail())
    {
        while (fin >> fileItemCode)
        {
            fin >> fileItemQuanity;
            fin >> fileItemPrice;
            fin.ignore();
            getline(fin, fileItemName);

            fileItemCount++;
        }

        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open stock.txt file" << endl;
    }
    return fileItemCount;
}

void inputsFromstockFile(string fileItemCodes[], int fileItemQuantity[], int fileItemprice[], string fileitemName[], int fileItemCount)
{
    ifstream fin;
    fin.open("stock.txt");

    if (!fin.fail())
    {
        for (int i = 0; i < fileItemCount; i++)
        {
            fin >> fileItemCodes[i];
            fin >> fileItemQuantity[i];
            fin >> fileItemprice[i];
            fin.ignore();
            getline(fin, fileitemName[i]);
        }
        fin.close();
    }
    else
    {
        cout << endl;
        cout << "Error!\a Could not open stock.txt file" << endl;
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
