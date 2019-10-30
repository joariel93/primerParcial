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
*masPedidosPendientes=auxClientes[0].id;
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
*masPedidosCompletados=auxCliente[0].id;
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
*masPedidosTotal=auxCliente[0].id;
	return 0;
}
int utn_getMasReciclador(cliente cArray[],int limiteCliente,int* masReciclador)
{
	cliente aux[limiteCliente];
	int i;
	int flag=0;
	int flag2=0;
	float nuevoMaximo;
	int idMaximo=0;

	utn_getClienteAux(cArray,aux,limiteCliente);

	while(flag==0)
	{
		flag=1;
		for(i=0;i<limiteCliente;i++)
		{
			if(aux[i].reciclado>nuevoMaximo||flag2==0)
			{
				printf("Llegue al if del swap");
				nuevoMaximo=aux[i].reciclado;
				idMaximo=aux[i].id;
				flag=0;
				flag2=1;
			}
		}
	}
*masReciclador=idMaximo;
	return 0;
}
int utn_getMenosReciclador(cliente cArray[],int limiteCliente,int* menosReciclador)
{

	cliente aux[limiteCliente];
	int i;
		int flag=0;
		int flag2=0;
		float nuevoMinimo;
		int idMinimo;

		utn_getClienteAux(cArray,aux,limiteCliente);

		while(flag==0)
		{
			flag=1;
			for(i=0;i<limiteCliente;i++)
			{
				if(aux[i].reciclado<nuevoMinimo&&flag2==0)
				{
					nuevoMinimo=aux[i].reciclado;
					idMinimo=aux[i].id;
					flag=0;
					flag2=1;
				}else if(aux[i].reciclado<nuevoMinimo)
				{
					nuevoMinimo=aux[i].reciclado;
					idMinimo=aux[i].id;
					flag=0;
				}
			}
		}
	*menosReciclador=idMinimo;
	return 0;
}
int utn_masMil(cliente cArray[],int limiteCliente,int* contadorMasMil)
{
	int contador=0;
	int i;
	for(i=0;i<limiteCliente;i++)
		{
				if(cArray[i].reciclado>1000)
				{
					contador++;
				}
			}

	*contadorMasMil=contador;
	return 0;
}
int utn_menosCien(cliente cArray[],int limiteCliente,int* contadorMenosCien)
{
	int contador=0;
		int i;
		for(i=0;i<limiteCliente;i++)
			{
					if(cArray[i].reciclado<100&&cArray[i].isEmpty==1&&cArray[i].pedidos==0)
					{
						contador++;
					}
				}

		*contadorMenosCien=contador;
		return 0;
}
int utn_reportarPedidosCompletados(cliente cArray[],pedido pArray[],int limitePedidos, int limiteCliente)
{
	int i;
	int posicionCliente;
	int idCliente;
	float reciclado;

	printf("\nPedidos completados\n");
	printf("ID pedido\tCUIT cliente\tporcentaje de plastico reciclado\n");

	for(i=0;i<limitePedidos;i++)
	{
		if(pArray[i].estado==2)
		{
			idCliente=pArray[i].idCliente;
			utn_findClienteById(cArray,limiteCliente,&posicionCliente,idCliente);
			reciclado=cArray[posicionCliente].reciclado/pArray[i].recolectado*100;
			printf("%d\t%s\t%.2f\n",pArray[i].idPedido,cArray[posicionCliente].cuit,reciclado);

		}
	}

	return 0;
}
int utn_pedidosPendientesPorLocalidad(cliente cArray[],int limiteCliente)
{
	char localidad[20];
	int pedPend;
	int i;
	fgets(localidad,20,stdin);

		for(i=0;i<limiteCliente;i++)
		{
			if(strcmp(localidad,cArray[i].localidad)==0)
			{
				pedPend=pedPend+cArray[i].pedidos;
			}

		}
	printf("En la localidad %s hay %d pedidos pendientes.\n",localidad,pedPend);
	return 0;
}
int utn_promedioPP(pedido pArray[],int limitePedidos)
{
	pedido aux[limitePedidos];
	int i;
	float acumulador=0;
	int contadorCliente=0;

	float promedio;

	for(i=0;i<limitePedidos;i++)
	{
		if(aux[i].PP>0&&aux[i].estado==2)
		{
			contadorCliente++;
			acumulador=acumulador+aux[i].PP;

		}
	}
	promedio=acumulador/(float)contadorCliente;

	printf("La cantidad de kilos de polipropileno reciclado promedio por cliente es %.2f\n",promedio);

	return 0;
}

