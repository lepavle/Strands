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
        auto tileRays = getRaysOfTile(tile);
        rays.insert(rays.end(), tileRays.begin(), tileRays.end());
    }
    
    std::vector<Edge> motifEdges;
    int i = 0;
    for(auto tile : baseTiling.getTiles())
    {
        auto motif = generateStarPatternOfTile(tile);
        motifEdges.insert(motifEdges.end(), motif.begin(), motif.end());
        //motifEdges.insert(motifEdges.end(), tile.getEdges().begin(), tile.getEdges().end());
    }
    this->motifEdges = motifEdges;
}

std::vector<Edge> StarPattern::generateStarPatternOfTile(Tile tile)
{
    /* For each edge, define a pair of (normalized) rays
     * determined by the given contact angle.
     */
    
    double pi = 3.14159265358979323846264;
    
    std::vector<Edge> rays = getRaysOfTile(tile);
    
    tile.setRays(rays);
        
    int numRays = rays.size();
        
    // return rays;
        
    // cost -> ray indices
    std::vector< std::pair<float, std::pair< int, int >> > costData;
    
    // ray pair indices -> poi
    std::vector< std::vector<glm::vec2> > poiArr(numRays,
                                                 std::vector<glm::vec2>(numRays));
    
    std::vector<Edge> test;
    // pairwise ray intersection
    for(int i = 0; i < numRays; ++i)
    {
        for(int j = 0; j < numRays; ++j)
        {
            if(i == j) continue;
            
            Edge ab = rays[i];
            Edge cd = rays[j];
            
            float t = utils::intersectRays( ab ,  cd );
                    
            max_t = std::max(max_t, t);
            
            // point of intersection
            glm::vec2 poi = ab.first + t * (ab.second - ab.first);
            poiArr[i][j] = poi;
            
            float apLen = glm::length(poi - ab.first);
            float cpLen = glm::length(poi - cd.first);
            
            float cost = apLen + cpLen;
            
            if(cost == 0) continue;
            
            auto data = std::make_pair( cost , std::make_pair(i,j) );
            
            costData.push_back(data);
        }
    }
    
    std::cout << "MAX T : " << max_t << std::endl;
    
    // sort by cost
    std::sort(costData.begin(), costData.end());
    
    // we flag a ray when it is used
    std::vector<bool> used(numRays, 0);
    int numUsed = 0;
    
    std::vector<Edge> motif;
    for(auto dat : costData)
    {
        if(numUsed == numRays) break;
        auto rayIndices = dat.second;
        
        int i = rayIndices.first;
        int j = rayIndices.second;
        
        if(used[i] || used[j]) continue;

        Edge ab = rays[i];
        Edge cd = rays[j];
        
        // for each intersection, we add two segments
        glm::vec2 poi = poiArr[i][j];
        
        Edge ap = std::make_pair(ab.first, poi);
        Edge cp = std::make_pair(cd.first, poi);
        
        motif.push_back(ap);
        //std::cout << ap.first << " " << ap.second << std::endl;
        motif.push_back(cp);
        
        used[i] = true;
        used[j] = true;
        
        numUsed += 2;
    }
    
    return motif;
}

std::vector<Edge> StarPattern::getRaysOfTile(Tile tile)
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
        Edge r2 = utils::rotateEdge(edge, M_PI - contactAngle);
        r2.first += .5*(b-a);
        r2.second += .5*(b-a);
        
        rays.push_back(r2);
    }
    
    return rays;
}

