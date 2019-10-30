/*
 ============================================================================
 Name        : primelParcialv1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"
#include "utn_informes.h"
#include "hardcodeo.h"

#define MAXCLIENTE 100
#define MAXPEDIDOS 1000
#define MAXCUIT 14
#define MAXDIRECCION 30
#define MAXNOMBRE 51
int main(void){
	cliente datosClientes[MAXCLIENTE];
	pedido datosPedido[MAXPEDIDOS];



	int contadorClientes=1;
	int contadorPedidos=1;
	int choice;
	int end=0;
	utn_initSistemCliente(datosClientes,MAXCLIENTE);
	utn_initSistemPedidos(datosPedido,MAXPEDIDOS);
	clientesHardcodeo(datosClientes,MAXCLIENTE);
	pedidosHardcodeados(datosPedido,MAXPEDIDOS);

	while(end==0)
	{
		printf("Bienvenido. ¿Que desea hacer?\n");
		printf("[1] Agregar cliente\n");
		printf("[2] Modificar cliente\n");
		printf("[3] Borrar cliente\n");
		printf("[4] Agregar pedido\n");
		printf("[5] Procesar pedido\n");
		printf("[6] Imprimir clientes\n");
		printf("[7] Imprimir pedidos pendientes\n");
		printf("[8] Imprimir pedidos procesados\n");
		printf("[9] Informes\n");
		printf("[10] Salir\n");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:		utn_addCliente(datosClientes,MAXCLIENTE,contadorClientes,MAXNOMBRE,MAXDIRECCION,MAXCUIT);
						contadorClientes++;
						break;
			case 2:		utn_modifyCliente(datosClientes,MAXCLIENTE,MAXDIRECCION);
						break;
			case 3:		utn_removeCliente(datosClientes,MAXCLIENTE);
						break;
			case 4:		utn_addPedido(datosClientes,datosPedido,MAXCLIENTE,MAXPEDIDOS,contadorPedidos);
						contadorPedidos++;
						break;
			case 5:		utn_procesarPedido(datosClientes,datosPedido,MAXPEDIDOS,MAXCLIENTE);
						break;
			case 6:		utn_imprimirClientes(datosClientes,MAXCLIENTE);
						break;
			case 7:		utn_reportPedidosPendientes(datosClientes,datosPedido,MAXPEDIDOS);
						break;
			case 8:		utn_reportPedidosProcesados(datosClientes,datosPedido,MAXPEDIDOS);
						break;
			case 9:		utn_informesParcial(datosClientes,datosPedido,MAXCLIENTE,MAXPEDIDOS);
						break;
			default:	return 0;
						break;
		}

	}
return 0;
}
