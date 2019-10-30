/*
 * hardcodeo.c
 *
 *  Created on: 24 oct. 2019
 *      Author: joariel93
 */
#include "utn_structBibCliente.h"
#include "utn_structBibPedido.h"
#include <string.h>
int clientesHardcodeo(cliente pArray[],int limite)
{
	int i;

	pArray[0].id=1;
	strcpy(pArray[0].name,"Telefonica");
	strcpy(pArray[0].cuit,"30112233445");
	strcpy(pArray[0].calle,"Lima 1234");
	strcpy(pArray[0].localidad,"CABA");
	pArray[0].reciclado=860;
	pArray[0].pedidos=1;
	pArray[0].isEmpty=1;

	pArray[1].id=2;
	strcpy(pArray[1].name,"DATASOFT");
	strcpy(pArray[1].cuit,"30445566776");
	strcpy(pArray[1].calle,"Corrientes 2547");
	strcpy(pArray[1].localidad,"CABA");
	pArray[1].reciclado=0;
	pArray[1].pedidos=2;
	pArray[1].isEmpty=1;

	pArray[2].id=3;
	strcpy(pArray[2].name,"NESTLE");
	strcpy(pArray[2].cuit,"30889955219");
	strcpy(pArray[2].calle,"cucha cucha 555");
	strcpy(pArray[2].localidad,"LANUS");
	pArray[2].reciclado=920;
	pArray[2].pedidos=0;
	pArray[2].isEmpty=1;

	pArray[3].id=4;
	strcpy(pArray[3].name,"TERRABUSI");
	strcpy(pArray[3].cuit,"30567814235");
	strcpy(pArray[3].calle,"rocha 784");
	strcpy(pArray[3].localidad,"QUILMES");
	pArray[3].reciclado=220;
	pArray[3].pedidos=0;
	pArray[3].isEmpty=1;

	pArray[4].id=5;
	strcpy(pArray[4].name,"DIA");
	strcpy(pArray[4].cuit,"31545812533");
	strcpy(pArray[4].calle,"Mitre 750");
	strcpy(pArray[4].localidad,"AVELLANEDA");
	pArray[4].reciclado=15;
	pArray[4].pedidos=0;
	pArray[4].isEmpty=1;

	pArray[5].id=6;
	strcpy(pArray[5].name,"QUILMES");
	strcpy(pArray[5].cuit,"30514857596");
	strcpy(pArray[5].calle,"rocha 741");
	strcpy(pArray[5].localidad,"QUILMES");
	pArray[5].reciclado=0;
	pArray[5].pedidos=1;
	pArray[5].isEmpty=1;


	return 0;
}
int pedidosHardcodeados(pedido array[],int limite)
{
	array[0].idPedido=1;
	array[0].idCliente=1;
	array[0].recolectado=425;
	array[0].estado=2;
	array[0].HDPE=200;
	array[0].LDPE=145;
	array[0].PP=230;
	array[0].isEmpty=1;

	array[1].idPedido=2;
	array[1].idCliente=1;
	array[1].recolectado=515;
	array[1].estado=2;
	array[1].HDPE=210;
	array[1].LDPE=45;
	array[1].PP=30;
	array[1].isEmpty=1;

	array[2].idPedido=3;
	array[2].idCliente=2;
	array[2].recolectado=100;
	array[2].estado=1;
	array[2].HDPE=0;
	array[2].LDPE=0;
	array[2].PP=0;
	array[2].isEmpty=1;

	array[3].idPedido=4;
	array[3].idCliente=2;
	array[3].recolectado=300;
	array[3].estado=1;
	array[3].HDPE=0;
	array[3].LDPE=0;
	array[3].PP=0;
	array[3].isEmpty=1;

	array[4].idPedido=5;
	array[4].idCliente=3;
	array[4].recolectado=580;
	array[4].estado=2;
	array[4].HDPE=500;
	array[4].LDPE=150;
	array[4].PP=270;
	array[4].isEmpty=1;

	array[5].idPedido=6;
	array[5].idCliente=4;
	array[5].recolectado=530;
	array[5].estado=2;
	array[5].HDPE=100;
	array[5].LDPE=50;
	array[5].PP=70;
	array[5].isEmpty=1;

	array[6].idPedido=7;
	array[6].idCliente=1;
	array[6].recolectado=200;
	array[6].estado=1;
	array[6].HDPE=0;
	array[6].LDPE=0;
	array[6].PP=0;
	array[6].isEmpty=1;

	array[7].idPedido=8;
	array[7].idCliente=5;
	array[7].recolectado=12;
	array[7].estado=2;
	array[7].HDPE=10;
	array[7].LDPE=5;
	array[7].PP=3;
	array[7].isEmpty=1;

	array[8].idPedido=9;
	array[8].idCliente=6;
	array[8].recolectado=456;
	array[8].estado=1;
	array[8].HDPE=0;
	array[8].LDPE=0;
	array[8].PP=0;
	array[8].isEmpty=1;
	return 0;
}
