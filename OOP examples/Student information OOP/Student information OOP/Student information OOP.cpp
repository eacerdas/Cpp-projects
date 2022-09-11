#include <iostream>
#include <string>
#include <vector>
#include "records.h"

using namespace std;

///////////// FUNCTIONS /////////////

int student_selector(vector <Student> students_list) {
	int userSelection;

	cout << "These are the students already created: \n";
	for (int i = 0; i < students_list.size(); i++) {
		cout << i+1 <<". " << students_list[i].get_name() << "\n";
	}

	cout << "\nWhich student do you want?: ";
	cin >> userSelection;

	system("CLS");

	cout << "\nThe student selected is: " << students_list[userSelection - 1].get_name() << "\n \n";

	return userSelection;
}

void change_students_name(vector <Student> &students_list, int studentChosen_) {
	string newName;
	//cout << "You are about to change the name of " << students_list[studentChosen_ - 1].get_name() << "\n";
	cout << "Please type the new name for the student: ";
	cin >> newName;

	students_list[studentChosen_ - 1].set_name(newName);

	cout << "The new name of the student is: " << students_list[studentChosen_ - 1].get_name() << "\n \n";
}

void add_new_course(vector <Student> students_list, vector <Grade> &grades_list, int studentChosen_) {

	int studentId = students_list[studentChosen_ - 1].get_id();
	int courseId;
	char grade = 'Z';

	cout << "You are about to add a new course for " << students_list[studentChosen_ - 1].get_name() << ": \n";
	cout << "1. Algebra \n";
	cout << "2. Physics \n";
	cout << "3. English \n";
	cout << "4. Economics \n";

	cout << "Please type the number of the course from the list above: \n";
	cin >> courseId;
	system("CLS");

	Grade new_grade(studentId, courseId, grade);

	grades_list.push_back(new_grade);

	cout << "The new course for " << students_list[studentChosen_ - 1].get_name() << " is: ";

	switch (grades_list[0].get_courseId()) {
	case 1: cout << "Algebra. \n \n"; break;
	case 2: cout << "Physics. \n \n"; break;
	case 3: cout << "English. \n \n"; break;
	case 4: cout << "Economics. \n \n"; break;
	}
}

void get_enrolled_courses(vector <Grade> &grades_list, int studentChosen_) {	
	int counter = 0;
	int flag = 0;
	for (int i = 0; i < grades_list.size(); i++) {
		if (studentChosen_ == grades_list[i].get_studentId()) {
			if (flag == 0) {
				flag = 1; cout << "The student is currently enrolled in " << counter << " courses: \n";
			}

			counter++;
			cout << counter << ". ";

			switch (grades_list[i].get_courseId()) {
			case 1: cout << "Algebra. \n \n"; break;
			case 2: cout << "Physics. \n \n"; break;
			case 3: cout << "English. \n \n"; break;
			case 4: cout << "Economics. \n \n"; break;
			}
		}
	}

	if (counter == 0){
		cout << "There are no courses in which this student is currently enrolled. \n \n";
	}

};

void student_options_selector(vector <Grade> &grades_list, vector <Student> &students_list, int studentChosen_) {
	int userSelection;
	string optionSelected;
	cout << "These are " << students_list[studentChosen_ - 1].get_name() << "'s options: \n";
	cout << "1. Add courses for the student \n";
	cout << "2. Check for the courses in which the student is enrolled \n";
	cout << "3. Edit the name of the student \n";
	//cout << "4. Get the last GPA calculated for the student \n";
	
	cout << "\nWhich option do you want?: ";
	
	cin >> userSelection;

	switch (userSelection) {
	case 1: optionSelected = "Add courses for "; break;
	case 2: optionSelected = "Check enrolled courses for "; break;
	case 3: optionSelected = "Edit the name of "; break;
	case 4: optionSelected = "Get the GPA of "; break;
	}

	system("CLS");

	cout << "The option selected is: " << optionSelected << students_list[studentChosen_ - 1].get_name() << "\n \n";

	switch (userSelection) { // 1. add courses 2. add grades, 3. change name, 4. Get gpa
	case 1: add_new_course(students_list, grades_list, studentChosen_); break; 
	case 2: get_enrolled_courses(grades_list, studentChosen_); break;
	case 3: change_students_name(students_list, studentChosen_); break;
	case 4: break;
	}

	//return userSelection;
}

bool ask_to_exit() {
	int userInput;
	bool want_to_exit = false;
	cout << "Do you want to finish the execution or to continue? : \n";
	cout << "1. Continue \n";
	cout << "2. Exit \n";

	cin >> userInput;

	if (userInput == 1) {
		want_to_exit = false; //do not finish the exec
	}
	else if (userInput == 2) {
		want_to_exit = true; //finish the exec
	}

	system("CLS");

	return want_to_exit;
};

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

/*void calc_gpa(vector <float> grades, vector <int> credits) {
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
}*/

///////////// GLOBAL VARS /////////////
int studentChosen;
int optionChosen;
bool exitFlag = 0;

///////////// VECTORS OF OBJECTS /////////////
vector <Student> students = {Student(1,"Edward"), Student(2, "Rolando")}; // Student (id, name)
vector <Course> courses = {Course(0, "Default", 0), Course(1, "Algebra", 5), Course(2, "Physics", 4), Course(3, "English", 3), Course(4, "Economics", 4)}; // Course (course_id, course_name, credits)
vector <Grade> grades = {}; // Grade (student_id, course_id, grade)

int main() { 

	cout << "Hello! Welcome to the main program. \n \n";

	while (!exitFlag) {
		studentChosen = student_selector(students);
		student_options_selector(grades, students, studentChosen);
		exitFlag = ask_to_exit();
	}

	return 0;
}
