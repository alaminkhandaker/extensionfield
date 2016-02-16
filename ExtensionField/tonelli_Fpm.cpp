//
//  tonelli_Fpm.cpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

#include "tonelli_Fpm.hpp"

struct poly tonelli_vector(struct poly n, LL qn, LL p) //Modular sqare root of vectors
{
    struct poly unit = vector_factory(1, 0, p);
    
    LL Q = p - 1, S = 0;
    while (Q % 2 == 0)
    {
        Q >>= 1;
        S++;
        printf("S =============%lld \n", S);
    }
    if (S == 1)
    {
        LL tm1 = (p+1)/4;
        printf("If S:: %lld , tm1 %lld , nx %lld ny%lld\n", S,tm1,n.x,n.y);
        
        struct poly r = modularExponen_vector(n, tm1, qn, p);
        printPoints(r);
        struct poly r1 = modularExponen_vector(r, 2, qn, p);
        if (r1.x == n.x && r1.y == n.y)
            return r;
        return vector_factory(0, 0, p);
    }
    
    // LL z;
    struct poly z = vector_factory(1,0,p);
    while (1)
    {
        LL temp1 = 1 + rand() % (p - 1);
        LL temp2 = 1 + rand() % (p - 1);
        printf("Random value ::temp1 %lld , temp2 == %lld\n", temp1,temp2);
        z = vector_factory(temp1, temp2,p);
        printf("Legendre sysmbol of vector Z = (%lld + %lld w) is %lld \n",z.x, z.y, legendre_poly(z,qn,p));
        // printPoints(z);
        if (legendre_poly(z,qn,p) != 1)
            break;
    }
    struct poly c = modularExponen_vector(z, Q, qn, p);
    struct poly R = modularExponen_vector(n, (Q + 1) / 2, qn, p);
    struct poly t = modularExponen_vector(n, Q, qn, p);
    
    LL M = S;
    LL i;
    struct poly b;
    while (1)
    {
        if (t.x % p == unit.x % p)
            break;
        for (i = 1; i < M; ++i)
        {
            struct poly temp = modularExponen_vector(t, 1 << i, qn, p);
            if (temp.x == unit.x)
                break;
        }
        b = modularExponen_vector(c, 1 << (M - i - 1), qn, p);
        R = multiply(R, b, qn, p);
        struct poly bsq = multiply(b, b, qn, p);
        t = multiply(t, bsq, qn, p);
        c = multiply(b, b, qn, p);
        M = i;
    }
    struct poly r1 = multiply(R, R, qn, p);
    if (r1.x == n.x && r1.y == n.y)
        return R;
    return vector_factory(0, 0, p);
}
