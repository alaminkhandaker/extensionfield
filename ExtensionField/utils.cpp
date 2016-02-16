//
//  utils.cpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

#include "utils.hpp"

// extended Euclidian algo
LL EGCD(LL a, LL b, LL& u, LL& v)
{
    u = 1;
    v = 0;
    LL g = a;
    LL u1 = 0;
    LL v1 = 1;
    LL g1 = b;
    while (g1 != 0) {
        LL q = g / g1;
        LL t1 = u - q * u1;
        LL t2 = v - q * v1;
        LL t3 = g - q * g1;
        u = u1;
        v = v1;
        g = g1;
        u1 = t1;
        v1 = t2;
        g1 = t3;
    }
    return g;
}

LL InvMod(LL x, LL n) // Solve linear congruence equation x * z == 1 (mod n) for z
{
    x = x % n;
    
    LL u, v, g, z;
    g = EGCD(x, n, u, v);
    if (g != 1) {
        z = 0;
    } else {
        
        z = u % n;
    }
    return z;
}

LL modularExponen(LL a, LL b, LL mod) //mod exp in Fp
{
    LL d = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            d = (d * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return d;
}


void printPoints(struct poly a)
{
    printf("(%lld + %lld w)\n", a.x, a.y);
}

LL mod (LL a, LL Prime)
{
    return (a % Prime + Prime) % Prime;
}


LL legendre(LL a, LL Prime)
{
    LL x, m;
    m = (Prime - 1) / 2;
    x = modularExponen(a, m, Prime);
    if (x == (Prime - 1))
    {
        x = -1;
    }
    
    return x;
}


LL getIrreduciblePolynomial(LL Prime)
{
    //    LL numberOfnonResidue = 0;
    LL array[Prime];
    for (LL i = 0; i < Prime; ++i)
    {
        LL x = legendre(i, Prime);
        if (x == -1)
        {
            array[i] = i;
            return i;
            break;
        }
    }
    return array[0];
}


