//
//  ArchimedeanTiling.cpp
//  Strands
//
//  Created by Pavle Simonovic on 2/19/20.
//

#include "ArchimedeanTiling.hpp"

using namespace tinyxml2;

ArchimedeanTiling::ArchimedeanTiling(const char* type)
{
    readTilingData(type);
}

void ArchimedeanTiling::fill(int width, int height)
{
    ofPath tilingPath;
    tilingPath.setStrokeColor(ofColor::black);
    tilingPath.setFillColor(ofColor::white);
    tilingPath.setStrokeWidth(3);
    
    double sc = 25;
    
    int num_horizontal = width;
    int num_vertical = height;
    
    ofColor color;
    
    for(int i = -num_horizontal; i < num_horizontal; ++i)
    {
        for(int j = -num_vertical; j < num_vertical; ++j)
        {
            for(auto tile : tiles)
            {
                tilingPath.newSubPath();

                Tile modified = tile;
                modified.applyAffineTransformation();
                modified.scale(sc);
                modified.translate(sc*i*A + sc*j*B + glm::vec2(200,200));
                std::vector<glm::vec2> vertices = modified.getVertices();
                                
                tilingPath.moveTo(vertices[0]);
                for(int i = 1; i < vertices.size(); ++i)
                {
                    glm::vec2 a = vertices[i % vertices.size()];
                    tilingPath.lineTo(a);
                }
                tilingPath.close();
            }
        }
    }
        
    this->tilingPath = tilingPath;
}

void ArchimedeanTiling::readTilingData(const char* type)
{
    bool debug = true;
    
    // vector of tiles
    std::vector<Tile> tiles;
    
    // load xml file
    XMLDocument archimedeansXML;
    if(archimedeansXML.LoadFile("/Users/pavsimono/workspace/of_v0.11.0_osx_release/apps/myApps/Strands/data/archimedeans.tl") != XML_SUCCESS)
    {
        std::cout << "failed to load archimedeans.tl" << std::endl;
        return;
    }
    
    XMLElement *root = archimedeansXML.RootElement();
    
    // loop through tilings
    XMLElement *tiling = root->FirstChildElement();
    while(tiling)
    {
        if(strcmp(type,tiling->FindAttribute("name")->Value()) == 0)
        {
            std::cout << "reading " << tiling->FindAttribute("name")->Value() << std::endl;
            
            // get translation vectors
            if(debug) std::cout << "reading translation vectors" << std::endl;
            
            XMLElement *translations = tiling->FirstChildElement();
            XMLElement *trans_a = translations->FirstChildElement();
            XMLElement *trans_b = trans_a->NextSiblingElement();
            
            double A_x = std::stod(trans_a->FindAttribute("x")->Value());
            double A_y = std::stod(trans_a->FindAttribute("y")->Value());
            
            double B_x = std::stod(trans_b->FindAttribute("x")->Value());
            double B_y = std::stod(trans_b->FindAttribute("y")->Value());
            
            this->A = glm::vec2(A_x, A_y);
            this->B = glm::vec2(B_x, B_y);
                        
            if(debug)
            {
                // print translation vectors
                std::cout << "a : " << A_x << " " << A_y << std::endl;
                std::cout << "b : " << B_x << " " << B_y << std::endl;
            }
            
            // get tiles in patch
            XMLElement *tile = translations->NextSiblingElement();
            while(tile)
            {
                // get tile shape
                XMLElement *shape = tile->FirstChildElement();
                // get num sides of tile
                int numSides = std::stoi(shape->FindAttribute("sides")->Value());
                
                if(debug) std::cout << "num_sides : " << numSides << std::endl;
                
                // get transforms of tile
                // for each transformation, we yield a tile with the current shape
                XMLElement *transform = shape->NextSiblingElement();
                while(transform)
                {
                    double a,b,c,d,e,f;
                    a = std::stod(transform->FindAttribute("a")->Value());
                    b = std::stod(transform->FindAttribute("b")->Value());
                    c = std::stod(transform->FindAttribute("c")->Value());
                    d = std::stod(transform->FindAttribute("d")->Value());
                    e = std::stod(transform->FindAttribute("e")->Value());
                    f = std::stod(transform->FindAttribute("f")->Value());
                    double T_arr[9] = { a, b, c, d, e, f, 0, 0, 1 };
                    glm::mat3 T = glm::transpose(glm::make_mat3(T_arr));
                    
                    if(debug) {
                        // print transform
                        std::cout << "transform : " << std::endl;
                        std::cout << T << std::endl << std::endl;
                    }

                    Tile tile = getRegularPolygon(numSides);
                    tile.setAffineTransformation(T);
                    tiles.push_back(tile);
                      
                    // get next transform
                    transform = transform->NextSiblingElement();
                }
                
                // get next tile
                tile = tile->NextSiblingElement();
            }
            
            this->tiles = tiles;
                        
            return;
        }
        else
        {
            // go to next tiling
            tiling = tiling->NextSiblingElement();
        }
    }
}

Tile ArchimedeanTiling::getRegularPolygon(int numSides)
{
    std::vector<glm::vec2> vertices;

    for( int idx = 0; idx < numSides; ++idx ) {
        double angle = (M_PI / numSides) * ( 2 * idx + 1 );
        double sc = 1.0 / std::cos( M_PI / numSides );
        double x = sc * std::cos( angle );
        double y = sc * std::sin( angle );
        vertices.push_back(glm::vec2( x , y ));
    }
    
    return Tile(vertices);
}
