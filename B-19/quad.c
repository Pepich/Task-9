/*********************************/
/* Benedikt Abel, Justus Faust   */
/* Gruppe: Di08                  */
/* Uebungsblatt: 9, Aufgabe B-19 */
/* Thema: call-by-reference      */
/* Version: v1.0.0               */
/* Datum: 20160627               */
/* Status: werks                 */
/*********************************/

#include <stdio.h>
#include <math.h>

int quad(double a, double b, double c, double *r_1, double *r_2)
{
    float d = b*b-4*a*c;
    // Returning logical false when no solutions are to be found or when it is not a quadratic equasion
    if (d < 0 || a == 0)
	return 0;
    // Calculating the solutions
    *r_1 = (-b+sqrt(d))/(4*a);
    *r_2 = (-b-sqrt(d))/(4*a);
    return 1;
}
int main(void)
{
    double a = 0, b = 0, c = 0, r_1 = 0, r_2 = 0;
    // Scanning values
    printf("Bitte a eingeben: ");
    scanf("%lf",&a);
    printf("Bitte b eingeben: ");
    scanf("%lf",&b);
    printf("Bitte c eingeben: ");
    scanf("%lf",&c);
    
    // Doing the work, outputting solutions, or if none to be found, outputting error message
    if (quad(a, b, c, &r_1, &r_2))
	printf("Die Lösungen der quadratischen Gleichung lauten %f; %f.\n", r_1, r_2);
    else
	printf("Es gibt keine Lösungen.\n");
    return 0;
}
