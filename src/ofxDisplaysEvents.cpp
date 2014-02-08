#include "ofxDisplaysEvents.h"



bool ofxDisplayEvents::bIsRegistered = false;
ofEvent<ofxDisplayEventsArgs> ofxDisplayEvents::displayEvent = ofEvent<ofxDisplayEventsArgs>();

void ofxDisplayEvents::enableDisplayEvents(){
	if(!bIsRegistered){
		CGDisplayRegisterReconfigurationCallback(ofxDisplayEvents::displayReconfigCB,NULL);
		bIsRegistered = true;
	}else{
		ofLogWarning("ofxDisplayEvents::enableDisplayEvents()", "display events already registered");
	}
}
void ofxDisplayEvents::disableDisplayEvents(){
	if(bIsRegistered){
		CGDisplayRegisterReconfigurationCallback(ofxDisplayEvents::displayReconfigCB,NULL);
		bIsRegistered = false;
	}else{
		ofLogWarning("ofxDisplayEvents::disableDisplayEvents()", "no display events registered");
	}
}
void ofxDisplayEvents::displayReconfigCB(CGDirectDisplayID display, CGDisplayChangeSummaryFlags flags, void *userInfo){
	ofxDisplayEventsArgs a;
	a.ID = display;
	a.bBeginConfig = flags & kCGDisplayBeginConfigurationFlag;
	a.bMoved = flags & kCGDisplayMovedFlag;
	a.bSetMain = flags & kCGDisplaySetMainFlag;
	a.bSetMode = flags & kCGDisplaySetModeFlag;
	a.bAdded = flags & kCGDisplayAddFlag;
	a.bRemoved = flags & kCGDisplayRemoveFlag;
	a.bEnabled = flags & kCGDisplayEnabledFlag;
	a.bDisabled = flags & kCGDisplayDisabledFlag;
	a.bMirror = flags & kCGDisplayMirrorFlag;
	a.bUnMirror = flags & kCGDisplayUnMirrorFlag;
	a.bDesktopShapeChanged = flags & kCGDisplayDesktopShapeChangedFlag;
	a.bAnyEvent = a.bBeginConfig || a.bMoved || a.bSetMain || a.bSetMode || a.bAdded || a.bRemoved || a.bEnabled || a.bDisabled || a.bMirror || a.bUnMirror || a.bDesktopShapeChanged;
	ofNotifyEvent(displayEvent, a);
}



