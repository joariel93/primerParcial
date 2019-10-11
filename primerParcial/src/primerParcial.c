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
utn_initSistemClientes(datosClientes,MAXCLIENTE);
utn_initSistemPedidos(datosPedido,MAXPEDIDOS);


}

