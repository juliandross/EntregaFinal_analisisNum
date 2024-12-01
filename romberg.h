#ifndef ROMBERG_H
#define ROMBERG_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include "expression.h"
#include "trapecio.h"

using integracion::trapecio;
using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

namespace integracion {
	
	/**
	* @brief Resultado de integración por Romberg.
	*/
	struct resultado_romberg {
		double valor; ///< Valor de la integral.
		double error; ///< Error relativo (%) de la integral.
		int k;        ///< Número de aproximaciones utilizadas.
		
		resultado_romberg(double valor = 0, double error = 0, int k = 0)
			: valor(valor), error(error), k(k) {}
	};
	
	class Romberg {
	private:
		string f_str;  ///< Función a integrar.
		double a;      ///< Límite inferior de la integral.
		double b;      ///< Límite superior de la integral.
		resultado_romberg resultado; ///< Resultado almacenado de la integral.
		
	public:
		/**
		* @brief Crear una instancia de la clase.
		* @param f_str Función a integrar.
		* @param a Límite inferior.
		* @param b Límite superior.
		*/
		Romberg(string f_str, double a, double b)
			: f_str(f_str), a(a), b(b), resultado(0, 0, 0) {}
		
		/**
		* @brief Calcula la integral con k aproximaciones.
		* @param k Número de aproximaciones.
		* @return Resultado de la integración.
		*/
		resultado_romberg calcular(int k) {
			size_t i, j;
			
			// Crear la matriz de k filas.
			vector<vector<double>> m(k);
			
			// Redimensionar las filas.
			for (i = 0; i < (size_t)k; i++) {
				m[i].resize(k - i);
			}
			
			// Llenar la primera columna de la matriz.
			for (i = 0; i < (size_t)k; i++) {
				int n = pow(2, i); // n = 2^i
				trapecio t(f_str, a, b, n);
				m[i][0] = t.calcular();
				
				// Depuración: Imprimir valores de la primera columna.
				cout << "m[" << i << "][0] = " << m[i][0] << endl;
			}
			
			// Realizar las combinaciones.
			for (j = 1; j < (size_t)k; j++) {
				int po = pow(4, j);
				for (i = 0; i < (k - j); i++) {
					m[i][j] = (po * m[i + 1][j - 1] - m[i][j - 1]) / (po - 1);
					
					// Depuración: Imprimir combinaciones en la matriz.
					cout << "m[" << i << "][" << j << "] = " << m[i][j] << endl;
				}
			}
			
			// Calcular el error de la integral.
			double v_real = m[0][k - 1];
			double v_estimado = m[0][k - 2];
			double error = (v_real != 0.0) ? std::abs((v_real - v_estimado) / v_real) * 100.0 : 0.0;
			
			// Almacenar el resultado.
			resultado = resultado_romberg(v_real, error, k);
			
			// Imprimir el resultado final.
			cout << "Resultado final: " << v_real << endl;
			cout << "Error relativo: " << error << "%" << endl;
			
			return resultado;
		}
		
		/**
		* @brief Obtiene el valor de la integral calculada.
		* @return Valor de la integral.
		*/
		double get_valor() const {
			return resultado.valor;
		}
		
		/**
		* @brief Obtiene el error relativo de la integral calculada.
		* @return Error relativo (%).
		*/
		double get_error() const {
			return resultado.error;
		}
	};
	
}

#endif
