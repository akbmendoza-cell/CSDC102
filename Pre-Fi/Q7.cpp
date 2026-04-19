#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out ("student.txt");
    cout << "=== Input === " <<endl;
    string name;
    float grade;

    for (int i = 0; i < 3; i++)
    {
        cin >> name >> grade;
        out << name << " " << grade << endl;
    }
    out.close();

    ifstream in("student.txt");
    cout << "Records saved successfully." <<endl;
    while (in >> name >> grade)
    {
        cout << name << " " << grade << endl;
    }
    in.close();
}