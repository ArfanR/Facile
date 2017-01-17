CC       = g++
CPPFLAGS = -Wall -g
BIN_DIR  = bin

facile: $(BIN_DIR)/facile

$(BIN_DIR)/facile: $(BIN_DIR)/llistint.o $(BIN_DIR)/stackint.o $(BIN_DIR)/State.o $(BIN_DIR)/Let.o $(BIN_DIR)/Print.o $(BIN_DIR)/PrintAll.o $(BIN_DIR)/Add.o $(BIN_DIR)/Sub.o $(BIN_DIR)/Mult.o $(BIN_DIR)/Div.o $(BIN_DIR)/Goto.o $(BIN_DIR)/If.o $(BIN_DIR)/Gosub.o $(BIN_DIR)/Return.o
	$(CXX) $(CPPFLAGS) $^ src/Facile.cpp -o $(BIN_DIR)/facile

$(BIN_DIR)/stackint.o: lib/stackint.h src/stackint.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/stackint.cpp -o $(BIN_DIR)/stackint.o

$(BIN_DIR)/llistint.o: lib/llistint.h src/llistint.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/llistint.cpp -o $(BIN_DIR)/llistint.o

$(BIN_DIR)/State.o: lib/ProgramState.h src/ProgramState.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/ProgramState.cpp -o $(BIN_DIR)/State.o

$(BIN_DIR)/Let.o: lib/Statement.h lib/LetStatement.h src/LetStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/LetStatement.cpp -o $(BIN_DIR)/Let.o

$(BIN_DIR)/Print.o: lib/Statement.h lib/PrintStatement.h src/PrintStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/PrintStatement.cpp -o $(BIN_DIR)/Print.o

$(BIN_DIR)/PrintAll.o: lib/Statement.h lib/PrintAllStatement.h src/PrintAllStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/PrintAllStatement.cpp -o $(BIN_DIR)/PrintAll.o

$(BIN_DIR)/Add.o: lib/Statement.h lib/AddStatement.h src/AddStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/AddStatement.cpp -o $(BIN_DIR)/Add.o

$(BIN_DIR)/Sub.o: lib/Statement.h lib/SubStatement.h src/SubStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/SubStatement.cpp -o $(BIN_DIR)/Sub.o

$(BIN_DIR)/Mult.o: lib/Statement.h lib/MultStatement.h src/MultStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/MultStatement.cpp -o $(BIN_DIR)/Mult.o

$(BIN_DIR)/Div.o: lib/Statement.h lib/DivStatement.h src/DivStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/DivStatement.cpp -o $(BIN_DIR)/Div.o

$(BIN_DIR)/Goto.o: lib/Statement.h lib/GotoStatement.h src/GotoStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/GotoStatement.cpp -o $(BIN_DIR)/Goto.o

$(BIN_DIR)/If.o: lib/Statement.h lib/IfStatement.h src/IfStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/IfStatement.cpp -o $(BIN_DIR)/If.o

$(BIN_DIR)/Gosub.o: lib/Statement.h lib/GoSubStatement.h src/GoSubStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/GoSubStatement.cpp -o $(BIN_DIR)/Gosub.o

$(BIN_DIR)/Return.o: lib/Statement.h lib/ReturnStatement.h src/ReturnStatement.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/ReturnStatement.cpp -o $(BIN_DIR)/Return.o

.PHONY: clean

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

clean:
	rm -rf $(BIN_DIR)