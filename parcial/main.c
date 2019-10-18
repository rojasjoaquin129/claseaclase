#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "informes.h"
void CargaForzadaCliente(aCliente *list, int len);
void CargaForzadaPedidos(aPedido *list, int len);
int main(void) {
	aCliente list[QTY_CLIENTES];
	aPedido  pedidos[QTY_PEDIDOS];
	int out = 1;
	int id = 0;
	int assistantAdd = -1;
	int opcion = 0;
	initCliente(list, QTY_CLIENTES);
	initLugarLibrePedido(pedidos,QTY_PEDIDOS);
	CargaForzadaCliente(list,QTY_CLIENTES);
	CargaForzadaPedidos(pedidos,QTY_PEDIDOS);
	do {
		printf("\n"
				"1. Alta de cliente\n"
				"2. Modificacion datos del cliente\n"
				"3. Baja del cliente\n"
				"4. crear pedido de recoleccion\n"
				"5. procesar resuidos\n"
				"6. imprimir Clientes\n"
				"7. Imprimir pedidos Pendientes\n"
				"8. Imprimir Pedidos Procesados\n"
				"9. cliente con mas pedidos\n");

		getInt(&opcion, "\nIngrese la opcion\n", "\n Error\n", 1, 10, 3);
		switch (opcion) {
		case 1:
			if (addUI(list, QTY_CLIENTES, id) == 0) {
				assistantAdd = 0;
				break;
			}
			break;
		case 2:
			if (assistantAdd == 0) {
				modifyUI(list, QTY_CLIENTES);
			} else {
				printf("No existe ningun CLIENTE para modificar\n");
			}
			break;
		case 3:
			if (assistantAdd == 0) {
				removeUI(list, QTY_CLIENTES);
			} else {
				printf("No existe ningun empleado para eliminar\n");
			}
			break;
		case 4:
			altaPedidoUI(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
			break;
		case 5:
			modificacionPedidoUI(pedidos,QTY_PEDIDOS);
			break;
		case 6:
            printCantidadDePedidos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,1);
            break;
        case 7:
            printPedidosporclientes(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,1);
            break;
        case 8:
            printPedidosporclientes(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,0);
            break;
        case 9 :
            printf("ingrese cual quiere hacer");
            printMayorDePedidos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,1);
            printMayorDePedidos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,0);
            printmayorDePedidosTotales(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            printMayorClienteporKilos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            printMenorClienteporKilos (pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            printClientesCantidadKilos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            printClientesCantidadMenosKilos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            printCantidadDePedidosCompletados(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            break;
		case 10:
			out = 0;
			printf("Que tenga un buen dia\n");
			break;
		default:
			printf("ERROR, la opcion es invalida\n");
			break;
		}
	} while (out);
	return EXIT_SUCCESS;
}

/*
 * \brief Carga forzada de datos para la entidad Pedido
 * \param list Pedido*
 * \param len int
 */
void CargaForzadaPedidos(aPedido *list, int len)
{
	int kilos[]={1000,800,100,300,1500,750,200 ,30,456};
	int aIdCliente[]={1,1,2,2,3,4,1,5,6};
	int aPendiente[]={0,0,1,1,0,0,1,0,1};
	int K1[]={200,210,0,0,500,100,0,10,0};
	int k2[]={145,45,0,0,150,50,0,5,0};
	int k3[]={230,30,0,0,270,70,0,3,0};
	int i;
	int id;
	for(i=0;i<11;i++){
		list[i].kilos= kilos[i];
		list[i].HDPE=K1[i];
		list[i].PP=k3[i];
		list[i].LDPE=k2[i];
		list[i].idCliente = aIdCliente[i];
		list[i].id=id++;
		list[i].prendiente=aPendiente[i];
	}

}


/*
 * \brief Carga forzada de datos para la entidad Cliente
 * \param list Cliente*
 * \param len int
 */
void CargaForzadaCliente(aCliente *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"Telefonica","DATASOFT","NESTLE","TERRABUSI","DIA","QUILMES"};
	char aCuit[][QTY_CARACTERES]={"36-83253654-5","18-95375743-5","17-23178762-3","20-23298383-5","23-21898839-4","20-34558439-8"};
	char aDireccion[][QTY_CARACTERES]={"Lima 1234","Corrientes 2547","cucha cucha 555","rocha 784","Mitre 750","Crocha 741"};
	char aLocalidad[][QTY_CARACTERES]={"CABA","CABA","LANUS","QUILMES","AVELLANEDA","QUILMES"};
	int i;
	int id=0;
	for(i=0;i<6;i++){
		strncpy(list[i].nombre,aNombre[i],QTY_CARACTERES);
		strncpy(list[i].cuit,aCuit[i],QTY_CARACTERES);
		strncpy(list[i].direccion,aDireccion[i],QTY_CARACTERES);
		strncpy(list[i].localidad,aLocalidad[i],QTY_CARACTERES);
		list[i].id=id++;

	}

}



