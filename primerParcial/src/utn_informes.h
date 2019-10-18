/*
 * utn_informes.h
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_INFORMES_H_
#define UTN_INFORMES_H_
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"

int utn_masPedidosPendientes(cliente pArray[],int limiteCliente);
int utn_masPedidosCompletados(pedido pArray[],int limite);
int utn_clienteMasPedidos(pedido pArray[],int limite);
int utn_clienteMasReciclador(cliente cArray[],pedido pArray[],int limiteCliente,int limitePedidos);
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos);
#endif /* UTN_INFORMES_H_ */
