#include <stdio.h>
#include <stdlib.h>
#include "cabeceras.h"

//FUNCIONES

/**
 * \brief Hace la operacion suma
 * \param Primer operando
 * \param Segundo operando
 * \return Retorna la suma ya efectuada
 */
int sumar (int x, int y)
		{
			int suma = x + y;
			return suma;
		}

/**
 * \brief Hace la operacion resta
 * \param Primer operando
 * \param Segundo operando
 * \return Retorna la resta ya efectuada
 */
int restar (int x, int y)
		{
			int resta = x - y;
			return resta;
		}

/**
 * \brief Hace la operacion multiplicar
 * \param Primer operando
 * \param Segundo operando
 * \return Retorna la multiplicacion ya efectuada
 */
int multiplicar (int x, int y)
		{
			int multi = x * y;
			return multi;
		}

/**
 * \brief Hace la operacion dividir
 * \param Primer operando
 * \param Segundo operando
 * \param Puntero a direccionDeVariable del tipo float
 * \return Retorna si la division se pudo realizar o no
 */
float dividir (int x, int y, float* direccionDeVariable)
{
			int hayError;

			if (y != 0)
		{

			float divid = (float)x / y;

			*direccionDeVariable = divid;

			hayError = 0;
		}
			else
		{
			hayError = 1;
		}

		return hayError;
}

/**
 * \brief Hace la operacion factorial
 * \param Operador x
 * \return Retorna el resultado de la operaion factorial
 */
int factorial(int x)
{
    int resultado1;

    if (x == 0)
    {
        resultado1 = 1;
    }
    else if (x < 0)
		{
    	resultado1 = 0;
		}
    else
    {
        resultado1 = x*factorial (x-1);
    }
    return resultado1;
}

/**
 * \brief Hace la operacion factorial
 * \param Operador y
 * \return Retorna el resultado de la operaion factorial
 */
int factorial1(int y)
{
    int resultado2;

    if (y == 0)
    {
        resultado2 = 1;
    }
    else if (y < 0)
  		{
      	resultado2 = 0;
  		}
    else
    {
        resultado2 = y*factorial (y-1);
    }
    return resultado2;
}
