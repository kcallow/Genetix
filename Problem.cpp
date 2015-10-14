#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<bool> Gene;

class Problem {
public:
	virtual void readProblem(string file);
	virtual double fitness(Gene x);
	int geneSize;
	string name;
};

enum SelectPolicy { RANDOM, FORTUNE, TOURNAMENT };

class Algorithm {
public:
	SelectPolicy policy;
	int crosses;
	double mutation;
	int popSize;
	Problem problem;
	void generacion(){}

	Algorithm( SelectPolicy policy, int crosses, double mutation, int popSize, Problem problem ){
		this->policy = policy;
		this->crosses = crosses;
		this->mutation = mutation;
		this->popSize = popSize;
		this->problem = problem;
	}

	void resetPopulation(string file){}
	void readPopulation(string file){}
	void writePopulation(string file){}
	Gene getBest(){}
};


int main(){return 0;};
