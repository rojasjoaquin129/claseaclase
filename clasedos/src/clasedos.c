/*
 ============================================================================
 Name        : clasedos.c
 Author      : joaquin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int suma (int numeroUno,int numeroDos);
int resta (int numeroUno,int numeroDos);
int divicion (int numeroUno,int numeroDos);
int multiplicacion (int numeroUno,int numeroDos);
int pedirNumero(char *mensaje);
int main(void)
{
 int numero1;
 int numero2;
 int operacion;;
 numero1=pedirNumero("ingrese primer numero");
 numero2=pedirNumero("ingrese segundo numero");
 operacion=pedirNumero("ingese operacion (1 suma , 2 restar 3 divide 4 multiplica)");
 if(hacerCalculo(numero1,numero2,operacion)==0){
	printf("error");
 }
}

int pedirNumero(char *mensaje){
	int numero;
	printf(mensaje);
	scanf("%d",&numero);
	return numero;
}

int suma (int numeroUno,int numeroDos){
	return numeroUno+numeroDos;
}
int resta (int numeroUno,int numeroDos){
	return numeroUno-numeroDos;
}
int divicion (int numeroUno,int numeroDos){
	return numeroUno/numeroDos;
}
int multiplicacion (int numeroUno,int numeroDos){
	return numeroUno*numeroDos;
}
