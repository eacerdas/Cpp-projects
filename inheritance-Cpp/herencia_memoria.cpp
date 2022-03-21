//Herencia de clase Memoria
//Edward Cerdas Rodríguez - B71956

#include <iostream>
using namespace std;

//DEFINICION DE CLASES

//Se define la clase Memoria
class Memoria{
	private: 
		int capacidad; 
		float precio;
	public: 
		Persona(int,float);
};

//Se define la clase RAM que hereda de la clase Memoria
class RAM : public Memoria{
	private:
		string tipo_ddr;
		int frecuencia;
	public:
		RAM(int,float,string,int);
};

//Se define la clase Cache que hereda de la clase Memoria
class Cache : public Memoria{
	private:
		string tipo_cache;
	public:
		Cache(int,float,string);
};


//Se define la clase MemoriaPrincipal que hereda de la clase Memoria
class MemoriaPrincipal : public Memoria{
	private:
		string tipo_conexion; //sata,PCI-E
	public:
		HDD(int,float,int);
};


//Se define la clase HDD que hereda de la clase MemoriaPrincipal
class HDD : public MemoriaPrincipal{
	private:
		int rpm;
	public:
		HDD(int,float,int,int);
};

//Se define la clase SDD que hereda de la clase MemoriaPrincipal
class SDD : public MemoriaPrincipal{
	private:
		int velocidad_escritura;
		int velocidad_lectura;
	public:
		HDD(int,float,int,int,int);
};

//CONSTRUCTORES

// Se define el constructor de Memoria que es la Clase Base
Memoria::Memoria(int _capacidad, float _precio) {
	capacidad = _capacidad;
	precio = _precio;
}

//Se define el Constructor de la clase RAM
RAM::RAM(int _capacidad, float _precio, string _tipo_ddr, int _frecuencia) : Memoria(_capacidad, _precio) {
	tipo_ddr = _tipo_ddr;
	frecuencia = _frecuencia;
}

//Se define el Constructor de la clase Cache
Cache::Cache(int _capacidad, float _precio, string _tipo_cache) : Memoria(_capacidad, _precio) {
	tipo_cache = _tipo_cache;
}

//Se define el Constructor de la clase MemoriaPrincipal
MemoriaPrincipal::MemoriaPrincipal(int _capacidad, float _precio, string _tipo_conexion) : Memoria(_capacidad, _precio) {
	tipo_conexion = _tipo_conexion;
}


//Se define el Constructor de la clase HDD
HDD::HDD(int _capacidad, float _precio, string _tipo_conexion, int _rpm) : MemoriaPrincipal(_capacidad, _precio, _tipo_conexion) {
	rpm = _rpm;
}

//Se define el Constructor de la clase SDD
SDD::SDD(int _capacidad, float _precio, string _tipo_conexion, int _velocidad_escritura, int _velocidad_lectura) : MemoriaPrincipal(_capacidad, _precio, _tipo_conexion) {
	velocidad_escritura = _velocidad_escritura;
	velocidad_lectura = _velocidad_lectura;
}