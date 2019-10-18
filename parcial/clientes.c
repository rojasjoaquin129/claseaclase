#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "utn.h"

/* \brief Genera un id autoincremental
* \return int
*
*/
static int generarId(void){
	static int id = 0;
	id++;
	return id;
}



/* \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initCliente(aCliente *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
/* \brief To indicate FREE  position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int findPlaceFreeCliente(aCliente *list, int len) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == STATUS_EMPTY) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/* \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */

int findClienteById(aCliente *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == STATUS_NOT_EMPTY) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/* \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/

int addCliente(aCliente *list, int len,aCliente item) {
	int retorno = -1;
		int index;
		if(list!=NULL && len>0)
		{
			index = findPlaceFreeCliente(list, len);
			if(index>=0)
			{
				list[index] = item;
				list[index].isEmpty = STATUS_NOT_EMPTY;
				list[index].id = generarId();
				retorno = 0;

		}
	}
	return retorno;
}

/* \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 *
 */
int removeCliente(aCliente *list, int len, int id) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = findClienteById(list, len, id);
		if (index != -1) {
			list[index].isEmpty = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
/* \brief modify a Employee by Id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 */

int modifyClienteforId(aCliente *list, int len, aCliente item) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = findClienteById(list, len, item.id);
		if (index != -1) {
			list[index] = item;
			list[index].isEmpty = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/*\brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printCliente(aCliente *list, int length) {
	int i;
	int retorno = -1;
	if (list != NULL && length > 0) {
		retorno = 0;
		printf("id     Nombre    Cuit    Direccion     Localidad\n");
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == STATUS_NOT_EMPTY) {
				printf("%d -- %s -- %s -- %s -- %s \n", list[i].id,
						list[i].nombre, list[i].cuit, list[i].direccion,
						list[i].localidad);
			}

		}
	}
	return retorno;
}

int addUI(aCliente*list, int len, int id) {
	aCliente bList;
	int retorno = -1;
	printf("ALTA\n");
	if (findPlaceFreeCliente(list, len) == -1) {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	} else {
		if (getNombre(bList.nombre, "Ingrese nombre\n", "Error\n", 1, 50, 3)
				!= -1) {
			if (getStringCuit(bList.cuit, "Ingrese cuit\n", "Error\n",10,
					14, 3) == 0) {
				if (getString(bList.direccion,
						"Ingese direccion de dicho cliente\n", "Error\n", 1,
						50, 3) != -1) {
					if (getNombre(bList.localidad, "Ingrese localidad \n",
							"Error\n", 1, 50, 3) != -1) {
						if (addCliente(list, len,bList)
								== 0) {
							printf("Alta exitosa\n");
							retorno = 0;
						}
					}
				}
			}
		}
	}
	if (retorno != 0) {
		printf("Error al cargar los datos\n");
	}
	return retorno;
}

int modifyUI(aCliente *list, int len) {
	aCliente bList;
	int idIn;
	int posicion;
	int retorno = -1;
	printf("Modificacion de cliente\n");
	getInt(&idIn, "Ingrese el id para modificar\n", "Error\n", 0, 100000, 3);
	posicion = findClienteById(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		bList = list[posicion];
		printf("id     Nombre    cuit    direccion     Localidad\n");
		printf("%d -- %s -- %s -- %s -- %s \n", list[posicion].id,
				list[posicion].nombre, list[posicion].cuit,
				list[posicion].direccion, list[posicion].localidad);
		if (listForModify(bList) == 0) {
			if (modifyClienteforId(list, len, bList) == 0) {
				printf("Modificacion exitosa\n");
				retorno = 0;
			}
		}
	}
	if (retorno != 0) {
		printf("error al modificar los datos\n");
	}
	return retorno;
}

int listForModify(aCliente item) {
	int lista;
	int retorno = -1;
	char conf;

	do {
		printf("\n"
				"1.  Modificar Direccion\n"
				"2.  Modificar Localidad\n"
				"3.  Confirmar Modificacion\n");
		getInt(&lista, "\nIngrese la opcion \n", "Error\n", 1, 5, 3);
		switch (lista) {
		case 1:
			if (getString(item.direccion, "Ingrese la nueva direccion\n", "Error\n", 1, 50, 3)
					== -1) {
				printf("Error en la direccion\n");
				break;
			}

			break;
		case 2:
			if (getNombre(item.localidad, "Ingrese la nueva localidad\n", "Error", 1,
					50, 2) == -1) {
				printf("Error en la localidad \n");
				break;
			}
			break;
		case 3:
			printf("%d -- %s -- %s -- %s -- %s \n", item.id, item.nombre,
					item.cuit, item.direccion, item.localidad);
			printf("Esta seguro de la  modificacion ? S/N\n");
			getChar(&conf, "Ingrese s para confirmar la modificacion\n",
					"Error\n", 'a', 'z', 3);
			if (conf != 's' && conf != 'n') {
				printf("Error al ingresar");
			}
			if (conf == 's') {
				retorno = 0;
			}
			break;
		default:
			printf("ERROR , eleccion no corresponde \n");
			break;
		}
	} while (conf != 's' && conf != 'n');
	return retorno;
}

int removeUI(aCliente *list, int len) {
	int idIn;
	int posicion;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&idIn, "Ingrese el id para dar de baja\n", "Error\n", 1, 100000, 30);
	posicion = findClienteById(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		printf("%d -- %s -- %s -- %s -- %s \n", list[posicion].id,
				list[posicion].nombre, list[posicion].cuit,
				list[posicion].direccion, list[posicion].localidad);
		getChar(&conf, "Ingrese s para confirmar la baja\n", "Error\n", 'a',
				'z', 2);
		if (conf == 's' || conf == 'S') {
			if (removeCliente(list, len, idIn) == 0) {
				printf("Baja exitosa\n");
				retorno = 0;
			}
		}
	}
	if (retorno != 0) {
		printf("error  al dar el baja \n");
	}
	return retorno;
}
