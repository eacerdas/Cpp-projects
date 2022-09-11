#include <iostream>
#include <string>
#include <vector>
#include "records.h"

/////////////////////// CLASS STUDENT ///////////////////////

	Student::Student() {
		id = 0;
		name = "";
		gpa = 0;
	}

	Student::Student(int id_i, std::string name_i, float gpa_i) {
		id = id_i;
		name = name_i;
		gpa = gpa_i;
	}

	int Student::get_id() {
		return id;
	}

	std::string Student::get_name() {
		return name;
	}

	float Student::get_gpa() {
		return gpa;
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

	Grade::Grade(int student_id_i, int course_id_i, char grade_i) {
		studentId = student_id_i;
		courseId = course_id_i;
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

	void Grade::set_grade(float grade_) {
		grade = grade_;
	}