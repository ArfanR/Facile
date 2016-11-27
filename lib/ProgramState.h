// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <map>
#include <string>
class ProgramState
{
public:
	// constructor
	ProgramState(int numLines);
	// destructor
	~ProgramState();

	// map functions
	int getValue(std::string var);
	void setValue(std::string var, int val);

	// program counter functions
	int getCounter();
	void setCounter(int val);
	std::map<std::string, int>* getMap();

	// stackint functions
	void pushLine(int num);
	void popLine();
	int topLine();
	bool isEmpty();

private:
	// program counter
	int m_numLines;
	// map to store variables and values
	std::map<std::string, int>* variables;
	// stack for return and gosub statements
	StackInt stack;
};

#endif



