#ifndef SIMPSON_H
#define SIMPSON_H
	
#include <string>
#include <vector>
#include <iostream>

#include "simpson13.h"
#include "simpson38.h"

using std::string;
using std::vector;
using integracion::Simpson13;
using integracion::simpson38;

namespace integracion{
	
	class simpson{
	public:
		simpson(vector<double> x, vector<double> y){
			int n=(int)x.size()-1;
			
			if(!(n%2!=0 && n%3 ==0)){
				return;
			}
			this->x=x;
			this->y=y;
			this->n=n;
			//revisar
			if(x.size()!=y.size()){
				return;
			}
			
		}
		simpson(string f_str, double a, double b, int n){
			this->n=0;
			if(n<3){
				return;
			}
			int i=0;
			//0. Evaluador 
			expression f(f_str);
			
			double h = (b-a)/(double)n;
			
			
			for(double xi = a;i<=n;i++,xi*=h){
				x.push_back(xi);
				y.push_back(f(xi));
				xi+=h;
			}
			
		}
		double calcular(){
			//Si la cantidad de segmentos es par, aplicar simpson 1/3
			//y retornar el valor calculado
			//TODO mostrar que simpson es, los segmentos de cada simpson escogido
			//Si la cantidad de segmentos es multiplo de 3, aplicar simpson38
			//vector<double>x_2(x.begin() + n_1,x.end());//Lo mismo pa y
			//vector<double>y_2(y.begin() + (n_1+1)y.end());
			//3. PASO
			cout<<"calcular la integral con "<<n<<" segmentos"<<endl;
			
			int mitad = n/2;
			cout<<"mitad del intervalo: "<<mitad<<endl;
			return NAN;
			
		}
			void imprimir_tabla(ostream & os){
				os<<std::setw(15)<<"x"
					<<std::setw(15)<<"y"<<endl;
				for(size_t i=0;i<x.size();i++){
					os<<std::setw(15)<<x[i]<<
						std::setw(15)<<y[i]<<endl;
				}
			}
		
	private:
		vector<double> x;
		vector<double> y;
		int n;
		
	};
};


#endif
