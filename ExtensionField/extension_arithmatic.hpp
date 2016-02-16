//
//  extension_arithmatic.hpp
//  ExtensionField
//
//  Created by Khandaker Md. Al-Amin on 2/16/16.
//  Copyright © 2016 Khandaker Md. Al-Amin. All rights reserved.
//

#include <stdio.h>
#include "tonelli_Fp.hpp"

struct poly vector_addition(struct poly a, struct poly b, LL P);
struct poly vector_subtraction(struct poly a, struct poly b, LL P);
struct poly multiply(struct poly a, struct poly b, LL c, LL P);
LL multiply_conjugates(struct poly a, LL c, LL P);
struct poly frobenious_map(struct poly a, LL P);
LL legendre_poly(struct poly a, LL c, LL P);
struct poly vector_factory(LL e, LL f,LL P);
struct poly modularExponen_vector(struct poly a, LL b,LL c, LL mod);