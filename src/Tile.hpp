//
//  Tile.hpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>

#include <vector>

#include "ofMain.h"

// debug
#include <iostream>

class Tile
{
public:
    
    Tile(std::vector<glm::vec2> vertices) : vertices(vertices){ }
    
    Tile& operator=(const Tile& other)
    {
        this->vertices = other.getVertices();
        return *this;
    }
    
    std::vector<glm::vec2> getVertices() const { return vertices; }
    
    void applyAffineTransformation(glm::mat3 T);
    
private:
    
    std::vector<glm::vec2> vertices;
};

#endif /* Tile_hpp */
