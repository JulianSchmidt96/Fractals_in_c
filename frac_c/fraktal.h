

#ifndef __fraktal
#define __fraktal

typedef enum ftype {
	apfel, julia
} ftype;

typedef struct tParam{

	double R,xmin, xmax, ymin, ymax;			//Radius
	int imax,xpoints, ypoints;		//maximale Iterationsschritte
		ftype f;


} tParam;

typedef struct tComplex{

	double realteil, imaginaerteil;

} tComplex;

/*--- Datentypvereinbarungen -----------------------------------------------*/



/*--- Fraktal analysieren und grafisch darstellen --------------------------*/


int GetItera(tComplex c, tComplex z, tParam p);
tColor GetColorValue(int i, int imax);
void Fraktal(tComplex c, tComplex z, tParam p);

#endif

/* v3_frakt.h */
