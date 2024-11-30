

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

#include "trapecio.h"
#include "caso.h"
#include "simpson38.h"
#include "simpson.h"



using std::cout;
using std::endl;

void caso_1_trapecio(){
	using integracion::trapecio;
	
	string f_str="e^(x^2)";
	double a=0.0f;
	double b=1.0f;
	int n=5;
	
	//Crear instancia del trapecio
	trapecio t(f_str,a,b,n);
	
	//Imprimir tabla de datos
	t.imprimir_tabla(cout);
	
	double valor=t.calcular();
	cout<<"El valor de la integral "<<f_str<<": "<<valor<<endl;
	
	
}
	void caso_1_simpson38(){
		using integracion::simpson38;
		
		string f_str="e^(x^2)";
		double a=0.0f;
		double b=1.0f;
		int n=5;
		
		//Crear instancia del simpson38
		simpson38 simp(f_str,a,b,n);
		
		//Imprimir tabla de datos
		simp.imprimir_tabla(cout);
		
		double valor=simp.calcular();
		cout<<"El valor de la integral "<<f_str<<": "<<valor<<endl;
		
		
	}
		
		
	void caso_1_simpson(){
		using integracion::simpson;
		
		string f_str="e^(x^2)";
		double a=0.0f;
		double b=1.0f;
		int n=15;
		std::vector<double> x = {0.0, 0.111, 0.222, 0.333, 0.444, 0.556,0.667,0.778,0.889,1.00};
		std::vector<double> y = {1.000,1.012422,1.050622,1.117519,1.218391, 1.361575, 1.559623, 1.831139, 2.203668, 2.718282};
		simpson38 simp2(x,y);
		//Crear instancia del simpson
		simpson38 simp(f_str,a,b,n);
		
		//Imprimir tabla de datos
		simp.imprimir_tabla(cout);
		
		double valor=simp2.calcular();
		cout<<"El valor de la integral "<<f_str<<": "<<valor<<endl;
		
	}
	

void caso_1_error_np(){
	using integracion::simpson;
	using integracion::simpson38;
	using integracion::Simpson13;
	using integracion::trapecio;
	
	string f_str = "(sin(x))^2";
	double a = 0.0f;
	double b=M_PI/3.0f;
	int n_trapecio =1;
	//Trapecio
	trapecio t(f_str,a,b,n_trapecio);
	double i_trapecio = t.calcular();
	cout << "El valor de la integral de " << f_str <<
		" en el intervalo ["<<a<<" , "<<b<<"] es"<<std::setprecision(7)<< i_trapecio<<" utilizando trapecio"
		<<" con un error "<<t.calcular_error("2*sin(x)")<<endl;
	//Simpson13
	int n_simpson13 = 2;
	Simpson13 s13(f_str, a, b, n_simpson13);
	double i_simpson13 = s13.calcular();
	cout << "El valor de la integral de " << f_str <<
		" en el intervalo ["<<a<<" , "<<b<<"] es "<<std::setprecision(7)<<i_simpson13<<" utilizando Simpson13"<<endl;
	//Simpson38
	int n_simpson38 = 3;
	simpson38 s38(f_str, a, b, n_simpson38);
	double i_simpson38 = s38.calcular();
	cout << "El valor de la integral de " << f_str <<
		" en el intervalo ["<<a<<" , "<<b<<"] es "<<std::setprecision(7)<<i_simpson38<<" utilizando Simpson38"<<endl;
	
	cout<<"Extension del caso. "<<endl;
	n_simpson13 = 8;
	Simpson13 s13_2(f_str,a,b,n_simpson13);
	
	double i_simpson13_2=s13_2.calcular();
	cout << "El valor de la integral de " << f_str <<
		" en el intervalo ["<<a<<" , "<<b<<"] es "<<std::setprecision(7)<<i_simpson13_2<<" utilizando Simpson38"<<
		" y 8 segmentos "<<endl;
	
	
}
