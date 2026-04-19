#include <iostream>
#include <string>
using namespace std;
 class BankAccount
    {
        private:
            string accountHolder;
            double balance;
            
        public:
            // Constructor
          
         BankAccount(string dep, double bal )
          {
            accountHolder = dep;
            balance = bal;
            
          }
        
          BankAccount()
          {
            accountHolder = "Mendoza";
            balance = 50000;
          }

          void deposit (double amount)
            { 
                int opt, customAmount;
                do
                {
                    
                    cout << "\n=== DEPOSIT ===" << endl;
                    cout << "1. Deposit 100" << endl;
                    cout << "2. Deposit 500" << endl;
                    cout << "3. Deposit 1000" << endl;
                    cout << "4. Deposit 5000" << endl;
                    cout << "5. Enter other amount" << endl;
                    cout << "6. Exit"<< endl;
                    cout << "Choice: ";
                    cin >> opt;

                    if(opt == 1)
                    {
                        amount = 100;
                        balance += amount;  
                        cout << "\nDeposit successful" << endl;
                        cout << "Your new Balance $:" << balance;
                    }
                    else if(opt == 2)
                    {
                        amount = 500;
                        balance += amount;  
                        cout << "\nDeposit successful" << endl;
                        cout << "Your new Balance $:" << balance;
                    }
                    else if(opt == 3)
                    {
                        amount = 1000;
                        balance += amount;  
                        cout << "\nDeposit successful" << endl;
                        cout << "Your new Balance $:" << balance;
                    }
                    else if(opt == 4)
                    {
                        amount = 5000;
                        balance += amount;  
                        cout << "\nDeposit successful" << endl;
                        cout << "Your new Balance $:" << balance;
                    }
                    else if(opt == 5)
                    {
                        cout << "\n----------\n";
                        cout << "Enter Amount: ";
                        cin >> customAmount;
                        amount = customAmount;

                        if (amount <= 0) 
                                {
                                    cout << "Amount Invalid\n\n" << endl;
                                    continue;
                                }
                                    else
                                    {
                                        balance += amount;  
                                        cout << "\nDeposit successful" << endl;
                                        cout << "Your new Balance $:" << balance;  
                                    } 
                    }

                }while(opt != 6);
    
            };

          void withdraw (double amount)
          {
            int opt, customAmount;
            do
            {
                double fee = 20;
                double totalDeduction = amount + fee;

                cout << "\n=== WITHDRAW ===" << endl;
                cout << "1. Withdraw 100" << endl;
                cout << "2. Withdraw 500" << endl;
                cout << "3. Withdraw 1000" << endl;
                cout << "4. Withdraw 5000" << endl;
                cout << "5. Enter other amount" << endl;
                cout << "6. Exit" << endl;
                cout << "Choice: ";
                cin >> opt;

                if(opt == 1)
                {
                    amount = 100;

                        if(balance >= totalDeduction) 
                        {
                            balance -= totalDeduction;  
                            cout << "\nWithdrawal successful" << endl;
                            cout << " Your new balance $:" << balance;
                        }
                            else
                            {
                                cout << "\nYou don't have enough balance on your account\n";
                                continue;
                            }
                }
                else if(opt == 2)
                {
                     amount = 500;
                      
                        if(balance >= totalDeduction) 
                        {
                            balance -= totalDeduction;  
                            cout << "\nWithdrawal successful" << endl;
                            cout << " Your new balance $:" << balance;
                        }
                            else
                            {
                                cout << "\nYou don't have enough balance on your account\n";
                                continue;
                            }
                }     
                else if(opt == 3)
                { 
                    amount = 1000;
                    
                        if(balance >= totalDeduction) 
                        {
                            balance -= totalDeduction;  
                            cout << "\nWithdrawal successful" << endl;
                            cout << " Your new balance $:" << balance;
                        }
                            else
                            {
                                cout << "\nYou don't have enough balance on your account\n";
                                continue;
                            }
                }        
                else if(opt == 4)
                { 
                    amount = 5000;
                    
                        if(balance >= totalDeduction) 
                        {
                            balance -= totalDeduction;  
                            cout << "\nWithdrawal successful" << endl;
                            cout << " Your new balance $:" << balance;
                        }
                            else
                            {
                                cout << "\nYou don't have enough balance on your account\n";
                                continue;
                            }
                }        
                else if(opt == 5) 
                {
                    cout << "\n----------\n";
                    cout << "Enter Amount: ";
                    cin >> customAmount;
                    amount = customAmount;

                    if (amount <= 0) 
                    {
                    cout << "Amount Invalid\n\n" << endl;
                    continue;
                    }  

                    if (amount >= balance) 
                    {
                        cout << "\nYou don't have enough balance on your account\n";
                        continue;
                    }
                        else
                        {
                            balance -= totalDeduction;  
                            cout << "\nWithdrawal successful" << endl;
                            cout << " Your new balance $:" << balance;
                        }

                }

            }while(opt != 6);
          };

            void displayBalance() 
            { 
                cout << accountHolder << ": $" << balance << endl;
            }
          
    };
    
main(){
   int choice;
   double amount;
    BankAccount Mendoza;
    do
    {
            cout << "=== BANK ACCOUNT SYSTEM ==="<<endl;
            cout << "[1] Deposit    [2] Withdraw    [3] Check Balance    [4] Exit" << endl;
            cout << "Enter command: ";
            cin  >> choice;

            if(choice == 1)
            {
                Mendoza.deposit(amount);
            }
                else if(choice == 2)
                {
                    Mendoza.withdraw(amount);
                }
                    else if(choice == 3)
                    {
                        Mendoza.displayBalance();
                    }
                        else if(choice == 4)
                        {
                            cout << " Thank you for using our Bank system.";
                        }
                            else
                            {
                                cout << " Invalid Command Please try again.";
                            }
    }while(choice != 4);

    return 0;
}