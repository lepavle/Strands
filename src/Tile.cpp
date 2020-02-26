//
//  Tile.cpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#include "Tile.hpp"

void Tile::translate(glm::vec2 T)
{
    std::vector<glm::vec2> translatedVertices;

    for(auto v : vertices)
    {
        translatedVertices.push_back(v + T);
    }
    
    vertices = translatedVertices;
}

void Tile::applyAffineTransformation()
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
