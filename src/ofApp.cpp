#include "ofApp.h"

#include <filesystem>

//--------------------------------------------------------------
void ofApp::setup(){
    // ArchimedeanTiling tiling("3.3.3.3.3.3");
    // ArchimedeanTiling tiling("4.6.12");
    ArchimedeanTiling tiling("3.3.3.4.4");
    tiling.fill(30,30);
    tilingPath = tiling.getPath();
    this->tiling = tiling;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
    Tile tile = ArchimedeanTiling::getRegularPolygon(5);
    tile.scale(50);
    tile.translate(glm::vec2(200,200));
    tile.draw();
    std::vector<Edge> rays = StarPattern::getRaysOfTile(tile, M_PI/4);
    utils::drawEdges(rays);
     */
    // std::cout << starPattern.getRays().size() << std::endl;
    
    StarPattern starPattern(tiling, currAngle);
    starPattern.generateStarPattern();
    this->starPattern = starPattern;
    utils::drawEdges(starPattern.getMotifEdges());
    
    if(currAngle > angleMax) increment = false;
    if(currAngle < angleMin) increment = true;
    
    if(increment) currAngle += .5;
    else currAngle -= .5;
    // tilingPath.draw();
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
