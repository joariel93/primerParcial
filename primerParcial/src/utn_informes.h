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

int utn_getMasPendientes(cliente cArray[],int limiteCliente,int* masPedidosPendientes);
int utn_getMasCompletados(cliente cArray[], pedido pArray[],int limitePedidos,int limiteClientes,int* masPedidosCompletados);
int utn_getMasPedidosTotal(cliente cArray[], pedido pArray[],int limitePedidos,int limiteClientes,int* masPedidosTotal);
int utn_getMasReciclador(pedido pArray[],int limitePedidos,int* masReciclador,pedido auxPedidos[]);
int utn_getMenosReciclador(pedido pArray[],int limitePedidos,int* menosReciclador);
int utn_masMil(pedido pArray[],int limitePedidos,int* contadorMasMil);
int utn_menosCien(pedido pArray[],int limitePedidos,int* contadorMenosCien);
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos);
#endif /* UTN_INFORMES_H_ */
