#include "scanner.hpp"

using namespace std;

states FSA_TABLE[state][columns] = {
//        a-z     A-Z     0-9     _       $       =       <       >       :       +       -       *       /       %       .       (       )       ,       {       }       ;       [       ]     WS     EOF 
/* s1  */ {s2,    ERROR,  s3,     ERROR,  s2,     s4,     s6,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  s1,    FINAL},
/* s2  */ {s2,    s2,     s2,     s2,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,     ID,   ID,    ID},
/* s3  */ {DIGIT, DIGIT,  s3,     DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,  DIGIT,DIGIT, DIGIT},
/* s4  */ {EQUAL, EQUAL,  EQUAL,  EQUAL,  EQUAL,  s5,     EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,  EQUAL,EQUAL, EQUAL},
/* s5  */ {DUBEQ, DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,  DUBEQ,DUBEQ, DUBEQ},
/* s6  */ {LESS,  LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS,   LESS, LESS,  LESS},
/* s7  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s8  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s9  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s10 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s11 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s12 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s13 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s14 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s15 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s16 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s17 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s18 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s19 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s20 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s21 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s22 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s23 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
};

map<char, int> columnMap = {
    {'a', 0},
    {'A', 1},
    {'1', 2},
    {'_', 3},
    {'$', 4},
    {'=', 5},
    {'<', 6},
    {'>', 7},
    {':', 8},
    {'+', 9},
    {'-', 10},
    {'*', 11},
    {'/', 12},
    {'%', 13},
    {'.', 14},
    {'(', 15},
    {')', 16},
    {',', 17},
    {'{', 18},
    {'}', 19},
    {';', 20},
    {'[', 21},
    {']', 22},
    {' ', 23},
    {EOF, 24},
    {'\0',24}
};

map<int, string> tokenTypes = {
    {2, "Digit_Token"},
    {3, "=_Token"},
    {4, "==_Token"},
    {5, "<_Token"}
};

set<string> keyWords = {"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"};

struct DriverData{
    int currentLineCount;
    int currentCharCount;
    int charIndex;
    char nextChar;

    DriverData(int initLine, int initChar, int initIndex){
        currentLineCount = initLine;
        currentCharCount = initChar;
        charIndex = initIndex;
    }
};

void printVector(vector<string> vector){
    for (int i = 0; i < vector.size(); i++){
        cout << vector.at(i) << endl;
    }
}

char getNextChar(string line, DriverData* data){
    char nextChar = line[data->charIndex];

    if (nextChar == '\0'){
        return '\0';
    } else {
        data->charIndex += 1;
        return nextChar;
    }
}

int getNextIndex(char nextChar){
    if (islower(nextChar))
        nextChar = 'a';
    if (isupper(nextChar))
        nextChar = 'A';
    if (isdigit(nextChar))
        nextChar = '1';
    
    return columnMap[nextChar];
}

void errorCall(DriverData* data){
    cout << "Scanner has encountered error at line " << data->currentLineCount << ", char " << data->currentCharCount << endl;
    exit(0);
}

Token* generateIDToken(string tokenValue, string type, DriverData* data){
    Token* generatedToken = new Token("", "", 0, 0);

    generatedToken->token = tokenValue;
    generatedToken->tokenType = type;
    generatedToken->charNum = data->currentCharCount;
    generatedToken->lineNum = data->currentLineCount;

    return generatedToken;
}

Token* generateOtherToken(string tokenValue, int state, DriverData* data){
    Token* generatedToken = new Token("", "", 0, 0);

    cout << "In generate with " << state << endl;

    generatedToken->token = tokenValue;
    generatedToken->tokenType = tokenTypes.at(state);
    generatedToken->charNum = data->currentCharCount;
    generatedToken->lineNum = data->currentLineCount;

    return generatedToken;
}

vector<Token*> buildTokenFromLine(string line, DriverData* data){
    Token* currentToken;
    vector<Token*> tokenList;
    states currentState = s1; // initial state
    states nextState;
    string tokenValue = "";

    char nextChar = getNextChar(line, data);
    int nextIndex = getNextIndex(nextChar);
    nextState = FSA_TABLE[currentState][nextIndex];
    
    while (currentState != FINAL || nextChar != '\0') {
        data->currentCharCount += 1;
        cout << "next State is " << nextState << endl;
        cout << "current state is " << currentState << endl;
        cout << "next char is " << nextChar << endl;
        cout << "next index found is " << nextIndex << endl;
        if (nextState == ERROR)
            errorCall(data);
        if (nextState > FINAL){
            if (nextState == ID){
                if (keyWords.find(tokenValue) != keyWords.end()){
                    currentToken = generateIDToken(tokenValue, "KeyWord_Token", data);

                    tokenList.push_back(currentToken);
                } else {
                    currentToken = generateIDToken(tokenValue, "ID_Token", data);

                    tokenList.push_back(currentToken);
                }
            } else {
                currentToken = generateOtherToken(tokenValue, currentState, data);

                tokenList.push_back(currentToken);
            }
                currentState = s1;
                tokenValue = "";
                nextState = FSA_TABLE[currentState][nextIndex];
        }
        else {
            currentState = nextState;
            if (nextChar != ' ') tokenValue.push_back(nextChar);
            nextChar = getNextChar(line, data);
            nextIndex = getNextIndex(nextChar);
            nextState = FSA_TABLE[currentState][nextIndex];
        }
    }

    return tokenList;
}

vector<Token*> driverFunction(vector<string> lines){
    vector<Token*> tokens;
    vector<Token*> tempTokensList;
    states state = s1; // initial state
    states nextState;
    DriverData* data = new DriverData(0,0,0);

    for (int i = 0; i < lines.size(); i++){

        tempTokensList = buildTokenFromLine(lines.at(i), data);

        tokens.insert(tokens.end(), tempTokensList.begin(), tempTokensList.end());

        data->charIndex = 0;
        data->currentCharCount = 0;
        data->currentLineCount += 1;
    }

    delete data;
    for (int i = 0; i < tokens.size(); i++){
        cout << "token Name " << tokens.at(i)->token << endl;
        cout << "token Type " << tokens.at(i)->tokenType << endl;
        cout << "token line " << tokens.at(i)->lineNum << endl;
        cout << "token char " << tokens.at(i)->charNum << endl;
    }
    return tokens;
}

// Reads from keyboard and returns a vector of all strings given
vector<string> readFromKeyBoard(){
    string line;
    vector<string> wordList;
    while (getline(cin, line)) // read input until none are left in stdin
    {
        wordList.push_back(line);
    }
    
    return wordList;
}

// Reads from keyboard and returns a vector of all strings given
vector<string> readFromFile(ifstream &file){
    string line;
    vector<string> wordList;
    while (getline(file, line)) // Read from file until no lines are left
    {   
        wordList.push_back(line);
    }

    return wordList;
}

// Opens the file of a specfic filename and reads from that file to get the words in there
vector<string> openFile(string fileName){
    ifstream file(fileName);
    vector<string> wordList;

    // Tries to open file, catches error if cannot and exits
    try {
        if (file)
            wordList = readFromFile(file);
        else
            throw -1;
    } catch(int error){
        cout << "ERROR: File could not be found, existing...\n";
        exit(1);
        
    }
    
    file.close();
    return wordList;
}

vector<Token*> createTokenVector(){
    vector<Token*> tokens;
    vector<string> lines = readFromKeyBoard();
    
    printVector(lines);

    tokens = driverFunction(lines);

    return tokens;
}

vector<Token*> createTokenVector(string fileName){
    vector<Token*> tokens;
    vector<string> lines = openFile(fileName);

    printVector(lines);

    tokens = driverFunction(lines);

    return tokens;
}