#include <iostream>
#include "caso.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	int opt;
	do{
		mostrarMenu();
		scanf("%d", &opt);
		switch(opt){
			case 1: 
				opcionIntegral();
				//Metodos integral
			case 2:
				opcionDerivacion();
				//Metodos de derivación
			case 0:
				printf("Finalizando programa");
			case default:
				printf("Opción invalida");
			
		}
	}while(opt!=0);
}

void mostrarMenu() {
	system("cls || clear"); // Limpia la consola (compatible con Windows y Unix)
	printf("=========================================\n");
	printf("              Menu Principal             \n");
	printf("=========================================\n");
	printf("  1. Calcular Integral                   \n");
	printf("  2. Calcular Derivacion                 \n");
	printf("  0. Calcular Derivacion                 \n");
	printf("=========================================\n");
	printf("Seleccione una opcion: ");
}

void opcionIntegral() {
	system("cls || clear");
	printf("=========================================\n");
	printf("        Opcion 1: Calcular Integral      \n");
	printf("=========================================\n");
	printf("Esta funcionalidad aun no esta disponible.\n");
	printf("Presione cualquier tecla para continuar...\n");
	getchar();
}

void opcionDerivacion() {
	system("cls || clear");
	printf("=========================================\n");
	printf("       Opcion 2: Calcular Derivacion     \n");
	printf("=========================================\n");
	printf("Esta funcionalidad aun no esta disponible.\n");
	printf("Presione cualquier tecla para continuar...\n");
	getchar();
}
