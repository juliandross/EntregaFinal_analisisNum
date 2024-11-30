/**
*@brief Metodo del Trapecio
*/
#ifndef TRAPECIO_H
#define TRAPECIO_H

#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include "expression.h"

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;


namespace integracion{
	class trapecio{
	private:
		vector<double> x; /*!<Valor de la variable independiente */
		vector<double> y;	/*!<Valor de la variable dependiente */
		/**
		*@brief encuentra el valor maximo en valor absoluto de d2f en el 
		* intervalo
		*/
		double calcular_f2e(string d2f_str){
			double maximo = 0.0;
			double signo = 1.0;
			
			expression d2f(d2f_str);

			
			for (const auto& xi : x) {
				double valor = d2f(xi);
				double valor_abs = std::fabs(valor);
				
				if (valor_abs > maximo) {
					maximo = valor_abs;
					signo = (valor >= 0) ? 1.0 : -1.0;
				}
			}
			
			// Devuelve el valor máximo multiplicado por el signo para conservar el signo
			return signo * maximo;
		}
			
			
	public:
		/**
		*@brief Contructor que recibe una funcion
		*@param f_str Funcion
		*@param a Limite superior
		*@param b Limite inferior
		*@param n Numero de segmentos
		*/
		trapecio(string f_str, double a, double b, int n){
			int i=0;
			double xi=a;
			// 0.Crear evaluador de expresiones
			expression f(f_str);
			
			
			// 1.Calcular el paso h
			double h = (b-a)/(double)n;
			
			// 2.Construir la tabla de datos
			for(  i=0;i<=n;i++){
				x.push_back(xi);
				y.push_back(f(xi));
				xi+=h;
			}
		}
		/**
		*@brief Contructor los datos
		*@param x Valor de la variable independiente
		*@param y Valor de la variable dependiente
		*/
		trapecio(vector<double> x,vector<double> y):x(x),y(y){
			
		}
		/**
		*@brief Calcula el valor de la integral en el intervalo dado
		*/
		double calcular(){
			/**
			Para el metodo del trapecio de necesitan alemnos
			dos datos
			*/
			if(x.size()<2){
				return NAN;
			}
			
			// Cantidad de segmentos= tamano del vector -1
			int n= (int)x.size()-1;
			
			//double sum = y[0] + y[n];
			double sum_int=0.0f;
			
			for(size_t i=1;(int)i<n;i++){
				sum_int+=y[i];
			}
			
			
			return (x[n]-x[0])*((y[0]+2.0f*sum_int+y[n])/(double)(n*2));
		}
		
		double calcular_error(string d2f_str){
			
			//1. Encontrar f2(epsilon)
			double f2e = calcular_f2e(d2f_str);//TODO!!
			//2. Calcular Et
			
			double h=0.0f;//TODOO!!
			double et = -(pow(h,3)/12)*f2e;
				
			return fabs(et);
		}
		//Es la integral mas el error 
		double calcular_ajustada(string d2f_str){
			return calcular_error(d2f_str)+calcular();
		}
		/**
		*@brief imprimir tabla de datos
		*/	
		void imprimir_tabla(ostream & os){
			os<<std::setw(15)<<"x"
				<<std::setw(15)<<"y"<<endl;
			for(size_t i=0;i<x.size();i++){
				os<<std::setw(15)<<x[i]
					<<std::setw(15)<<y[i]<<endl;
			}
		}
		
	};
};
#endif
