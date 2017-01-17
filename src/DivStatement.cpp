#include "../lib/DivStatement.h"
#include <stdexcept>
using namespace std;

DivStatement::DivStatement(std::string variableName, int value)
	: m_variableName( variableName ), var2(""), m_value( value )
{}

DivStatement::DivStatement(std::string variableName, std::string variable2) 
	: m_variableName( variableName ), var2(variable2), m_value(0) 
{}

DivStatement::~DivStatement() {

}

// The DivStatement version of execute() should make two changes to the
// state of the program:
//
//    * divide the appropriate variable by the value
//    * increment the program counter
void DivStatement::execute(ProgramState * state, ostream &outf) {
	int newVal;
	if (var2 == "") {
		// throw exception for dividing by zero
		if (m_value == 0) {
			throw std::invalid_argument("Divide by zero exception");
		}
		newVal = state->getValue(m_variableName) / m_value;
	}
	else if (m_value == 0) {
		// check for dividing by zero 
		if (state->getValue(var2) == 0) {
			throw std::invalid_argument("Divide by zero exception");
		}
		newVal = state->getValue(m_variableName) / state->getValue(var2);
	}
	state->setValue(m_variableName, newVal);
	int counter = state->getCounter() + 1;
	state->setCounter(counter);
}
