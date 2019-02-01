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
    //square mats
    typedef CML2P::matrix<float, 4, 4> mat4;
    typedef CML2P::matrix<float, 3, 3> mat3;
    typedef CML2P::matrix<float, 2, 2> mat2;
    
    //vecs
#if (DATA_STORE == 3)
    typedef CML2P::matrix<float, 4, 1> vec4;
    typedef CML2P::matrix<float, 3, 1> vec3;
    typedef CML2P::matrix<float, 2, 1> vec2;
#else
    typedef CML2P::vector<float, 4> vec4;
    typedef CML2P::vector<float, 3> vec3;
    typedef CML2P::vector<float, 2> vec2;
#endif
    //other mats
    typedef CML2P::matrix<float, 4, 3> mat4x3;
    typedef CML2P::matrix<float, 4, 2> mat4x2;
    
    typedef CML2P::matrix<float, 3, 4> mat3x4;
    typedef CML2P::matrix<float, 3, 2> mat3x2;
    
    typedef CML2P::matrix<float, 2, 4> mat2x4;
    typedef CML2P::matrix<float, 2, 3> mat2x3;
}

#pragma GCC visibility pop
#endif /* CML2_hpp */
