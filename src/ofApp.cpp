#include "ofApp.h"

using namespace tinyxml2;

#include <filesystem>

//--------------------------------------------------------------
void ofApp::setup(){
    
    bool debug = false;
    
    // read in tilings
    XMLDocument archimedeans_xml;
    if(archimedeans_xml.LoadFile("/Users/pavsimono/workspace/of_v0.11.0_osx_release/apps/myApps/Strands/data/archimedeans.tl") == XML_SUCCESS)
    {
        XMLElement *root = archimedeans_xml.RootElement();
        
        // loop through tilings
        XMLElement *tiling = root->FirstChildElement();
        while(tiling)
        {
            std::cout << "reading " << tiling->FindAttribute("name")->Value() << std::endl;
            
            // get translation vectors
            std::cout << "reading translation vectors" << std::endl;
            XMLElement *translations = tiling->FirstChildElement();
            XMLElement *trans_a = translations->FirstChildElement();
            XMLElement *trans_b = trans_a->NextSiblingElement();
            
            double a_x = std::stod(trans_a->FindAttribute("x")->Value());
            double a_y = std::stod(trans_a->FindAttribute("y")->Value());
            
            double b_x = std::stod(trans_b->FindAttribute("x")->Value());
            double b_y = std::stod(trans_b->FindAttribute("y")->Value());
            
            if(debug == true)
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
                    double T_arr[9] = { a, b, c, d, e, f, 0, 0, 1}; // row-wise
                    glm::mat3 T = glm::transpose(glm::make_mat3(T_arr));
                    
                    if(debug == true){
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
            
            // go to next tiling definition
            tiling = tiling->NextSiblingElement();
            std::cout << "here" << std::endl;
        }
    }
    else
    {
        std::cout << "failed to load archimedeans.tl" << std::endl;
    }
    
    // constants
    double side_len = 2;
    double pi = 3.14159265358979323846264;
    
    // compute equilateral triangle vertices
    std::vector<glm::vec2> triangle_vertices;
    
    double tri_theta_offs = 0.698132;
    
    double tri_radius = side_len/(2*std::sin(pi/3));

    double x_tri_offs = -1*tri_radius*std::sin(2*(2*pi/3));
    double y_tri_offs = -1*tri_radius*std::cos(2*(2*pi/3));
    
    for(int i = 0; i < 3; ++i)
    {
        double radians = i*(2*pi/3);
        double x = tri_radius*std::sin(radians) + x_tri_offs;
        double y = tri_radius*std::cos(radians) + y_tri_offs;
        triangle_vertices.push_back(glm::vec2(x,y));
    }
    
    // compute pentagon vertices
    std::vector<glm::vec2> pentagon_vertices;
    
    double pent_radius = side_len/(2*std::sin(pi/5));

    double x_pent_offs = -1*pent_radius*std::sin(3*(2*pi/5));
    double y_pent_offs = -1*pent_radius*std::cos(3*(2*pi/5));

    for(int i = 0; i < 5; ++i)
    {
        double radians = i*(2*pi/5);
        double x = pent_radius*std::sin(radians) + x_pent_offs;
        double y = pent_radius*std::cos(radians) + y_pent_offs;
        pentagon_vertices.push_back(glm::vec2(x,y));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
