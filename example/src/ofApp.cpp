#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofxDisplayEvents::enableDisplayEvents();
	ofAddListener(ofxDisplayEvents::displayEvent, this, &ofApp::displayChange);
	//Once you have this running, go to your display preferences and change any of the parameters and check what is being printed to the console
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}

//--------------------------------------------------------------
void ofApp::displayChange(ofxDisplayEventsArgs & e){
	cout << "NEW DISPLAY EVENT " << e.ID << endl;
	if(e.bAnyEvent){// is true if any other event argument is true;
		cout << "displayChanged ID: " << e.ID << endl;
	}
	if(e.bBeginConfig){
		cout << "begin config" << endl;		
	}
	if(e.bMoved){
		cout << "moved" << endl;	
	}
	if(e.bSetMain){
		cout << "set main" << endl;	
	}
	if(e.bSetMode){
		cout << "set mode" << endl;	
	}
	if(e.bAdded){
		cout << "added" << endl;	
	}
	if(e.bRemoved){
		cout << "removed" << endl;	
	}
	if(e.bEnabled){
		cout << "enabled" << endl;	
	}
	if(e.bDisabled){
		cout << "disabled" << endl;	
	}
	if(e.bMirror){
		cout << "mirror" << endl;	
	}
	if(e.bUnMirror){
		cout << "unMirror" << endl;	
	}
	if(e.bDesktopShapeChanged){
		cout << "desktop shape changed" << endl;	
	}
	cout << "==================================" << endl;
}