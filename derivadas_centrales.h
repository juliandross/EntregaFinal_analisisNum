#ifndef DERIVADAS_CENTRALES_H
#define DERIVADAS_CENTRALES_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include "expression.h"

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

namespace derivadas{
	class PrimerasCentrales{
	private:
		vector<double> x;
		vector<double> y;
		string f_str;
	public:
		/**
		* @brief Crear una instancia de la clase 
		* @param f_str funcion a utilizar
		*/
		PrimerasCentrales(string f_str):f_str(f_str){
			
		}
		
		/**
		* @brief Construir la tabla de datos a utilizar
		* @param iterador Variable para evaluar nuestra función que ira aumentando a cierto paso
		* @param paso Variable que define el paso al que aumnetara el iterador
		* @param 
		*/
		void construir(double iterador,double paso,double numDatos){
			// Creamos el evaluador de epresiones
			expression f(f_str);
			
			// Creamos tabla de datos
			for(size_t i=0;i<(size_t)numDatos;i++){
				x.push_back(iterador);
				y.push_back(f(iterador));
				iterador+=paso;
			}
		}
			/**
			* @brief Imprimir tabla de datos	
			*/
			void imprimir(){
				cout<<std::setprecision(7)<<"x"<<std::setw(9)<<""<<"y"<<endl;
				for(int i=0;i<x.size();i++){
					cout<<std::setprecision(7)<<x[i]<<std::setw(9)<<""<<y[i]<<endl;
				}
			}
				
				/**
				* @brief Calcular la derivada en un punto
				* @param punto Punto donde calcular la derivada
				*/	
				double calcular(double punto){
					
					int indice=0;
					// Encontramos el indice en donde se encuentra el punto y devolvemos NAN si no existe
					for(int i=0;i<x.size();i++){
						if(x[i]==punto){
							indice=i;
						}else if(i==x.size()){
							return NAN;
						}
					}
					
					//Empleamos la formula
					return (y[indice+1]-y[indice-1])/(2.0f*(x[indice]-x[indice-1]));
				}
					
					/**
					* @brief Calcular el error 	
					* @param df_str Primera derivada de la funcion
					* @param punto Punto a evaluar
					*/	
					double error(string df_str, double punto){
						expression f(df_str);
						double VA=f(punto);
						double VM=calcular(punto);
						return (fabs((VA-VM)/VA))*100.0f;
					}
	};
	
	
	
	class SegundasCentrales{
	private:
		vector<double> x;
		vector<double> y;
		string f_str;
	public:
		/**
		* @brief Crear una instancia de la clase 
		* @param f_str funcion a utilizar
		*/
		SegundasCentrales(string f_str):f_str(f_str){
			
		}
		
		/**
		* @brief Construir la tabla de datos a utilizar
		* @param iterador Variable para evaluar nuestra función que ira aumentando a cierto paso
		* @param paso Variable que define el paso al que aumnetara el iterador
		* @param 
		*/
		void construir(double iterador,double paso,double numDatos){
			// Creamos el evaluador de epresiones
			expression f(f_str);
			
			// Creamos tabla de datos
			for(size_t i=0;i<(size_t)numDatos;i++){
				x.push_back(iterador);
				y.push_back(f(iterador));
				iterador+=paso;
			}
		}
			/**
			* @brief Imprimir tabla de datos	
			*/
			void imprimir(){
				cout<<std::setprecision(7)<<"x"<<std::setw(9)<<""<<"y"<<endl;
				for(int i=0;i<x.size();i++){
					cout<<std::setprecision(7)<<x[i]<<std::setw(9)<<""<<y[i]<<endl;
				}
			}
				
				/**
				* @brief Calcular la derivada en un punto
				* @param punto Punto donde calcular la derivada
				*/	
				double calcular(double punto){
					
					int indice=0;
					// Encontramos el indice en donde se encuentra el punto y devolvemos NAN si no existe
					for(int i=0;i<x.size();i++){
						if(x[i]==punto){
							indice=i;
						}else if(i==x.size()){
							return NAN;
						}
					}
					
					//Empleamos la formula
					return ((-y[indice-2])+8*y[indice+1]-8*y[indice-1]+y[indice+2])/(12*(x[indice]-x[indice-1]));
				}
					
					/**
					* @brief Calcular el error 	
					* @param df_str Primera derivada de la funcion
					* @param punto Punto a evaluar
					*/	
					double error(string df_str, double punto){
						expression f(df_str);
						double VA=f(punto);
						double VM=calcular(punto);
						return (fabs((VA-VM)/VA))*100.0f;
					}
						
	};
	
};
#endif
