/*********************************/
/* Benedikt Abel, Justus Faust   */
/* Gruppe: Di08                  */
/* Uebungsblatt: 9, Aufgabe B-18 */
/* Thema: Integrale              */
/* Version: v1.0.0               */
/* Datum: 20160627               */
/* Status: werks                 */
/*********************************/

#include <stdio.h>
#include <math.h>

const static double limit = 0.000001;
static int error = 0;

double abs(double x)
{
    return x > 0 ? x : -x;
}

// Returns the function value for x if x > 0, sets error message to -2 and returns 0 elsewise
double f(double x)
{
    if (x <= 0)
    {
	error = -2;
	return 0;
    }

    return log(x)/x;
}

// returns the integral via iteration if the parameters are ok, sets the error to -1 and returns 0 elsewise
double trapez(double a, double b, int n)
{
    // If n <= 0 (aka 0 or less iterations), return -1 as error value
    if (n <= 0)
    {
	error = -1;
	return 0;
    }
    // If the limits are swapped around, switch them to be in the correct order
    if (a > b)
	return trapez(b, a, n);
    double result = 0;
    double h = (b-a)/n;

    // Iterative calculation of the integral
    for (int i = 0; i < n; i++)
    {
	result += f(a+i*h);
    }

    result *= h/2;
    return result;
}

int main(void)
{
    double a = 0, b = 0, r = 0, rp = 0;
    int done = 0, n = 0;
    
    // Scanning values
    printf("Bitte untere Grenze a eingeben: ");
    scanf("%lf",&a);
    printf("Bitte obere Grenze b eingeben: ");
    scanf("%lf",&b);
    
    // Main loop
    while (!done)
    {
	n += 5;
	rp = r;
     	r = trapez(a, b, n);

	// Cancel the loop when the approximation is close enough
	if ((abs(rp-r)/abs(r))<limit)
	    done = 1;
	// Cancel the loop when too many iterations are about to be made
	if (n > 100)
	    done = 1;
	// Cancel the loop when an error has occured
	if (error != 0)
	    done = 1;
    }
    
    // Program output
    switch (error)
    {
	case 0:
	    printf("Das Integral von %f bis %f über f(x) ergibt %f\n.", a, b, r);
	    break;
	case -1:
	    printf("Ein Fehler ist aufgetreten: Die Anzahl der Iterationen ist kleiner oder gleich 0.\n");
	    break;
	case -2:
	    printf("Ein Fehler ist aufgetreten: f(x) ist fuer x <= 0 nicht definiert.\n");
	    break;
	default:
	    printf("Ein Fehler ist aufgetreten: Unbekannter Fehler.\n");
	    break;
    }
    return 0;
}
