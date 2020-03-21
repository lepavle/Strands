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
    path.setStrokeWidth(3);
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