int utn_cantidadPlasticoPorCUIT(cliente cArray[],pedido pArray[],int limiteCliente,int limitePedidos)
{
	char CUITBuscado[14];
	float kilosReciclados=0;
	char plastico;
	int pos;
	int i;
	int idCliente=NULL;
	int tipoPlastico;
	int flag=1;
	pedido aux[limitePedidos];
	utn_getPedidoAux(pArray,aux,limitePedidos);


	while(flag==1)
	{
		fgets(CUITBuscado,14,stdin);
			for(i=0;i<limiteCliente;i++)
			{
				if(strcmp(CUITBuscado,cArray[i].cuit)==0)
				{
					idCliente=cArray[i].id;
					flag=0;
					break;
				}
			}
			if(idCliente==NULL)
			{
				printf("El CUIT ingresado no corresponde a un cliente. Intente nuevamente\n");
				flag=1;
			}
	}

	utn_getInt(&tipoPlastico,"Ingrese el tipo de plastico (1 HDPE-2 LDPE-3 PP","Error, favor de ingresar uno de los tipos de plastico",1,3,5);

	for(i=0;i<limitePedidos;i++)
	{
		if(aux[i].idCliente==idCliente)
		{
			if(tipoPlastico==1)
			{
				kilosReciclados=kilosReciclados+aux[i].HDPE;
				plastico="HDPE";
			}
			else if(tipoPlastico==2)
			{
				kilosReciclados=kilosReciclados+aux[i].LDPE;
				plastico="LDPE";
			}
			else
			{
				kilosReciclados=kilosReciclados+aux[i].PP;
				plastico="  PP";
			}

		}

	}
	utn_findClienteById(cArray,limiteCliente,&pos,idCliente);

	printf("El cliente %s ha reciclado %.2f kilos de %s",cArray[pos].name,kilosReciclados,plastico);


	return 0;
}

int utn_informesParcial(cliente cArray[],pedido pArray[], int limiteCliente,int limitePedidos)
{
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
int end=0;
int choice;
cliente auxCliente[limiteCliente];
cliente auxCliente2[limiteCliente];
utn_getClienteAux(cArray,auxCliente,limiteCliente);
utn_getClienteAux(auxCliente,auxCliente2,limiteCliente);






utn_getMasPendientes(cArray,limiteCliente,&masPedidosPendientes);
utn_getMasCompletados(cArray,pArray,limitePedidos,limiteCliente,&masPedidosCompletados);
utn_getMasPedidosTotal(cArray,pArray,limitePedidos,limiteCliente,&masPedidosTotal);
utn_getMasReciclador(auxCliente,limiteCliente,&masReciclador);
utn_getMenosReciclador(auxCliente,limiteCliente,&menosReciclador);
utn_masMil(auxCliente,limiteCliente,&contadorMasMil);
utn_menosCien(auxCliente,limiteCliente,&contadorMenosCien);

utn_findClienteById(cArray,limiteCliente,&posMasPP,masPedidosPendientes);
utn_findClienteById(cArray,limiteCliente,&posMasPC,masPedidosCompletados);
utn_findClienteById(cArray,limiteCliente,&posMasPT,masPedidosTotal);
utn_findClienteById(cArray,limiteCliente,&posMasR,masReciclador);
utn_findClienteById(cArray,limiteCliente,&posMenR,menosReciclador);






while(end==0)
	{
		printf("Bienvenido. ¿Que desea hacer?\n");
		printf("[1] Cliente con mas pedidos pendientes\n");
		printf("[2] Cliente con mas pedidos completados\n");
		printf("[3] Cliente con mas pedidos (Total)\n");
		printf("[4] Cliente que mas ha reciclado\n");
		printf("[5] Cliente que menos ha reciclado\n");
		printf("[6] Cantidad de clientes que han reciclado mas de 1000kg\n");
		printf("[7] Cantidad de cliente que han reciclado menos de 100kg\n");
		printf("[8] Pedidos completados con porcentaje de reciclaje\n");
		printf("[9] Buscar pedidos pendientes por localidad\n");
		printf("[10] Cantidad de kilos de polipropileno reciclado promedio por cliente\n");
		printf("[11] Buscar por CUIT y tipo de plastico\n");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:		printf("El cliente con mas pedidos pendientes es %s con %d pedidos pendientes.\n",cArray[posMasPP].name,cArray[posMasPP].pedidos);
						break;
			case 2:		printf("El cliente con mas pedidos completados es %s.\n",cArray[posMasPC].name);
						break;
			case 3:		printf("El cliente con mas pedidos es %s.\n",cArray[posMasPT].name);
						break;
			case 4:		printf("El cliente que mas ha reciclado es %s.\n",cArray[posMasR].name);
						break;
			case 5:		printf("El cliente que menos ha reciclado es %s.\n",cArray[posMenR].name);
						break;
			case 6:		printf("%d han reciclado mas de 1000kg.\n",contadorMasMil);
						break;
			case 7:		printf("%d han reciclado menos de 100kg.\n",contadorMenosCien);
						break;
			case 8:		utn_reportarPedidosCompletados(cArray,pArray,limitePedidos,limiteCliente);
						break;
			case 9:		utn_pedidosPendientesPorLocalidad(auxCliente2,limiteCliente);
						break;
			case 10:	utn_promedioPP(pArray,limitePedidos);
						break;
			case 11:	utn_cantidadPlasticoPorCUIT(auxCliente2,pArray,limiteCliente,limitePedidos);
						break;
			default:	return 0;
						break;
		}

	}

return 0;
}
