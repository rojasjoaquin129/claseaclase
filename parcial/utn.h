#ifndef UTN_H_
#define UTN_H_
#define EXIT_ERROR -1

int esSoloLetras(char str[]);
int esNumerico(char str[]);
int esCuit(char str[]);

int getStringCuit (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos);

int getChar( char *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 char minimo,
			 char maximo,
			 int reintentos);

int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getNombre (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getStringNumeros (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);

void burbuja(int array[], int limite);

void insercion(int array[], int limite);



#endif /* UTN_H_ */
