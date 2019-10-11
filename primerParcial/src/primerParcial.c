/*
 ============================================================================
 Name        : primerParcial.c
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

#define MAXCLIENTE 100
#define MAXPEDIDOS 1000
#define MAXCUIT 14
#define MAXDIRECCION 30
#define MAXNOMBRE 51
int main(void){
	cliente datosClientes[MAXCLIENTE];
	pedido datosPedido[MAXPEDIDOS];
	int contadorClientes=0;
	int contadorPedidos=0;
	int choice;
	int end=0;
	int flagCliente=0;
	int flagPedidos=0;
utn_initSistemClientes(datosClientes,MAXCLIENTE);
utn_initSistemPedidos(datosPedido,MAXPEDIDOS);

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
	printf("[9] Salir\n");
	__fpurge(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:	utn_reportPedidosProcesados(datosPedido,MAXPEDIDOS);
			break;
	default:	return 0;
				break;
	}

}


}

