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
		Grade(int student_id_i, int course_id_i, char grade_i);

		int get_studentId();
		int get_courseId();
		char get_grade();

		void set_grade(char grade_);	
	};

	/////////////////////// STUDENT RECORDS CLASS ///////////////////////
	/*class StudentRecords {
	private:
		std::vector <Student> students;
		std::vector <Course> courses;
		std::vector <Grade> grades;

		float get_numeric_grade();

	public:
		StudentRecords();

		void add_student(int id);
		void add


	};*/



#endif // !RECORDS_H
