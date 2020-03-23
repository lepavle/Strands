#pragma once

#include "ofMain.h"

#include "StarPattern.hpp"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:

    ArchimedeanTiling tiling;
    StarPattern starPattern;
    ofPath tilingPath;
    int timestep = 0;
    
    float angleMin = M_PI/5;
    float angleMax = M_PI/4;
    float currAngle = angleMin;
    bool increment = true;
		
};
