#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "=== Input ===" << endl;
    string* names = new string[n];
    cin.ignore();
    
    for(int i = 0; i < n; i++)
    {
        getline(cin, names[i]);
    }
    cout<< "=== Output === "<< endl;
    for(int i = 0; i < n; i++)
    {
        cout << names[i] << endl;
    }

    delete[] names;
}