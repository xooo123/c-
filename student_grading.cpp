#include<iostream>
using namespace std;
#define MAX_STUDENT 1000
//this function to input the grades for each student and store in in memory
/*  num_student: number of student choosen by the user
    num_subject:  number of subjects choosen
    *num_grades: point to the number of grades per subject
*/
 float*** grades_input(int num_student, int num_subject, int* num_grades);
 //this function to calculate average of each student in all subjects
 /* grades: (triple pointer) represent a to a 3D array stores the num of student the subject for each student and the grades for each subject */
 float* average_grades(float*** grades, int num_student, int num_subject, int* num_grades);
 // this function finds the highest average among the students
 //averages: pointer points to the adress that stores the average for each student
 float find_highest(float* averages, int num_student);
 // this function finds the lowest average among the students
 float find_lowest(float* averages, int num_student);
 // this function sort the grades for subjects in a ascending way
 void sort_grades(float*** grades, int num_student, int num_subject, int* num_grades);
 // it display the grades of students being registered in the memory
 void dispay_grades(float*** grades, float* average,float highest, float lowest, int num_student, int num_subject, int* num_grades);

int main()
{
     int num_student;
     int num_subject;
     int* num_grades = new int[num_subject];
     do{
         cout << "enter number of student" << endl;
       cin >> num_student;
           cout << "enter the number of subjects: " <<endl;
           cin >> num_subject;
           for(int i = 0; i < num_subject; i++)
           {
                  cout << "number of grades for subject " << i + 1 << " is: "<<endl;
                  cin >> num_grades[i];
           }
        if(num_student <= 0|| num_subject <= 0)
        {
               cout << "invalid input" << endl;
           }

     } while(num_student <= 0 ||  num_subject <= 0);

    float*** grades = grades_input(num_student, num_subject, num_grades);
    float* average = average_grades(grades, num_student, num_subject, num_grades);
    float highest = find_highest(average, num_student);
    float lowest = find_lowest(average, num_student);
    sort_grades(grades, num_student, num_subject, num_grades);
    dispay_grades(grades, average,highest, lowest, num_student, num_subject, num_grades);


}
float*** grades_input(int num_student, int num_subject, int* num_grades)
 {
     //store the number of student
     float*** students = new float**[num_student];
     for(int i = 0; i < num_student; i++)
    {
        cout << "grades for student " << i + 1 << endl;
        //store the subjects of each student
    students[i] = new float*[num_subject];
        for(int j = 0; j < num_subject ; j++)
        {
        //store the grades for each subject
        students[i][j] = new float[num_grades[j]];
    for(int k = 0; k < num_grades[j]; k++)
    {
        cout << "enter grades for subject  " << j + 1 << endl;
       cin >> students[i][j][k];

    }
        }
    }
     return students;
 }
float* average_grades(float*** grades, int num_student, int num_subject, int* num_grades)
 {
     //points on the adress that stores average for each student
     float* average = new float[num_student];
     for(int i = 0;i < num_student; i++)
    {
        //final_grade for storing final grades for subjects
          float final_grade = 0.0;
        for(int j = 0; j < num_subject ; j++)
        {
            //store the sum of grades per subject
            float sum_grades = 0.0;
    for(int k = 0; k < num_grades[j]; k++)
    {
       sum_grades += grades[i][j][k];
    }

     final_grade += sum_grades/ num_grades[j];
        }
        average[i] = final_grade/num_subject;
    }
 return average;
 }

float find_highest(float* averages, int num_student)
{
    //for storing the highest average
   float highest_average = averages[0];

    for(int i = 0; i < num_student; i++)
    {
                if(averages[i] > highest_average)
                {
                    highest_average = averages[i];
                }
    }

    return highest_average;

}
float find_lowest(float* averages, int num_student)
{
    //store lowest average
    float lowest_average = averages[0];

    for(int i = 0; i < num_student; i++)
    {
                if(averages[i] < lowest_average)
                {
                    lowest_average = averages[i];
                }
    }

   return lowest_average;

}

 void sort_grades(float*** grades, int num_student, int num_subject, int* num_grades)
 {
     //temporary variable to store the grades
     float temp = 0;
     for(int i = 0; i < num_student; i++)
     {
         for(int j = 0; j < num_subject; j++)
         {
            for(int k = 0; k < num_grades[j] - 1; k++)
             {
                 for (int l = 0; l < num_grades[j] - k - 1; l++)
                    {
                    if (grades[i][j][l] > grades[i][j][l + 1])
                    {
                        temp = grades[i][j][l];
                        grades[i][j][l] = grades[i][j][l + 1];
                        grades[i][j][l + 1] = temp;
                    }
             }
         }

     }
     }
}
void dispay_grades(float*** grades, float* average,float highest, float lowest, int num_student, int num_subject, int* num_grades)
{
     for(int i = 0; i < num_student; i++)
     {
         cout << "the grades of student " << i + 1;
         for(int j = 0; j < num_subject; j++)
         {
             cout << endl;
              cout << "subject: " << j + 1<< endl;
              cout << "grades: ";
             for(int k = 0; k < num_grades[j]; k++)
             {
                 cout << grades[i][j][k];
                 cout << "  ";
             }

         }
         cout << endl;
         cout << "the student " << i + 1 << " got a final grade of " << average[i] << endl;
     }
     cout << "the highest average is: " << highest <<endl;
     cout << "the lowest average is: " << lowest <<endl;

 }
