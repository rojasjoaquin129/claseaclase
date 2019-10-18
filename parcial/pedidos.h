#ifndef PEDIDO_H_
#define PEDIDO_H_
#define QTY_PEDIDOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#include "clientes.h"
struct {
	int id;
	int idCliente;
	int kilos;
	int HDPE;
	int LDPE;
	int PP;
	int prendiente;
	int isEmpty;

}typedef aPedido;

int altaPedidoUI (aPedido *list ,int len , aCliente *listClientes,int length);
int modificacionPedidoUI (aPedido *pedidos , int len);
int ordenarPedidoPorCliente(aPedido*aArray,int cantidad);
int modificarPedidoporId(aPedido *list, int len, aPedido item);
int printPedidos(aPedido *list, int length);
int initLugarLibrePedido(aPedido *aArray, int cantidad);
int buscarLugarLibrePedido(aPedido *aArray, int cantidad);
int buscarPedidoPorId(aPedido *aArray, int cantidad,int id);
int altaPedidoPorId(aPedido *aArray, int cantidad,aPedido item);
#endif /* PEDIDO_H_ */

