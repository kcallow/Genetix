#include "Algorithm.h"
#include <fstream>

int main(int argc, char * argv[]){
	srand((unsigned)time(NULL));
	int argn = 0;
	//ifstream problemFile(argv[++argn], ios_base::in);
	ifstream dataFile(argv[++argn], ios_base::in);
	ofstream outFile(argv[argc-1]);


	cout << "Leyendo problema:" << endl;
	string name;
	cout << "\tNombre del problema:\n\t\t";
	getline(cin,name);
	Problem* problem = makeProblem(name);
	if(problem == NULL){
		cout << "Codigo de problema desconocido. Terminando...\n";
		return -1;
	}

	problem->readProblem();
	cout << "Escribiendo problema a archivo '" << argv[argc-1] << "'..." << endl;
//Redirect stdout to file stream
	auto coutBackup = cout.rdbuf();
	cout.rdbuf(outFile.rdbuf());
//Write problem to file	
	problem->writeProblem();
//Reset stdout to normal
	cout.rdbuf(coutBackup);
	

	int generations, popSize, crosses;
       	double mutation;
	SelectPolicy policy;

	generations = getIntArg(argc,argv,++argn,1+rand()%2048); //If generations not specified, use random up to 2048
	popSize = getIntArg(argc,argv,++argn,1+rand()%8192); //If popSize not specified, use random up to 8192
	crosses = getIntArg(argc,argv,++argn,1+rand()%4); //If crosses not specified, use random up to 4
	mutation = getIntArg(argc,argv,++argn,1+rand()%100); //If mutation not specified, use random up to 100
	policy = (SelectPolicy) getIntArg(argc,argv,++argn,rand()%3); //If policy not specified, select at random from all 3

	Algorithm algorithm = Algorithm(policy, crosses, mutation, popSize, problem);
	cout << "--------------" << endl;
	cout << "Leyendo genes:" << endl;
	algorithm.readPopulation();
	cout << "Escribiendo genes a archivo '" << argv[argc-1] << "'..." << endl;
	cout << name << endl;

//Redirect stdout to file stream
	cout.rdbuf(outFile.rdbuf());
//Write algorithm to file	
	algorithm.writePopulation();
//Reset stdout to normal
	cout.rdbuf(coutBackup);

	return 0;
}
