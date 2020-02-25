//
//  ArchimedeanTiling.hpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#ifndef ArchimedeanTiling_hpp
#define ArchimedeanTiling_hpp

#include <stdio.h>

#include <tinyxml2.h>

#include <iostream>
#include <vector>
#include <string>

#include "ofMain.h"

#include "Tile.hpp"

class ArchimedeanTiling
{
    
public:
        
    ArchimedeanTiling(const char* type);
    
    void fill(int width, int height);

public:
    
    static Tile getRegularTile(int num_sides);
    
private:
    
    std::vector<Tile> tiles;
    
    void setTranslations(glm::vec2 a, glm::vec2 b);
    void setTransformations(std::vector<glm::mat3> T_mats);
    
    void getTilingData(const char* type);
};

#endif /* ArchimedeanTiling_hpp */
