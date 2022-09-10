#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {

public:	
	//default constructor 
	Student (){		
		id = 0;
		name = "";
		gpa = 0;
	}
	
	//constructor
	Student (int id_i, string name_i, float gpa_i){
		id = id_i;
		name = name_i;
		gpa = gpa_i;
	}
	
	////////////// GETTERS /////////////	
	int get_id(){
		return id;
	}
	
	string get_name(){
		return name;
	}
			
	float get_gpa(){	
		return gpa; 
	}
	
	/////////////// SETTERS //////////////
	void set_id(){
		cout << "Please enter the new id for " << name << ": " << endl;
		cin >> id;
	}
	
	void set_name(){
		cout << "Please enter the new name for this student: " << endl;
		cin >> name;
	}
	
	
	////////////// METHODS /////////////
	
	
	
	/*void calc_gpa(vector <float> grades, vector <int> credits){
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
	}*/

private:
	int id;
	string name;
	float gpa;
};

class Course {
public:	
	//default constructor 
	Course (){		
		id = 0;
		name = "";
		credits = 0;
	}
	
	//constructor
	Course (int id_i, string name_i, int credits_i){
		id = id_i;
		name = name_i;
		credits = credits_i;
	}
	
	////////////// GETTERS /////////////	
	int get_id(){
		return id;
	}
	
	string get_name(){
		return name;
	}
			
	float get_credits(){	
		return credits; 
	}
	
	/////////////// SETTERS //////////////
	void set_id(){
		cout << "Please enter the new id for the course" << name << ": " << endl;
		cin >> id;
	}
	
	void set_name(){
		cout << "Please enter the new name for this course: " << endl;
		cin >> name;
	}
	
	void set_credits(){
		cout << "Please enter the new amount of credits for the course" << name << ": " << endl;
		cin >> credits;
	}
	
	////////////// METHODS /////////////
	
private: 
	int id;
	string name;
	int credits;	
};

class Grade {
	public:	
	//default constructor 
	Grade (){		
		student_id = 0;
		course_id = 0;
		grade = {};

	}
	
	//constructor
	Grade (int student_id_i, int course_id_i, char grade_i){
		student_id = student_id_i;
		course_id = course_id_i;
		grade = grade_i;
	}
	
	////////////// GETTERS /////////////	
			
	float get_grade(){	
		return grade; 
	}
	
	/////////////// SETTERS //////////////
	
	void set_grade(){
		cout << "Please enter the new grade for the student " << student_id << " in the course " << course_id << ": " << endl;
		cin >> grade;
	}
	
	////////////// METHODS /////////////
	
private: 
	int student_id;
	int course_id;
	char grade;
};


//// FUNCTIONS

void set_grades(vector <float> *grades, vector <int> *credits){
		char grade_in;
		int credits_in;
		float gradePoints;
		cout << "Please enter the grades for the following courses: ";
		
		for (int i=0; i < grades->size(); i++){
			bool validGrade = false;
			
			courseNumber = course.get_id();
			
			cout << "Grade for " <<  <<  ": ";
			
			while (validGrade == false){
	                              
				validGrade = true;
				cout << "Please enter the letter (a, b, c, d, f) corresponding to the grade for " << courses[0].get_name() << ": " << endl;
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


///////////// GLOBAL VARS ///////////

// VECTORS OF OBJECTS

vector <Student> students = {Student(1,"Edward", 0), Student(2, "Rolando", 0)};
vector <Course> courses = {Course(1, "Algebra", 5), Course(2, "Physics", 4), Course(3, "English", 3), Course(4, "Economics", 4)};
vector <Grade> grades = {Grade(1, 1, 'Z'), Grade(1, 2, 'Z'), Grade(2, 3, 'Z'), Grade(1, 4, 'Z')};


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
