#include "Problem.h"
#include "time.h"

enum SelectPolicy { RANDOM, FORTUNE, TOURNAMENT };

class Algorithm {
public:
	SelectPolicy policy;
	int crosses;
	double mutation;
	int popSize;
	Problem *problem;
	void generacion(){}

	Algorithm( SelectPolicy policy, int crosses, double mutation, int popSize, Problem *problem ){
		this->policy = policy;
		this->crosses = crosses;
		this->mutation = mutation;
		this->popSize = popSize;
		this->problem = problem;
	}

	~Algorithm() { delete problem; }

	void resetPopulation(string file){}
	void readPopulation(string file){}
	void writePopulation(string file){}
	Gene getBest(){}
};


int main(){
	srand(time(0));
	string name;
	cout << "Nombre del problema:\t";
	cin >> name;
	Problem* problem = makeProblem(name);
	if(problem == NULL){
		cout << "Codigo de problema desconocido. Terminando...\n";
		return -1;
	}
	problem->generateRandomProblem();
	delete problem;
	return 0;
};
