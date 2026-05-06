#include <iostream>
using namespace std;
int main(){
int r= 0, c=0;
int sum = 0;
int max;
cout << ": ";
cin >> r;
cin >> c;

int grid[r][c];// size intializer for grid
if(r <= 1 || c >= 10){
    cout << "ERROR: 'Contraint'  1 <= r || c >= 100";
    return 0;
}
else{
    cout << ": ";// cin for grid 
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
            if (grid[i][j] >= 100){
                cout << "ERROR: 'constraint' grid[i][j] >= 100 ";
            return 0;
        }
    }

    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
        sum = sum + grid[i][j];// both i and j since it needs the sums of all rows.
        }
            cout << "Row "<< i + 1 <<": "<< sum << endl;
        sum = 0;
    }
    // i is for row j is for column 
    // searching for row choose i 
    // for column choose j thus j is the for while i is the nested.
    for(int j = 0; j < r; j++){
        max = grid[0][j];
        for(int i = 0; i < c; i++){
            if(max < grid[i][j])
            {
                max = grid[i][j];
            }
        }
        cout << "Column "<< j + 1 << ": " << max << endl;
    }
}
    return 0;
}
