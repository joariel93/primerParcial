/*
 * utn_inputs.h
 *
 *  Created on: 16 oct. 2019
 *      Author: joariel93
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char *pMensaje,char *pMensajeError,float minimo,float maximo,int reintentos);
int utn_getString (char *pResultado,char *pMensaje,char *pMensajeError,int maximo,int limite);
int utn_getStringCUIT (char *pResultado,char *pMensaje,char *pMensajeError,int maximo,int limite);

#endif /* UTN_INPUTS_H_ */
