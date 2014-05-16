#pragma once

#include "ofMain.h"

class holo : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
                void setup_webcam();
                void update_webcam();
                void draw_webcam();

		ofEasyCam camera;
                ofVideoPlayer mm;
                ofShader xholo;
                ofImage img;
                ofFbo fbo,fboImg,fbobo;
                ofTrueTypeFont font;
                ofVideoPlayer mov;
                ofVideoGrabber cam
;
                int camWidth,w;
                int camHeight,h;
		string buffer;
		float state = 1.0;
		int xMouse,yMouse,zMouse;
};
