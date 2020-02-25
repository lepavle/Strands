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

#include <glm/mat3x3.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Tile
{
public:
    
    Tile(std::vector<glm::vec2> vertices) : vertices(vertices) { }
    Tile(std::vector<glm::vec2> vertices, glm::mat3 T) : vertices(vertices), T(T) { }
    
    Tile& operator=(const Tile& other)
    {
        this->vertices = other.getVertices();
        return *this;
    }
    
    std::vector<glm::vec2> getVertices() const { return vertices; }
    
private:
    
    std::vector<glm::vec2> vertices;
    glm::mat3 T;
};

#endif /* Tile_hpp */
