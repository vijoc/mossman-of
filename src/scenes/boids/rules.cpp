#include "rules.hpp"

float Rules::weight = 10.0;
float Rules::radius = 10.0;
float Rules::deceleration = 0.3;
float Rules::maxSpeed = 2.0;

float Rules::separationWeight = 8.0;
float Rules::cohesionWeight   = 0.125;
float Rules::alignmentWeight  = 0.0625;

float Rules::desiredSeparation = 50;
float Rules::cohesionDist      = 150;
float Rules::alignmentDist     = 150;
