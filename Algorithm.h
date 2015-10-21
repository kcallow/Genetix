#include "Problem.h"

enum SelectPolicy { RANDOM, FORTUNE, TOURNAMENT };

class Algorithm {
public:
	SelectPolicy policy;
	int crosses;
	double mutation;
	int popSize;
	Problem* problem;
	void generacion(){}

	Algorithm( SelectPolicy policy, int crosses, double mutation, int popSize, Problem* problem ){
		this->policy = policy;
		this->crosses = crosses;
		this->mutation = mutation;
		this->popSize = popSize;
		this->problem = problem;
	}

	~Algorithm() { delete problem; }

	void resetPopulation(){
		for(int i = 0; i < popSize; i++)
			addRandomGene();

	}

	void readPopulation(){
		for(int i = 0; i < popSize; i++){
			cout << "\tGen: ";
			getGene();
		}
	}

	void writePopulation(){
		for(int i = 0; i < popSize; i++)
			writeGene(population[i]);
	}

	Gene getBest(){
		int maxFitness = problem->fitness(population[0]);
		int best = 0;
		int currentFitness;
		for(int i = 1; i < popSize; i++){
			currentFitness = problem->fitness(population[i]);
			if(maxFitness < currentFitness){
				maxFitness = currentFitness;
				best = i;
			}
		}
		return population[best];
	}

private:
	vector<Gene> population;

	void addRandomGene() {
		int geneSize = problem->geneSize();
		Gene newGene(geneSize);
		for(int i = 0; i < geneSize; i++)
			newGene[i] = rand()%2;

		population.push_back(newGene);
	}

	void getGene() {
		int geneSize = problem->geneSize();
		Gene newGene(geneSize);
		string line;
		getline(cin,line); 
		line.resize(geneSize, '0'); //Resize string to geneSize. Fill missing with 0's
		for(int i = 0; i < geneSize; i++)
			newGene[i] = line[i] - '0'; //Convert char to number

		population.push_back(newGene);
	}

	void writeGene(Gene gene) {
		int geneSize = problem->geneSize();
		for(int i = 0; i < geneSize; i++)
			cout << gene[i];
		cout << endl;
	}

};
