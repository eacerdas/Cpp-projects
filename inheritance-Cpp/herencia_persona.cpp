//Herencia de clase Persona
//Edward Cerdas Rodríguez - B71956

#include <iostream>
using namespace std;

//DEFINICION DE CLASES

//Se define la clase Persona
class Persona{
	private: 
		string nombre;
		int edad;
	public: 
		Persona(string,int);
};

//Se define la clase Estudiante que hereda de la clase Persona
class Estudiante : public Persona{
	private:
		string num_carne;
		float nota;
	public:
		Estudiante(string,int,string,float);
};

//Se define la clase EstudianteUniversitario que hereda de la clase Estudiante
class EstudianteUniversitario : public Estudiante{
	private:
		string carrera;
	public:
		EstudianteUniversitario(string,int,string,float,string);
};

//CONSTRUCTORES

// Se define el constructor de Persona que es la Clase Base
Persona::Persona(string _nombre, int _edad) {
	nombre = _nombre;
	edad = _edad;
}

//Se define el Constructor de la clase Estudiante
Estudiante::Estudiante(string _nombre, int _edad, string _num_carne, float _nota) : Persona(_nombre, _edad) {
	num_carne = _num_carne;
	nota = _nota;
}
//Se define el Constructor de la clase EstudianteUniversitario
EstudianteUniversitario::EstudianteUniversitario(string _nombre, int _edad, string _num_carne, float _nota, string _carrera) : Estudiante(_nombre, _edad, _num_carne, _nota) {
	carrera = _carrera;
}
