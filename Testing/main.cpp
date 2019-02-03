//
//  main.cpp
//  Testing
//
//  Created by Callum Hart on 17/01/2019.
//  Copyright © 2019 Callum Hart. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <CML2.hpp>

int main(int argc, const char * argv[]) {
    clock_t t = clock();
    
    CML2::mat4 m(2);
    m(3,3) = 9;
    CML2::mat4 m2(3);
    CML2::mat4 r = m*m2;
    t = clock() - t;
    r.printint();
    printf("%d ticks taken \n", t);
    return 0;
}

//benchmarking
//static: 6 ticks, 3 ticks, 3 ticks
//dynamic: 6 ticks, 3/4 ticks, 4 ticks
