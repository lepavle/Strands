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
    Tile(std::vector<glm::vec2> vertices,
         std::vector<glm::mat3x3> T_mats) : vertices(vertices), T_mats(T_mats) { };
    
private:
    
    std::vector<glm::vec2> vertices;
    std::vector<glm::mat3x3> T_mats;
};

#endif /* Tile_hpp */
