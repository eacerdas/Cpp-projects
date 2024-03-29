#include <iostream>
#include <string>
#include <vector>
#include "records.h"

/////////////////////// CLASS STUDENT ///////////////////////

Student::Student() {
	id = 0;
	name = "";
}

Student::Student(int id_i, std::string name_i) {
	id = id_i;
	name = name_i;
}

int Student::get_id() {
	return id;
}

std::string Student::get_name() {
	return name;
}

void Student::set_id(int id_) {
	id = id_;
}

void Student::set_name(std::string name_) {
	name = name_;
}

/////////////////////// CLASS COURSE ///////////////////////

Course::Course() {
	id = 0;
	name = "";
	credits = 0;
}

Course::Course(int id_i, std::string name_i, int credits_i) {
	id = id_i;
	name = name_i;
	credits = credits_i;
}

int Course::get_id() {
	return id;
}

std::string Course::get_name() {
	return name;
}

int Course::get_credits() {
	return credits;
}

void Course::set_id(int id_) {
	id = id_;
}

void Course::set_name(std::string name_) {
	name = name_;
}

void Course::set_credits(int credits_) {
	credits = credits_;
}

/////////////////////// CLASS GRADE ///////////////////////

Grade::Grade() {
	studentId = 0;
	courseId = 0;
	grade = {};
}

Grade::Grade(int studentId_i, int courseId_i, char grade_i) {
	studentId = studentId_i;
	courseId = courseId_i;
	grade = grade_i;
}

int Grade::get_student_id() {
	return studentId;
}

int Grade::get_course_id() {
	return courseId;
}

char Grade::get_grade() {
	return grade;
}

void Grade::set_grade(char grade_) {
	grade = grade_;
}

/////////////////////// STUDENT RECORDS CLASS ///////////////////////

float StudentRecords::get_numeric_grade(char grade_in) {

	float gradePoints = 0.0f;

	switch (grade_in) {
	case 'A': {
		gradePoints = 4.0f; break;
	}
	case 'B': {
		gradePoints = 3.0f; break;
	}
	case 'C': {
		gradePoints = 2.0f; break;
	}
	case 'D': {
		gradePoints = 1.0f; break;
	}
	case 'F': {
		gradePoints = 0.0f; break;
	}
	}

	return gradePoints;
}

void StudentRecords::add_student(int id_, std::string name_) {
	students.push_back(Student(id_, name_));
}
void StudentRecords::add_course(int id_, std::string name_, int credits_) {
	courses.push_back(Course(id_, name_, credits_));
}
void StudentRecords::add_grade(int studentId_, int courseId_, char grade_) {
	grades.push_back(Grade(studentId_, courseId_, grade_));
}

//GETTERS
int StudentRecords::get_students_list_size() {
	int size = students.size();
	return size;
}

int StudentRecords::get_grades_list_size() {
	int size = grades.size();
	return size;
}

std::string StudentRecords::get_student_name(int studentChosenId_) {
	return students[studentChosenId_].get_name();
}

int StudentRecords::Student_get_student_id(int studentChosenId_) {
	return students[studentChosenId_].get_id();
}

int StudentRecords::Grades_get_student_id(int studentChosenId_) {
	return grades[studentChosenId_].get_student_id();
}

int StudentRecords::Grades_get_course_id(int courseChosen_) {
	return grades[courseChosen_].get_course_id();
}


//SETTERS
void StudentRecords::set_student_name(std::string name_, int studentChosenId_) {
	students[studentChosenId_ - 1].set_name(name_);
}

//METHODS
void StudentRecords::get_gpa(int studentChosenId_) {
	int totalCredits = 0;
	float totalGrades = 0.0f;
	float numericGrade = 0.0f;
	float gpa = 0.0f;
	std::cout << "The gpa for " << students[studentChosenId_ - 1].get_name() << " is: ";
	
	//adds the total amount of credits
	for (int i = 0; i < get_grades_list_size(); i++) {
		if (studentChosenId_ == grades[i].get_student_id()) {
			totalCredits = totalCredits + courses[i].get_credits();
		}
	}

	//looks for the courses in which the student is enrolled
	for (int i = 0; i < get_grades_list_size(); i++) {
		if (studentChosenId_ == grades[i].get_student_id()) {
			numericGrade = get_numeric_grade(grades[i].get_grade());
			totalGrades = totalGrades + (courses[grades[i].get_course_id() - 1].get_credits()) * numericGrade;
		}
	}

	gpa = totalGrades / totalCredits;
	std::cout << gpa << "\n";
}