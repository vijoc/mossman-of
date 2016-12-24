#ifndef RULESET_H
#define RULESET_H

class RuleSet {
public:
	RuleSet() {;}
	RuleSet(std::vector<int> birthCounts, std::vector<int> survivalCounts): birthCounts(birthCounts), survivalCounts(survivalCounts) {;}

	bool birthRulesContain(int i) { return std::find(birthCounts.begin(), birthCounts.end(), i) != birthCounts.end(); }
	bool survivalRulesContain(int i) { return std::find(survivalCounts.begin(), survivalCounts.end(), i) != survivalCounts.end(); }
private:
	std::vector<int> birthCounts = { 3 };
	std::vector<int> survivalCounts = { 2, 3 };
};

#endif /* RULESET_H */
