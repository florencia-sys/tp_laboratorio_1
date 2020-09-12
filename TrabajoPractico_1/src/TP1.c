#include <stdio.h>
#include <stdlib.h>
#include "cabeceras.h"

int main(void) {

	setbuf (stdout, NULL);
//VARIABLES
	int num1 = 0;
	int num2 = 0;
	int resultado;
	float resultadoConComa;
	int resultado1;
	int resultado2;
	int opcion;
//IMPRESION DE MENU
	do{
		printf("1.Ingrese el primer numero\n");
		printf("2.Ingrese el segundo numero\n");
		printf ("3.Calcular todas las operaciones\n");
		printf("4.Informar resultados\n");
		printf("5.Salir\n");
		printf("Ingrese opcion: ");
		scanf("%d",&opcion);

//MUESTRA DE RESULTADOS

	switch(opcion){

	case 1:
			printf("Numero 1:");
			scanf("%d", &num1);
			printf ("A = %d\n", num1);
			break;
	case 2:
			printf("Numero 2:");
			scanf("%d", &num2);
			printf ("B = %d\n", num2);
			break;

	case 3:
			printf("Calcular la suma (%d + %d)\n", num1, num2);
			printf("Calcular la resta (%d - %d)\n", num1, num2);
			printf("Calcular la multiplicacion (%d * %d)\n", num1, num2);
			printf("Calcular la division (%d / %d)\n", num1, num2);
			printf("Calcular el factorial (%d!) y (%d!)\n", num1, num2);
			break;

	case 4:

	resultado = sumar (num1, num2);
	printf ("El resultado de  %d + %d es: %d\n", num1, num2, resultado);

	resultado = restar (num1, num2);
		printf ("El resultado de %d - %d es: %d\n", num1, num2, resultado);

	resultado = multiplicar (num1, num2);
		printf ("El resultado de %d * %d es: %d\n", num1, num2, resultado);

	int retornoHayError = dividir (num1, num2, &resultadoConComa);//Guardo el retorno de la funcion dividir.

	if (retornoHayError == 1)//Si la variable retorna 1, no se puede dividir.

		printf ("No se puede dividir por 0\n");

	else//Si la variable retorna 0, se puede dividir.

		printf ("El resultado de %d / %d es: %.2f\n", num1, num2, resultadoConComa);//Informo el resultado.

	resultado1 = factorial(num1);
	resultado2 = factorial1(num2);
	printf("El factorial de %d es: %d y el factorial de %d es: %d\n", num1, resultado1, num2, resultado2);
	break;

	case 5:
			break;

	default:
			printf("La opcion ingresada es incorrecta");
			break;
	}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
