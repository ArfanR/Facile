CC       = g++
CPPFLAGS = -Wall -g
BIN_DIR  = bin

facile: $(BIN_DIR)/facile

$(BIN_DIR)/facile: $(BIN_DIR)/llistint.o $(BIN_DIR)/stackint.o $(BIN_DIR)/State.o $(BIN_DIR)/Let.o $(BIN_DIR)/Print.o $(BIN_DIR)/PrintAll.o $(BIN_DIR)/Add.o $(BIN_DIR)/Sub.o $(BIN_DIR)/Mult.o $(BIN_DIR)/Div.o $(BIN_DIR)/Goto.o $(BIN_DIR)/If.o $(BIN_DIR)/Gosub.o $(BIN_DIR)/Return.o
	$(CXX) $(CPPFLAGS) $^ Facile.cpp -o $(BIN_DIR)/facile

$(BIN_DIR)/stackint.o: stackint.h stackint.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c stackint.cpp -o $(BIN_DIR)/stackint.o

$(BIN_DIR)/llistint.o: llistint.h llistint.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c llistint.cpp -o $(BIN_DIR)/llistint.o

$(BIN_DIR)/State.o: ProgramState.h ProgramState.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c ProgramState.cpp -o $(BIN_DIR)/State.o

$(BIN_DIR)/Let.o: Statement.h LetStatement.h LetStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c LetStatement.cpp -o $(BIN_DIR)/Let.o

$(BIN_DIR)/Print.o: Statement.h PrintStatement.h PrintStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c PrintStatement.cpp -o $(BIN_DIR)/Print.o

$(BIN_DIR)/PrintAll.o: Statement.h PrintAllStatement.h PrintAllStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c PrintAllStatement.cpp -o $(BIN_DIR)/PrintAll.o

$(BIN_DIR)/Add.o: Statement.h AddStatement.h AddStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c AddStatement.cpp -o $(BIN_DIR)/Add.o

$(BIN_DIR)/Sub.o: Statement.h SubStatement.h SubStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c SubStatement.cpp -o $(BIN_DIR)/Sub.o

$(BIN_DIR)/Mult.o: Statement.h MultStatement.h MultStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c MultStatement.cpp -o $(BIN_DIR)/Mult.o

$(BIN_DIR)/Div.o: Statement.h DivStatement.h DivStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c DivStatement.cpp -o $(BIN_DIR)/Div.o

$(BIN_DIR)/Goto.o: Statement.h GotoStatement.h GotoStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c GotoStatement.cpp -o $(BIN_DIR)/Goto.o

$(BIN_DIR)/If.o: Statement.h IfStatement.h IfStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c IfStatement.cpp -o $(BIN_DIR)/If.o

$(BIN_DIR)/Gosub.o: Statement.h GoSubStatement.h GoSubStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c GoSubStatement.cpp -o $(BIN_DIR)/Gosub.o

$(BIN_DIR)/Return.o: Statement.h ReturnStatement.h ReturnStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c ReturnStatement.cpp -o $(BIN_DIR)/Return.o

.PHONY: clean

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

clean:
	rm -rf $(BIN_DIR)