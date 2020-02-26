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
        this->vertices = other.vertices;
        this->T = other.T;
        return *this;
    }
    
    std::vector<glm::vec2> getVertices() const { return vertices; }
    
    void translate(glm::vec2 T);
    
    void setAffineTransformation(glm::mat3 T) { this->T = T; }
    
    void applyAffineTransformation();
    
private:
    
    std::vector<glm::vec2> vertices;
    glm::mat3 T;
};

#endif /* Tile_hpp */
