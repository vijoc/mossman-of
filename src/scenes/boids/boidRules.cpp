#include "boidRules.hpp"

float BoidRules::separationWeight = 2.0;
float BoidRules::cohesionWeight   = 0.25;
float BoidRules::alignmentWeight  = 0.5;

float BoidRules::desiredSeparation = 100;
float BoidRules::cohesionDist      = 150;
float BoidRules::alignmentDist     = 200;
