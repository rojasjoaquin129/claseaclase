#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}


int initLugarLibrePedido(aPedido *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			aArray[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLugarLibrePedido(aPedido *aArray, int cantidad){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].isEmpty == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printPedidos(aPedido *list, int length) {
	int i;
	int retorno = -1;
	if (list != NULL && length > 0) {
		retorno = 0;

		printf("id       id del Cliente       Kilos a recolectar        Estado\n");
		for (i = 0; i < length; i++) {
            if (list[i].isEmpty == STATUS_NOT_EMPTY) {
                if(list[i].prendiente==0){
                    printf("%d ------------ %d ------------------- %d ------------------- Completado \n", list[i].id,
						list[i].idCliente, list[i].kilos);
                    } else {
                    printf("%d ------------ %d ------------------- %d ------------------- pendiente \n", list[i].id,
						list[i].idCliente, list[i].kilos);
                        }
			}

		}
	}
	return retorno;
}

int ordenarPedidoPorCliente(aPedido*aArray,int cantidad){
    int i;
	int retorno = -1;
	aPedido buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(aArray[i].idCliente<aArray[i+1].idCliente)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}
				else if(aArray[i].idCliente==aArray[i+1].idCliente)
				{
					if(aArray[i].kilos>aArray[i+1].kilos)
					{
						fSwap = 1;
						buffer = aArray[i];
						aArray[i]=aArray[i+1];
						aArray[i+1]=buffer;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}






int buscarPedidoPorId(aPedido *aArray, int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(aArray[i].id == id && aArray[i].isEmpty == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}





int modificarPedidoporId(aPedido *list, int len, aPedido item) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = buscarPedidoPorId(list, len, item.id);
		if (index != -1) {
			list[index] = item;
			list[index].prendiente=0;
			list[index].isEmpty = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int altaPedidoPorId(aPedido *aArray, int cantidad,aPedido item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarLugarLibrePedido(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].prendiente=1;
			aArray[index].isEmpty = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}


int altaPedidoUI (aPedido *list ,int len , aCliente*listClientes,int length){
    aPedido bPedidos;
    int retorno=-1;
    printf("\n Alta de pedido\n");
    if (buscarLugarLibrePedido(list, QTY_PEDIDOS) == -1) {
        printf("Error no hay mas lugar para pedidos\n");
        }else{
            printCliente(listClientes,length);
            if (getInt(&bPedidos.idCliente, "Ingrese el id del cliente\n", "Error",
							1, 1000000, 2) == -1) {
                printf("Error en el id\n");
            }else {
                if(findClienteById(listClientes,length, bPedidos.idCliente)== -1){
                    printf("Error id del cliente inexistente");
                }else{
                    if (getInt(&bPedidos.kilos, "Ingrese la cantidad de kilos\n", "Error",
								1, 10000000, 2) == -1) {
                        printf("Error en la cantidad de kilos\n");
                    }else{
                        if (altaPedidoPorId(list, len, bPedidos) == 0) {
                                printf("pedido de recoleccion exitoso\n");
                                retorno=0;
                        }else {
                                printf("Error al hacer el pedido\n");
                                }
                            }
                        }
                    }
                }
    return retorno;
            }

int modificacionPedidoUI (aPedido *pedidos , int len) {
    aPedido bPedidos;
    int retorno=-1;
    int auxPedido=0;
    int posicion;
    if (buscarLugarLibrePedido(pedidos, len) == -1) {
        printf("Error no hay mas lugar para pedidos\n");
    }else{
        printPedidos(pedidos,QTY_PEDIDOS);
        if (getInt(&bPedidos.id, "Ingrese el id del pedido\n", "Error\n",
            1, 100000, 2) == -1) {
            printf("Error en el id\n");
        }else{
			posicion=buscarPedidoPorId(pedidos,QTY_PEDIDOS, bPedidos.id);
			if(posicion== -1){
                printf("Error id del pedido inexistente\n");
			}else{
                if (getInt(&bPedidos.HDPE, "Ingrese la cantidad de polietileno de alta densidad\n", "Error",
										1, 1000000, 2) == -1) {
                    printf("Error en la cantidad de HDPE\n");
                }else{
                    if (getInt(&bPedidos.LDPE, "Ingrese la cantidad de polietileno de Baja densidad\n", "Error",
                                        1, 1000000, 2) == -1) {
                        printf("Error en la cantidad de LDPE\n");
                    }else{
                        if (getInt(&bPedidos.PP, "Ingrese la cantidad de polietileno \n", "Error\n",
                                        1, 1000000, 2) == -1) {
                            printf("Error en la cantidad de PP\n");
                        }else{
                            auxPedido=bPedidos.PP+bPedidos.HDPE+bPedidos.PP;
                            if(auxPedido>pedidos[posicion].kilos){
                                printf("Error en la cantidad de plastico");
                            }else{
                                if (modificarPedidoporId(pedidos, QTY_PEDIDOS, bPedidos) == 0) {
                                    printf("PROCESO exitoso\n");
                                    retorno=0;
                                    } else {
                                        printf("Error al hacer el PROCESO\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return retorno;
}



