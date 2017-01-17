// PrintStatement.cpp:
#include "../lib/PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}

PrintStatement::~PrintStatement() {

}

void PrintStatement::execute(ProgramState * state, std::ostream &outf) {
	// print out the value of the variable 
	outf << state->getValue(m_variableName) << std::endl;
	// increment counter
	int counter = state->getCounter() + 1;
	state->setCounter(counter);
}


