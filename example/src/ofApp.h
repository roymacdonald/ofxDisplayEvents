#pragma once

#include "ofMain.h"
#include "ofxDisplaysEvents.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	void displayChange(ofxDisplayEventsArgs & e);



};
