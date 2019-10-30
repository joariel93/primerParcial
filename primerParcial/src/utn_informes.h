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
int utn_getMasReciclador(cliente cArray[],int limiteCliente,int* masReciclador);
int utn_getMenosReciclador(cliente cArray[],int limiteCliente,int* menosReciclador);
int utn_masMil(cliente cArray[],int limiteCliente,int* contadorMasMil);
int utn_menosCien(cliente cArray[],int limiteCliente,int* contadorMenosCien);
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos);
int utn_reportarPedidosCompletados(cliente cArray[],pedido pArray[],int limitePedidos, int limiteCliente);
int utn_pedidosPendientesPorLocalidad(cliente cArray[],int limiteCliente);
int utn_promedioPP(pedido pArray,int limitePedidos);
int utn_cantidadPlasticoPorCUIT(cliente cArray[],pedido pArray[],int limiteCliente,int limitePedidos);
#endif /* UTN_INFORMES_H_ */
