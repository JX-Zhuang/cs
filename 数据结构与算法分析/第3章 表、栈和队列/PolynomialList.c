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
void Insert(Polynomial Poly, Polynomial P)
{
    P->Next = Poly->Next;
    Poly->Next = P;
}
void SortPolynomial(Polynomial P)
{
    Polynomial Max, MaxBefore, Tmp1 = P->Next, Tmp2, TmpBefore, Before, Next;
    int C, E;
    MaxBefore = P;
    Before = P;
    while (Tmp1)
    {
        TmpBefore = Tmp1;
        Max = Tmp1;
        Tmp2 = Tmp1->Next;
        while (Tmp2)
        {
            if (Tmp2->Exponent > Max->Exponent)
            {
                Max = Tmp2;
                MaxBefore = TmpBefore;
            }
            TmpBefore = Tmp2;
            Tmp2 = Tmp2->Next;
        }
        Next = Max->Next;
        Before->Next = Max;
        if (Tmp1->Next == Max)
        {
            Max->Next = Tmp1;
        }
        else
        {
            Max->Next = Tmp1->Next;
        }
        MaxBefore->Next = Tmp1;
        Tmp1->Next = Next;
        Tmp1 = Max->Next;
        Before = Max;
        MaxBefore = Max;

        // C = Max->Coefficient;
        // E = Max->Exponent;
        // Max->Coefficient = Tmp1->Coefficient;
        // Max->Exponent = Tmp1->Exponent;
        // Tmp1->Coefficient = C;
        // Tmp1->Exponent = E;
        // Tmp1 = Tmp1->Next;
    }
}
void MergeExponent(Polynomial P)
{
    Polynomial Tmp1 = P->Next, Tmp2, Before;
    while (Tmp1)
    {
        Before = Tmp1;
        Tmp2 = Tmp1->Next;
        while (Tmp2)
        {
            if (Tmp1->Exponent == Tmp2->Exponent)
            {
                Tmp1->Coefficient += Tmp2->Coefficient;
                Before->Next = Tmp2->Next;
            }
            else
            {
                Before = Tmp2;
            }

            Tmp2 = Tmp2->Next;
        }
        Tmp1 = Tmp1->Next;
    }
}
Polynomial MultPolynomial(Polynomial P1, Polynomial P2)
{
    Polynomial TmpMult, Tmp, TmpP2 = P2->Next, PolyMult = CreatePolynomial();
    TmpMult = PolyMult;
    P1 = P1->Next;
    while (P1)
    {
        while (TmpP2)
        {
            TmpMult->Next = CreatePolynomialNode(P1->Coefficient * TmpP2->Coefficient, P1->Exponent + TmpP2->Exponent);
            TmpP2 = TmpP2->Next;
            TmpMult = TmpMult->Next;
        }
        TmpP2 = P2->Next;
        P1 = P1->Next;
    }
    MergeExponent(PolyMult);
    SortPolynomial(PolyMult);
    return PolyMult;
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
    Polynomial PSum = AddPolynomial(P1, P2), PMult = MultPolynomial(P1, P2);
    PrintPolynomial(PSum);
    PrintPolynomial(PMult);
    return 0;
}