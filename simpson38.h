#ifndef SIMPSON38_H
#define SIMPSON38_H

#include "expression.h"
#include <cmath>    // Para std::fabs y std::pow
#include <iomanip>  // Para std::setw y std::setprecision

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace integracion {
	
	class simpson38 {
	public:
		simpson38(string f_str, double a, double b, int n) : f_str(f_str), a(a), b(b), n(n) {
			if (!(n % 2 != 0 && n % 3 == 0)) {
				cout << "Error: n debe ser múltiplo de 3 para el método Simpson 3/8." << endl;
				return;
			}
			
			int i = 0;
			expression f(f_str);
			
			double h = (b - a) / static_cast<double>(n);
			
			for (double xi = a; i <= n; i++, xi += h) {
				x.push_back(xi);
				y.push_back(f(xi));
			}
		}
		
		double calcular() {
			int n = x.size() - 1;
			if (n < 3) {
				cout << "Error: Se necesitan al menos tres intervalos para Simpson 3/8." << endl;
				return 0;
			}
			
			double b = x[n];
			double a = x[0];
			double h = (b - a) / static_cast<double>(n);
			
			double sum_1 = 0.0, sum_2 = 0.0, sum_3 = 0.0;
			
			for (int i = 1; i < n; i += 3) {
				sum_1 += y[i];
			}
			for (int j = 2; j < n; j += 3) {
				sum_2 += y[j];
			}
			for (int k = 3; k < n - 2; k += 3) {
				sum_3 += y[k];
			}
			
			return ((3.0 * h) / 8.0) * (y[0] + 3.0 * (sum_1 + sum_2) + 2.0 * sum_3 + y[n]);
		}
		
		double calcular_error() {
			if (n < 3) {
				cout << "Error: Se necesitan al menos tres intervalos para calcular el error." << endl;
				return 0;
			}
			
			expression f4("(0.00002401*(e^(0.07*x)))+(-(714*(x^3)))+(30*x)"); // Se define para calcular la cuarta derivada
			
			// Determinar el valor máximo de la cuarta derivada en [a, b]
			double f4_max = 0;
			double h = (b - a) / 1000.0; // Evaluar en 1000 puntos como aproximación
			for (double xi = a; xi <= b; xi += h) {
				double f4_val = fabs(f4(xi));
				if (f4_val > f4_max) {
					f4_max = f4_val;
				}
			}
			
			// Fórmula del error
			double error = (pow(b - a, 5) / (80.0 * pow(n, 4))) * f4_max;
			return error;
		}
		
		void imprimir_tabla(std::ostream &os) {
			os << std::setw(15) << "x" << std::setw(15) << "y" << endl;
			for (size_t i = 0; i < x.size(); i++) {
				os << std::setw(15) << x[i]
					<< std::setw(15) << y[i] << endl;
			}
		}
		
	private:
			vector<double> x;
			vector<double> y;
			string f_str; // Expresión de la función
			double a, b;  // Límites de integración
			int n;        // Número de segmentos
				};
	
} // namespace integracion

#endif
