//
//  Tile.cpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#include "Tile.hpp"

void Tile::applyAffineTransformation(glm::mat3 T)
{
    std::vector<glm::vec2> transformedVertices;
    
    for(auto v : vertices)
    {
        glm::vec3 V( v.x, v.y , 1);
        V = T*V;
        transformedVertices.push_back(glm::vec2( V.x , V.y ));
    }
    
    vertices = transformedVertices;
}
