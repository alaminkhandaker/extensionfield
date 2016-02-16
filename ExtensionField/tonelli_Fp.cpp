//
//  tonelli_Fp.cpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

#include "tonelli_Fp.hpp"

LL tonelli(LL n, LL p) // Modular Square root in Fp
{
    if (p == 2)
    {   //***
        if (n % p == 1) {
            printf("1\n");
            return 1;
        }
        else
            puts("No root");
        return -1;
    }
    
    if (modularExponen(n, (p - 1) / 2, p) != 1) {
        puts("No root");
        return -1;
    }
    
    LL Q = p - 1, S = 0;
    while (Q % 2 == 0)
    {
        Q >>= 1;
        S++;
    }
    if (S == 1)
    {
        return modularExponen(n, (p + 1) / 4, p);
    }
    LL z;
    while (1)
    {
        z = 1 + rand() % (p - 1);
        printf(" Z :: %lld\n", z);
        if (modularExponen(z, (p - 1) / 2, p) != 1)
            break;
    }
    LL c = modularExponen(z, Q, p);
    LL R = modularExponen(n, (Q + 1) / 2, p);
    LL t = modularExponen(n, Q, p);
    LL M = S, b, i;
    while (1)
    {
        if (t % p == 1)
            break;
        for (i = 1; i < M; ++i)
        {
            if (modularExponen(t, 1 << i, p) == 1)
                break;
        }
        b = modularExponen(c, 1 << (M - i - 1), p);
        R = (R * b) % p;
        t = (t * b * b) % p;
        c = (b * b) % p;
        M = i;
    }
    return (R % p + p) % p;
}