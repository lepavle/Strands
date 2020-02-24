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

#include "Tile.hpp"

class ArchimedeanTiling
{
    
public:
        
    ArchimedeanTiling(const char* type);
    
    void fill(int width, int height);
    
    void setTranslations(glm::vec2 a, glm::vec2 b);
    void setTransformations(std::vector<glm::mat3> T_mats);
    
private:
    
    std::vector<Tile> tiles;
        
};

#endif /* ArchimedeanTiling_hpp */
