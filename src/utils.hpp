//
//  utils.hpp
//  Strands
//
//  Created by Pavle Simonovic on 3/17/20.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>

#include "ofMain.h"

#include "Tile.hpp"

class utils
{
    
public:
    // draw tile in middle of window
    static void drawTile(Tile tile);
    
    static void drawEdges(std::vector<Edge> edges);
    
    static Edge rotateEdge(Edge edge, float angle);
    
    static Edge translateEdge(Edge edge, glm::vec2 T);
    
    static float intersectRays(Edge a, Edge b);
};

#endif /* utils_hpp */
