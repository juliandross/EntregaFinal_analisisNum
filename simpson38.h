#ifndef SIMPSON38_H
#define SIMPSON38_H

#include "expression.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace integracion{
	
	class simpson38{
	public:
		simpson38(string f_str, double a, double b, int n){
			if(!(n%2!=0 && n%3 ==0)){
				return;
			}
			
			int i=0;
			//0. Evaluador 
			expression f(f_str);
			
			double h = (b-a)/(double)n;
			
			
			for(double xi = a;i<=n;i++,xi+=h){
				x.push_back(xi);
				y.push_back(f(xi));
			}
			
		}
		double calcular(){
			int n = x.size()-1;
			if(n<4){
				
			}
			double b = x[n];
			double a = x[0];
			
			double h = (b-a)/(double)n;
			
			double sum_1=0.0f;
			double sum_2=0.0f;
			double sum_3=0.0f;
			
			for(int i=1;i<n-1;i+=3){
				sum_1+=y[i];
				cout<<"\n\n\nsum_1"<<sum_1<<endl;
			}
			for(int j=2;j<n;j+=3){
				sum_2+=y[j];
				cout<<"\nsum_2"<<sum_2<<endl;
			}
			for(int k=3;k<n-2;k+=3){
				sum_3+=y[k];
				cout<<"\nsum_3"<<sum_3<<endl;
			}
			return ((3.0f*h)/(double)8.0f)*(y[0]+3.0f*(sum_1+sum_2)+2.0f*sum_3+y[n]);
			
		}
			void imprimir_tabla(ostream & os){
				os<<std::setw(15)<<"x"
					<<std::setw(15)<<"y"<<endl;
				for(size_t i=0;i<x.size();i++){
					os<<std::setw(15)<<x[i]<<
						std::setw(15)<<y[i]<<endl;
				}
			}
				
				simpson38(vector<double> x, vector<double> y){
					int n=(int)x.size()-1;
					
					if(!(n%2!=0 && n%3 ==0)){
						return;
					}
					//revisar
					if(x.size()!=y.size()){
						return;
					}
					this->x=x;
					this->y=y;
				}
					
			void calcular_error(string f2_str){
				//double h = ((pow((a-b),5))/180*n*n);
				
			}
	private:				
			vector<double> x;
			vector<double> y;
				
	};
	}



#endif
