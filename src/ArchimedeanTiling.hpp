//
//  ArchimedeanTiling.hpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#ifndef ArchimedeanTiling_hpp
#define ArchimedeanTiling_hpp

#include <stdio.h>

#include <tinyxml2.h>

#include <iostream>
#include <vector>
#include <string>

#include "ofMain.h"

#include "Tile.hpp"

#include <math.h>

class ArchimedeanTiling
{
    
public:
        
    ArchimedeanTiling(const char* type);
    
    void fill(int width, int height);
    
    ofPath getPath() { return tilingPath; }
    
    std::vector<Tile> getTiles() { return tiles; }

public:
    
    static Tile getRegularPolygon(int numSides);
    
private:
    
    void readTilingData(const char* type);
    
private:
    
    ofPath tilingPath;
    
    std::vector<Tile> tiles;
    
    glm::vec2 A, B;
};

#endif /* ArchimedeanTiling_hpp */
