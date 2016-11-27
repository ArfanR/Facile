#include "IfStatement.h"
using namespace std;

IfStatement::IfStatement(std::string variableName, std::string op, int value, int line)
	: m_variableName(variableName), m_operator(op), m_value(value), m_line(line)
{}

IfStatement::~IfStatement() {

}

// The IfStatement version of execute() should make one change to the
// state of the program:
//
//    * compares variable to an int and 
// 	  * changes program counter to new line
void IfStatement::execute(ProgramState * state, ostream &outf) {
	bool go = false;
	// get the value of variable for comparison
	int val = state->getValue(m_variableName);
	// check for all the comparison operators 
	// greater than
	if (m_operator == ">") {
		if (val > m_value) {
			go = true;
		}
	}
	// less than
	else if (m_operator == "<") {
		if (val < m_value) {
			go = true;
		}
	}
	// greater than or equal to
	else if (m_operator == ">=") {
		if (val >= m_value) {
			go = true;
		}
	}
	// less than equal to 
	else if (m_operator == "<=") {
		if (val <= m_value) {
			go = true;
		}
	}
	// equal to 
	else if (m_operator == "=") {
		if (val == m_value) {
			go = true;
		}
	}
	// not equal to 
	else if (m_operator == "<>") {
		if (val != m_value) {
			go = true;
		}
	}
	// if statement is true
	if (go) {
		state->setCounter(m_line);
	}
	// if statement is false; move on to next line
	else {
		int counter = state->getCounter() + 1;
		state->setCounter(counter);
	}
}

