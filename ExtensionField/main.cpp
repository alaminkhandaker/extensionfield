//
//  main.cpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//


#include "tonelli_Fpm.hpp"

LL Prime;
LL c;
LL b;

struct rastional {
    struct poly P, Q;
    bool isRastional;
};

struct rastional getRationalPoint(struct poly X)
{
    
    struct rastional R;
    //RHS
    struct poly a = modularExponen_vector(X, 3, c, Prime); // X^3+b;
    struct poly b = vector_factory(1, 0, Prime); //b= (1,0) scalar
    struct poly rhs = vector_addition(a, b, Prime);
    struct poly lhs = vector_factory(0, 0, Prime); //
    
    if(legendre_poly(rhs, c, Prime) == 1)
    {
        lhs = tonelli_vector(rhs, c, Prime);
        R.P = rhs;
        R.Q = lhs;
        R.isRastional = true;
    }
    else
    {
        R.isRastional = false;
//        printf("X = (%lld, %lld w) has no modulo sqare root \n",rhs.x, rhs.y);
    }
    return R;
}





int main()
{
    printf("Please enter a Prime number\n");
    scanf("%lld", &Prime);
    
    c = getIrreduciblePolynomial(Prime);
    printf("\tx^2 - %lld is an irreducible in F_%lld \n", c, Prime);
    
    LL index = 0;
    struct rastional R[Prime*Prime];
    for(LL i = 0; i < Prime; i++) {
        for(LL j = 0; j < Prime; j++) {
            
            struct poly X = vector_factory(i, j, Prime);
            struct rastional temp = getRationalPoint(X);
            R[++index] = temp;
            if(R[++index].isRastional)
                printf("R(%lld,%lld w),(%lld, %lldw)\n",temp.P.x, temp.P.y, temp.Q.x, temp.Q.y);
        }
    }
    
//    int T;
//    printf("Please enter number of test cycles\n");
//    scanf("%d", &T);
//    while (T--)
//    {
//        printf("Please enter 2 number to get a vector\n");
//        LL p, q;
//        scanf("%lld %lld", &p, &q);
//        
//        struct poly a = vector_factory(p, q,Prime);
//        printf("Legendre sysmbol of vector A = (%lld + %lld w) is %lld \n", p, q, legendre_poly(a,c,Prime));
//        
//        LL v = legendre_poly(a,c,Prime);
//       
//        struct poly g = modularExponen_vector(a, (Prime*Prime - 1)/2, c, Prime);
//        printPoints(g);
//        
//        if (v != 1)
//        {
//            puts("Square root can not be found");
//            continue;
//        }
//        
//        //Squaring
//        struct poly asq = modularExponen_vector(a, 2, c, Prime);
//        printf("Legendre sysmbol of vector A^2 = (%lld + %lld w) is %lld \n",asq.x, asq.y, legendre_poly(asq,c,Prime));
////        printf("Square of A = (%lld + %lld w) is :: ", p, q);
////        printPoints(asq);
//        
//        //Square Roots
//        struct poly asqrt = tonelli_vector(asq, c, Prime);
//        // struct poly asqrt = tonelli_shanks(asq, Prime);
//        printf("Square Root of sqrt(A^2) =(%lld + %lld w) is calculated by tonelli\n", asqrt.x, asqrt.y);
////        printPoints(asqrt);
//        
//        LL m = modularExponen(q, 2, Prime);
//        LL z = tonelli(m, Prime);
//        printf("\n\nSquare of q = %lld is %lld \n Sqrt is %lld \n\t And legendre of q = %lld and q^2 = %lld\n",q,m,z,legendre(q,Prime), legendre(m, Prime));
//        
//    }
    
    return 0;
}

