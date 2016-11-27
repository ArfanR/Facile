// Facile.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "PrintAllStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GotoStatement.h"
#include "IfStatement.h"
#include "GoSubStatement.h"
#include "ReturnStatement.h"
#include "ProgramState.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <stdexcept>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

/*
int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}
*/

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cerr << "Program usage: ./Facile inputFile outputFile" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);
    if (!inFile)
    {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return 1;
    }
    if(!outFile)
    {
        std::cerr << "Could not open file " << argv[2] << std::endl;
        return 1;
    }

    interpretProgram(inFile, outFile);
    inFile.close();
    outFile.close();

    return 0;
}


void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	stringstream ss2;
	string type;
	string var;
	string var2;
	string op;
	int val, line_num;

	ss << line;
	ss >> type;
	// let statement
	if ( type == "LET" ) {
		ss >> var;
		ss >> val;
		statement = new LetStatement(var, val);
	}
	// end statement
	else if (type == "END" || type == ".") {
		statement = NULL;
	}
	// print one variable
	else if (type == "PRINT") {
		ss >> var;
		statement = new PrintStatement(var);
	}
	// print all variables
	else if (type == "PRINTALL") {
		statement = new PrintAllStatement();
	}
	// add a value or variable 
	else if (type == "ADD") {
		ss >> var;
		ss >> var2;
		ss2 << var2;
		// determine whether it is a number or string var
		if (isdigit(ss2.peek())) {
			ss2 >> val;
			statement = new AddStatement(var, val);
		}
		// check for negative number and parse appropriately
		else if (ss2.peek() == '-') {
			ss2.get();
			ss2 >> val;
			val *= -1;
			statement = new AddStatement(var, val);
		}
		// check if it is a string
		else if ((ss2.peek() >= 'A' && ss2.peek() <= 'z') || (ss2.peek() >= '0' && ss2.peek() <= '9')) {
			statement = new AddStatement(var, var2);
		}
	}
	// subtract a value or variable
	else if (type == "SUB") {
		ss >> var;
		ss >> var2;
		ss2 << var2;

		if (isdigit(ss2.peek())) {
			ss2 >> val;
			statement = new SubStatement(var, val);
		}
		else if (ss2.peek() == '-') {
			ss2.get();
			ss2 >> val;
			val *= -1;
			statement = new SubStatement(var, val);
		}
		else if ((ss2.peek() >= 'A' && ss2.peek() <= 'z') || (ss2.peek() >= '0' && ss2.peek() <= '9')) {
			statement = new SubStatement(var, var2);
		}
	} 
	// multiply value/variable by a var
	else if (type == "MULT") {
		ss >> var;
		ss >> var2;
		ss2 << var2;
		if (isdigit(ss2.peek())) {
			ss2 >> val;
			statement = new MultStatement(var, val);
		}
		else if (ss2.peek() == '-') {
			ss2.get();
			ss2 >> val;
			val *= -1;
			statement = new MultStatement(var, val);
		}
		else if ((ss2.peek() >= 'A' && ss2.peek() <= 'z') || (ss2.peek() >= '0' && ss2.peek() <= '9')) {
			statement = new MultStatement(var, var2);
		}
	}
	// divide variable by value/variable
	else if (type == "DIV") {
		ss >> var;
		ss >> var2;
		ss2 << var2;
		if (isdigit(ss2.peek())) {
			ss2 >> val;
			statement = new DivStatement(var, val);
		}
		else if (ss2.peek() == '-') {
			ss2.get();
			ss2 >> val;
			val *= -1;
			statement = new DivStatement(var, val);
		}
		else if ((ss2.peek() >= 'A' && ss2.peek() <= 'z') || (ss2.peek() >= '0' && ss2.peek() <= '9')) {
			statement = new DivStatement(var, var2);
		}
	}
	// skip to a line 
	else if (type == "GOTO") {
		ss >> val;
		statement = new GotoStatement(val);
	}
	// check for conditional statement
	else if (type == "IF") {
		ss >> var;
		ss >> op;
		ss >> val;
		ss >> var2;
		ss >> line_num;
		statement = new IfStatement(var, op, val, line_num);
	}
	// skip to a line and return
	else if (type == "GOSUB") {
		ss >> line_num;
		statement = new GoSubStatement(line_num);
	}
	// return to a line
	else if (type == "RETURN") {
		statement = new ReturnStatement();
	}

	return statement;
	
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	ProgramState *state = new ProgramState(1);

	int i = 0;
	// loop until end statement
	while (static_cast<unsigned int>(state->getCounter()) < program.size()) {
		i = state->getCounter();
		// out of bounds counter
		if (i <= 0 || static_cast<unsigned int>(i) >= program.size()) {
			throw std::invalid_argument("Illegal jump instruction");
		}
		// check for end statement or return with no gosub
		if (program[i] == NULL || i == 1001) {
			delete state;
			// deallocate all *statements
			for (unsigned int i = 0; i < program.size(); i++) {
				Statement* statement = program.at(i);
        		delete statement;
    		}
			program.clear();
			break;
		}
		// execute each statement line by line
		program[i]->execute(state, outf);
	}

}

