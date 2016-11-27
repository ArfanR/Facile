#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
private:
	std::string m_variableName, var2;
	int m_value;

public:
	MultStatement(std::string variableName, int value);
	MultStatement(std::string variableName, std::string variable2);
	~MultStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif