#ifndef CLIENTES_H_
#define CLIENTES_H_
#define QTY_CLIENTES 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct {
	int id;
	char cuit[QTY_CARACTERES];
	char direccion[QTY_CARACTERES];
	char localidad[QTY_CARACTERES];
	char nombre[QTY_CARACTERES];
	int isEmpty;
}typedef aCliente;

int initCliente(aCliente *list, int len);
int findPlaceFreeCliente(aCliente *list, int len);
int findClienteById(aCliente *list, int len, int id);
int addCliente(aCliente *list, int len, aCliente item);
int removeCliente(aCliente *list, int len, int id);
int modifyClienteforId(aCliente *list, int len, aCliente item);
int printCliente(aCliente *list, int length);
int sortCliente(aCliente *list, int len, int order);
int printUI(aCliente* list,int len);
int addUI(aCliente *list, int len, int id);
int modifyUI(aCliente *list, int len);
int listForModify(aCliente item);
int removeUI(aCliente *list, int len);
int averageCliente(aCliente *list, int length);

#endif /* CLIENTES_H_ */

