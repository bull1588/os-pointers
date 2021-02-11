// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(Student *student, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    
    string namehold; 
   
    //first name
    cout << "Please enter the student's first name: ";
    cin >> namehold;
    
    student.f_name = new char[sizeof(namehold)];
    strcpy(student.f_name, namehold.c_str());
    
    cin.clear();
    cin.ignore(10000, '\n'); //clean cin for next entry
    
    //last name
    cout << "Please enter the student's last name: ";
    cin >> namehold;
    
    student.l_name = new char[sizeof(namehold)];
    strcpy(student.l_name, namehold.c_str());
    
    cin.clear();
    cin.ignore(10000, '\n'); //clean cin for next entry
    
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    student.grades = new double[student.n_assignments];
    cout << "\n";
    
    for(int i = 0; i < student.n_assignments; i++){
        string message = "Please enter grade for assignment ";
        message += to_string(i);
        message += ": ";
    	student.grades[i] = promptDouble(message, 0, 1000.00);
    }
    
    // Call `CalculateStudentAverage(???, ???)` 
    
    calculateStudentAverage(&student, &average);
    
    // Output `average`
    cout << "\nStudent: " << student.f_name << " " << student.l_name << " [" << to_string(student.id) << "]\n";
    cout << "  Average grade: " << average << "\n";

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    std::string hold;
    int failflag = 0;
    int result;
    
    while(1){
    	cout << message;
   	 cin >> hold;
    
    	 for(int i = 0; i < hold.length(); i++){
    		if(isdigit(hold[i]) == false){
    			failflag = 1;
    		}
   	 }
    
   	 if(failflag == 0){
    		result = stoi(hold, nullptr, 10);
    		
    		if(result > max || result < min){
    			failflag = 1;
    		}
  	 }
      
   	 if(failflag == 0){
   	 	break;
   	 } else {
    		cin.clear();
    		cin.ignore(99999999,'\n');
    		cout << "Sorry, I cannot understand your answer\n";
   	  }
   	  
   	  failflag = 0;
     }
   
    return result; 	
}
    


/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    std::string hold;
    int failflag = 0;
    double result;
    
    while(1){
    	cout << message;
   	 cin >> hold;
    
    	 for(int i = 0; i < hold.length(); i++){
    		if(isdigit(hold[i]) == false && hold[i] != '.'){
    			failflag = 1;
    		}
   	 }
    
   	 if(failflag == 0){
    		result = stod(hold, nullptr);
    		
    		if(result > max || result < min){
    			failflag = 1;
    		}
  	 }
      
   	 if(failflag == 0){
   	 	break;
   	 } else {
    		cin.clear();
    		cin.ignore(99999999,'\n');
    		cout << "Sorry, I cannot understand your answer\n";
   	  }
   	  
   	  failflag = 0;
     }
     

   
    return result;  
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(Student *student, double *avg)
{

    for(int i = 0; i < student->n_assignments; i++){
    	*avg += student->grades[i];
    }
    
    *avg = *avg / (double)student->n_assignments;
    
    int hold = trunc(*avg * 10);
    if(hold % 10 > 5){
    	hold++;
    }
    
    *avg = (double)hold / 10;
    
    // Code to calculate and store average grade
}
