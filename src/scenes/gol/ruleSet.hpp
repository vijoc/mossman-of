class RuleSet {
public:
	RuleSet() {;} // TODO currently default to default GOL rules
	bool birthRulesContain(int i) { return std::find(birthCounts.begin(), birthCounts.end(), i) != birthCounts.end(); }
	bool survivalRulesContain(int i) { return std::find(survivalCounts.begin(), survivalCounts.end(), i) != survivalCounts.end(); }
private:
	std::vector<int> birthCounts = { 3 };
	std::vector<int> survivalCounts = { 2, 3 };
};
