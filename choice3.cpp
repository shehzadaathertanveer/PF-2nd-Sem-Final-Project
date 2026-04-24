//reciept
// reciept

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int StockFileCount();
void inputsFromstockFile(string[], int[], int[], string[], int);

// showing stock
void showStock(string fileItemCodes[], string fileItemNames[], int fileItemQuantity[], int fileItemPrice[], int size)
{
    cout << "Code\tItem\t\tStock\tPrice";

    for (int i = 0; i < size; i++)
    {
        cout << fileItemCodes[i] << "\t" << fileItemNames[i] << "\t\t" << fileItemQuantity[i] << "\t" << fileItemPrice[i] << endl;
    }
}
// billing
void billing(string fileitemcodes[], string fileitemnames[], int fileitemquantity[], int fileitemprice[], int size)

{
    string buyID;
    int quantity;

    string billID[50];
    string billItem[50];
    int billQuantity[50];
    int billPrice[50];
    int billTotal[50];
     
    int count =0;
    int grandtotal=0;

    cout << "\n===== BILLING SYSTEM =====\n";

    do
    {
        cout << "\nPlease enter the item code ";
        cin >>buyID;
         bool found = false;

         bool found = false;

        for(int i = 0; i < size; i++)
        {
            if(fileitemcodes[i] == buyID)
            {
                found = true;

                cout << "Please enter the quantity: ";
                cin >> quantity;

                if(quantity > 0 && quantity <= fileitemquantity[i])
                {
                    int total = quantity* fileitemprice[i];

                    billID[count] = fileitemcodes[i];
                    billItem[count] = fileitemnames[i];
                    billQuantity[count] = quantity;
                    billPrice[count] = fileitemprice[i];
                    billTotal[count] = total;

                    count++;
                    grandtotal=total+grandtotal;

                    fileitemquantity[i] = fileitemquantity[i] - quantity;

                    cout<<"your items added\n";
                }
                else
                {
                    cout << "Invalid quantity. Please try again\n";
                }

                break;
            }
        }
        if(!found)
        {
            cout << "Item code not found. Please try again\n";
        }
          
         char more;
        cout << "Do you want to add more items? (y/n) ";
        cin >> more;
        
         while( more != 'y' && more != 'Y' && more != 'n' && more != 'N')
        {
            cout << "Invalid input! Enter y or n: ";
            cin >> more;
        }

    } while( more == 'y' || more == 'Y');

    cout << "\n========= RECEIPT =========\n";
    cout << "Code\tItem\tQuantity\tPrice\tTotal\n";

    for(int i = 0; i < count; i++)
    {
        cout << billID[i] << "\t"
             << billItem[i] << "\t"
             << billQuantity[i] << "\t"
             << billPrice[i] << "\t"
             << billTotal[i] << endl;
    }

    cout << "-----------------\n";
    cout << "Grand Total: " << grandtotal << endl;
    cout << "=====================\n";

    }
   
        int StockFileCount()
    {
    string fileItemCode;
    int fileItemPrice; int fileItemQuantity;
    int count = 0;

    ifstream fin("stock.txt");

    if(!fin)
    {
        cout << "Error in opening file!\n";
        return 0;
    }
    string fileitemname;
    fin>>fileItemCode>>fileitemname>>fileItemQuantity>>fileItemPrice;
    {
        fin.ignore();
        getline(fin, fileitemname);
        count++;
    }
        fin.close();
        return count;
    }

    void inputsFromstockFile(string fileItemCodes[], int fileItemQuantity[], int fileItemPrice[], string fileItemNames[], int size)
{
    ifstream fin("stock.txt");

    if(!fin)
    {
        cout << "Error opening file!\n";
        return;
    }

    for(int i = 0; i < size; i++)
    {
        fin >> fileItemCodes[i] >> fileItemQuantity[i] >> fileItemPrice[i];
        fin.ignore();
        getline(fin, fileItemNames[i]);
    }

    fin.close();
}
  int main()
{
    int fileitemcount = StockFileCount();
    string* fileItemCodes = new string[fileitemcount];
    string* fileItemNames = new string[fileitemcount];
    int* fileItemQuantity = new int[fileitemcount];
    int* fileItemPrice = new int[fileitemcount];

    inputsFromstockFile(fileItemCodes, fileItemQuantity, fileItemPrice, fileItemNames, fileitemcount);
    int choice ;
do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Want to purchase something?\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "\n===== PRODUCTS AVAILABLE =====\n";
            showStock(fileItemCodes, fileItemNames, fileItemQuantity, fileItemPrice, fileItemCount);

            billing(fileItemCodes, fileItemNames, fileItemQuantity, fileItemPrice, fileItemCount);
        }
        else if(choice == 2)
        {
            cout << "Thank you! Goodbye.\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while(choice != 2);

    return 0;
}
               
do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Want to purchase something?\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "\n===== PRODUCTS AVAILABLE =====\n";
            showStock(fileItemCodes, fileItemNames, fileItemQuantity, fileItemPrice, fileItemCount);

            billing(fileItemCodes, fileItemNames, fileItemQuantity, fileItemPrice, fileItemCount);
        }
        else if(choice == 2)
        {
            cout << "Thank you! Goodbye.\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while(choice != 2);

    return 0;
}