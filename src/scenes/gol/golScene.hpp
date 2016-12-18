#include "ofMain.h"
#include "scene.hpp"

class GolScene : public Scene {
public:
	GolScene();
	void draw();
	void update(float dt);
	void activate();
	void deactivate();
	void keyPress(int key);
};
