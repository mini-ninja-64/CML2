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
#define DATA_STORE 0 //how data is stored, 0 - std::vectors, 1 - array, 2 - 2d array, 3 custom vector system

namespace CML2P{
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
        T * data; //can be static as templates now
#elif (DATA_STORE == 2)
        T ** data; //can be static as templates now
#elif (DATA_STORE == 3)
        T ** data; //can be static as templates now
#endif
    };
    
#if (DATA_STORE == 3)
    template <typename T, int R>
    struct vector{
    public:
        vector(int fill=0);
        ~vector();
        
        //op overloads
        vector operator-(const vector<T, R> &rhs);
        vector operator+(const vector<T, R> &rhs);
        vector operator*(const matrix<T, R>& rhs);
        
        //data access
        T& operator()(const unsigned& row);
        const T& operator()(const unsigned& row) const;
        
        //fun-ctions lol
        void print();
        
    private:
    }
#endif
}
#pragma GCC visibility pop
#endif /* CMLPrivate_hpp */
