#include "SubStatement.h"
using namespace std;

SubStatement::SubStatement(std::string variableName, int value)
	: m_variableName( variableName ), var2(""), m_value( value )
{}

SubStatement::SubStatement(std::string variableName, std::string variable2) 
	: m_variableName( variableName ), var2(variable2), m_value(0) 
{}

SubStatement::~SubStatement() {

}

// The SubtractStatement version of execute() should make two changes to the
// state of the program:
//
//    * subtract the value or the variable's value from the appropriate variable
//    * increment the program counter
void SubStatement::execute(ProgramState * state, ostream &outf) {
	int newVal;
	if (var2 == "") {
		newVal = state->getValue(m_variableName) - m_value;
	}
	else if (m_value == 0) {
		newVal = state->getValue(m_variableName) - state->getValue(var2);
	}
	state->setValue(m_variableName, newVal);
	int counter = state->getCounter() + 1;
	state->setCounter(counter);
}
