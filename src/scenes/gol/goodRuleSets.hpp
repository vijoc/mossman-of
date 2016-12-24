#include "ruleSet.hpp"

namespace GoodRuleSets {
	RuleSet gol({ 2, 3 }, { 3 });
	RuleSet lifeWithoutDeath({ 2, 3 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8 });
	RuleSet twoXTwo({ 3, 6 }, { 1, 2, 5 });
}
