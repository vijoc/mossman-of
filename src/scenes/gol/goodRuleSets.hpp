#include "ruleSet.hpp"

namespace GoodRuleSets {
	RuleSet amoeba			({ 3, 5, 7 },		{ 1, 3, 5, 8 });
	RuleSet assimilation		({ 3, 4, 5 },		{ 4, 5, 6, 7 });
	RuleSet coagulations		({ 3, 7, 8 },		{ 2, 3, 5, 6, 7, 8 });
	RuleSet coral			({ 3 },			{ 4, 5, 6, 7, 8 });
	RuleSet dayAndNight		({ 3, 6, 7, 8 },	{ 3, 4, 6, 7, 8 });
	RuleSet diamoeba		({ 3, 5, 6, 7, 8 },	{ 5, 6, 7, 8 });
	RuleSet gnarl			({ 1 },			{ 1 });
	RuleSet gol			({ 2, 3 },		{ 3 });
	RuleSet highLife		({ 3, 6 },		{ 2, 3 });
	RuleSet lifeWithoutDeath	({ 2, 3 },		{ 0, 1, 2, 3, 4, 5, 6, 7, 8 });
	RuleSet longLife		({ 3, 4, 5 },		{ 5 });
	RuleSet maze			({ 3 },			{ 1, 2, 3, 4, 5 });
	RuleSet mazectric		({ 3 },			{ 1, 2, 3, 4 });
	RuleSet move			({ 3, 6, 8 },		{ 2, 4, 5 });
	RuleSet pseudoLife		({ 3, 5, 7 },		{ 2, 3, 8 });
	RuleSet replicator		({ 1, 3, 5, 7 },	{ 1, 3, 5, 7 });
	RuleSet seedsTwo		({ 2 },			{ });
	RuleSet serviettes		({ 2, 3, 4 },		{ });
	RuleSet stains			({ 3, 6, 7, 8 },	{ 2, 3, 5, 6, 7, 8 });
	RuleSet threeFourLife		({ 3, 4 },		{ 3, 4 });
	RuleSet twoXTwo			({ 3, 6 },		{ 1, 2, 5 });
	RuleSet walledCities		({ 4, 5, 6, 7, 8 },	{ 2, 3, 4, 5 });

	std::vector<RuleSet> goodRuleSets({ amoeba, assimilation, coagulations, coral, dayAndNight, diamoeba, gnarl, gol, highLife, lifeWithoutDeath, longLife, maze, mazectric, move, pseudoLife, replicator, seedsTwo, serviettes, stains, threeFourLife, twoXTwo, walledCities });

	RuleSet getRandomRuleSet() {
		return goodRuleSets[rand() % goodRuleSets.size()]; // TODO skewed distribution
	}
}
