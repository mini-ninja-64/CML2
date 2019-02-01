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

//assign memory (if it is static there is no need to assign any memory
#if (DYNAMIC_ARRAY)
    #if (DATA_STORE == 1)
        data = new T[R*C]; // allocates memory
    #elif (DATA_STORE == 2)
        data = new T*[R]; //allocates array
        for (int i=0; i<R; i++) {
            data[i] = new T[C]; //allocates memory for coulumn
        }
    #elif (DATA_STORE == 3)
        data = new vector<T, R>[C]; //allocates vector array
    #endif
#endif
    
//fill our arrays
#if (DATA_STORE == 0)
    data.reserve(R*C); //reserves our data
    for (int i=0; i<R*C; i++) { data.push_back(fill); } //sets all to zero
#else
    for (int row=0; row<R; row++) {
        for (int col=0; col<C; col++) {
            (*this)(row,col) = fill; //fill matirx
        }
    }
#endif
    
};

//destructor
template <typename T, int R, int C>
matrix<T, R, C>::~matrix() {
    
#if (DATA_STORE == 0) //delete std::vector
        data.clear();
#endif
    
#if (DYNAMIC_ARRAY) //only need to memory manage if using dynamic arrays
    #if ((DATA_STORE == 1) || (DATA_STORE == 3)) //delete the allocated space for 1 dimensional array types
        delete [] data;
        data = nullptr;
    #elif (DATA_STORE == 2) //delete the 2D array
        for(int i = 0; i < C; i++){
            delete [] data[i];
        }
        delete [] data;
        data = nullptr;
    #endif
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
#elif (DATA_STORE == 3)
    return this->data[col](row); //get the correct column vector and its corresponding row
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
#elif (DATA_STORE == 3)
    return this->data[col](row); //get the correct column vector and its corresponding row
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

//Custom Vecs
#if (DATA_STORE == 3)
//TODO: implement vector functions and stuff
#endif
