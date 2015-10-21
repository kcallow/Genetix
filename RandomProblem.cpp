#include "Algorithm.h"

int main(int argc, char* argv[]){
	srand((unsigned)time(NULL));
	string name;
	//cout << "Nombre del problema:\t";
	cin >> name;
	Problem* problem = makeProblem(name);
	if(problem == NULL){
		cout << "Codigo de problema desconocido. Terminando...\n";
		return -1;
	}
	problem->generateRandomProblem(argc, argv);
	problem->writeProblem();
	delete problem;
	return 0;
}
