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
    std::vector<Edge> rays;
    for(auto tile : baseTiling.getTiles())
    {
        auto tileRays = getRaysOfTile(tile, M_PI/4);
        rays.insert(rays.end(), tileRays.begin(), tileRays.end());
    }
    this->rays = rays;
}

void StarPattern::generateStarPatternOfTile(Tile tile)
{
    /* For each edge, define a pair of (normalized) rays
     * determined by the given contact angle.
     */
    
    double pi = 3.14159265358979323846264;
    
    /* Inference alg */
    inference(tile);
}

std::vector<Edge> StarPattern::inference(Tile tile)
{
    std::vector<Edge> rays = getRaysOfTile(tile, M_PI/4);
    
    int numRays = rays.size();
    
    // we flag a ray when it is used
    std::vector<bool> used(numRays, 0);
    
    // we associated a cost with each pair of rays
    std::map<std::pair<int,int>, float> costs;
    
    // pairwise ray intersection
    for(int i = 0; i < rays.size(); ++i)
    {
        for(int j = 0; j < rays.size(); ++j)
        {
            if(i == j) continue;
            
            Edge ab = rays[i];
            Edge cd = rays[j];
            float t = utils::intersectRays( ab,  cd );
                        
            // point of intersection
            glm::vec2 p = ab.first + t * (ab.second - ab.first);
            
            float apLen = glm::length(p - ab.first);
            float cpLen = glm::length(p - cd.first);
            
            float cost = apLen + cpLen;
            
            costs[std::make_pair( i, j )] = cost;
        }
    }
}

std::vector<Edge> StarPattern::getRaysOfTile(Tile tile, double contactAngle)
{
    std::vector<Edge> edges = tile.getEdges();
    std::vector<Edge> rays;

    for(auto edge : edges)
    {
        glm::vec2 a = edge.first;
        glm::vec2 b = edge.second;
        
        glm::vec2 midpt = a + .5*(b - a);
        
        Edge r1 = utils::rotateEdge(edge, contactAngle);
        r1.first += .5*(b-a);
        r1.second += .5*(b-a);
        
        rays.push_back(r1);
        
        // reflect to get second ray
        Edge r2 = utils::rotateEdge(edge, 2*M_PI - contactAngle);
        r2.first += .5*(b-a);
        r2.second += .5*(b-a);
        
        rays.push_back(r2);
    }
    
    return rays;
}

