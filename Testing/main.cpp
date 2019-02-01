//
//  main.cpp
//  Testing
//
//  Created by Callum Hart on 17/01/2019.
//  Copyright © 2019 Callum Hart. All rights reserved.
//

#include <iostream>
#include <CML2.hpp>

int main(int argc, const char * argv[]) {
    
    CML2::mat4 m(2);
    m(3,3) = 9;
    CML2::mat4 m2(3);
    CML2::mat4 r = m*m2;
    r.printint();
    return 0;
}
