#include <iostream>
#include <vector>
using namespace std;
//global functions
vector<string> receiptItems;
vector<double> receiptPrices;
vector<int> receiptQuantities;
string ADMIN_PASSCODE = "6767";
//function 1
void displayMenu (const vector<string> & menuItems,
                  const vector<double> & menuPrices ){
    std::cout <<"=============================\n";
    std::cout <<"            MENU\n";
    std::cout <<"=============================\n\n";

    for(int i = 0; i < menuItems.size(); i++){
      std::cout<< i << " - " << menuItems[i] << " php" << menuPrices[i] <<endl;
    }
}

//function 2
int login() {
   int role;
   string passcode;
   

   std::cout << "[1] User   [2] Admin   [3] Shutdown\n";
   std::cout << "Enter choice: ";
   std::cin >> role;

   
    if(role == 2) {
        std::cout << "Enter Admin Passcode: ";
        std::cin >> passcode;
        if(passcode != ADMIN_PASSCODE) return 0; // invalid
    }
    return role;  // 1, 2, or 3
    
   }


//function 3
void Viewreciept ( vector<string> & receiptItems,
                   vector<int> &receiptQuantities){
  cout << "Do you want to checkout and pay? (Y/N): ";
char checkout;
cin >> checkout;
int total,index;
if(checkout == 'Y' || checkout == 'y') {
    double payment;
    do {
        cout << "Enter payment amount: ";
        cin >> payment;
        if(payment < total)
            cout << "Insufficient. Please enter at least " << total;
    } while(payment < total);

    double change = payment - total;
    cout << "Change: " << change << endl;

    // Clear receipt after successful payment
    receiptItems.clear();
    receiptPrices.clear();
    receiptQuantities.clear();
    receiptItems.erase(receiptItems.begin() + index);
}

} 

//function 4
// the user menu was inspired from lab exercise 2
void userMenu(vector<string>& menuItems,
              vector<double>& menuPrices
              ) {
    int choice, index;
        do{
      cout<<"\n";
      std::cout <<"=============================\n";
    std::cout <<"          USER  MENU\n";
    std::cout <<"=============================\n\n";
    cout<< " 1. View Menu\n ";
     cout<< "2. Add Item to Receipt\n ";
     cout<< "3. Remove Item from Receipt\n ";
     cout<< "4. View Receipt\n ";
     cout<< "5. Exit\n ";
     cout<< "Enter choice: ";
     std::cin>> choice;
   // view menu
   if(choice == 1){
      cout<<"\n";
       displayMenu(menuItems, menuPrices);
       cout<<"\n";
       cout << "Press any number to continue: ";
       std::cin>>choice;

   }
   //add item
   else if(choice == 2){
       int quantity;
       bool found = false;
       cout<<"\n ";
       for(int i = 0; i < menuItems.size(); i++ ){
           cout << i << "-"<< menuItems[i] << "- Php" << menuPrices[i] << endl;
       }
       cout << " Enter item number to add: ";
       std::cin>> index;
       for(int i = 0; i < receiptItems.size(); i++) {
    if(receiptItems[i] == menuItems[index]) {
        receiptQuantities[i] += quantity; // merge!
        found = true;
        break;
    }
}
       if(!found) {
    receiptItems.push_back(menuItems[index]);
    receiptPrices.push_back(menuPrices[index]);
    receiptQuantities.push_back(quantity);

    cout<<"Added " << menuItems[index] << "- php" << menuPrices[index] << " - " <<quantity <<endl; 
       
    }
       else{
           cout << "Invalid Input\n";
       }
       cout << "Press a number to continue: ";
       std::cin>>choice;
    
   //remove item
   } else if(choice == 3){
    cout<<"\n";
       if(receiptItems.empty()){
           cout <<"receipt is empty\n";
       }
       else{
           for(int i = 0; i < receiptItems.size(); i++ ){
           cout << i << "-"<< receiptItems[i] << "- Php" << receiptPrices[i] << endl;
       }
       cout<< "Enter item number to remove: ";
       cin>>index;
       
       if(index >= 0 && index < menuItems.size()){
        receiptItems.erase(receiptItems.begin() + index);
        receiptPrices.erase(receiptPrices.begin() + index);
        receiptQuantities.erase(receiptQuantities.begin() + index);
        cout<< " Item removed successfully. \n";
       }
       else{
           cout<< "Invalid output\n";
       }
      }
   }
   // view reciept
   else if(choice == 4){cout<<"\n";
       if(receiptItems.empty()){
           cout << " No items ordered yet.\n";
       }
       else {
           double total = 0;
           for(int i = 0; i < receiptItems.size(); i++) {
               cout << i << "-"<< receiptItems[i] << "- Php" << receiptPrices[i] << " - " << receiptQuantities[i]<< endl;
               total += receiptPrices[i] * receiptQuantities[i];
           }
           cout << "Total: " << total << endl;
           Viewreciept(receiptItems, receiptQuantities);
       }
   }
   //exit
    } while(choice != 5);
}

              

//function 5
void adminMenu(vector<string>& menuItems,
               vector<double>& menuPrices
               ) {
    int choice;
    
    do {
        cout << "1. View Menu\n";
        cout << "2. Add New Menu Item\n";
        cout << "3. Change admin Passcode\n";
        cout << "4. Exit\n";
        cin >> choice;
   
        if(choice == 1){
            displayMenu(menuItems, menuPrices);
            cout<<"\n";
        }
        if(choice == 2) {
            string newItem; double newPrice;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, newItem);
            cout << "Enter price: ";
            cin >> newPrice;
            menuItems.push_back(newItem);
            menuPrices.push_back(newPrice);
        }
         
        else if(choice == 3){
            string newPass;
            cout << "Enter new admin passcode: ";
            cin >> newPass;
            ADMIN_PASSCODE = newPass;
            std::cout << "Password changed successfully.\n";
        }
        

    } while(choice != 4);
    
}


int main(){
   vector<string> menuItems = {"Burger","Fries","Coke","Chicken"};
    vector<double> menuPrices = {99, 49, 39, 129};
    
    while(true) {
        
        int role = login();
        if(role == 1) userMenu(menuItems, menuPrices);
        else if(role == 2) adminMenu(menuItems, menuPrices);
        else if(role == 3) { break; } // shutdown
        else { cout << "Access Denied.\n"; break; }
    }

    return 0;
}
