#include <iostream>
#include <string>
using namespace std;


struct student {
   
    string name;    // student name
    float midterm;  // grade
    float final_exam; //grade
    float average;  //average
    string remark;
};




main ()
{
   
    student stud[5];


    //student 1
    stud[0].name                                       = "Henry  ";
    stud[0].midterm                                    = 92;
    stud[0].final_exam                                 = 93;
    stud[0].average = stud[0].midterm + stud[0].final_exam;
    stud[0].average /= 2;
    if(stud[0].average >= 75 )
    {
        stud[0].remark                                 = "Passed" ;
    }
        else
        {
            stud[0].remark                             = "Failed";
        }


    //Student 2
    stud[1].name                                       = "James  ";
    stud[1].midterm                                    = 93;
    stud[1].final_exam                                 = 94;
    stud[1].average = stud[1].midterm + stud[1].final_exam;
    stud[1].average /= 2;
    if(stud[1].average >= 75 )
    {
        stud[1].remark                                 = "Passed" ;
    }
        else
        {
            stud[1].remark                             = "Failed";
        }


    //student 3
    stud[2].name                                       = "Aljosh ";
    stud[2].midterm                                    = 75;
    stud[2].final_exam                                 = 63;
    stud[2].average = stud[2].midterm + stud[2].final_exam;
    stud[2].average /= 2;
    if(stud[2].average >= 75 )
    {
        stud[2].remark                                 = "  Passed" ;
    }
        else
        {
            stud[2].remark                             = "  Failed";
        }
     
    //Student 4
    stud[3].name                                       = "Romeo  ";
    stud[3].midterm                                    = 98;
    stud[3].final_exam                                 = 99;
    stud[3].average = stud[3].midterm + stud[3].final_exam;
    stud[3].average /= 2;
    if(stud[3].average >= 75 )
    {
        stud[3].remark                                 = "Passed" ;
    }
        else
        {
            stud[3].remark                             = "Failed";
        }
   
    //Student 5
    stud[4].name                                       = "Althea";
    stud[4].midterm                                    = 100;
    stud[4].final_exam                                 = 99;
    stud[4].average = stud[4].midterm + stud[4].final_exam;
    stud[4].average /= 2;
    if(stud[4].average >= 75 )
    {
        stud[4].remark                                 = "Passed" ;
    }
        else
        {
            stud[4].remark                             = "Failed";
        }
   
    cout <<"Name      Midterm   Final   Average   Remark"<<endl;
    cout <<"----      -------   -----   -------   ------"<<endl;
    for(int i = 0; i < 5; i++)
    {
     cout <<stud[i].name << "       " << stud[i].midterm << "       "<<stud[i].final_exam << "      " << stud[i].average<< "     " << stud[i].remark<<endl;
    }


    return 0;
}


