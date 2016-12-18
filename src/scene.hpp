#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	virtual void activate() = 0;
	virtual void deactivate() = 0;
	virtual void keyPress(int key) = 0;
};
#endif /* SCENE_H */
