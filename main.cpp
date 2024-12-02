#include <iostream>
#include "caso.h"

using std::cout;
using std::endl;

void mostrarMenu();
void opcionIntegral();
void opcionDerivacion();


int main(int argc, char *argv[]) {
	int opt;
	opcionIntegral();
	do{
		mostrarMenu();
		scanf("%d", &opt);
		switch(opt){
			case 1: 
				opcionIntegral();
				break;
			case 2:
				opcionDerivacion();
				break;
			case 0:
				printf("Finalizando programa");
				break;
			default:
				printf("Opción invalida");
				break;
			
		}
		printf("Presione cualquier tecla para continuar...\n");
		getchar();
		getchar();
	}while(opt!=0);
}

void mostrarMenu() {
	system("cls || clear"); // Limpia la consola (compatible con Windows y Unix)
	printf("=========================================\n");
	printf("              Menu Principal             \n");
	printf("=========================================\n");
	printf("  1. Calcular Integral                   \n");
	printf("  2. Calcular Derivacion                 \n");
	printf("  0. Salir				                 \n");
	printf("=========================================\n");
	printf("Seleccione una opcion: ");
}

void opcionIntegral() {
	printf("=========================================\n");
	printf("        Opcion 1: Calcular Integral      \n");
	printf("=========================================\n");
	printf("Simpson38 con 15 segmentos\n");
	caso_simpson38();
	printf("\n=========================================\n");
	printf("Simpson13 con 16 segmentos\n");
	caso_simpson13();
	printf("\n=========================================\n");
	printf("\nRomberg\n");
	caso_romberg();
}

void opcionDerivacion() {
	printf("=========================================\n");
	printf("       Opcion 2: Calcular Derivacion     \n");
	printf("=========================================\n");
	printf("Derivaccion con primeras derivadas centrales\n");
	caso_1_derivadas_centrales();
	printf("Derivaccion con segundas derivadas centrales\n");
	caso_2_derivadas_centrales();
}
