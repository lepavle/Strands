//
//  StarPattern.cpp
//  Strands
//
//  Created by Pavle Simonovic on 3/5/20.
//

#include "StarPattern.hpp"

void StarPattern::generateStarPattern()
{
    /* A motif only needs to be computed once per tile type.
     * We create one tile corresponding to each type in the
     * provided tiling and generate its motif.
     */
    bool seen[5] = { 0 };
    for(auto tile : baseTiling.getTiles())
    {
        seen[tile.numVertices()-1] = true;
    }
    std::vector<Tile> baseTiles;
    for(int i = 0; i < 5; ++i)
    {
        if(seen[i])
        {
            Tile baseTile = ArchimedeanTiling::getRegularPolygon(i+1);
            baseTiles.push_back(baseTile);
        }
    }
}

void StarPattern::generateStarPatternOfTile(Tile tile)
{
    /* For each edge, define a pair of (normalized) rays
     * determined by the given contact angle.
     */
    auto edges = tile.getEdges();
    std::vector< std::pair< glm::vec2, glm::vec2 > > rays;
    
    double pi = 3.14159265358979323846264;
    
    for(auto edge : edges)
    {
        glm::vec2 a = edge.first;
        glm::vec2 b = edge.second;
        
        glm::vec2 midpt = a + .5*(b - a);
        
        // get first ray
        glm::vec2 axis = b - a;
        glm::vec2 r1, r2;
        
        r1.x = axis.x * cos(contactAngle) - axis.y * sin(contactAngle);
        r1.y = axis.x * sin(contactAngle) + axis.y * cos(contactAngle);
        
        // normalize
        r1 /= r1.length();
        
        // rotate to get second ray
        float rayTheta = 2*pi - contactAngle;
    }
}
