//
//  extension_arithmatic.cpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

#include "extension_arithmatic.hpp"

struct poly vector_factory(LL e, LL f,LL P)
{
    e = mod(e,P);
    f = mod(f,P);
    struct poly ret;
    ret.x = e;
    ret.y = f;
    return ret;
}


LL legendre_poly(struct poly a, LL c, LL P)
{
    LL x;
    x = multiply_conjugates(a,c,P); //A^(P^2-1)/2 = (A.A^P)^(P-1)/
//    printf("X=%lld",x);
    return legendre(x,P);
}


struct poly frobenious_map(struct poly a, LL P) // // x^p = (x-yw)
{
    LL e = a.x;
    LL f = -a.y;
    e = mod(e,P);
    struct poly ret;
    ret.x = e;
    ret.y = f;
    return ret;
}

LL multiply_conjugates(struct poly a, LL c, LL P)
{   //n(x) = x*x^p
    // struct poly b = frobenious_map(a); //b = x^p, a= x
    LL e = a.x * a.x;
    LL f = c * a.y * a.y;
//    printf("e=%lld, f=%lld",e,f);
    e = e - f;
    return mod(e,P);
}

struct poly vector_addition(struct poly a, struct poly b, LL P)
{
    LL e = a.x + b.x;
    LL f = a.y + b.y;
    return vector_factory(e, f,P);
}

struct poly vector_subtraction(struct poly a, struct poly b, LL P)
{
    LL e = a.x - b.x;
    LL f = a.y - b.y;
    return vector_factory(e, f, P);
}


struct poly multiply(struct poly a, struct poly b, LL c, LL P) // This function is for to multiply to polynomial
{
    // printf("C:: ======%lld\n",c );
    LL e = a.x * b.x + (c) * a.y * b.y;
    LL f = a.x * b.y + b.x * a.y;
    return vector_factory(e, f, P);
}


struct poly inversion(struct poly a, LL c, LL P) // x^-1 = n(x)^-1 * x^p
{
    struct poly b = frobenious_map(a, P); // calculat conjugate
    LL n = multiply_conjugates(a,c,P);
    
    LL invn  = InvMod(n,P); //n(x)^-1
    LL e = invn * b.x;
    LL f = invn * b.y;
    return vector_factory(e,f,P);
}

struct poly modularExponen_vector(struct poly a, LL b,LL c, LL mod) // mod exp in extension field
{
    struct poly d = vector_factory(1, 0,mod);
    while (b > 0)
    {
        if (b & 1)
        {
            d = multiply(d, a, c, mod);
        }
        b = b >> 1;
        a = multiply(a, a, c, mod);
    }
    return d;
}
