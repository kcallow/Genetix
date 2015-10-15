#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>

using namespace std;


int factorial(int n) {
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

typedef set<bool> Gene;

class Problem {
public:
	virtual void readProblem() =0;
	virtual double fitness(Gene x) =0;
	virtual void generateRandomProblem(int argc, char* argv[], int maxN = 2048) {cout << name << endl;};
	int geneSize;
	string name;
};

int getIntArg(int argc, char* argv[], int argn, int defValue=0){
	if(argc > argn)
		return strtol(argv[argn], NULL, 10);
	else
		return defValue;
}

class GT1 : public Problem {
public:
	int N, M, K;
	set <pair<int, int> > edges;
	void readProblem(){
		cout << "Cantidad de vertices:\t";
		cin >> N;
		cout << "Cantidad de aristas:\t";
		cin >> M;
		cout << "Recubrimiento:\t";
		cin >> K;
		cout << "E = {\n";
		int Vi, Vf;
		for (int i = 0; i<M; i++){
			cin >> Vi;
			cin >> Vf;
			edges.insert(make_pair(Vi, Vf));
		}
		cout << "}";
	}

	double fitness(Gene x) {return 0;}

	GT1() { name = "GT1"; }

	void generateRandomProblem(int argc, char* argv[], int maxN ) {
		Problem::generateRandomProblem(argc, argv, maxN);
		cout << name << endl;
		int N, M, K;
		N = getIntArg(argc, argv, 1, rand()%maxN);
		cout << N << endl;
		M = getIntArg(argc, argv, 2, rand()%(1+N*maxN));
		cout << M << endl;
		K = getIntArg(argc, argv, 3, rand()%N);
		cout << K << endl;
		for (int i = 0; i<M; i++){
			edges.insert(make_pair(rand()%N, rand()%N));
		}
		//Print out in order, without duplicates
		for (auto const &it : edges) {
			cout << it.first << "\t" << it.second << endl;
		}
	}
};

class SP5 : public Problem {
public:
	int N, M;
	set <int> C;

	void readProblem(){
		cout << "Tamaño de S:\t";
		cin >> N;
		cout << "Cantidad de subconjuntos de S que se encuentran en C:\t";
		cin >> M;
		int E;
		cout << "C = {";
		while (cin >> E)
			C.insert(E);
		cout << "}";
	}

	double fitness(Gene x) {return 0;}

	SP5() { name = "SP5"; }

	void generateRandomProblem(int argc, char* argv[], int maxN){
		Problem::generateRandomProblem(argc, argv, maxN);
		int N, M, maxM;
		set <int> C;
		N = getIntArg(argc, argv, 1, rand()%maxN);
		cout << N << endl;
		maxM = (1 << N)%(1 << 20); //Real maximum is 2^N, but topping at 2^20 for computational complexity.
		M = getIntArg(argc, argv, 2, rand()%maxM);
		cout << M << endl;
		for (int i = 0; i<M; i++){
			C.insert(rand()%M);
		}
		//Print out in order, without duplicates
		for (auto const &it : C) {
			cout << it << " ";
		}
	}
};

Problem * makeProblem(string name) {
	if(name == "GT1")
		return new GT1();
	else if (name == "SP5")
		return new SP5();
	return NULL;
}
