/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"




	/*--- Interne Funktion: Analyse der iterationszahlationsanzahl -----------------------*/


int Getitera(tComplex c,tComplex z,tParam p){

		int iterationszahl = 0;
		double a = c.realteil;
		double b = c.imaginaerteil;
		double xi = z.realteil;
		double yi = z.imaginaerteil;
		double r = p.R;
		double x_0, y_0;
		double Betrag=sqrt(pow(xi,2)+pow(yi,2));


		do{
			x_0 =xi;
			y_0 =yi;
			xi = (pow(x_0,2)-pow(y_0,2) + a);
			yi = (2*x_0*y_0+b);
			iterationszahl++;

		}while ((Betrag<r)&&(iterationszahl<p.imax));

			return iterationszahl;






			/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/


tColor GetColorValue(int i, int imax){
				tColor color;
				int colorValue = i%15+1;

				if(i >= imax){
				return color = black;
				}
				else {
				switch (colorValue){
				case 1:		color = green;		break;
				case 2:		color = red;			break;
				case 3:   	color = lightblue;		break;
				case 4:   	color = lightcyan;		break;
				case 5:   	color = lightmagenta;	break;
				case 6:   	color = brightwhite;	break;
				case 7:   	color = lightyellow;	break;
				case 8:   	color = gray;			break;
				case 9:   	color = lightred;		break;
				case 10:  	color = blue;			break;
				case 11:   	color = magenta;	break;
				case 12:   	color = brown;		break;
				case 13:   	color = white;		break;
				case 14:   	color = cyan;		break;
				case 15:   	color = lightgreen;	break;
				}
				return color;
				}




				/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/



			}
void Fraktal(tComplex c, tComplex z, tParam p){}


			double dimensionx = (p.xmax - p.xmin) / p.xpoints;
			double dimensiony = (p.ymax - p.ymin) / p.ypoints;
			double x, y;

			tComplex z_zwischenwert, c_zwischenwert;
			int i = 0;

			tColor color;

			for(x = p.xmin; x < p.xmax; x += dimensionx){
					for(y = p.ymin; y < p.ymax; y += dimensiony){
					if(p.f == julia)
					{
						z_zwischenwert.realteil = x;
						z_zwischenwert.imaginaerteil = y;

						i = GetItera(c, z_zwischenwert, p);

					}else {

					}
						c_zwischenwert.realteil = x;
						c_zwischenwert.imaginaerteil = y;

						i = GetItera(c_zwischenwert, z, p);
					}

					color = GetColorValue(i, p.imax);

					SetPoint(x, y, color);

					}

}
