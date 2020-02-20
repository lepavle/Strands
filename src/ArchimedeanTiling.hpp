//
//  ArchimedeanTiling.hpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#ifndef ArchimedeanTiling_hpp
#define ArchimedeanTiling_hpp

#include <stdio.h>

#include <vector>

#include <glm/mat3x3.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class ArchimedeanTiling
{
    
public:
        
    ArchimedeanTiling(const char* type);
    
    void generate();
    
    void setTranslations(glm::vec2 a, glm::vec2 b);
    void setTransformations(std::vector<glm::mat3> T_mats);
        
};

#endif /* ArchimedeanTiling_hpp */
