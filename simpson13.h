#ifndef SIMPSON13_H
#define SIMPSON13_H

#include "expression.h"
#include <iomanip> // Para std::setw y std::setprecision

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace integracion {
	
	class Simpson13 {
	public:
		Simpson13(string f_str, double a, double b, int n) : f_str(f_str), a(a), b(b), n(n) {
			if (n % 2 != 0) { // n debe ser par para Simpson 1/3
				cout << "Error: n debe ser par para el método Simpson 1/3." << endl;
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
			int n = x.size() - 1; // Número de intervalos
			if (n < 2) {
				cout << "Error: Se necesitan al menos dos puntos para Simpson 1/3." << endl;
				return 0;
			}
			
			double h = (x[n] - x[0]) / static_cast<double>(n);
			double sum_odd = 0.0;
			double sum_even = 0.0;
			
			for (int i = 1; i < n; i += 2) {
				sum_odd += y[i];
			}
			for (int i = 2; i < n - 1; i += 2) {
				sum_even += y[i];
			}
			
			return (h / 3.0) * (y[0] + 4 * sum_odd + 2 * sum_even + y[n]);
		}
		
		double calcular_error() {
			if (n < 2) {
				cout << "Error: Se necesitan al menos dos intervalos para calcular el error." << endl;
				return 0;
			}
			
			expression f4("(0.00002401*(e^(0.07*x)))+(-(714*(x^3)))+(30*x)");
			
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
			double error = (pow(b - a, 5) / (180.0 * pow(n, 4))) * f4_max;
			return error;
		}
		
		void imprimir_tabla(std::ostream &os) {
			os << std::setw(15) << "x" << std::setw(15) << "y" << endl;
			for (size_t i = 0; i < x.size(); i++) {
				os << std::setw(15) << x[i] << std::setprecision(8) << x[i]
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
