#include <stdio.h>
#define MaxDegree 1000
typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;
void ZeroPolynomial(Polynomial Poly)
{
    for (int i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}