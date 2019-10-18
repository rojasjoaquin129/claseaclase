#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "informes.h"

int contarClientekilos(aPedido *list, int length,int id) {
	int i;
	int retorno = -1;
	int acumulador=0;
	if(list!=NULL && length>0){
    for (i = 0; i < length; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY && list[i].prendiente==0) {
            if(list[i].idCliente==id){
                acumulador=acumulador+list[i].HDPE+list[i].LDPE+list[i].PP;
            }
			}
          }
          retorno=acumulador;
		}
    return retorno;
}

int printMayorClienteporKilos (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int mayor=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            contador=contarClientekilos(list,length,listCliente[i].id);
            if (contador!=-1){
                if(mayor<contador){
                    mayor=contador;
                    j=i;
                }

            }
        retorno=0;
        }
        printf("el cliente q tiene mas kilos resiclados  es : \n");
        printf("\n%d-----%s----%s------%s------%s\n",listCliente[j].id,
                    listCliente[j].nombre,listCliente[j].cuit,
                    listCliente[j].localidad,listCliente[j].direccion);
        printf("con la cantidad de %d\n",mayor);

    }
	return retorno;
}


int printMenorClienteporKilos (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int menor=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            contador=contarClientekilos(list,length,listCliente[i].id);
            if (contador!=-1){
                if(menor>contador){
                    menor=contador;
                    j=i;
                }

            }
        retorno=0;
        }
        printf("el cliente q tiene menos kilos resiclados  es : \n");
        printf("\n%d-----%s----%s------%s------%s\n",listCliente[j].id,
                    listCliente[j].nombre,listCliente[j].cuit,
                    listCliente[j].localidad,listCliente[j].direccion);
        printf("con la cantidad de %d\n",menor);

    }
	return retorno;
}

int printClientesCantidadKilos (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    int contador=0;
    int kilos=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            kilos=contarClientekilos(list,length,listCliente[i].id);
            if (kilos!=-1){
                if(kilos>1000){
                    contador++;
                }

            }
        retorno=0;
        }
        printf("la cantidad de clientes que superan los 1000 kilos resiclados  es : %d\n",contador);

    }
	return retorno;
}

int printClientesCantidadMenosKilos (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    int contador=0;
    int kilos=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            kilos=contarClientekilos(list,length,listCliente[i].id);
            if (kilos!=-1){
                if(kilos<100){
                    contador++;
                }

            }
        retorno=0;
        }
        printf("la cantidad de clientes que reciclaron menos de  100 kilos es : %d\n",contador);

    }
	return retorno;
}




int contarPedidoPorId(aPedido *list, int length,int id,int estado) {
	int i;
	int contador=0;
	int retorno = -1;
	if(list!=NULL && length>0){
    for (i = 0; i < length; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY && list[i].prendiente==estado) {
            if(list[i].idCliente==id){
                contador++;
            }
			}
          }
          retorno=contador;
		}
    return retorno;
}



int contarMaspediddosPorId(aPedido *list, int length,int id) {
	int i;
	int contador=0;
	int retorno = -1;
	if(list!=NULL && length>0){
    for (i = 0; i < length; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY ) {
            if(list[i].idCliente==id){
                contador++;
            }
			}
          }
          retorno=contador;
		}
    return retorno;
}


int printmayorDePedidosTotales (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int mayor=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            contador=contarMaspediddosPorId(list,length,listCliente[i].id);
            if (contador!=-1){
                if(mayor<contador){
                    mayor=contador;
                    j=i;
                }

            }
        retorno=0;
        }

        printf("el cliente q tiene mas pedidos pendientes es : \n");
        printf("\n%d-----%s----%s------%s------%s\n",listCliente[j].id,
                    listCliente[j].nombre,listCliente[j].cuit,
                    listCliente[j].localidad,listCliente[j].direccion);
        printf("con la cantidad de %d\n",mayor);

    }
	return retorno;
}


