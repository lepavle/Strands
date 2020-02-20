#include "ofApp.h"

using namespace tinyxml2;

#include <filesystem>

//--------------------------------------------------------------
void ofApp::setup(){
    std::cout << std::filesystem::current_path() << std::endl;
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
            
            // print translation vectors
            std::cout << "a : " << a_x << " " << a_y << std::endl;
            std::cout << "b : " << b_x << " " << b_y << std::endl;
            
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
                    
                    // print transform
                    std::cout << "transform : " << std::endl;
                    std::cout << T << std::endl << std::endl;
                    
                    // get next transform
                    transform = transform->NextSiblingElement();
                }
                
                // get next tile
                tile = tile->NextSiblingElement();
            }
            
            // go to next tiling definition
            tiling = tiling->NextSiblingElement();
        }
    }
    else
    {
        std::cout << "failed to load archimedeans.tl" << std::endl;
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
