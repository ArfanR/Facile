// PrintStatement.cpp:
#include "PrintAllStatement.h"
using namespace std;

PrintAllStatement::PrintAllStatement() {

}

PrintAllStatement::~PrintAllStatement() {

}

void PrintAllStatement::execute(ProgramState * state, std::ostream &outf) {
	std::map<std::string, int>* temp = state->getMap();
	// create map iterator
	std::map<std::string, int>::iterator it;
	// iterator through each key and value
	for (it = temp->begin(); it != temp->end(); it++) {
		outf << it->first << " " << it->second << endl;
	}
	// increment program counter
	int counter = state->getCounter() + 1;
	state->setCounter(counter);
}
