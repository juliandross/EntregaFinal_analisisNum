
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

#include "trapecio.h"
#include "caso.h"
#include "simpson38.h"
#include "simpson.h"
#include "romberg.h"


using std::cout;
using std::endl;

void caso_simpson38(){
	using integracion::simpson38;
	
	string f_str="(e^(0.07*x))+(-(0.85*(x^7)))+(0.25*(x^5))+(2.5*((x)^2))";
	double a=0.0f;
	double b=1.41f;
	int n=15;
	
	//Crear instancia del simpson38
	simpson38 simp(f_str,a,b,n);
	
	//Imprimir tabla de datos
	simp.imprimir_tabla(cout);
	
	double valor=simp.calcular();
	
	double error=simp.calcular_error();
	
	cout<<"El valor de la integral "<<f_str<<": "<<valor<<endl;
	
	cout<<"Valor del error teorico: "<<error<<endl;
	
}
	
void caso_simpson13(){
	using integracion::Simpson13;

	string f_str="(e^(0.07*x))+(-(0.85*(x^7)))+(0.25*(x^5))+(2.5*((x)^2))";
	double a=0.0f;
	double b=1.41f;
	int n=16;
	
	//Crear instancia del simpson38
	Simpson13 simp(f_str,a,b,n);
	
	//Imprimir tabla de datos
	simp.imprimir_tabla(cout);
	
	double valor=simp.calcular();
	
	double error=simp.calcular_error();
	
	cout<<"El valor de la integral "<<f_str<<": "<<valor<<endl;
	
	cout<<"Valor del error teorico: "<<error<<endl;
}
	
void caso_romberg(){
	using integracion::Romberg;
	
	string f_str="(e^(0.07*x))+(-(0.85*(x^7)))+(0.25*(x^5))+(2.5*((x)^2))";
	double a=0.0f;
	double b=1.41f;
	int k=15;//aproximaciones
	//Crear instancia de romberg
	Romberg romb(f_str,a,b);
	
	
	romb.calcular(k);
	
}
