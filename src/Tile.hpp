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

#include "ofMain.h"

// debug
#include <iostream>
#include <utility>

typedef std::pair< glm::vec2, glm::vec2 > Edge;

class Tile
{
    
public:
    
    Tile(std::vector<glm::vec2> vertices);
    
    Tile& operator=(const Tile& other)
    {
        this->vertices = other.vertices;
        this->edges = other.edges;
        this->T = other.T;
        return *this;
    }
    
public:
    
    int numVertices() { return vertices.size(); }
    glm::vec2 getVertex(int i) { return vertices[i]; }
    std::vector<glm::vec2> getVertices() { return vertices; }
    
    int numEdges() { return edges.size(); }
    std::vector<Edge> getEdges() { return edges; }
    void updateEdges();
    
    int numRays() { return rays.size(); }
    std::vector<Edge> getRays() { return rays; }
    void setRays(std::vector<Edge> rays) { this->rays = rays; }

public:
    
    void scale(float s);
    void translate(glm::vec2 T);
    
    void setAffineTransformation(glm::mat3 T) { this->T = T; }
    
    void applyAffineTransformation();
    void setColor(ofColor color) { this->color = color; }
    
    void draw();
    
private:
    
    std::vector<glm::vec2> vertices;
    std::vector<Edge> edges;
    glm::mat3 T;
    ofColor color;
    
    // motif data
    std::vector<Edge> rays;
    
};

#endif /* Tile_hpp */
