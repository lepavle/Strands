//
//  StarPattern.hpp
//  Strands
//
//  Created by Pavle Simonovic on 3/5/20.
//

#ifndef StarPattern_hpp
#define StarPattern_hpp

#include <stdio.h>

#include "ArchimedeanTiling.hpp"

class StarPattern
{
    
public:
    
    StarPattern(ArchimedeanTiling baseTiling, double contactAngle) :
    baseTiling(baseTiling), contactAngle(contactAngle) { };

private:

    void generateStarPattern();
    void generateStarPatternOfTile(Tile tile);
    
private:
    
    ArchimedeanTiling baseTiling;
    float contactAngle;
    
private:
    
    glm::vec2 rotate(float rad);
    
};

#endif /* StarPattern_hpp */
