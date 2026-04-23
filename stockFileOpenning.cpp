#include<iostream>
#include<String>
#include<fstream>
#include<iomanip>

using namespace std;

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
        getline(fin,fileItemName);
        fin>>fileItemQuanity;
        fin>>fileItemPrice;
        fileItemCount++;
        fin>>fileItemCode;
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
      fin >> fileItemCodes[i];
      getline(fin,fileitemName[i]);
      fin >> fileItemQuantity[i];
      fin >> fileItemprice[i];
    }
    fin.close();
  }
   else
  {
    cout<<endl;
    cout<<"Error!\aCould not open stock.txt file"<<endl;
  }
}