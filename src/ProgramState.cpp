#include "ProgramState.h"
using namespace std;

ProgramState::ProgramState(int numLines) {
	m_numLines = numLines;
	variables = new std::map<std::string, int>();
}

ProgramState::~ProgramState() {
	delete variables;
}

// return value of the variable
int ProgramState::getValue(string var) {
	return (*variables)[var];
}

// set a new value of the variable 
void ProgramState::setValue(string var, int val) {
	std::map<std::string, int>::iterator it = variables->find(var);
	// check if the variable exists
	if (it != variables->end()) {
		(*variables)[var] = val;
	}
	// make new key if variable doesn't exist 
	else {
		variables->insert(std::make_pair(var, val));
	}
}

// return program counter 
int ProgramState::getCounter() {
	return m_numLines;
}

// set val to the program counter
void ProgramState::setCounter(int val) {
	m_numLines = val;
}

// return the map of variables 
std::map<std::string, int>* ProgramState::getMap() {
	return variables;
}

// push new line number onto the stack
void ProgramState::pushLine(int num) {
	stack.push(num);
}

// pop the top of the stack
void ProgramState::popLine() {
	stack.pop();
}

// return the most recent line number 
int ProgramState::topLine() {
	return stack.top();
}

// check if stackint is empty
bool ProgramState::isEmpty() {
	return stack.empty();
}
