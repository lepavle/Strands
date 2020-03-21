//
//  Tile.cpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#include "Tile.hpp"

Tile::Tile(std::vector<glm::vec2> vertices) : vertices(vertices)
{
    updateEdges();
}

void Tile::updateEdges()
{
    std::vector<std::pair<glm::vec2, glm::vec2>> edges;
    for(int i = 0; i < vertices.size(); ++i)
    {
        auto edge = std::make_pair(vertices[i],
                                   vertices[(i+1) % vertices.size()]);
        edges.push_back(edge);
    }
    this->edges = edges;
}

void Tile::draw()
{
    updateEdges();
    
    ofPath tilePath;
    tilePath.setStrokeColor(ofColor::white);
    tilePath.setStrokeWidth(3);
    tilePath.moveTo(vertices[0]);
    for(int i = 1; i < vertices.size(); ++i)
    {
        glm::vec2 a = vertices[i % vertices.size()];
        tilePath.lineTo(a);
    }
    tilePath.close();
    tilePath.draw();
}

void Tile::translate(glm::vec2 T)
{
    std::vector<glm::vec2> translatedVertices;

    for(auto v : vertices)
    {
        translatedVertices.push_back(v + T);
    }
    
    vertices = translatedVertices;
    
    updateEdges();
}

void Tile::scale(float s)
{
    std::vector<glm::vec2> scaledVertices;
    
    for(auto v : vertices)
    {
        scaledVertices.push_back(s*v);
    }
    
    vertices = scaledVertices;
    
    updateEdges();
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
    
    updateEdges();
}
        
