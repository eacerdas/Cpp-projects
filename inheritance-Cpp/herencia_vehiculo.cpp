//Herencia de clase Vehiculo
//Edward Cerdas Rodríguez - B71956

#include <iostream>
using namespace std;

//DEFINICION DE CLASES

//Se define la clase Vehiculo
class Vehiculo{
	private: 
		string marca;
		string color;
		int año_fabricacion;
	public: 
		Vehiculo(string,string,int);
};

//Se define la clase Moto que hereda de la clase Vehiculo
class Moto : public Vehiculo{
	private:
		string tipo_ruedas;
		int cilindraje;
		int tiempos_motor;
	public:
		Moto(string,string,int,string,int,int);
};

//Se define la clase Carro que hereda de la clase Vehiculo
class Carro : public Vehiculo{
	private:
		int num_puertas;
		string tipo_combustible;
		int num_cambios;
	public:
		Carro(string,string,int,int,string,int);
};

//Se define la clase Bus que hereda de la clase Vehiculo
class Bus : public Vehiculo{
	private:
		int num_pasajeros;
		int num_pisos;
		bool wifi;
	public:
		Bus(string,string,int,int,int,bool);
};
//CONSTRUCTORES

// Se define el constructor de Vehiculo que es la Clase Base
Vehiculo::Vehiculo(string _marca, string _color, int _año) {
	marca = _marca;
	color = _color;
	año_fabricacion = _año;
}

//Se define el Constructor de la clase Moto
Moto::Moto(string _marca, string _color, int _año, string _tipo_ruedas, int _cilindraje, int _tiempos_motor) : Vehiculo(_marca, _color, _año) {
	tipo_ruedas = _tipo_ruedas;
	cilindraje = _cilindraje;
	tiempos_motor = _tiempos_motor;
}

//Se define el Constructor de la clase Carro
Carro::Carro(string _marca, string _color, int _año, int _puertas, string _combustible, int _cambios) : Vehiculo(_marca, _color, _año) {
	num_puertas = _puertas;
	tipo_combustible = _combustible;
	num_cambios = _cambios;
}

//Se define el Constructor de la clase Bus
Bus::Bus(string _marca, string _color, int _año, int _pasajeros, int _pisos, bool _wifi) : Vehiculo(_marca, _color, _año) {
	num_pasajeros = _pasajeros;
	num_pisos = _pisos;
	wifi = _wifi;
}