//
//  CMLPrivate.hpp
//  CML2
//
//  Created by Callum Hart on 17/01/2019.
//  Copyright © 2019 Callum Hart. All rights reserved.
//

#ifndef CMLPrivate_hpp
#define CMLPrivate_hpp

/* The classes below are not exported */
#pragma GCC visibility push(hidden)

#include <stdio.h>
#include <vector>

//pre processer vars
#define DATA_STORE 1 //how data is stored, 0 - std::vectors(flat), 1 - array, 2 - 2D array, 3 - custom vector array
#define DYNAMIC_ARRAY 0 // 0 - static array, 1 - dynamic

namespace CML2P{
    template <typename T, int R>
    struct vector;
    
    template <typename T, int R, int C>
    struct matrix{
    public:
        matrix(int fill=0);
        ~matrix();
        
        //op overloads
        matrix operator-(const matrix<T, R, C> &rhs);
        matrix operator+(const matrix<T, R, C> &rhs);
        template <int C2>
        matrix<T,R,C2> operator*(const matrix<T, C, C2>& rhs);
        
        //data access
        T& operator()(const unsigned& row, const unsigned& col);
        const T& operator()(const unsigned& row, const unsigned& col) const;
        
        //fun-ctions lol
        void printint();
        void printfloat();
        
    private:
//        int r; //row(y)
//        int c; //column(x)
#if (DATA_STORE == 0)
        std::vector<T> data; //vector data
#elif (DATA_STORE == 1)
    #if (DYNAMIC_ARRAY)
        T * data;
    #else
        T data[R*C];
    #endif
#elif (DATA_STORE == 2)
    #if (DYNAMIC_ARRAY)
        T ** data;
    #else
        T data[R][C];
    #endif
#elif (DATA_STORE == 3)
    #if (DYNAMIC_ARRAY)
        vector<T, R> * data;
    #else
        vector<T, R> data[C];
    #endif
#endif
    };
}

#if (DATA_STORE == 3)
namespace CML2P{
    template <typename T, int R>
    struct vector{
    public:
        vector(int fill=0);
        ~vector();
        
        //op overloads
        vector operator-(const vector<T, R> &rhs);
        vector operator+(const vector<T, R> &rhs);
        vector operator*(const vector<T, R>& rhs);
        
        //data access
        T& operator()(const unsigned& row);
        const T& operator()(const unsigned& row) const;
        
        //fun-ctions lol
        void printint();
        void printfloat();
        
    private:
    };
}
#endif

#pragma GCC visibility pop
#endif /* CMLPrivate_hpp */
