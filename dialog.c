/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */
/* Carl Barks, Dagobert Duck, Klaas Klever, Mac Moneysac; 30.01.2017 */

/*****************************************************************************

  Praktikumsversuch: Einfuehrung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};

/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};

/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};

/*--- Parameter Dialog ------------------------------------------------------*/

ftype getFType(){
	printf("Fraktaltyp eingeben (0 = Mandelbrot, 1 = Julia): ");
	int i;
	InputInt(&i);
 	if(i == 0){
	return apfel;
	} else{
	return julia;
	}
}

tComplex getC(){
	double c_realteil;
	double c_imaginaerteil;
	tComplex c;
	printf("realteilteil von c eingeben: ");
	InputDouble(&c_realteil);
	printf("imaginaerteilinaerteil von c eingeben: ");
	InputDouble(&c_imaginaerteil);
	c.realteil = c_realteil;
	c.imaginaerteil = c_imaginaerteil;
	return c;
}

int paramTest(tParam p){
	if((p.R > 0) && (p.imax > 0) && (p.xmax > p.xmin) && (p.ymax > p.ymin) && (p.xpoints > 0) && (p.ypoints > 0)){
	return 1;
	} else {
	printf("Mindestens ein eingegebener Wert unzulaessig.");
	return 0;
	}
}

int ParamDialog(tParam *p_in, tComplex *c_in){
	tParam p = *p_in;
	tComplex c = *c_in;
	int input;
	int warten = 0;
	do{
	printf("\n------------------------------------------------------------------------|\n									|\n");
	printf("Programm zur Fraktalanalyse						|\n");
	printf("[0]  Fraktaltyp (0 = Mandelbrot, 1 = Julia)...%i				|\n", p.f);
	printf("[1]  Radius:..................................%f			|\n", p.R);
	printf("[2]  Komplexe Zahl c:.........................%+f%+fj	|\n", c.realteil, c.imaginaerteil);
	printf("[3]  Iterationsgrenze:........................%i			|\n", p.imax);
	printf("Gebiet der Gaussschen Ebene						|\n");
	printf("[4]  x_min:...................................%+f			|\n", p.xmin);
	printf("[5]  x_max:...................................%+f			|\n", p.xmax);
	printf("[6]  y_min:...................................%+f			|\n", p.ymin);
	printf("[7]  y_max:...................................%+f			|\n", p.ymax);
	printf("Aufloesung (horizontal/vertikal)					|\n");
	printf("[8]  x_points:................................%i			|\n", p.xpoints);
	printf("[9]  y_points:................................%i			|\n", p.ypoints);
	printf("									|\n");
	printf("[10] Fraktal darstellen.						|\n");
	printf("[11] Programm beenden.							|\n");
	printf("------------------------------------------------------------------------|\n");
	InputInt(&input);
	switch(input){
	case 0: p.f = getFType(); 	break;
	case 1:
		printf("Radius eingeben: ");
		InputDouble(&p.R);	break;
	case 2: c = getC();		break;
	case 3:
		printf("Iterationsgrenze eingeben: ");
		InputInt(&p.imax);	break;
	case 4:
		printf("x_min eingeben: ");
		InputDouble(&p.xmin);	break;
	case 5:
		printf("x_max eingeben: ");
		InputDouble(&p.xmax);	break;
	case 6:
		printf("y_min eingeben: ");
		InputDouble(&p.ymin);	break;
	case 7:
		printf("y_max eingeben: ");
		InputDouble(&p.ymax);	break;
	case 8:
		printf("x_points eingeben: ");
		InputInt(&p.xpoints);	break;
	case 9:
		printf("y_points eingeben: ");
		InputInt(&p.ypoints);	break;
	case 10: if(paramTest(p) == 1){
		warten = 1;
		}			break;
	case 11:
		printf("Programm wird beendet.\n");
		return 0;		break;
	default:
		printf("Bitte zulaessige Zahl eingeben."); break;
	}
		*p_in = p;
		*c_in = c;
	}
	while(warten != 1);
	return 1;
}
