#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {

public:	
	//default constructor 
	Student (){		
		name = "";
		grades = {};
		GPA = 0;
		credits = {};
	}
	
	//constructor
	Student (string name_i, vector <float> grades_i, float GPA_i, vector <int> credits_i){
		name = name_i;
		grades = grades_i;
		GPA = GPA_i;
		credits = credits_i;
	}
	
	////////////// GETTERS /////////////	
	string get_name(){
		return name;
	}
	
	vector <float> get_grades(){
		return grades;
	}
		
	float get_gpa(){	
		return GPA; 
	}
	
	vector <int> get_credits(){
		return credits;
	}
	
	/////////////// SETTERS //////////////
	void set_name(){
		cout << "Please enter the new name for this student: " << endl;
		cin >> name;
	}
	
	////////////// METHODS /////////////
	void set_grades(vector <float> *grades, vector <int> *credits){
		char grade_in;
		int credits_in;
		int amountGrades;
		float gradePoints;
		cout << "Please enter the amount of grades that you have: ";
		cin >> amountGrades;
		
		for (int i=0; i < amountGrades; i++){
			bool validGrade = false;
			while (validGrade == false){
	                              
				validGrade = true;
				cout << "Please enter the letter (A, B, C, D, F) corresponding to grade number " << i+1 << ": " << endl;
				cin >> grade_in;
		
				switch(grade_in){
					case 'a': {
						gradePoints = 4.0f; validGrade = true; break;
					}
					case 'b': {
						gradePoints = 3.0f; validGrade = true; break;
					}
					case 'c': {
						gradePoints = 2.0f; validGrade = true; break;
					}
					case 'd': {
						gradePoints = 1.0f; validGrade = true; break;
					}
					case 'f': {
						gradePoints = 0.0f; validGrade = true; break;
					}
					
					default: {
						cout << "Incorrect value for grade has been entered. " << endl << endl;
						validGrade = false; break;
					}	
				}
				cout << "Please enter the credits number for the course number " << i+1 << ": " << endl;
				cin >> credits_in;
			}
			grades->push_back(gradePoints);
			credits->push_back(credits_in);	                             
		}
	}
	
	void calc_gpa(vector <float> grades, vector <int> credits){
		float totalGrades = 0.0f;
		int totalCredits = 0.0f;
		
		for (int i=0; i < grades.size(); i++){
			totalGrades = totalGrades + (grades[i] * credits[i]);
			totalCredits = totalCredits + credits[i];
		}
		GPA = totalGrades / totalCredits; 
		
		#ifdef DEBUG 
			cout << "TotalGrades: " << totalGrades << endl;
			cout << "totalCredits: " << totalCredits << endl;
			cout << "The GPA calculated in the method is: " << GPA << endl;
		#endif
	}

private:
	string name;
	vector <float> grades;
	float GPA;
	vector <int> credits;
};

///////////// GLOBAL VARS ///////////

int amountGrades = 0;
vector<float> grades{};
vector<int> credits{};

int main () {
	
	Student edward("Edward", grades, 0, credits);
	Student rolando("Rolando", grades, 0, credits);
	
	int studentChosen;
	int optionChosen;
	bool exitFlag = false;
	
	while (exitFlag == false){
		cout << "Which student do you want? or enter any other thing to exit: " << endl << "1. " << edward.get_name() << endl << "2. " << rolando.get_name() << endl;
		cin >> studentChosen;
		switch (studentChosen){
			case 1: { // Edward
				cout << "This is " << edward.get_name() <<"'s information" << endl << endl;
				cout << "What do you want to do? " << endl;
				cout << "1. Add the grades for the student " << endl << "2. Edit the name of the student " << endl << "3. Get the last GPA calculated for the student" << endl;
				cin >> optionChosen;
				switch(optionChosen){
					case 1: {
						edward.set_grades(&grades, &credits);
						edward.calc_gpa(grades, credits);
						cout << "The student's GPA is: " << edward.get_gpa() << endl << endl;
						break;
					}
					case 2: {
						edward.set_name();
						cout << "The new name of the student is: " << edward.get_name() << endl << endl;
						break;
					}
					case 3: {
						cout << "The student's GPA is: " << edward.get_gpa() << endl << endl;
						break;
					}
				}
				break;
			}
			case 2: { // Rolando
				cout << "This is " << rolando.get_name() <<"'s information" << endl << endl;
				cout << "What do you want to do? " << endl;
				cout << "1. Add the grades for the student " << endl << "2. Edit the name of the student " << endl << "3. Get the last GPA calculated for the student" << endl;
				cin >> optionChosen;
				switch(optionChosen){
					case 1: {
						rolando.set_grades(&grades, &credits);
						cout << "The student's GPA is: " << rolando.get_gpa() << endl << endl;
						break;
					}
					case 2: {
						rolando.set_name();
						cout << "The new name of the student is: " << rolando.get_name() << endl << endl;
						break;
					}
					case 3: {
						cout << "The student's GPA is: " << rolando.get_gpa() << endl << endl;
						break;
					}
				}
				break;
			}
			default:{
				exitFlag = true;
				break;
			}	
		}
	}
	return 0;	
}
