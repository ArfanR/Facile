#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GoSubStatement: public Statement
{
private:
	int m_line;

public:
	GoSubStatement(int line);
	~GoSubStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif