#include <iostream>
using namespace std;
void problem1();
void problem2();
void problem3();
int main() {
cout<<"PROBLEM 1"<<endl;
cout<<"Queue Chaos! VIP Alert at the Customer Service Desk"<<endl;
cout<<"ONE DIMENSIONAL ARRAY"<<endl;
cout<<"=============="<<endl;  
   problem1();
   cout<<endl;
cout<<"PROBLEM 2"<<endl;

cout<<"Tindahan ni Aling Nena: Week-to-Week Sales Showdown"<<endl;
cout<<"Two-Dimensional Array - Matrix Operations"<<endl;
cout<<"=============="<<endl;  
cout<<endl;
   problem2();
   cout<<"\n\n";
cout<<"PROBLEM 3"<<endl;

cout<<"A Week in Degrees: Making Sense of Daily Temperatures"<<endl;
cout<<"Functions with Array Parameters"<<endl;  
cout<<"=============="<<endl;
cout<<endl;
problem3();
    return 0;
}
void problem1(){

    
        // Step 1: Declare and initialize matrices
    int A[3][3] = {
        {150, 200, 180},
        {220, 190, 210},
        {170, 230, 195}
    };
    
    int B[3][3] = {
        {165, 210, 195},
        {205, 185, 200},
        {180, 240, 210}
    };
    
    int C[3][3];

    
    // Step 3: Matrix addition using nested loops
    // [WRITE YOUR CODE HERE] 
    for(int i = 0; i < 3; i++ ){
      for(int j = 0; j < 3; j++){
        C[i][j] = A[i][j] + B[i][j];
      }
    }
    
    // Step 4: Display the result
    // [WRITE YOUR CODE HERE] 
    cout<<"Matrix C (Total Sales from both weeks in Pesos): "<<endl;
    cout<< "         Softdrinks  Snacks  Load"<<endl;
    for(int i = 0; i < 3; i++){
        if(i == 0){
            cout<<" Monday    ";
        }
        else if(i == 1){
            cout<<" Tuesday   ";
        }
        else{
            cout<<" Wednesday ";
        }
        for(int j = 0; j < 3; j++){
            cout<< "P"<< C[i][j]<< "     ";
        }
        cout<<endl;


    }
}
void problem2(){
    // Declare and initialize
    string queue[8] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "", "", ""};
    int size = 5;
    string newElement = "Frank";
    int position = 2;

    // Step 2: Check if array is full
    // INSERT CODE HERE
   if (size >= 8){
       cout<<"Queue is full, cannot insert";
   }
     
     
    // Step 3: Check if position is valid
    // INSERT CODE HERE
  if(position < 0 || position > size){
      cout<< "Invalid position";
  }
    // Step 4: Shift elements to the right
    // INSERT CODE HERE
  for(int i = size - 1; i >= position; i--){
        queue[i + 1] = queue[i];
    }
     
    // Step 5: Insert new element
    // INSERT CODE HERE
queue[position] = newElement;
    // Step 6: Update size
    // INSERT CODE HERE
   size = size + 1;
    // Step 7: Display result
    // INSERT CODE HERE
    cout<<"Original queue:  'Alice'  'Bob'  'Charlie'  'Diana'  'Eve' "<<endl;
    cout<<"After inserting Frank at position 2: "<<endl;
    for(int i = 0; i < 8 ; i++){
        cout<< queue[i]<<" ";
    }
    cout<<"\n";
    cout<<"New size: "<< size;
    
}
void problem3(){
    


    // Declare and initialize the temperatures array
    
    int temps[7] = {28, 31, 29, 33, 30, 27, 32};
  int size = 7;
  int sum = 0;
  float average = 0.0;
    // Call the function and store result
    // [WRITE YOUR CODE HERE] 
    for(int i = 0; i < size; i++){
        sum = sum + temps[i];
    }
    average = (float)sum/size;
    // Display the result
    // [WRITE YOUR CODE HERE]
    cout<<"Average Temperature: "<< average << "c";
    //cout<<sum;
   
}

