#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Lexer.h"
using namespace std;


void print(string tokens){
	cout << "> " << tokens << endl;
}
int main () {

  string line;
  ifstream myfile ("D://prueba.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
    
    }
    myfile.close();
  }else cout << "Unable to open file"; 


  //for_each(tokens.begin(), tokens.end(), print);

  Lexer* lexer = new Tokens();
  
  remove_if(line.begin(), line.end(), isspace);
  lexer->scanner(line);
  system("pause");

}






