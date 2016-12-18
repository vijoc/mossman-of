#include "ofMain.h"
#include "flock.hpp"
#include "boidsRenderer.hpp"
#include "scene.hpp"

class BoidsScene : public Scene
{
public:
	BoidsScene();
	void draw();
	void update(float dt);
	void activate();
	void deactivate();
	void keyPress(int key);
private:
	Flock* flock;
	BoidsRenderer* boidsRenderer;
};
