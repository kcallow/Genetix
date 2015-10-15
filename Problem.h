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
	virtual void generateRandomProblem(int maxN = 2048) =0;
	int geneSize;
	string name;
};

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

	void generateRandomProblem(int maxN ) {
		int N, M, K;
		N = rand()%maxN;
		cout << N << endl;
		M = rand()%(1+N*maxN);
		cout << M << endl;
		K = rand()%N;
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

	void generateRandomProblem(int maxN ){
		int N, M, maxM;
		set <int> C;
		N = rand()%maxN;
		cout << N << endl;
		maxM = (1 << (N - 2)); //Real maximum is 2^N, but truncating to 2^(N-2) for computational complexity.
		M = rand()%maxM;
		cout << M << endl;
		for (int i = 0; i<M; i++){
			C.insert(rand()%maxM);
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
