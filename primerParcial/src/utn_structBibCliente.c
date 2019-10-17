/*
 * utn_structBibCliente.c
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

#define SECURITY "Esta seguro de querer modificar la "
int utn_initSistemCliente(cliente pArrayCliente[],int limite)
{
int i;
	for(i=0;i<limite;i++)
	{
	pArrayCliente[i].pedidos=0;
	pArrayCliente[i].isEmpty=0;
	}

	return 0;
}
int utn_findFreeCliente(cliente pArray[], int limite,int* posicion)
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
int utn_findClienteById(cliente pArray[], int limite,int* posicion,int idEnviado)
{
int retorno=-1;
int i;
	for(i=0;i<limite;i++)
	{
		if(pArray!=NULL && limite>0	&&	posicion!=NULL &&	idEnviado>=0)
		{
			if(pArray[i].id==idEnviado)
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
int utn_addCliente(cliente pArray[],int limite,int contador,int nameLimit,int direcLimit,int cuitLimit)
{
char names[nameLimit];
int posicion;
int retorno=-1;
char icuit[cuitLimit];
char direccion[direcLimit];
int empty[4]={0,0,0,0};
int seleccion;
int end=0;
int errorDatos=1;

 if(pArray!=NULL&&limite>0&&contador>=0)
 {
	 if(utn_findFreeCliente(pArray,limite,&posicion)==-1)
	 {
		 printf("\n No hay lugares vacios");
	 }
	 else
	 {	while(end==0)
	 	 {	 printf("Pantalla de ingreso de datos:\n");
		 	 printf("[1] Razón social\n");
		 	 printf("[2] CUIT\n");
		 	 printf("[3] Dirección\n");
		 	 printf("[4] Localidad\n");
		 	 printf("[5] Volver\n");
		 	 __fpurge(stdin);
		 	 scanf("%d",&seleccion);
		 	 switch(seleccion)
		 	 {
		 	 case 1:	utn_getString(names,"Ingrese la razón social: ","Error debe ingresar caracteres alfabéticos",nameLimit,nameLimit);
		 	 	 	 	strncpy(pArray[posicion].name,names,nameLimit);
		 	 	 	 	empty[0]=1;
	 					break;
		 	 case 2:	utn_getStringCUIT(icuit,"Ingrese el numero de CUIT sin guiones: ","Error solo debe ingresar numeros",cuitLimit,cuitLimit);
		 	 	 	 	 printf("Sali de la funcion me traje %s",icuit);
		 	 	 	 	strncpy(pArray[posicion].cuit,icuit,cuitLimit);
		 	 	 	 	printf("Hago la copia, el cuit es %s",pArray[posicion].cuit);
		 	 	 	 	empty[1]=1;
	 					break;
		 	 case 3:	utn_getString(direccion,"Ingrese la dirección: ","Error debe ingresar caracteres alfabéticos",nameLimit,nameLimit);
	 	 	 			strncpy(pArray[posicion].calle,direccion,direcLimit);
		 	 	 	 	empty[2]=1;
	 					break;
		 	 case 4:	utn_getString(direccion,"Ingrese la localidad: ","Error debe ingresar caracteres alfabéticos",nameLimit,nameLimit);
	 	 	 			strncpy(pArray[posicion].localidad,direccion,direcLimit);
		 	 	 	 	empty[3]=1;
	 					break;
		 	 default:	utn_comprobeCliente(empty,4,&errorDatos);
		 		 	 	if(errorDatos==1)
	 					{
	 					printf("Falta ingresar datos.\n");
	 					}
	 					else
	 					{
	 					pArray[posicion].isEmpty=1;
	 					pArray[posicion].id=contador;
	 					retorno=0;
	 					return retorno;
	 					}
		 	 }
 		 }
	 }
 }

return retorno;
}
int utn_modifyCliente(cliente pArray[],int limite,int stringLimit)
{	cliente aux[limite];
	int retorno = -1;
	int volver;
	int seleccion;
	int posicion;
	int legajo;
	int end = 0;
	int definitiveModification = 0;
	char newDireccion[stringLimit];

	while (end == 0)
	{
		printf("[1] Ingresar ID de cliente a modificar\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d", &volver);
		switch (volver)
		{
			case 2:	return 0;
					break;
			default:utn_showClientes(pArray,limite);
					printf("Ingrese el numero de legajo del cliente que desea modificar: ");
					__fpurge(stdin);
					scanf("%d", &legajo);
					if (utn_findClienteById(pArray, limite, &posicion, legajo) == 0)
					{
						printf("Que desea modificar a %s:\n", pArray[posicion].name);
						printf("[1] Direccion\n");
						printf("[2] Localidad\n");
						printf("[3] Volver\n");
						__fpurge(stdin);
						scanf("%d", &seleccion);
						switch (seleccion)
						{
							case 1:	utn_getString(newDireccion, "Ingrese nueva dirección: ","Error ha superado la cantidad de caracteres(30).", stringLimit,stringLimit);
									while (definitiveModification == 0)
									{
										printf("%s dirección de %s a %s?\n", SECURITY,aux[posicion].calle, newDireccion);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	strncpy(aux[posicion].calle, newDireccion, stringLimit);
													strncpy(pArray[posicion].calle, aux[posicion].calle, stringLimit);
													end=1;
													break;
											case 2:	break;
										}
									}
									break;
							case 2:	utn_getString(newDireccion, "Ingrese nueva localidad: ","Error ha superado la cantidad de caracteres(30)", stringLimit, stringLimit);
									while (definitiveModification == 0)
									{
										printf("%s localidad de %s a %s?\n", SECURITY,aux[posicion].localidad, newDireccion);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	strncpy(aux[posicion].localidad, newDireccion,stringLimit);
													strncpy(pArray[posicion].localidad, aux[posicion].localidad, stringLimit);
													end=1;
													break;
											case 2:	break;
										}
									}
									break;

							default:break;
						}
					}
					break;
			}

		}

	retorno = 0;
	return retorno;

}
int utn_removeCliente(cliente pArray[],int limite)
{
int end=0;
int legajo;
int volver;
int delete=0;
int seleccion;
int definitiveModification=0;
int posicion;
while (end == 0)
	{
		printf("[1] Ingresar id de cliente a eliminar\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d", &volver);
		switch (volver)
		{
			case 2:	return 0;
					break;
			default:printf("Ingrese el numero de id de cliente que desea eliminar: ");
					__fpurge(stdin);
					scanf("%d", &legajo);
					if (utn_findClienteById(pArray, limite, &posicion, legajo) == 0)
					{
						printf("Desea eliminar a %s\n",pArray[posicion].name);
						printf("[1] Si\n[2] No\n");
						__fpurge(stdin);
						scanf("%d", &seleccion);
						switch (seleccion)
						{
							case 1:	while (definitiveModification == 0)
									{
										printf("Confirme su decision\n");
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	pArray[posicion].isEmpty = delete;

													end=1;
													break;
											case 2:	break;
										}
									}
						}
					}
		}
	}

return 0;
}
int utn_comprobeCliente(int pArray[],int limite,int *errorDatos)
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
int utn_showClientes(cliente pArray[],int limite)
{
	int i;
	printf("ID\tRazón Social\n");
		for(i=0;i<limite;i++)
		{
				if(pArray[i].isEmpty==1)
				{
					printf("%d\t%s\n",pArray[i].id,pArray[i].name);
				}else if(pArray[i].isEmpty==0)
				{
					continue;
				}
		}
		return 0;
}
int utn_imprimirClientes(cliente pArray[],int limiteCliente)
{
	int i;
		printf("ID\tRazón Social\t\tC.U.I.T\tDireccion\t\tLocalidad\t\tCant. de ped. pendientes\n");
			for(i=0;i<limiteCliente;i++)
			{
					if(pArray[i].isEmpty==1)
					{
						printf("%d\t%s\t\t%s\t%s\t\t%s\t\t%d\n",pArray[i].id,pArray[i].name,pArray[i].cuit,pArray[i].calle,pArray[i].localidad,pArray[i].pedidos);
					}else if(pArray[i].isEmpty==0)
					{
						continue;
					}
			}
			return 0;
}

