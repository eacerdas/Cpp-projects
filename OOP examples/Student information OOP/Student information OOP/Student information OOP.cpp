#include <iostream>
#include <string>
#include <vector>
#include "records.h"

using namespace std;



/////////////////////// CLASS STUDENT ///////////////////////

class Student {
public:
	///////////////////////default constructor 
	Student() {
		id = 0;
		name = "";
		gpa = 0;
	}

	///////////////////////constructor
	Student(int id_i, string name_i, float gpa_i) {
		id = id_i;
		name = name_i;
		gpa = gpa_i;
	}

	/////////////////////// GETTERS	
	int get_id() {
		return id;
	}

	string get_name() {
		return name;
	}

	float get_gpa() {
		return gpa;
	}

	/////////////////////// SETTERS 
	void set_id(int id_) {
		id = id_;
	}

	void set_name(string name_) {
		name = name_;
	}

	/////////////////////// METHODS 



	/////////////////////// ATTRIBUTES 
private:
	int id;
	string name;
	float gpa;
};


/////////////////////// CLASS COURSE ///////////////////////

class Course {
public:
	/////////////////////// default constructor 
	Course() {
		id = 0;
		name = "";
		credits = 0;
	}

	/////////////////////// constructor
	Course(int id_i, string name_i, int credits_i) {
		id = id_i;
		name = name_i;
		credits = credits_i;
	}

	/////////////////////// GETTERS 	
	int get_id() {
		return id;
	}

	string get_name() {
		return name;
	}

	int get_credits() {
		return credits;
	}

	/////////////////////// SETTERS 
	void set_id() {
		cout << "Please enter the new id for the course" << name << ": " << endl;
		cin >> id;
	}

	void set_name() {
		cout << "Please enter the new name for this course: " << endl;
		cin >> name;
	}

	void set_credits() {
		cout << "Please enter the new amount of credits for the course" << name << ": " << endl;
		cin >> credits;
	}

	/////////////////////// METHODS 

private:
	int id;
	string name;
	int credits;
};


/////////////////////// CLASS GRADE ///////////////////////


class Grade {
public:
	/////////////////////// default constructor 
	Grade() {
		student_id = 0;
		course_id = 0;
		grade = {};

	}

	/////////////////////// constructor
	Grade(int student_id_i, int course_id_i, char grade_i) {
		student_id = student_id_i;
		course_id = course_id_i;
		grade = grade_i;
	}

	/////////////////////// GETTERS 	

	float get_grade() {
		return grade;
	}

	/////////////////////// SETTERS 

	void set_grade() {
		cout << "Please enter the new grade for the student " << student_id << " in the course " << course_id << ": " << endl;
		cin >> grade;
	}

	/////////////////////// METHODS 

private:
	int student_id;
	int course_id;
	char grade;
};


//// FUNCTIONS

