#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 1000
typedef struct Node *PtrToNode;
struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
int Max(int a, int b)
{
    return a > b ? a : b;
}
Polynomial CreatePolynomialNode(int Coefficient, int Exponent)
{
    Polynomial P = malloc(sizeof(struct Node));
    P->Coefficient = Coefficient;
    P->Exponent = Exponent;
    P->Next = NULL;
    return P;
}
Polynomial CreatePolynomial()
{
    Polynomial P = malloc(sizeof(struct Node));
    P->Next = NULL;
    return P;
}
Polynomial AddPolynomial(Polynomial P1, Polynomial P2)
{
    Polynomial Tmp, PolySum = CreatePolynomial();
    Tmp = PolySum;
    P1 = P1->Next;
    P2 = P2->Next;
    while (P1 && P2)
    {
        if (P1->Exponent > P2->Exponent)
        {
            Tmp->Next = CreatePolynomialNode(P1->Coefficient, P1->Exponent);
            P1 = P1->Next;
        }
        else if (P1->Exponent < P2->Exponent)
        {
            Tmp->Next = CreatePolynomialNode(P2->Coefficient, P2->Exponent);
            P2 = P2->Next;
        }
        else
        {
            Tmp->Next = CreatePolynomialNode(P1->Coefficient + P2->Coefficient, P1->Exponent);
            P1 = P1->Next;
            P2 = P2->Next;
        }
        Tmp = Tmp->Next;
    }
    Polynomial P = P1 ? P1 : P2;
    while (P)
    {
        Tmp->Next = CreatePolynomialNode(P->Coefficient, P->Exponent);
        Tmp = Tmp->Next;
        P = P->Next;
    }
    return PolySum;
}
void Insert(Polynomial Header, Polynomial P)
{
    P->Next = Header->Next;
    Header->Next = P;
}
void MultPolynomial(const Polynomial P1, const Polynomial P2, Polynomial PolyMult)
{
}
void PrintPolynomial(Polynomial P)
{
    int i = 0;
    P = P->Next;
    while (P)
    {
        if (i)
        {
            printf(P->Coefficient > 0 ? "+" : "-");
        }
        printf("%d", P->Coefficient);
        if (P->Exponent)
        {
            printf("*x^%d", P->Exponent);
        }
        P = P->Next;
        i = 1;
    }
    printf("\n");
}
//P1:5*x^4+x^3+x+12
//P2:3*x^5+2*x^3+x^2
int main()
{
    Polynomial P1 = CreatePolynomial();
    Insert(P1, CreatePolynomialNode(12, 0));
    Insert(P1, CreatePolynomialNode(1, 1));
    Insert(P1, CreatePolynomialNode(1, 3));
    Insert(P1, CreatePolynomialNode(5, 4));
    Polynomial P2 = CreatePolynomial();
    Insert(P2, CreatePolynomialNode(1, 2));
    Insert(P2, CreatePolynomialNode(2, 3));
    Insert(P2, CreatePolynomialNode(3, 5));
    Polynomial PSum = AddPolynomial(P1, P2);
    PrintPolynomial(PSum);
    // MultPolynomial(P1, P2, PMult);
    // PrintPolynomial(PMult);
    return 0;
}