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

int main()
{
    printf("Please enter a Prime number\n");
    scanf("%lld", &Prime);
    
    c = getIrreduciblePolynomial(Prime);
    printf("\tx^2 - %lld is an irreducible in F_%lld \n", c, Prime);
    
    int T;
    printf("Please enter number of test cycles\n");
    scanf("%d", &T);
    while (T--)
    {
        printf("Please enter 2 number to get a vector\n");
        LL p, q;
        scanf("%lld %lld", &p, &q);
        
        struct poly a = vector_factory(p, q,Prime);
        printf("Legendre sysmbol of vector A = (%lld + %lld w) is %lld \n", p, q, legendre_poly(a,c,Prime));
        
        LL v = legendre_poly(a,c,Prime);
        vector_addition(a, a, Prime);
        
        if (v != 1)
        {
            puts("Square root can not be found");
            continue;
        }
        
        //Squaring
        struct poly asq = modularExponen_vector(a, 2, c, Prime);
        printf("Legendre sysmbol of vector A^2 = (%lld + %lld11     w) is %lld \n",asq.x, asq.y, legendre_poly(asq,c,Prime));
        printf("Square of A = (%lld + %lld w) is :: ", p, q);
        printPoints(asq);
        
        //Square Roots
        struct poly asqrt = tonelli_vector(asq, c, Prime);
        // struct poly asqrt = tonelli_shanks(asq, Prime);
        printf("Square Root of A^2 =(%lld + %lld w) is calculated by tonelli\n", asq.x, asq.y);
        printPoints(asqrt);
        
//        LL z = tonelli(73, Prime);
//        printf("Square root of 73 %lld And legendre of 73 is %lld\n",z,legendre(73,Prime));
        
    }
    
    return 0;
}

