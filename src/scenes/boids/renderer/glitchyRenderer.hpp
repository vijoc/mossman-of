#include "ofmain.h"
#include "flock.hpp"

class GlitchyRenderer {
public:
	GlitchyRenderer(Flock& flock): flock(flock) {;}
	void draw();
private:
	Flock& flock;
};
