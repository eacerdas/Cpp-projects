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

	int Grade::get_studentId() {
		return studentId;
	}

	int Grade::get_courseId() {
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
		float numericGrade = 0.0f;
		switch (grade_in) {
		case 'a': {
			numericGrade = 4.0f; break;
		}
		case 'b': {
			numericGrade = 3.0f; break;
		}
		case 'c': {
			numericGrade = 2.0f; break;
		}
		case 'd': {
			numericGrade = 1.0f; break;
		}
		case 'f': {
			numericGrade = 0.0f; break;
		}
		}
		return numericGrade;
	}

	void StudentRecords::add_student(int id_, std::string name_) {
		students.push_back(Student(id_, name_));
	}
	void StudentRecords::add_course(int id_, std::string name_, int credits_) {
		courses.push_back(Course(id_, name_, credits_));
	}
	void StudentRecords::add_grade(int studentId_, int courseId_, char gradeId_) {
		grades.push_back(Grade(studentId_, courseId_, gradeId_));
	}

	//GETTERS
	int StudentRecords::get_students_list_size() {
		int size = students.size();
		return size;
	}

	std::string StudentRecords::get_student_name(int studentChosen_) {
		return students[studentChosen_].get_name();
	}


	//SETTERS
	void StudentRecords::set_student_name(std::string name_, int studentChosen_) {
		students[studentChosen_-1].set_name(name_);
	}

	//METHODS

	/*float StudentRecords::get_gpa(int studentChosen_) {
		//for later
	}*/