/*
 * utn_structBibPedido.h
 *
 *  Created on: 16 oct. 2019
 *      Author: joariel93
 */

#ifndef UTN_STRUCTBIBPEDIDO_H_
#define UTN_STRUCTBIBPEDIDO_H_
struct pedido
{
	int idPedido;
	int idCliente;
	float recolectado;
	int estado;
	float HDPE;
	float LDPE;
	float PP;
	float totalReciclado;
	int isEmpty;
};
typedef struct pedido pedido;
#include "utn_structBibCliente.h"

int utn_initSistemPedidos(pedido pArray[],int limite);
int utn_findFreePedido(pedido pArray[],int limite,int* posicion);
int utn_findPedidoById(pedido pArray[], int limite,int* posicion,int idEnviado);
int utn_addPedido(cliente array[],pedido pArray[],int limiteClientes,int limitePedidos,int contador);
int utn_procesarPedido(cliente arrayCliente[],pedido pArray[],int limite);
int utn_reportPedidosPendientes(cliente cArray[],pedido pArray[],int limite);
int utn_reportPedidosProcesados(cliente array[],pedido pArray[],int limite);
int utn_comprobePedido(int pArray[],int limite,int *errorDatos);
int utn_agregaID(cliente show[],int limiteCliente,int* idCliente);
int utn_showPedidosPendientes(pedido pArray[],int limitePedidos);
int utn_compruebaPeso(float pMax);


#endif /* UTN_STRUCTBIBPEDIDO_H_ */
