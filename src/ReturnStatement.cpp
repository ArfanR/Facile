#include "../lib/ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement()
{}

ReturnStatement::~ReturnStatement() {

}

// The ReturnStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the program counter to the recent GOSUB
//    * pop the recent stack value
void ReturnStatement::execute(ProgramState * state, ostream &outf) {
	// check is stack is empty or no GOSUB statement 
	if (state->isEmpty()) {
		state->setCounter(1001);
	}
	else {
		// get the most recent GOSUB
		int line = state->topLine() + 1;
		state->popLine();
		state->setCounter(line);
	}
}

