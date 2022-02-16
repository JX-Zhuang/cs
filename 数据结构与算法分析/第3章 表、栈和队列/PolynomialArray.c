#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 1000
struct P
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
};
typedef struct P *Polynomial;
int Max(int a, int b)
{
    return a > b ? a : b;
}
void ZeroPolynomial(Polynomial Poly)
{
    for (int i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}
void AddPolynomial(const Polynomial P1, const Polynomial P2, Polynomial PolySum)
{
    int i;
    ZeroPolynomial(PolySum);
    i = PolySum->HighPower = Max(P1->HighPower, P2->HighPower);
    for (; i >= 0; i--)
    {
        PolySum->CoeffArray[i] = P1->CoeffArray[i] + P2->CoeffArray[i];
    }
}
void MultPolynomial(const Polynomial P1, const Polynomial P2, Polynomial PolyMult)
{
    int i = P1->HighPower, j;
    ZeroPolynomial(PolyMult);
    PolyMult->HighPower = P1->HighPower + P2->HighPower;
    for (; i >= 0; i--)
        for (j = P2->HighPower; j >= 0; j--)
            PolyMult->CoeffArray[i + j] += P1->CoeffArray[i] * P2->CoeffArray[j];
}
void PrintPolynomial(Polynomial P)
{
    int i = P->HighPower;
    for (; i >= 0; i--)
    {
        if (P->CoeffArray[i] == 0)
            continue;
        if (i != P->HighPower)
        {
            printf(P->CoeffArray[i] > 0 ? "+" : "-");
        }
        printf("%d", P->CoeffArray[i]);
        if (i != 0)
            printf("*x^%d", i);
    }
    printf("\n");
}
//P1:5*x^4+x^3+x+12
//P2:3*x^5+2*x^3+x^2
int main()
{
    Polynomial P1 = malloc(sizeof(struct P));
    ZeroPolynomial(P1);
    P1->HighPower = 4;
    P1->CoeffArray[4] = 5;
    P1->CoeffArray[3] = 1;
    P1->CoeffArray[1] = 1;
    P1->CoeffArray[0] = 12;
    Polynomial P2 = malloc(sizeof(struct P));
    ZeroPolynomial(P2);
    P2->HighPower = 5;
    P2->CoeffArray[5] = 3;
    P2->CoeffArray[3] = 2;
    P2->CoeffArray[2] = 1;
    Polynomial PSum = malloc(sizeof(struct P)), PMult = malloc(sizeof(struct P));
    AddPolynomial(P1, P2, PSum);
    PrintPolynomial(PSum);
    MultPolynomial(P1, P2, PMult);
    PrintPolynomial(PMult);
    return 0;
}