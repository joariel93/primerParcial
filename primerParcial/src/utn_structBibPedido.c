/*
 * utn_structBibPedido.c
 *
 *  Created on: 16 oct. 2019
 *      Author: joariel93
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"
#define SECURITY " fué el peso ingresado, confirma ingreso?"
int utn_initSistemPedidos(pedido pArray[],int limite)
{
int i;

	for(i=0;i<limite;i++)
		{
		pArray[i].estado=0;
		pArray[i].isEmpty=0;
		}
	return 0;
}
int utn_findFreePedido(pedido pArray[], int limite,int* posicion)
{
int retorno=-1;
int i;
	if(pArray!=NULL && limite>0 && posicion!=NULL)
	{
		for(i=0;i<limite;i++)
		{if(pArray[i].isEmpty==0)
		{
			*posicion=i;
			retorno=0;
			break;
		}



		}
	}
return retorno;
}
int utn_findPedidoById(pedido pArray[], int limite,int* posicion,int idEnviado)
{
int retorno=-1;
int i;
	for(i=0;i<limite;i++)
	{
		if(pArray!=NULL && limite>0	&&	posicion!=NULL &&	idEnviado>=0)
		{
			if(pArray[i].idPedido==idEnviado)
			{
				*posicion=i;
				retorno=0;
				return retorno;
				break;
			}

		}
	}
	printf("No se ha encontrado el número de legajo ingresado\n");
return retorno;
}
int utn_addPedido(cliente array[],pedido pArray[],int limiteClientes,int limitePedidos,int contador)
{
int posicion;
int retorno=-1;
float kilos;
int idClientes;
int empty[1]={0};
int seleccion;
int end=0;
int errorDatos=1;

 if(pArray!=NULL&&limitePedidos>0&&contador>=0)
 {
	 if(utn_findFreePedido(pArray,limitePedidos,&posicion)==-1)
	 {
		 printf("\n No hay lugares vacios");
	 }
	 else
	 {	while(end==0)
	 	 {	 utn_showClientes(array,limiteClientes);
		 	 printf("Pantalla de ingreso de datos:\n");
		 	 printf("[1] ID de cliente\n");
		 	 printf("[2] Volver\n");
		 	 __fpurge(stdin);
		 	 scanf("%d",&seleccion);
		 	 switch(seleccion)
		 	 {
		 	 case 1:	utn_agregaID(array,limiteClientes,&idClientes);
		 	 	 	 	pArray[posicion].idCliente=idClientes;
		 	 	 	 	utn_getFloat(&kilos,"Ingrese la cantidad de kilos a recolectar","Error debe ingresar un peso válido",0.1,5000,5);
		 	 	 	 	pArray[posicion].recolectado=kilos;
		 	 	 	 	empty[0]=1;
	 					break;

		 	 default:	utn_comprobePedido(empty,1,&errorDatos);
		 		 	 	if(errorDatos==1)
	 					{
	 					printf("Falta ingresar datos.");
	 					}
	 					else
	 					{
	 					pArray[posicion].isEmpty=1;
	 					pArray[posicion].estado=1;
	 					pArray[posicion].idPedido=contador;
	 					pArray[posicion].HDPE=0;
	 					pArray[posicion].LDPE=0;
	 					pArray[posicion].PP=0;
	 					array[idClientes].pedidos++;
	 					retorno=0;
	 					return retorno;
	 					}
		 		 	 	break;
		 	 }
 		 }
	 }
 }

return retorno;
}
int utn_procesarPedido(cliente arrayCliente[],pedido pArray[],int limite)
{
	int retorno = -1;
	int flag=0;
	int volver;
	int seleccion;
	float pesoMaximo;
	int posicion;
	int nPedido;
	int end = 0;
	int auxId;

	float newHDPE=0;
	float newLDPE=0;
	float newPP=0;
	while (end == 0)
	{	utn_showPedidosPendientes(pArray,limite);
		printf("[1] Ingresar el pedido a procesar:\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d", &volver);
		switch (volver)
		{
			case 2:	return 0;
					break;
			default:printf("Ingrese el numero de pedido que desea procesar: ");
					__fpurge(stdin);
					scanf("%d", &nPedido);
					if (utn_findPedidoById(pArray, limite, &posicion, nPedido) == 0&&flag==0)
					{
						pesoMaximo=pArray[posicion].recolectado;
						auxId=pArray[posicion].idCliente;
						printf("Ingrese los tipos de plásticos procesados del pedido %d quedan por asignar:\n", pArray[posicion].idPedido,pesoMaximo);
						printf("[1] Polietileno de alta densidad\n");
						printf("[2] Polietileno de baja densidad\n");
						printf("[3] Polipropileno\n");
						printf("[4] Volver\n");
						__fpurge(stdin);
						scanf("%d", &seleccion);
						switch (seleccion)
						{
							case 1:	utn_getFloat(&newHDPE,"Ingrese el peso de polietileno de alta densidad reciclado: ","Error debe ingresar un valor valido.",0,pesoMaximo,5);
									pArray[posicion].HDPE=newHDPE;
									pesoMaximo=pesoMaximo-newHDPE;
									if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
									{
										pArray[posicion].estado=2;
										arrayCliente[auxId].pedidos--;
										printf("me meti al if por algun motivo");
										return 0;
									}
									pArray[posicion].estado=2;
									arrayCliente[auxId].pedidos--;
									flag=1;
									printf("Me saltie el if, el pendiente de pedidos por procesar quedo en %d",arrayCliente[auxId].pedidos);
									break;
							case 2:	utn_getFloat(&newLDPE, "Ingrese la cantidad de Polietileno de baja densidad: ","Error debe ingresar un peso válido",0,pesoMaximo,5);
									pArray[posicion].LDPE=newHDPE;
									pesoMaximo=pesoMaximo-newLDPE;
									if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
									{
										pArray[posicion].estado=2;
										arrayCliente[auxId].pedidos--;
										flag=1;
									}
									break;

							case 3:	utn_getFloat(&newPP, "Ingrese la cantidad de Poliproleno: ","Error debe ingresar un peso válido",0,pesoMaximo,5);
									pArray[posicion].PP=newPP;
									pesoMaximo=pesoMaximo-newPP;
									if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
									{
										pArray[posicion].estado=2;
										arrayCliente[auxId].pedidos--;
										flag=1;
									}
									break;
							default:	if(pesoMaximo==pArray[posicion].recolectado)
										{
										pArray[posicion].estado=1;
										end=1;
										}
										else
										{
										pArray[posicion].estado=2;
										end=1;
										flag=1;
										}
										break;
						}
					}
					else
					{
						printf("Ingrese los tipos de plásticos procesados del pedido %d quedan por asignar:\n", pArray[posicion].idPedido,pesoMaximo);
												printf("[1] Polietileno de alta densidad\n");
												printf("[2] Polietileno de baja densidad\n");
												printf("[3] Polipropileno\n");
												printf("[4] Volver\n");
												__fpurge(stdin);
												scanf("%d", &seleccion);
												switch (seleccion)
												{
													case 1:	utn_getFloat(&newHDPE,"Ingrese el peso de polietileno de alta densidad reciclado: ","Error debe ingresar un valor valido.",0,pesoMaximo,5);
															pArray[posicion].HDPE=newHDPE;
															pesoMaximo=pesoMaximo-newHDPE;
															if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
															{
																pArray[posicion].estado=2;
																arrayCliente[auxId].pedidos--;
																printf("me meti al if por algun motivo");
																return 0;
															}
															pArray[posicion].estado=2;
															arrayCliente[auxId].pedidos--;
															printf("Me saltie el if, el pendiente de pedidos por procesar quedo en %d",arrayCliente[auxId].pedidos);
															break;
													case 2:	utn_getFloat(&newLDPE, "Ingrese la cantidad de Polietileno de baja densidad: ","Error debe ingresar un peso válido",0,pesoMaximo,5);
															pArray[posicion].LDPE=newHDPE;
															pesoMaximo=pesoMaximo-newLDPE;
															if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
															{
																pArray[posicion].estado=2;
																arrayCliente[auxId].pedidos--;
															}
															break;
													case 3:	utn_getFloat(&newPP, "Ingrese la cantidad de Poliproleno: ","Error debe ingresar un peso válido",0,pesoMaximo,5);
															pArray[posicion].PP=newPP;
															pesoMaximo=pesoMaximo-newPP;
															if(pesoMaximo<0||utn_compruebaPeso(pesoMaximo)==1)
															{
																pArray[posicion].estado=2;
																arrayCliente[auxId].pedidos--;
															}
															break;
													default:	if(pesoMaximo==pArray[posicion].recolectado)
																{
																pArray[posicion].estado=1;
																end=1;
																}
																else
																{
																pArray[posicion].estado=2;
																end=1;
																}
																break;
												}
					}
					break;
			}

		}

	retorno = 0;
	return retorno;

}
int utn_reportPedidosPendientes(cliente cArray[],pedido pArray[],int limite)
{
	int i;
	int auxId;

	printf("CUIT\tDirección\t\tKg. a recolectar\n");
	for(i=0;i<limite;i++)
	{
		auxId=pArray[i].idCliente;
		if(pArray[i].isEmpty==1&&pArray[i].estado==1&&cArray[auxId].isEmpty==1)
		{
			printf("%s\t%s\t\t%.2f\n",cArray[auxId].cuit,cArray[auxId].calle,pArray[i].recolectado);
		}else if(pArray[i].isEmpty==0)
		{
			continue;
		}
	}
	return 0;
}
int utn_reportPedidosProcesados(cliente array[],pedido pArray[],int limite)
{
	int i;
	printf("CUIT\tDirección\t\tHDPE reciclados\t\tLDPE reciclados\t\tPP reciclados\n");
	for(i=0;i<limite;i++)
	{
		if(pArray[i].isEmpty==1&&pArray[i].estado==2&&array[pArray[i].idCliente].isEmpty==1)
		{
			printf("%s\t%s\t\t%.2f\n",array[pArray[i].idCliente].cuit,array[pArray[i].idCliente].calle,pArray[i].recolectado);
		}else if(pArray[i].isEmpty==0)
		{
			continue;
		}
	}
	return 0;
}
int utn_comprobePedido(int pArray[],int limite,int *errorDatos)
{
	int i;
	for(i=0;i<limite;i++)
			 	 	 	 	{
			 		 	 		if(pArray[i]==0)
			 		 	 		{
			 		 	 		*errorDatos=1;
			 		 	 		break;
			 		 	 		}
			 		 	 		else
			 		 	 		{
			 		 	 		*errorDatos=0;
			 		 	 		continue;
			 		 	 		}
			 	 	 	 	}
	return 0;
}
int utn_agregaID(cliente show[],int limiteCliente,int* idCliente)
{
	int id;
	int idEnviado=idCliente;
	printf("Ingrese el numero de ID\n");
	__fpurge(stdin);
	scanf("%d",&idEnviado);
	utn_findClienteById(show,limiteCliente,&id,idEnviado);
	*idCliente=id;
	return 0;
}
int utn_showPedidosPendientes(pedido pArray[],int limitePedidos)
{
	int i;
	printf("ID Pedido\tID Cliente\tKilos\n");
			for(i=0;i<limitePedidos;i++)
			{
					if(pArray[i].isEmpty==1&&pArray[i].estado==1)
					{
						printf("%d\t%d\t%.2f\n",pArray[i].idPedido,pArray[i].idCliente,pArray[i].recolectado);
					}else if(pArray[i].isEmpty==0||pArray[i].estado!=1)
					{
						continue;
					}
			}
			return 0;
}
int utn_compruebaPeso(float pMax)
{
	if(pMax<=0)
		{
		printf("Se ha asigando el total de residuos del pedido");
		return 1;
		}
	return 0;
}

