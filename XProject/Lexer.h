#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
using namespace std;

class Lexer{
	public:
		virtual void scanner(string cmd) = 0;

};

class Tokens : public Lexer{

	enum OPERATORS_MATH {
		SUM = '+',
		MIN = '-',
		MULT = '*',
		DIV  = '/',
		MOD = '%'
	};
	enum OPERATORS_GENERAL{
		ASIGN = '=',
		COMMA = ',',
		QUOTE = '"',
		SEMICOLON = ';',
		LEFT_PARENT = '(',
		RIGHT_PARENT = ')',
		LEFT_BRACKET = '[',
		RIGHT_BRACKET = ']'
	};
public:
	Tokens();
	void scanner( string cmd);
private:
	typedef map<string, string> mapSS;
	mapSS keywords;
	mapSS::const_iterator itkeywords;
	string output;

	void searchOperatorMath(char token);
	
	void initKeywords();
};

class generatorCode{


};