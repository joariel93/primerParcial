/*
 * utn_structBibCliente.h
 *
 *  Created on: 16 oct. 2019
 *      Author: joariel93
 */

#ifndef UTN_STRUCTBIBCLIENTE_H_
#define UTN_STRUCTBIBCLIENTE_H_
struct cliente
{
	int id;
	char name[51];
	char cuit[14];
	char calle[30];
	char localidad[30];
	int pedidos;
	int isEmpty;
};
typedef struct cliente cliente;

int utn_initSistemCliente(cliente pArray[],int limite);
int utn_findFreeCliente(cliente pArray[],int limite,int* posicion);
int utn_findClienteById(cliente pArray[], int limite,int* posicion,int legajo);
int utn_addCliente(cliente pArray[],int limite,int contador,int nameLimit,int direcLimit,int cuitLimit);
int utn_modifyCliente(cliente pArray[],int limite, int stringLimit);
int utn_removeCliente(cliente pArray[],int limite);
int utn_comprobeCliente(int pArray[],int limite,int *errorDatos);
int utn_showClientes(cliente pArray[],int limite);
int utn_imprimirClientes(cliente pArray[],int limiteCliente);


#endif /* UTN_STRUCTBIBCLIENTE_H_ */
