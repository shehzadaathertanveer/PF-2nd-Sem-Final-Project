#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int adminFileCount();
void inputsFromAdminFile(string[], int[], int);

int main()
{
    int choice1 = 1;

    if (choice1 == 1)
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
                        cout << endl
                             << "Invalid Input!" << endl;
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
                                cout << endl
                                     << "Invalid Input!" << endl;
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
                                cout << endl
                                     << "Thank you for using the program " << endl;
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
                cout << endl
                     << "Invalid credentials!\aplease try again " << endl;
            }
        } while (choice1 != 3);
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
        cout << "Error!\aCould not open Admin.txt file" << endl;
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
        cout << "Error!\aCould not open Admin.txt file" << endl;
    }
}