#include <iostream>
#include <string>
using namespace std;

struct product{
  string name;
  int quantity;
  float price;
  int Total_value;  

};

main(){
    product Fields [5]; 
    int n;
    int highest = 0;
    cout << " How many products: ";
    cin  >> n;

    if( n <= 5)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Name of product: ";
            cin  >> Fields[i].name;
            cout << "Quantity of product: ";
            cin  >> Fields[i].quantity;
            cout << "Price of product: ";
            cin  >> Fields[i].price;
        }
    }
    else
    {
        cout << "Maximum of 5 Products only";
        return 0;
    }

    cout <<"Name      Quantity   Price   Total value"<<endl;
    cout <<"----      -------    -----   -----------"<<endl;
    for(int i = 0; i < n; i++)
    {
        Fields[i].Total_value = Fields[i].quantity * Fields[i].price;
     cout <<Fields[i].name << "         " << Fields[i].quantity << "         "<<Fields[i].price << "      "<<Fields[i].Total_value <<endl;
    }
    for (int i = 0; i < n; i++)
    {
      for(int j = i + 1; j < n; j++)
      {
        if (Fields[i].Total_value < Fields[j].Total_value)
        {
            highest = Fields[i].Total_value;
            Fields[i].Total_value = Fields[j].Total_value;
            highest = Fields[j].Total_value;
            cout << "Most expensive product"<<endl;
            cout << Fields[j].name<< "         " << Fields[j].quantity << "         " <<Fields[j].price;
        }
      }
    }
    cout<<"      " << highest;
    return 0;
}