/*
 * inputs.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"
int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int number;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&number)==1 && number >= minimo && number <= maximo)
		{
			*pResultado = number;
			retorno = 0;
			break;
		}
		reintentos--;
		printf("%s, le quedan %d intentos.\n",pMensajeError,reintentos);

	}while(reintentos >= 0);
	return retorno;
}
int utn_getFloat(float* pResultado,char *pMensaje,char *pMensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float number;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%f",&number)==1 && number >= minimo && number <= maximo)
		{
			*pResultado = number;
			retorno = 0;
			break;
		}
		reintentos--;
		printf("%s, le quedan %d intentos.\n",pMensajeError,reintentos);

	}while(reintentos >= 0);
	return retorno;
}
int utn_getString (char *pResultado,char *pMensaje,char *pMensajeError,int maximo,int limite)
{
	int flagError=-1;
	int i;
	int retorno = -1;
	char text[limite];
	if(	pResultado != NULL && pMensaje	!= NULL &&	0< maximo)
	{
		while(flagError==-1)
		{
			flagError=0;
			printf("%s",pMensaje);
			__fpurge(stdin);
			fgets(text,sizeof(text),stdin);
			text[strlen(text)-1] = '\0';
			if(strlen(text) <= maximo)
			{
				strncpy(pResultado,text,maximo+1);
				retorno = 0;
			}
			for(i=0;i<strlen(text)-1;i++)
			{
				if(!((text[i]>='A'&&text[i]<='Z')||(text[i]>='a'&&text[i]<='z')))
				{
					printf("%s\n",pMensajeError);
					flagError=-1;
					break;
				}
			}
		}

	}
	return retorno;
}

