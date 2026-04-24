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