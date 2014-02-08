#pragma once

#include "ofMain.h"
#import <ApplicationServices/ApplicationServices.h>

class ofxDisplayEventsArgs : public ofEventArgs{
public:
	uint32_t ID;
	bool bBeginConfig, bMoved, bSetMain, bSetMode, bAdded, bRemoved, bEnabled, bDisabled, bMirror, bUnMirror, bDesktopShapeChanged, bAnyEvent;
};
class ofxDisplayEvents{
public:
	static ofEvent<ofxDisplayEventsArgs> displayEvent;

	static void enableDisplayEvents();
	static void disableDisplayEvents();
	static bool IsEnabled();
	static void displayReconfigCB(CGDirectDisplayID display, CGDisplayChangeSummaryFlags flags, void *userInfo);
private:
	static bool bIsRegistered;
	
};