void calc_gpa(vector <float> grades, vector <int> credits){
	float totalGrades = 0.0f;
	int totalCredits = 0;
	float GPA;

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


/*void set_grades(vector <float>* grades, vector <int>* credits) {
	char grade_in;
	int credits_in;
	float gradePoints;
	cout << "Please enter the grades for the following courses: ";

	for (int i = 0; i < grades->size(); i++) {
		bool validGrade = false;

		int courseNumber = courses[0].get_id();

		cout << "Grade for the course number " << courseNumber <<  ": ";

		while (validGrade == false) {

			validGrade = true;
			cout << "Please enter the letter (a, b, c, d, f) corresponding to the grade for " << courses[0].get_name() << ": " << endl;
			cin >> grade_in;

			switch (grade_in) {
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
			cout << "Please enter the credits number for the course number " << i + 1 << ": " << endl;
			cin >> credits_in;
		}
		grades->push_back(gradePoints);
		credits->push_back(credits_in);
	}
}*/


int student_selector(vector <Student> students_list) {
	int userSelection;

	cout << "These are the students already created: \n";
	for (int i = 0; i < students_list.size(); i++) {
		cout << i+1 <<". " << students_list[i].get_name() << "\n";
	}

	cout << "\nWhich student do you want? or enter any other thing to exit: ";
	cin >> userSelection;
	cout << "\nThe student selected is: " << students_list[userSelection - 1].get_name() << "\n \n";

	return userSelection;
}

int student_options_selector(vector <Student> students_list, int studentChosen_) {
	int userSelection;
	string optionSelected;
	cout << "These are " << students_list[studentChosen_ - 1].get_name() << "'s options: \n";
	cout << "1. Add courses for the student \n";
	cout << "2. Add grades for the student \n";
	cout << "3. Edit the name of the student \n";
	cout << "4. Get the last GPA calculated for the student \n";
	
	cout << "\nWhich option do you want?: ";
	
	cin >> userSelection;

	switch (userSelection) {
	case 1: optionSelected = "Add courses for "; break;
	case 2: optionSelected = "Add grades for "; break;
	case 3: optionSelected = "Edit the name of "; break;
	case 4: optionSelected = "Get the GPA of "; break;
	}

	cout << "\nThe option selected is: " << optionSelected << students_list[studentChosen_ - 1].get_name() << "\n \n";
	return userSelection;
}

/*void add_new_course(vector <Student> students_list, vector <Course> courses_list, vector <Grade> grades_list, int studentChosen_) {
	int userSelection;

	cout << "You are about to add a new course for " << students_list[studentChosen_ - 1].get_name() << "\n ";
	cout << "Please type the id of the course from the following list: \n \n";
	cout << "1. Algebra \n";
	cout << "2. Physics \n";
	cout << "3. English \n";
	cout << "4. Economics \n";

	cin >> userSelection;

	int whereToAppend = grades_list.size();

	switch (userSelection) {
	case 1: grades_list[whereToAppend].push_back(1); break;
	case 2: grades_list[whereToAppend].push_back(2); break;
	case 3: grades_list[whereToAppend].push_back(3); break;
	case 4: grades_list[whereToAppend].push_back(4); break;
	}
}*/

void change_students_name(vector <Student> &students_list, int studentChosen_) {
	string newName;
	//cout << "You are about to change the name of " << students_list[studentChosen_ - 1].get_name() << "\n";
	cout << "Please type the new name for the student: ";
	cin >> newName;

	students_list[studentChosen_ - 1].set_name(newName);

	cout << "The new name of the student is: " << students_list[studentChosen_ - 1].get_name() << "\n \n";

}


///////////// GLOBAL VARS /////////////
int studentChosen;
int optionChosen;
int exitFlag = 0;

///////////// VECTORS OF OBJECTS /////////////

vector <Student> students = {Student(1,"Edward", 0), Student(2, "Rolando", 0)}; // Student (id, name, gpa)
vector <Course> courses = {Course(0, "Default", 0), Course(1, "Algebra", 5), Course(2, "Physics", 4), Course(3, "English", 3), Course(4, "Economics", 4)}; // Course (course_id, course_name, credits)
vector <Grade> grades = {}; // Grade (student_id, course_id, grade)


int amountGrades = 0;
//vector<float> grades{};
//vector<int> credits{};

int main() { 

	cout << "Main program, Hello! \n \n";

	while (exitFlag == 0) {

		studentChosen = student_selector(students);
		optionChosen = student_options_selector(students, studentChosen);

		switch (optionChosen) { // 1. add courses 2. add grades, 3. change name, 4. Get gpa
		case 1: break; //add_new_course(students, courses, &grades, studentChosen); 
		case 2: break;
		case 3: change_students_name(students, studentChosen); break;
		case 4: break;
		}


		cout << "Do you want to finish the execution or to continue? : \n";
		cout << "1. Exit \n";
		cout << "2. Continue \n";

		cin >> exitFlag;

		if(exitFlag == 1){
			exitFlag = 1;
		}
		else if (exitFlag == 2){
			exitFlag = 0;
		}
		system("CLS");
	}



	/*
	while (exitFlag == false) {
		cout << "Which student do you want? or enter any other thing to exit: " << endl << "1. " << edward.get_name() << endl << "2. " << rolando.get_name() << endl;
		cin >> studentChosen;
		switch (studentChosen) {
		case 1: { // Edward
			cout << "This is " << edward.get_name() << "'s information" << endl << endl;
			cout << "What do you want to do? " << endl;
			cout << "1. Add the grades for the student " << endl << "2. Edit the name of the student " << endl << "3. Get the last GPA calculated for the student" << endl;
			cin >> optionChosen;
			switch (optionChosen) {
			case 1: {
				set_grades(&grades, &credits);
				//calc_gpa(grades, credits);
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
			cout << "This is " << rolando.get_name() << "'s information" << endl << endl;
			cout << "What do you want to do? " << endl;
			cout << "1. Add the grades for the student " << endl << "2. Edit the name of the student " << endl << "3. Get the last GPA calculated for the student" << endl;
			cin >> optionChosen;
			switch (optionChosen) {
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
		default: {
			exitFlag = true;
			break;
		}
		}
	}*/

	return 0;
}
