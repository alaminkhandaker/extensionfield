//
//  utils.hpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

//#include "modular_exponen.cpp"
#include "global_data.h"

LL EGCD(LL a, LL b, LL& u, LL& v);
LL InvMod(LL x, LL n);

void printPoints(struct poly a);
LL mod (LL a, LL P);
LL legendre(LL a, LL Prime);
LL getIrreduciblePolynomial(LL Prime);
LL modularExponen(LL a, LL b, LL mod);