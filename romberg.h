
/*
copiar y pegar en caso.h
 
void caso_1_romberg();
*/

/*
Copiar y pegar en caso.cpp
void caso_1_romberg(){
string f_str="(sin(x))^2";
double a=0.0f;
double b=PI/3.0f;
int k=5;

cout<<" Metodo de Romberg"<<endl;

Romberg r(f_str,a,b);
resultado_romberg rs=r.calcular(k);

cout<<"Funcion utilizada: "<<f_str<<endl;	
cout<<"El resultado de la Integracion por Romberg es: "<<rs.valor<<endl;
cout<<"Con un error de: "<<rs.error<<"%"<<endl;
}

*/

/**
* @file
* @brief Metodo de Romberg
* @author Juan David Moran
*/

/**
* @brief
* @param
* @return
*/
/*!< */

#ifndef ROMBERG_H
#define ROMBERG_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include "expression.h"
#include "trapecio.h"

using Integracion::trapecio;
using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

namespace Integracion{
	
	/**
	* @brief Resultado de integracion por romberg
	*/
	struct resultado_romberg{
		double error;
		double valor;
		int k;
		resultado_romberg(double a, int b, double c){
			valor=a;
			error=c;
			k=b;
		}
	};
	
	class Romberg{
	private:
		string f_str;
		double a;
		double b;
	public:
		
		/**
		* @brief Crear una instancia de la clase
		* @param a Limite inferior
		* @param a Limite superior
		*/
		Romberg(string f_str,double a, double b):f_str(f_str),a(a),b(b){
			
		}
		
		/**
		* @brief Calcula la integral con k aproximaciones
		* @param k Numero de aproximaciones
		* @return resultado de la integracion 
		*/
		resultado_romberg calcular(int k){
			size_t i;
			size_t j;
			
			//crear la matriz de k filas
			vector<vector<double>> m(k);
			
			//Redimensionar las filas
			for (i=0;i<(size_t)k;i++){
				m[i].resize(k-i);
			}
			
			//llenar la primera columna de la matriz
			for(i=0;i<(size_t)k;i++){
				//con trapecio (f_str, a, b, n=2^i)
				int n=pow(2,i);
				trapecio t(f_str,a,b,n);
				m[i][0]=t.calcular();
			}
			
			//Realizar las combinaciones
			for(j=1;j<(size_t)k;j++){
				int po=pow(4,j);
				for(i=0;i<(k-j);i++){
					m[i][j]=((double)((double)po/(double)(po-1))*m[i+1][j-1])-
						((double)(1.0f/(double)(po-1))*m[i][j-1]);
				}
			}
			
			//Imprimir la Matriz
			for(i=0;i<(size_t)k;i++){
				for(j=0;j<m[i].size();j++){
					cout<<std::setprecision(7)<<std::setw(9)<<m[i][j]<<" ";
				}
				cout<<endl;
			}
			
			//Calcular el error de la integral
			double v_real=m[0][k-1];
			double v_estiamdo=m[0][k-2];
			double error=(v_real-v_estiamdo)/v_real;
			
			return resultado_romberg {v_real, k, error*100.0f};
		}
	};
};

#endif


