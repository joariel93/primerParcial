/*
 * utn_informes.c
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"

int utn_getMasPendientes(cliente cArray[],int limiteCliente,int* masPedidosPendientes)
{
cliente auxClientes[limiteCliente];
cliente auxSwap;
int i;
int flag=0;

utn_getClienteAux(cArray,auxClientes,limiteCliente);
while(flag==0)
{
	flag=1;
	for(i=0;i<limiteCliente;i++)
	{
		if(auxClientes[i].isEmpty==1&&auxClientes[i+1].isEmpty==1)
		{
			if(auxClientes[i].pedidos<auxClientes[i+1].pedidos)
			{
				auxSwap=auxClientes[i];
				auxClientes[i]=auxClientes[i+1];
				auxClientes[i+1]=auxSwap;
				flag=0;
			}
		}else if(auxClientes[i].isEmpty==0&&auxClientes[i+1].isEmpty==1)
		{
			auxSwap=auxClientes[i];
			auxClientes[i]=auxClientes[i+1];
			auxClientes[i+1]=auxSwap;
			flag=0;
		}else
		{
			continue;
		}

	}
}
masPedidosPendientes=auxClientes[0].id;
	return 0;
}
int utn_getMasCompletados(cliente cArray[], pedido pArray[],int limitePedidos,int limiteClientes,int* masPedidosCompletados)
{
cliente auxCliente[limiteClientes];
cliente auxSwap;
int i;
int posCliente;
int flag=0;
utn_getClienteAux(cArray,auxCliente,limiteClientes);
utn_limpiarPedidosClientes(auxCliente,limiteClientes);

for(i=0;i<limitePedidos;i++)
{
	if(pArray[i].estado==2)
	{
		utn_findClienteById(auxCliente,limiteClientes,&posCliente,pArray[i].idCliente);
		auxCliente[posCliente].pedidos++;
	}
}
while(flag==0)
{
	flag=1;
	for(i=0;i<limiteClientes;i++)
	{
		if(auxCliente[i].isEmpty==1&&auxCliente[i+1].isEmpty==1)
		{
			if(auxCliente[i].pedidos<auxCliente[i+1].pedidos)
			{
				auxSwap=auxCliente[i];
				auxCliente[i]=auxCliente[i+1];
				auxCliente[i+1]=auxSwap;
				flag=0;
			}
		}else if(auxCliente[i].isEmpty==0&&auxCliente[i+1].isEmpty==1)
		{
			auxSwap=auxCliente[i];
			auxCliente[i]=auxCliente[i+1];
			auxCliente[i+1]=auxSwap;
			flag=0;
		}else
		{
			continue;
		}
	}
}
masPedidosCompletados=auxCliente[0].id;
	return 0;
}
int utn_getMasPedidosTotal(cliente cArray[], pedido pArray[],int limitePedidos,int limiteClientes,int* masPedidosTotal)
{
	cliente auxCliente[limiteClientes];
	cliente auxSwap;
	int i;
	int flag=0;
	int posCliente;

	utn_getClienteAux(cArray,auxCliente,limiteClientes);

	for(i=0;i<limitePedidos;i++)
	{
		if(pArray[i].estado==2)
		{
			utn_findClienteById(auxCliente,limiteClientes,&posCliente,pArray[i].idCliente);
			auxCliente[posCliente].pedidos++;
		}
	}

	while(flag==0)
	{
		flag=1;
		for(i=0;i<limiteClientes;i++)
		{
			if(auxCliente[i].isEmpty==1&&auxCliente[i+1].isEmpty==1)
			{
				if(auxCliente[i].pedidos<auxCliente[i+1].pedidos)
				{
					auxSwap=auxCliente[i];
					auxCliente[i]=auxCliente[i+1];
					auxCliente[i+1]=auxSwap;
					flag=0;
				}
			}else if(auxCliente[i].isEmpty==0&&auxCliente[i+1].isEmpty==1)
			{
				auxSwap=auxCliente[i];
				auxCliente[i]=auxCliente[i+1];
				auxCliente[i+1]=auxSwap;
				flag=0;
			}else
			{
				continue;
			}
		}
	}
masPedidosTotal=auxCliente[0].id;
	return 0;
}
int utn_getMasReciclador(pedido pArray[],int limitePedidos,int* masReciclador,pedido auxPedidos[])
{
	int i;
	int flag=0;
	pedido auxSwap;

	utn_getPedidoAux(pArray,auxPedidos,limitePedidos);
	utn_limpiarRecolectado(auxPedidos,limitePedidos);
	utn_sumarCategoriasPlasticos(auxPedidos,limitePedidos);

	while(flag==0)
	{
		flag=1;
		for(i=0;i<limitePedidos;i++)
		{
			if()
		}
	}

	return 0;
}
int utn_getMenosReciclador(pedido pArray[],int limitePedidos,int* menosReciclador);
int utn_masMil(pedido pArray[],int limitePedidos,int* contadorMasMil);
int utn_menosCien(pedido pArray[],int limitePedidos,int* contadorMenosCien);
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos)
{
pedido auxPedidos[limitePedidos];
int masPedidosPendientes=0;
int masPedidosCompletados=0;
int masPedidosTotal=0;
int masReciclador=0;
int menosReciclador=0;
int posMasPP;
int posMasPC;
int posMasPT;
int posMasR;
int posMenR;
int contadorMasMil=0;
int contadorMenosCien=0;

utn_getMasPendientes(cArray,limiteCliente,&masPedidosPendientes);
utn_getMasCompletados(cArray,pArray,limitePedidos,limiteCliente,&masPedidosCompletados);
utn_getMasPedidosTotal(cArray,pArray,limitePedidos,limiteCliente,&masPedidosTotal);
utn_getMasReciclador(pArray,limitePedidos,&masReciclador,auxPedidos);
utn_getMenosReciclador(auxPedidos,limitePedidos,&menosReciclador);
utn_masMil(auxPedidos,limitePedidos,&contadorMasMil);
utn_menosCien(auxPedidos,limitePedidos,&contadorMenosCien);




return 0;
}
