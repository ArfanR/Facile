#include "GoSubStatement.h"
using namespace std;

GoSubStatement::GoSubStatement(int line)
	: m_line(line)
{}

GoSubStatement::~GoSubStatement() {

}

// The GoSubStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the program counter to the line number
// 	  * push line number onto the stack
void GoSubStatement::execute(ProgramState * state, ostream &outf) {
	state->pushLine(state->getCounter());
	state->setCounter(m_line);

}

