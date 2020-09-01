/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */
/* Carl Barks, Dagobert Duck, Klaas Klever, Mac Moneysac; 30.01.2017 */

/*****************************************************************************

  Praktikumsversuch: Einfuehrung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>

int main (void)
{
	/*--- Variablendeklaration & Initialwerte--------------------------------*/

	tParam p ={
	2.0,
	75,
	-2.0,
	2.0,
	-2.0,
	2.0,
	1280,
	960,
	apfel
	};
	tComplex c1 ={0.4, 0.4};
	tComplex z1 ={0.0, 0.0};

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter ueber Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/
	
	while(ParamDialog(&p, &c1)){

	InitGraph (p.xmin, p.xmax, p.ymin, p.ymax); 	// Initialisierung der Grafik

	LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein

	Fraktal(c1, z1, p);

	UnlockScreen(); // Alle aenderungen auf Bildschirm ausgeben
    	/*Aufrufen von InputChar() um das Programm nach dem oeffnen der Graphik   */
    	/*anzuhalten. Erst wenn in der Konsole eine Taste gedrueckt wird, schliesst*/
    	/*sich das Fenster wieder. */
    	InputChar();
    	CloseGraph();
	}
	return 0;
}
