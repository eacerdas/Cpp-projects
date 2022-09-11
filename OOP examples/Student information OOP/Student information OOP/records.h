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
		float gpa;
	
	public:
		Student();
		Student(int id_i, std::string name_i, float gpa_i);

		int get_id();
		std::string get_name();
		float get_gpa();

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
	public:
		Grade();
		Grade(int student_id_i, int course_id_i, char grade_i);

		float get_grade();

		void set_grade(float grade_);

	private:
		int student_id;
		int course_id;
		char grade;
	};


#endif // !RECORDS_H
