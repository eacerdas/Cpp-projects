#include <iostream>
#include <string>
#include <vector>
#include "records.h"

using namespace std;

///////////// FUNCTIONS /////////////
int student_selector(StudentRecords SR_);
void update_students_name(StudentRecords& SR_, int studentChosenId_);
void enroll_student_to_course(StudentRecords& SR_, int studentChosenId_);
void get_students_enrolled_courses(StudentRecords SR_, int studentChosenId_);
void add_new_student(StudentRecords& SR);
void student_options_selector(StudentRecords& SR_, int studentChosenId_);

void initialize();
bool ask_to_exit();
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
int studentChosenId;
int optionChosen;
bool exitFlag = 0;

StudentRecords SR;

///////////// VECTORS OF OBJECTS ///////////// this lines just for reference, not longer needed
//vector <Student> students = {Student(1,"Edward"), Student(2, "Rolando")}; // Student (id, name)
//vector <Course> courses = {Course(0, "Default", 0), Course(1, "Algebra", 5), Course(2, "Physics", 4), Course(3, "English", 3), Course(4, "Economics", 4)}; // Course (course_id, course_name, credits)
//vector <Grade> grades = {}; // Grade (student_id, course_id, grade)

int main() {

	initialize();

	cout << "Hello! Welcome to the main program. \n \n";

	while (!exitFlag) {
		studentChosenId = student_selector(SR);
		student_options_selector(SR, studentChosenId);
		exitFlag = ask_to_exit();
	}
	return 0;
}


int student_selector(StudentRecords SR_) {
	int userSelection;

	cout << "These are the students already added to the student records system: \n";
	for (int i = 0; i < SR_.get_students_list_size(); i++) {
		cout << i + 1 << ". " << SR_.get_student_name(i) << "\n";
	}

	cout << "\nWhich student do you want?: ";
	cin >> userSelection;

	system("CLS");

	cout << "\nThe student selected is: " << SR_.get_student_name(userSelection - 1) << "\n \n";

	return userSelection;
} 

void update_students_name(StudentRecords& SR_, int studentChosenId_) {
	string newName;
	cout << "Please type the new name for the student: ";
	cin >> newName;

	SR_.set_student_name(newName, studentChosenId_);
	cout << "The new name of the student is: " << SR_.get_student_name(studentChosenId_ - 1) << "\n \n";
} 

void enroll_student_to_course(StudentRecords& SR_, int studentChosenId_) {

	int studentId = studentChosenId_;
	int courseId = 0;
	char grade = '0'; // Default grade when the student just got enrolled

	cout << "You are about to add a new course for " << SR_.get_student_name(studentChosenId_ - 1) << ": \n";
	cout << "1. Algebra \n";
	cout << "2. Physics \n";
	cout << "3. English \n";
	cout << "4. Economics \n";

	cout << "Please type the number of the course from the list above: \n";
	cin >> courseId;
	system("CLS");

	SR_.add_grade(studentChosenId, courseId, grade);

	cout << "The new course for " << SR_.get_student_name(studentChosenId_ - 1) << " is: ";

	switch (courseId) {
	case 1: cout << "Algebra. \n \n"; break;
	case 2: cout << "Physics. \n \n"; break;
	case 3: cout << "English. \n \n"; break;
	case 4: cout << "Economics. \n \n"; break;
	}
}

void get_students_enrolled_courses(StudentRecords SR_, int studentChosenId_) {
	int counter = 0;
	int flag = 0;
	for (int i = 0; i < SR_.get_grades_list_size(); i++) {
		if (studentChosenId_ == SR_.Grades_get_student_id(i)) {
			counter++;
			if (flag == 0) { // Prints this only the first time
				flag = 1;
				cout << SR_.get_student_name(studentChosenId_ - 1) << " is currently enrolled in: \n\n";
				cout << " -------------------------  \n";
				cout << "| Course ID | Course name | \n";
				cout << " -------------------------  \n";
				//cout << "|     1     |   Algebra   | \n";
				//cout << "|     1     |   Physics   | \n";
				//cout << "|     1     |   English   | \n";
				//cout << "|     1     |  Economics  | \n";
			}

			//cout << counter << ". ";

			switch (SR_.Grades_get_course_id(i)) {
			case 1: cout << "|     1     |   Algebra   | \n"; cout << " -------------------------  \n"; break;
			case 2: cout << "|     2     |   Physics   | \n"; cout << " -------------------------  \n"; break;
			case 3: cout << "|     3     |   English   | \n"; cout << " -------------------------  \n"; break;
			case 4: cout << "|     4     |  Economics  | \n"; cout << " -------------------------  \n"; break;
			}
		}
	}

	if (counter == 0) {
		cout << "There are no courses in which this student is currently enrolled. \n";
	}

}

void add_new_student(StudentRecords& SR_) {
	int studentId = 0;
	string studentName;

	for (int i = 0; i < SR_.get_students_list_size(); i++) {
		studentId = i + 1;
	}

	cout << "Enter the name of the new student: ";
	cin >> studentName;

	cout << "\n\nPlease note that the student's ID is going to be consecutive to the last student registered. ";

	SR.add_student(studentId, studentName);
}

void student_options_selector(StudentRecords& SR_, int studentChosenId_) {
	int userSelection;
	string optionSelected;
	cout << "These are " << SR_.get_student_name(studentChosenId_ - 1) << "'s options: \n";
	cout << "1. Enroll the student in a course \n";
	cout << "2. Check for the courses in which the student is enrolled \n";
	cout << "3. Update the name of the student \n";
	cout << "4. Add a new student \n";

	cout << "\nWhich option do you want?: ";

	cin >> userSelection;

	system("CLS");

	cout << "The option selected is: ";

	switch (userSelection) {
	case 1: cout << "Enroll " << SR_.get_student_name(studentChosenId_ - 1) << " in a course \n \n"; break;
	case 2: cout << "Check for the courses in which " << SR_.get_student_name(studentChosenId_ - 1) << " is enrolled \n \n"; break;
	case 3: cout << "Edit the name of " << SR_.get_student_name(studentChosenId_ - 1) << "\n \n"; break;
	case 4: cout << "Add a new student \n \n"; break;
	}

	switch (userSelection) { // 1. add courses 2. add grades, 3. change name, 4. Get gpa
	case 1: enroll_student_to_course(SR_, studentChosenId_); break;
	case 2: get_students_enrolled_courses(SR_, studentChosenId_); break;
	case 3: update_students_name(SR_, studentChosenId_); break;
	case 4: add_new_student(SR); break;
	}

	//return userSelection;
}

void initialize() {
	SR.add_student(1, "Edward");
	SR.add_student(2, "Rolando");
	SR.add_course(1, "Algebra", 5);
	SR.add_course(2, "Physics", 4);
	SR.add_course(3, "English", 3);
	SR.add_course(4, "Economics", 4);
}

bool ask_to_exit() {
	int userInput;
	bool want_to_exit = false;
	cout << "\nDo you want to finish the execution or to continue? : \n";
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
}