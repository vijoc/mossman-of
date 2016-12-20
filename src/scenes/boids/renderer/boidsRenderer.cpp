#include "boidsRenderer.hpp"

RenderingModes mode = RenderingModes::Circle;

void BoidsRenderer::draw() {
	switch(mode) {
		case RenderingModes::Circle:
			cr.draw();
			break;
		case RenderingModes::Glitchy:
			gr.draw();
			break;
		case RenderingModes::Closest:
			nr.draw();
			break;
		default:
			break;
	}
}

void BoidsRenderer::setRenderingMode(RenderingModes rMode) {
	mode = rMode;
}
