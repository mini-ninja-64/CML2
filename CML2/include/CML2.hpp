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
    
    //projection matrix constructpors
    mat4 Perspective(float fovY, float aspectRatio, float nearPlane, float farPlane);
    mat4 Ortho(float left, float right, float top, float bottom, float nearPlane, float farPlane);
    mat4 lookAt(float eye, float center, float up);
    
    template<typename T, int R, int C>
    CML2P::matrix<T, R, C> inverse(CML2P::matrix<float, R, C> m);
    template<typename T, int R, int C>
    T determinant(CML2P::matrix<T, R, C> m);
    /*
     how to determinant:
     go through top row number (a,b,c,d) and create a new equation like this
        w,x,y,z = create a matrix of size <R-1,C-1> set the contents to be all excluding first row and column of the currently selected integer
        determinant = +a(determinant(w))-b(determinant(x))+c(determinant(y))-d(determinant(z))...
     
     https://en.wikipedia.org/wiki/Minor_(linear_algebra)#Inverse_of_a_matrix ty wiki
     how to inverse:
     inverse = (1/det(M))*adjugate(M)
     whats the adjugate matrix?
        the "transpose" of the co-factor matrix (transpose means swap r and c)
     
     whats a co-factor matrix?
     
     inverse optimisations:
        have pre calcualted equations or something for 4x4, 3x3, 2x2 as these are common and calcualtiong inverse on the fly will probs be intensive
     */
}

#pragma GCC visibility pop
#endif /* CML2_hpp */
