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
    getTilingData(type);
}

void ArchimedeanTiling::getTilingData(const char* type)
{
    bool debug = false;
    
    // load xml file
    XMLDocument archimedeans_xml;
    if(archimedeans_xml.LoadFile("/Users/pavsimono/workspace/of_v0.11.0_osx_release/apps/myApps/Strands/data/archimedeans.tl") != XML_SUCCESS)
    {
        std::cout << "failed to load archimedeans.tl" << std::endl;
        return;
    }
    
    XMLElement *root = archimedeans_xml.RootElement();
    
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
            
            double a_x = std::stod(trans_a->FindAttribute("x")->Value());
            double a_y = std::stod(trans_a->FindAttribute("y")->Value());
            
            double b_x = std::stod(trans_b->FindAttribute("x")->Value());
            double b_y = std::stod(trans_b->FindAttribute("y")->Value());
            
            if(debug)
            {
                // print translation vectors
                std::cout << "a : " << a_x << " " << a_y << std::endl;
                std::cout << "b : " << b_x << " " << b_y << std::endl;
            }
                
            // get tiles
            XMLElement *tile = translations->NextSiblingElement();
            while(tile)
            {
                // get tile shape
                XMLElement *shape = tile->FirstChildElement();
                // get num sides of tile
                int num_sides = std::stoi(shape->FindAttribute("sides")->Value());
                
                if(debug) std::cout << "num_sides : " << num_sides << std::endl;
                
                // get transforms of tile
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
                    double T_arr[9] = { a, b, c, d, e, f, 0, 0, 1 }; // row-wise
                    glm::mat3 T = glm::transpose(glm::make_mat3(T_arr));
                    
                    if(debug) {
                        // print transform
                        std::cout << "transform : " << std::endl;
                        std::cout << T << std::endl << std::endl;
                    }
                      
                    // get next transform
                    transform = transform->NextSiblingElement();
                }
                
                // get next tile
                tile = tile->NextSiblingElement();
            }
            return;
        }
        
        // go to next tiling definition
        tiling = tiling->NextSiblingElement();
    }
}

Tile ArchimedeanTiling::getRegularTile(int num_sides)
{
    std::vector<glm::vec2> vertices(num_sides);

    double pi = 3.14159265358979323846264;

    for( int idx = 0; idx < num_sides; ++idx ) {
        double angle = (pi / num_sides) * ( 2 * idx + 1 );
        double sc = 1.0 / std::cos( pi / num_sides );
        double x = sc * std::cos( angle );
        double y = sc * std::sin( angle );
        vertices[ idx ] = glm::vec2( x , y );
    }
    
    return Tile(vertices);
}
