#include "holo.h"

ofFbo fboImg,fbobo;
string buffer;
float state = 1.0;
ofEasyCam camera;
int xMouse,yMouse,zMouse;

void holo::setup_webcam(){
   camWidth  = 800;
   camHeight = 600;
   vector<ofVideoDevice> devices = cam.listDevices();
   for(int i = 0; i < devices.size(); i++){
      cout << devices[i].id << ": " << devices[i].deviceName;
      if( devices[i].bAvailable ){
         cout << endl;
         }else{
         cout << " - unavailable " << endl;
         }
      }   
   cam.setDeviceID(0);
   cam.setDesiredFrameRate(60);
   cam.initGrabber(camWidth,camHeight);
}

void holo::update_webcam(){
   cam.update();  
}

void holo::draw_webcam(){
   ofSetHexColor(0xffffff);
   cam.draw(0,0);
}


//--------------------------------------------------------------
void holo::setup() {
   //xholo.load("holo.vertex","holo.fragment");
   //xholo.load("glitch_faster.vertex","glitch_faster.fragment");
   //xholo.load("highlight_stroke.vertex","highlight_stroke.fragment");
   //xholo.load("deformed.vertex","deformed.fragment");
   //xholo.load("video_effect.vertex","video_effect.fragment");
   //xholo.load("effect_distorsion.vertex","effect_distorsion.fragment");
   //xholo.load("tv_distorsion.vertex","tv_distorsion.fragment");
   //xholo.load("extrude_image.vertex","extrude_image.fragment");
   //xholo.load("distorsion.vertex","distorsion.fragment");
   //xholo.load("menger_tunnel.vertex","menger_tunnel.fragment");
   xholo.load("vento_solare.vertex","vento_solare.fragment");

//   mm.loadMovie("mov.mp4");
//   mm.play();
//   ofEnableDepthTest();
//   ofEnableNormalizedTexCoords();
   img.loadImage("model.jpg");
   w=ofGetScreenWidth();
   h=ofGetScreenHeight();
   fbo.allocate(w,h, GL_RGBA);
   fboImg.allocate(w,h, GL_RGBA);
   fbobo.allocate(w,h, GL_RGBA);
   setup_webcam();
   font.loadFont("verdana.ttf", 18, true, true);
}

//--------------------------------------------------------------
void holo::update() {
   ofSetWindowTitle(ofToString(ofGetFrameRate()));
   update_webcam();
   //mm.update();

   fbo.begin();
   ofClear(5,5,5,255);
   cam.draw(0,0,w,h);
   fbo.end();

   fbobo.begin();
     xholo.begin();
     xholo.setUniform3f("iResolution", w,h,0);
     xholo.setUniform1f("iGlobalTime", -ofGetElapsedTimef());
     xholo.setUniformTexture("iChannel0", img.getTextureReference(), 1);
     xholo.setUniformTexture("iChannel1", fbo.getTextureReference(), 2);
     xholo.setUniform4f("iMouse", ofMap(xMouse,0,w,0,25.5), ofMap(yMouse,0,h,0,25.5), ofMap(zMouse,0,1000,0,25.5),0);
     //xholo.setUniform1f("param", state);
     //xholo.setUniform1f("summs", ofMap(mouseX,0.0,w,-10.0,10.0));
     //xholo.setUniformTexture("texture", fbo.getTextureReference(), 1);
     //xholo.setUniformTexture("iCh", fbo.getTextureReference(), 2);
     //xholo.setUniform1f("param", state);
     //xholo.setUniform1f("summs", ofMap(mouseX,0.0,w,0.0,30.0));
     fboImg.draw(0,0);
     xholo.end();
   fbobo.end();
}

//--------------------------------------------------------------
void holo::draw() {   
   fbobo.draw(0,0,w,h);
}

//--------------------------------------------------------------
void holo::keyPressed(int key){
if(key=='1')
	state=1.0;
if(key=='2')
	state=2.0;
if(key=='3')
	state=3.0;
if(key=='s')
	ofSaveFrame();
if(key=='f')
	ofToggleFullscreen();
if(key==OF_KEY_RIGHT)
	xMouse+=2;
if(key==OF_KEY_LEFT)
	xMouse-=2;
if(key==OF_KEY_DOWN)
	yMouse+=2;
if(key==OF_KEY_UP)
	yMouse-=2;
if(key=='w')
	zMouse+=1;
if(key=='s')
	zMouse-=1;
}

//--------------------------------------------------------------
void holo::keyReleased(int key){

}

//--------------------------------------------------------------
void holo::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void holo::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::windowResized(int w, int h){

}

//--------------------------------------------------------------
void holo::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void holo::dragEvent(ofDragInfo dragInfo){ 

}