int contarClientekilosCompletados(aPedido *list, int length,int id,float *porsentaje) {
	int i;
	float retorno = -1;
	int acumulador=0;
	int total=0;
	if(list!=NULL && length>0){
    for (i = 0; i < length; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY && list[i].prendiente==0) {
            if(list[i].idCliente==id){
                acumulador=acumulador+list[i].HDPE+list[i].LDPE+list[i].PP;
                total=total+list[i].kilos;

            }
			}
          }
          *porsentaje=acumulador/total;

          retorno=0;
		}
    return retorno;
}

int printCantidadDePedidosCompletados (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    float porsentaje;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        printf("ID    CUIT      PORSENTAJE RECICLADO");
        for(i=0;i<len;i++){
            if(listCliente[i].isEmpty==STATUS_NOT_EMPTY){
            contarClientekilosCompletados(list,length,listCliente[i].id,&porsentaje);
                printf("\n%d-----%s----------------- %f \n",listCliente[i].id,listCliente[i].cuit,porsentaje);
                }
        }
        retorno=0;
    }
	return retorno;
}





int printMayorDePedidos (aPedido* list,int length,aCliente*listCliente,int len,int estado){
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int mayor=0;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        for(i=0;i<len;i++){
            contador=contarPedidoPorId(list,length,listCliente[i].id,estado);
            if (contador!=-1){
                if(mayor<contador){
                    mayor=contador;
                    j=i;
                }

            }
        retorno=0;
        }
        if(estado==1){
        printf("el cliente q tiene mas pedidos pendientes es : \n");
                printf("\n%d-----%s----%s------%s------%s\n",listCliente[j].id,
                    listCliente[j].nombre,listCliente[j].cuit,
                    listCliente[j].localidad,listCliente[j].direccion);
                    }else {
                printf("el cliente q tiene mas pedidos completados es : \n");
                printf("\n%d-----%s----%s------%s------%s\n",listCliente[j].id,
                    listCliente[j].nombre,listCliente[j].cuit,
                    listCliente[j].localidad,listCliente[j].direccion);
                    }
                printf("con la cantidad de %d\n",mayor);

    }
	return retorno;
}










int printCantidadDePedidos (aPedido* list,int length,aCliente*listCliente,int len,int estado){
    int retorno=-1;
    int i;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        printf("ID    NOMBRE    CUIT   DIRECCION    LOCALIDAD    PEDIDOS");
        for(i=0;i<len;i++){
            if(listCliente[i].isEmpty==STATUS_NOT_EMPTY){
                printf("\n%d-----%s----%s------%s------%s-----%d\n",listCliente[i].id,
                    listCliente[i].nombre,listCliente[i].cuit,
                    listCliente[i].localidad,listCliente[i].direccion,contarPedidoPorId(list,length,listCliente[i].id,estado));
                }
        }
        retorno=0;
    }
	return retorno;
}


int printPedidosporclientes (aPedido* list,int length,aCliente*listCliente,int len,int estado){
    int retorno=-1;
    int i;
    int posicion;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        printf("ID    CUIT   DIRECCION    LOCALIDAD  RECOLECTAR(kilos)");
        for(i=0;i<len;i++){
            if(list[i].isEmpty==STATUS_NOT_EMPTY && list[i].prendiente==estado){
                posicion=buscarclientesPorPedidos(listCliente,len,list[i].idCliente);
                if(posicion!=-1){
                printf("\n%d-----%s----%s------%s------%d\n",list[i].id,
                    listCliente[posicion].cuit,
                    listCliente[posicion].direccion,listCliente[posicion].localidad,list[i].kilos);
                }
            }
        }
        retorno=0;
    }
	return retorno;
}

int buscarclientesPorPedidos(aCliente *list, int len,int id) {
	int i;
	int retorno = -1;
	if(list!=NULL && len>0){
    for (i = 0; i < len; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY ) {
            if(list[i].id==id){
            retorno=i;
            }
        }
          }
		}
    return retorno;
}
