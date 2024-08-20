#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	
	int radius = 250;
	ofColor color;
	for (int z = -300; z <= 300; z += 20) {

		auto deg_start = ofMap(ofNoise((z + 300) * 0.00085 + ofGetFrameNum() * 0.005), 0, 1, -720, 720);

		for (int deg = deg_start + 720; deg < deg_start + 360 + 720; deg += 90) {

			color.setHsb(ofMap(deg, deg_start + 720, deg_start + 360 + 720, 0, 255), 200, 255);
			ofSetColor(color, ofMap(z, -300, 300, 64, 255));

			ofDrawLine(glm::vec3(radius * cos((deg + 5) * DEG_TO_RAD), radius * sin((deg + 5) * DEG_TO_RAD), z),
				glm::vec3(radius * cos((deg + 85) * DEG_TO_RAD), radius * sin((deg + 85) * DEG_TO_RAD), z));
		}
	}

	/*
	int start = 150 + 205;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}