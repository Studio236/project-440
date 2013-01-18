#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// print the available output ports to the console
	ofxMidiOut::listPorts(); // via static too
	
	// connect
	midiOut.openPort(1);	// by number
	//midiOut.openPort("IAC Driver Pure Data In");	// by name
	//midiOut.openVirtualPort("ofxMidiOut");		// open a virtual port
	
	channel = 1;
	currentPgm = 0;
	note = 0;
	velocity = 0;
	controllers[0] = 100;
	controllers[1] = 100;
	controllers[2] = 100;


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	// let's see something
	ofSetColor(0);
	stringstream text;
	text << "connected to port " << midiOut.getPort() 
		 << " \"" << midiOut.getName() << "\"" << endl
		 << "is virtual?: " << midiOut.isVirtual() << endl << endl
		 << "sending to channel " << channel << endl << endl
		 << "current program: " << currentPgm << endl << endl
		 << "Controller One: " << controllers[0] << endl
		 << "Controller Two: " << controllers[1] << endl
		 << "Three? (click): " << controllers[2];
	ofDrawBitmapString(text.str(), 20, 20);
	if(controllers[2] > 0) {
		controllers[2] --;
	}
	midiOut.sendControlChange(channel, 40, controllers[2]);
	
	

}

void testApp::exit() {
	// clean up
	midiOut.closePort();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){


	//Param 1 - Controller 20
	controllers[0] = ofMap(x, 0, ofGetWidth(), 0, 127);
	midiOut.sendControlChange(channel, 20, controllers[0]);

	//Param 2 - Controller 30
	controllers[1] = ofMap(y, 0, ofGetWidth(), 0, 127);
	midiOut.sendControlChange(channel, 30, controllers[1]);

	
	
	

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//Param 1 - Controller 40
	controllers[2] = 127;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}