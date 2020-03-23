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

class StarPattern
{
    
public:
    
    StarPattern() { };
        
    StarPattern(ArchimedeanTiling baseTiling, float contactAngle) : baseTiling(baseTiling), contactAngle(contactAngle)
    { };
    
public:
    
    std::vector<Edge> getMotifEdges() { return motifEdges; }

public:
    
    void generateStarPattern();
    std::vector<Edge> generateStarPatternOfTile(Tile tile);
    
private:
    
    std::vector<Edge> getRaysOfTile(Tile tile);
    
private:
    
    ArchimedeanTiling baseTiling;
    std::vector<Edge> motifEdges;

private:
    
    glm::vec2 rotate(float rad);
    
    float contactAngle;
    
    float max_t = 0; // debug
    
};

#endif /* StarPattern_hpp */
