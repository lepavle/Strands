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
        
    StarPattern(ArchimedeanTiling baseTiling) : baseTiling(baseTiling)
    { };
    
public:
    
    std::vector<Edge> getMotifEdges() { return motifEdges; }

public:
    
    void generateStarPattern();
    std::vector<Edge> generateStarPatternOfTile(Tile tile);
    
    static std::vector<Edge> getRaysOfTile(Tile tile, double contactAngle);
    
private:
    
    ArchimedeanTiling baseTiling;
    std::vector<Edge> motifEdges;

private:
    
    glm::vec2 rotate(float rad);
    
    
};

#endif /* StarPattern_hpp */
