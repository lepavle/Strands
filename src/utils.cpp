//
//  utils.cpp
//  Strands
//
//  Created by Pavle Simonovic on 3/17/20.
//

#include "utils.hpp"

void utils::drawTile(Tile tile)
{
    return;
}

void utils::drawEdges(std::vector<Edge> edges)
{
    ofPath path;
    path.setStrokeColor(ofColor::white);
    path.setStrokeWidth(2);
    for(auto edge : edges)
    {
        path.moveTo(edge.first);
        path.lineTo(edge.second);
    }
    path.draw();
}

Edge utils::rotateEdge(Edge edge, float angle)
{
    glm::vec2 axis = edge.second - edge.first;
    
    glm::vec2 rot;
    
    rot.x = axis.x * cos(angle) - axis.y * sin(angle);
    rot.y = axis.x * sin(angle) + axis.y * cos(angle);
    
    glm::vec2 org = edge.first;
    glm::vec2 dst = org + rot;
    
    return std::make_pair( org , dst );
}

Edge utils::translateEdge(Edge edge, glm::vec2 T)
{
    return std::make_pair(edge.first + T, edge.second + T);
}

float utils::intersectRays(Edge a, Edge b)
{
    float x1 = a.first.x;
    float y1 = a.first.y;
    
    float x2 = a.second.x;
    float y2 = a.second.y;
    
    float x3 = b.first.x;
    float y3 = b.first.y;
    
    float x4 = b.second.x;
    float y4 = b.second.y;
    
    float top = (x1 - x3)*(y3 - y4) - (y1 - y2)*(x1 - x3);
    float bot = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
    
    if(bot < 1e-5) return 1e+6;
    
    return top/bot;
}
