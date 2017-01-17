#include "../lib/AddStatement.h"
using namespace std;

AddStatement::AddStatement(std::string variableName, int value)
	: m_variableName( variableName ), var2(""), m_value( value )
{}

AddStatement::AddStatement(std::string variableName, std::string variable2) 
	: m_variableName( variableName ), var2(variable2), m_value(0) 
{}

AddStatement::~AddStatement() {

}

// The AddStatement version of execute() should make two changes to the
// state of the program:
//
//    * add the value or the variable's value to the appropriate variable
//    * increment the program counter
void AddStatement::execute(ProgramState * state, ostream &outf) {
	int newVal;
	/// add a value
	if (var2 == "") {
		newVal = state->getValue(m_variableName) + m_value;
	}
	// add a variable
	else if (m_value == 0) {
		newVal = state->getValue(m_variableName) + state->getValue(var2);
	}
	state->setValue(m_variableName, newVal);
	int counter = state->getCounter() + 1;
	state->setCounter(counter);
}


