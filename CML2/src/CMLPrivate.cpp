//
//  CMLPrivate.cpp
//  CML2
//
//  Created by Callum Hart on 17/01/2019.
//  Copyright © 2019 Callum Hart. All rights reserved.
//

#include "CMLPrivate.hpp"

using namespace CML2P;

//constructor
template <typename T, int R, int C>
matrix<T, R, C>::matrix(int fill) {
    printf ("DATA_MODE: %i \n", DATA_STORE);
    int size = R*C;
#if (DATA_STORE == 0)
    data.reserve(size); //reserves our data
    for (int i=0; i<size; i++) { data.push_back(fill); } //sets all to zero
#elif (DATA_STORE == 1)
    data = new T[size];
    for (int i=0; i<size; i++) { data[i] = fill; } //sets all to zero
#elif (DATA_STORE == 2)
    data = new T*[R];
    for (int i=0; i<R; i++) {
        data[i] = new T[C]; //x
        for (int j=0; j<C; j++) {
            data[i][j] = fill; //set as 0
        }
    }
#endif
};

//destructor
template <typename T, int R, int C>
matrix<T, R, C>::~matrix() {
#if (DATA_STORE == 0)
    data.clear();
#elif (DATA_STORE == 1)
    delete [] data;
    data = nullptr;
#elif (DATA_STORE == 2)
    for(int i = 0; i < C; i++){
        delete [] data[i];
    }
    delete [] data;
    data = nullptr;
#endif
};

//op overloads
template <typename T, int R, int C>
matrix<T, R, C> matrix<T, R, C>::operator-(const matrix<T, R, C> &rhs) {
    matrix<T,R,C> result;
    for(int i = 0; i < R*C; i++){
        result.data[i]=this->data[i]-rhs.data[i];
    }
    return result;
}

template <typename T, int R, int C>
matrix<T, R, C> matrix<T, R, C>::operator+(const matrix<T, R, C> &rhs) {
    matrix<T,R,C> result;
    for(int i = 0; i < R*C; i++){
        result.data[i]=this->data[i]+rhs.data[i];
    }
    return result;
}

template <typename T, int R, int C>
template <int C2>
matrix<T, R, C2> matrix<T, R, C>::operator*(const matrix<T, C, C2>& rhs){
    matrix<T,R,C2> result;
    
    //for each row in lhs
    for (unsigned rowL=0; rowL < R; rowL++) {
        //for each column in rhs
        for (unsigned colR=0; colR < C2; colR++) {
            int sum = 0;
            //calculate result
            for (int i = 0; i < C; i++){
                //lhs(rowL,i) * rhs(i,colR)
                //sum += this->data[rowL][i] * rhs(i,colR);
                sum += (*this)(rowL,i) * rhs(i,colR);
            }
            int row = rowL; int col = colR; //result position
            //assign resulting sum to correct position
            result(row,col) = sum;
        }
    }
    
    return result;
}

//data access
template <typename T, int R, int C>
T& matrix<T,R,C>::operator()(const unsigned& row, const unsigned& col) {
#if (DATA_STORE == 0)
    return this->data[(row*C)+col]; //vector data
#elif (DATA_STORE == 1)
    return this->data[(row*C)+col]; //single array
#elif (DATA_STORE == 2)
    return this->data[row][col]; //2d array
#endif
}

template <typename T, int R, int C>
const T& matrix<T,R,C>::operator()(const unsigned& row, const unsigned& col) const {
#if (DATA_STORE == 0)
    return this->data[(row*C)+col]; //vector data
#elif (DATA_STORE == 1)
    return this->data[(row*C)+col]; //single array
#elif (DATA_STORE == 2)
    return this->data[row][col]; //2d array
#endif
}


//fun-ctions lol
template <typename T, int R, int C>
void matrix<T, R, C>::printint(){
    printf ("DATA_MODE: %i, Size: %i*%i \n", DATA_STORE, R, C);
    for (unsigned row=0; row < R; row++) {
        for (unsigned col=0; col < C; col++) {
            printf ("%i,", (int)(*this)(row,col));
        }
        printf ("\n");
    }
}


template <typename T, int R, int C>
void matrix<T, R, C>::printfloat(){
    printf ("DATA_MODE: %i, Size: %i*%i \n", DATA_STORE, R, C);
    for (unsigned row=0; row < R; row++) {
        for (unsigned col=0; col < C; col++) {
            printf ("%f,", (float)(*this)(row,col));
        }
        printf ("\n");
    }
}
