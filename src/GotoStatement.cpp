#include "GotoStatement.h"
using namespace std;

GotoStatement::GotoStatement(int value)
	: m_value( value )
{}

GotoStatement::~GotoStatement() {

}

// The GotoStatement version of execute() should make one change to the
// state of the program:
//
//    * set the program counter to the line number
void GotoStatement::execute(ProgramState * state, ostream &outf) {
	state->setCounter(m_value);
}

