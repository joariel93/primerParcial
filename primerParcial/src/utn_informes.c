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

int utn_masPedidosPendientes(cliente pArray[],int limiteCliente)
{
	cliente aux[limiteCliente];
	cliente aux2;
	int i,j;

	for(j=0;j<limiteCliente;j++)
	{
		aux[j].id=pArray[j].id;
		aux[j].pedidos=pArray[j].pedidos;
	}

	for(i=0;i<limiteCliente;i++)
	{
		if(aux[i].pedidos<aux[i+1].pedidos||aux[i].isEmpty==0)
		{
			aux2=aux[i];
			aux[i]=aux[i+1];
			aux[i+1]=aux2;
		}
		else
		{
			continue;
		}
	}

return aux[0].id;
}
int utn_masPedidosCompletados(pedido pArray[],int limite)
{
pedido aux[limite];
int guardaId[limite];
int auxID;
int i,j,k;

for(k=0;k<limite;k++)
{
	if(pArray[k].estado==2)
	{
		aux[k].estado=pArray[k].estado;
		aux[k].idCliente=pArray[k].idCliente;
	}
}
for(i=0;i<limite;i++)
{
	if(aux[i].estado==2)
	{
		for(j=0;j<(limite-1);j++)
		{
			if(aux[i].idCliente==aux[j].idCliente)
			{
				aux[j].estado=3;
				guardaId[j]++;
			}
			else
			{
				continue;
			}
		}
	}
}
for(i=0;i>limite;i++)
{
	if(guardaId[i]<guardaId[i+1])
	{
		auxID=guardaId[i];
		guardaId[i]=guardaId[i+1];
		guardaId[i+1]=auxID;
	}
}
return guardaId[0];
}
int utn_clienteMasPedidos(pedido pArray[],int limite)
{
pedido aux[limite];
int guardaId[limite];
int auxID;
int i,j,k;

for(k=0;k<limite;k++)
{
	if(pArray[k].estado>=1)
	{
		aux[k].estado=pArray[k].estado;
		aux[k].idCliente=pArray[k].idCliente;
	}
}
for(i=0;i<limite;i++)
{
	if(aux[i].estado>=1)
	{
		for(j=0;j<(limite-1);j++)
		{
			if(aux[i].idCliente==aux[j].idCliente)
			{
				aux[j].estado=0;
				guardaId[j]++;
			}
			else
			{
				continue;
			}
		}
	}
}
for(i=0;i>limite;i++)
{
	if(guardaId[i]<guardaId[i+1])
	{
		auxID=guardaId[i];
		guardaId[i]=guardaId[i+1];
		guardaId[i+1]=auxID;
	}
}
return guardaId[0];

}
int utn_clienteMasReciclador(pedido pArray[],int limite)
{
	return 0;
}
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos)
{
int IDmasPP;
int posMasPP;
int IDmasPC;
int posMasPC;
int IDmasP;
int posMasP;

IDmasPP=utn_masPedidosPendientes(cArray,limiteCliente);
posMasPP=utn_findClienteById(cArray,limiteCliente,&posMasPP,IDmasPP);
IDmasPC=utn_masPedidosCompletados(pArray,limitePedidos);
posMasPC=utn_findClienteById(cArray,limiteCliente,&posMasPC,IDmasPP);
IDmasP=utn_masPedidosCompletados(pArray,limitePedidos);
posMasP=utn_findClienteById(cArray,limiteCliente,&posMasP,IDmasP);


printf("El cliente con más pedidos pendientes es: %s con %d pedidos pendientes.\n",cArray[posMasPP].name,cArray[posMasPP].pedidos);
printf("El cliente con más pedidos completados es: %s con %d pedidos completados.\n",cArray[posMasPC].name,cArray[posMasPC].pedidos);
printf("El cliente con más pedidos solicitados es: %s con %d pedidos solicitados.\n",cArray[posMasP].name,cArray[posMasP].pedidos);
return 0;
}
