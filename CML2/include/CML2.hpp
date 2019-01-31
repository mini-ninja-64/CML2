//
//  CML2.hpp
//  CML2
//
//  Created by Callum Hart on 17/01/2019.
//  Copyright © 2019 Callum Hart. All rights reserved.
//

#ifndef CML2_hpp
#define CML2_hpp

/* The classes below are exported */
#pragma GCC visibility push(default)

#include "CMLPrivate.hpp"
#include "../src/CMLPrivate.cpp"
namespace CML2 {
    typedef CML2P::matrix<float, 4, 4> mat4;
}

#pragma GCC visibility pop
#endif /* CML2_hpp */
