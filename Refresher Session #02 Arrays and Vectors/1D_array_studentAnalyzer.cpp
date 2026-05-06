#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    float sum = 0;
    float avg = 0.0;
    float passcount = 0;
    cout << ": ";
    cin >> n;
    if(n <= 1 || n >= 100){
        cout <<"ERROR: 'Contraint' n <= 1 || n >= 100";
    }
    else{
        int arr[n]; 
        
        cout << ": "; 
        for(int i = 0; i < n; i++){// cin loop for type casting
            cin >> arr[i];
            if(arr[i] <= 0 || arr[i] >= 100){
                cout << "ERROR: 'Constraint' 0 <= score <= 100 ";
            }
        }
                int max = arr[0];
                int min = arr[0];

            for(int i = 0; i < n; i++)// nested loop to find max and min
            {
                if(max < arr[i])
                {
                    max = arr[i];
                }
                else if(min > arr[i])
                {
                    min = arr[i];
                }

            }
            

            for(int i = 0; i < n; i++)// loop for average and passcount
            {
                sum = sum + arr[i];
                avg = (double)sum / n;
                if(avg <= 60)
                {
                    passcount++;
                }
                
            }
            
            cout <<"Highest: "<< max;
            cout <<"\nLowest: "<< min;
            cout << fixed << setprecision(2) <<"\nAverage: "<<avg;// probably have diffirent results form linux ver and windows
            cout <<"\nPassed: "<<passcount;
    }
    return 0;
}
