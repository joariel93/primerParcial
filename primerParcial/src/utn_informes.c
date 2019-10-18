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
	else
		aux[k].estado=0;
}
for(i=0;i<limite;i++)
{
	if(aux[i].estado==2)
	{
		for(j=1;j<(limite-1);j++)
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
int utn_recicladores(cliente cArray[],pedido pArray[],int limiteCliente,int limitePedidos,int*IDmas,int*posMas,int*IDmen,int*posMen,int*masMil,int*menCien)
{
cliente auxCliente[limiteCliente];
pedido auxPedidos[limitePedidos];
pedido filtraPedidos[limitePedidos];
pedido auxFiltraPedido;
float pesoTotal=0;
int i,j,k;
for(i=0;i<limiteCliente;i++)
{
	if(cArray[i].isEmpty==1)
	{
		auxCliente[i]=cArray[i];
	}
	else
	{
		continue;
	}
}
for(i=0;i>limitePedidos;i++)
{
	if(pArray[i].isEmpty==1)
	{
		auxPedidos[i]=pArray[i];
	}
	else
	{
		continue;
	}

}
for(j=0;j<limitePedidos;j++)
{
	for(k=1;k<limitePedidos-1;k++)
	{
		if(auxPedidos[j].idCliente==auxPedidos[k].idCliente)
		{
			filtraPedidos[j].idCliente=auxPedidos[j].idCliente;
			filtraPedidos[j].totalReciclado=auxPedidos[j].totalReciclado+auxPedidos[k].totalReciclado;
		}
		else
		{
			continue;
		}
	}

}
for(i=0;i<limitePedidos;i++)
{
	if(filtraPedidos[i].totalReciclado<filtraPedidos[i+1].totalReciclado)
	{
		auxFiltraPedido=filtraPedidos[i];
		filtraPedidos[i]=filtraPedidos[i+1];
		filtraPedidos[i+1]=auxFiltraPedido;
	}
}
IDmas=filtraPedidos[0].idCliente;
posMas=utn_findClienteById(cArray,limiteCliente,&posMas,IDmas);
for(i=0;i<limitePedidos;i++)
{
	if(filtraPedidos[i].totalReciclado>filtraPedidos[i+1].totalReciclado)
	{
		auxFiltraPedido=filtraPedidos[i];
		filtraPedidos[i]=filtraPedidos[i+1];
		filtraPedidos[i+1]=auxFiltraPedido;
	}
}
IDmen=filtraPedidos[0].idCliente;
posMen=utn_findClienteById(cArray,limiteCliente,&posMen,IDmen);
for(i=0;i<limitePedidos;i++)
{
	if(filtraPedidos[i].totalReciclado>1000)
	{
		masMil++;
	}
}
for(i=0;i<limitePedidos;i++)
{
	if(filtraPedidos[i].totalReciclado<100)
	{
		menCien++;
	}
}
	return 0;
}
int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos)
{
int IDmasPP,posMasPP;
int IDmasPC,posMasPC;
int IDmasP,posMasP;
int IDmasR,posMasR;
int IDmenR,posMenR;
int cMas1000=0;
int cMenos100=0;



IDmasPP=utn_masPedidosPendientes(cArray,limiteCliente);
posMasPP=utn_findClienteById(cArray,limiteCliente,&posMasPP,IDmasPP);
IDmasPC=utn_masPedidosCompletados(pArray,limitePedidos);
posMasPC=utn_findClienteById(cArray,limiteCliente,&posMasPC,IDmasPP);
IDmasP=utn_masPedidosCompletados(pArray,limitePedidos);
posMasP=utn_findClienteById(cArray,limiteCliente,&posMasP,IDmasP);
utn_recicladores(cArray,pArray,limiteCliente,limitePedidos,&IDmasR,&posMasR,&IDmenR,&posMenR,&cMas1000,&cMenos100);


printf("El cliente con más pedidos pendientes es: %s con %d pedidos pendientes.\n",cArray[posMasPP].name,cArray[posMasPP].pedidos);
printf("El cliente con más pedidos completados es: %s con %d pedidos completados.\n",cArray[posMasPC].name,cArray[posMasPC].pedidos);
printf("El cliente con más pedidos solicitados es: %s con %d pedidos solicitados.\n",cArray[posMasP].name,cArray[posMasP].pedidos);
printf("El cliente que mas kilos ha reciclado es: %s.\n",cArray[posMasR].name);
printf("El cliente que menos kilos ha reciclado es: %s.\n",cArray[posMenR].name);
printf("%d clientes han reciclado más de 1000 kilos.\n",cMas1000);
printf("%d clientes han reciclado menos de 100 kilos.\n",cMenos100);
return 0;
}
