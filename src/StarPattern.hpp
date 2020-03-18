//
//  StarPattern.hpp
//  Strands
//
//  Created by Pavle Simonovic on 3/5/20.
//

#ifndef StarPattern_hpp
#define StarPattern_hpp

#include <stdio.h>

#include "utils.hpp"

#include "ArchimedeanTiling.hpp"

#include "StarPattern.hpp"

class StarPattern
{
    
public:
    
    StarPattern(ArchimedeanTiling baseTiling) : baseTiling(baseTiling) { };

public:
    
    void generateStarPattern();
    void generateStarPatternOfTile(Tile tile);
    
    static std::vector<Edge> getRaysOfTile(Tile tile, double contactAngle);
    
private:
    
    ArchimedeanTiling baseTiling;
    
private:
    
    glm::vec2 rotate(float rad);
    
};

#endif /* StarPattern_hpp */
