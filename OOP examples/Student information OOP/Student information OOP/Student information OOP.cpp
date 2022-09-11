#include <iostream>
#include <string>
#include <vector>
#include "records.h"

using namespace std;

///////////// FUNCTIONS /////////////
void initialize();
int student_selector(StudentRecords SR_);
void change_students_name(StudentRecords &SR_, int studentChosen_);
void enroll_to_course(vector <Student> students_list, vector <Grade>& grades_list, int studentChosen_);
void get_enrolled_courses(vector <Grade>& grades_list, int studentChosen_);
void add_new_student(StudentRecords &SR, vector <Student> students_list);
void student_options_selector(StudentRecords SR_, int studentChosen_);
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
int studentChosen;
int optionChosen;
bool exitFlag = 0;

StudentRecords SR;

///////////// VECTORS OF OBJECTS /////////////
//vector <Student> students = {Student(1,"Edward"), Student(2, "Rolando")}; // Student (id, name)
//vector <Course> courses = {Course(0, "Default", 0), Course(1, "Algebra", 5), Course(2, "Physics", 4), Course(3, "English", 3), Course(4, "Economics", 4)}; // Course (course_id, course_name, credits)
//vector <Grade> grades = {}; // Grade (student_id, course_id, grade)

int main() { 

	initialize();

	cout << "Hello! Welcome to the main program. \n \n";

	while (!exitFlag) {
		studentChosen = student_selector(SR);
		student_options_selector(SR, studentChosen);
		exitFlag = ask_to_exit();
	}

	return 0;
}

void initialize() {
	SR.add_student(1, "Edward");
	SR.add_student(2, "Rolando");
	SR.add_course(1, "Algebra", 5);
	SR.add_course(2, "Physics", 4);
	SR.add_course(3, "English", 3);
	SR.add_course(4, "Economics", 4);
}

int student_selector(StudentRecords SR_) {
	int userSelection;

	cout << "These are the students already created: \n";
	for (int i = 0; i < SR_.get_students_list_size(); i++) {
		cout << i + 1 << ". " << SR_.get_student_name(i) << "\n";
	}

	cout << "\nWhich student do you want?: ";
	cin >> userSelection;

	system("CLS");

	cout << "\nThe student selected is: " << SR_.get_student_name(userSelection - 1) << "\n \n";

	return userSelection;
} // this one is done

void change_students_name(StudentRecords &SR_, int studentChosen_)  { 
	string newName;
	cout << "Please type the new name for the student: ";
	cin >> newName;

	SR_.set_student_name(newName, studentChosen_);
	cout << "The new name of the student is: " << SR_.get_student_name(studentChosen_ - 1) << "\n \n";
} //this one is done

void enroll_to_course(vector <Student> students_list, vector <Grade>& grades_list, int studentChosen_) {

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

void get_enrolled_courses(vector <Grade>& grades_list, int studentChosen_) {
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

	if (counter == 0) {
		cout << "There are no courses in which this student is currently enrolled. \n \n";
	}

}

void add_new_student(StudentRecords& SR, vector <Student> students_list) {
	int studentId = 0;
	string studentName;

	for (int i = 0; i < students_list.size(); i++) {
		studentId = i + 1;
	}

	cout << "Enter the name of the new student: ";
	cin >> studentName;

	cout << "\n\nPlease note that the student's ID is going to be consecutive to the last student registered. ";

	SR.add_student(studentId, studentName);
} // this one is done

void student_options_selector(StudentRecords SR_, int studentChosen_) {
	int userSelection;
	string optionSelected;
	cout << "These are " << SR_.get_student_name(studentChosen_ -1) << "'s options: \n";
	cout << "1. Add courses for the student \n";
	cout << "2. Check for the courses in which the student is enrolled \n";
	cout << "3. Edit the name of the student \n";
	cout << "4. Add a new student \n";

	cout << "\nWhich option do you want?: ";

	cin >> userSelection;

	system("CLS");

	cout << "The option selected is: ";

	switch (userSelection) {
	case 1: cout << "Add courses for "			  << SR_.get_student_name(studentChosen_ - 1) << "\n \n"; break;
	case 2: cout << "Check enrolled courses for " << SR_.get_student_name(studentChosen_ - 1) << "\n \n"; break;
	case 3: cout << "Edit the name of "			  << SR_.get_student_name(studentChosen_ - 1) << "\n \n"; break;
	case 4: cout << "Add a new student \n \n"; break;
	}

	switch (userSelection) { // 1. add courses 2. add grades, 3. change name, 4. Get gpa
	case 1: break; //enroll_to_course(students_list, grades_list, studentChosen_); 
	case 2: break; //get_enrolled_courses(grades_list, studentChosen_);
	case 3: change_students_name(SR, studentChosen_); break;
	case 4: break; //add_new_student(SR, students_list);
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
}