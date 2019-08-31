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
int suma (int *numeroUno,int *numeroDos);
int main(void)
{
int numeroUno;
int numeroDos;
int resultado=0;
 printf("ingrese primero numero");
 scanf("%d",&numeroUno);
 printf("ingrese segundo numero");
 scanf("%d",&numeroDos);
 resultado=suma(&numeroUno, &numeroDos);
 printf("el resultado es %d",resultado);
}
int suma (int *numeroUno,int *numeroDos){
	int auxiliar;
	auxiliar=*numeroUno+*numeroDos;
	return auxiliar;
}
