#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    vector<string> items;
    string command, item;
    int cmds = 0;

    while(true)// Will initialize without using a size to dynamic, since it's vector size will increase with each push back
    {// command stops if DONE or false
        cin >> command;
        if(command == "DONE")
        {
            break;
        }
        else if(command == "ADD")
        {
            cin >> item;
            items.push_back(item);
            cmds++;
        }
        else if(command == "REMOVE")
        {
            if(items.empty()){
                cout << "\nList is empty ";
                cmds++;
            }
            else{
                items.pop_back();
                cmds++;
            }
        }
        else if(command == "COUNT"){
            if(items.empty()){
                cout << "\nList is empty ";
                cmds++;
            }
            else{
             cout << size(items);
             cmds++;
            }
        }
        else if(command == "SHOW")
        {
            cmds++;
            for(int i = 0; i < size(items); i++){
                cout << i + 1 <<". "<< items[i] << endl;
            }
        }
        else if(cmds >= 50 ){
            cout<< "Limits of commands reached";
            break;
        }
    }
    cout << "Final list has " << size(items) << "items(s).";
    return 0;
}
