#ifndef RECORDS_H
#define RECORDS_H

#include <iostream>
#include <string>
#include <vector>


/////////////////////// CLASS STUDENT ///////////////////////
class Student {

private:
	int id;
	std::string name;

public:
	Student();
	Student(int id_i, std::string name_i);

	int get_id();
	std::string get_name();

	void set_id(int id_);
	void set_name(std::string name_);
};


/////////////////////// CLASS COURSE ///////////////////////
class Course {
private:
	int id;
	std::string name;
	int credits;

public:
	Course();
	Course(int id_i, std::string name_i, int credits_i);

	int get_id();
	std::string get_name();
	int get_credits();

	void set_id(int id_);
	void set_name(std::string name_);
	void set_credits(int credits_);
};


/////////////////////// CLASS GRADE ///////////////////////
class Grade {
private:
	int studentId;
	int courseId;
	char grade;

public:
	Grade();
	Grade(int studentId_i, int courseId_i, char grade_i);

	int get_student_id();
	int get_course_id();
	char get_grade();

	void set_grade(char grade_);
};

/////////////////////// STUDENT RECORDS CLASS ///////////////////////
class StudentRecords {
private:
	std::vector <Student> students;
	std::vector <Course> courses;
	std::vector <Grade> grades;

	float get_numeric_grade(char grade_in);

public:
	void add_student(int id_, std::string name_);
	void add_course(int id_, std::string name_, int credits_);
	void add_grade(int studentId_, int courseId_, char grade_);

	//GETTERS
	int get_students_list_size();
	int get_grades_list_size();
	std::string get_student_name(int studentChosenId_);
	int Student_get_student_id(int studentChosenId_);
	int Grades_get_student_id(int studentChosenId_);
	int Grades_get_course_id(int courseChosen_);

	//SETTERS 
	void set_student_name(std::string name_, int studentChosenId_);

	//METHODS
	void get_gpa(int studentChosenId_);
};

#endif // !RECORDS_H
