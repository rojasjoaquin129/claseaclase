#ifndef INFORMES_H_
#define INFORMES_H_
#define QTY_PEDIDOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

int contarClientekilosCompletados(aPedido *list, int length,int id,float *porsentaje);
int printCantidadDePedidosCompletados (aPedido* list,int length,aCliente*listCliente,int len);


int printClientesCantidadKilos (aPedido* list,int length,aCliente*listCliente,int len);
int printClientesCantidadMenosKilos (aPedido* list,int length,aCliente*listCliente,int len);
int printMenorClienteporKilos (aPedido* list,int length,aCliente*listCliente,int len);
int contarClientekilos(aPedido *list, int length,int id);
int printMayorClienteporKilos (aPedido* list,int length,aCliente*listCliente,int len);
int printmayorDePedidosTotales (aPedido* list,int length,aCliente*listCliente,int len);
int contarMaspediddosPorId(aPedido *list, int length,int id);
int printPedidosporclientes (aPedido* list,int length,aCliente*listCliente,int len,int estado);
int buscarclientesPorPedidos(aCliente *list, int len,int id);
int contarPedidoPorId(aPedido *list, int length,int id,int estado);
int printCantidadDePedidos (aPedido* list,int length,aCliente*listCliente,int len,int estado);
int printMayorDePedidos (aPedido* list,int length,aCliente*listCliente,int len,int estado);
#endif /* IMFORMES_H_ */
