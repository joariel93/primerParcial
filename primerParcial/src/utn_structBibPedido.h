/*
 * structBib.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_STRUCTBIBPEDIDO_H_
#define UTN_STRUCTBIBPEDIDO_H_

typedef struct
{
	int idPedido;
	int idCliente;
	float recolectado;
	int estado;
	float HDPE;
	float LDPE;
	float PP;
	int isEmpty;
}pedido;
#include "utn_structBibCliente.h"
int utn_initSistemPedidos(pedido pArray[],int limite);
int utn_findFreePedido(pedido pArray[],int limite,int* posicion);
int utn_findPedidoById(pedido pArray[], int limite,int* posicion,int idEnviado);
int utn_addPedido(pedido pArray[],int limite,int contador);
int utn_procesarPedido(pedido pArray[],int limite);
int utn_reportPedidosPendientes(pedido pArray[],int limite);
int utn_reportPedidosProcesados(pedido pArray[],int limite);
int utn_comprobe(int pArray[],int limite,int *errorDatos);
int utn_agregaID(cliente show[],int limiteCliente,int* idCliente);
int utn_showPedidosPendientes(pedido pArray[],int limitePedidos);
int utn_compruebaPeso(float*pMax);

#endif /* UTN_STRUCTBIBPEDIDO_H_ */
