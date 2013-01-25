#include "Lexer.h"

Tokens::Tokens(){
	output = "";
	initKeywords();
}

void Tokens::initKeywords() {

	keywords["std::cout"] = "out";
}
void Tokens::scanner(string cmd){

  cout << endl << ":: Lexical Analysis ::" << endl;
  cout << endl << "Input: \n\t" << cmd << endl << endl;

  vector<string> tokens;

  bool keywordActive = false;
  string temp ="";
  for(int i = 0, size = cmd.size(); i < size; ++i){
        while(i < size && isalpha(cmd[i]) ){
			cout << cmd[i];
			output += cmd[i];
			temp += cmd[i];
			++i;
			keywordActive = true;

        }
        if( keywordActive ){
			cout << "  :: ID" << endl;
			
		}
        keywordActive = false;
		if(temp == keywords["std::cout"]){
			output  = output.erase(i-temp.size()+2, temp.size());
			//cout << "  :: KEYWORD - OUT" << endl;
			output +="  \tstd::cout << ";
		}

		temp = "";
	  if(i < size){
		  
		  while( i < size && isdigit(cmd[i])){
			  cout << cmd[i] ;
			  output += cmd[i];
			  ++i;
			  keywordActive = true;
		  }
            if( keywordActive ) cout << "  :: number" << endl;
            keywordActive = false;
			  searchOperatorMath(cmd[i]);
		 
	  }
  }

  string final_output = "Output: \n :: Generation Code - C++ :: \n\n";
  final_output += "#include <iostream>\n int main(){\n \tint " + output + " \n }";

  cout << endl << final_output << endl;

}

void Tokens::searchOperatorMath(char token){
	 switch( token ){

        case SUM:
            cout << "< " << token  << " >" << "  :: arithmetic operator" << endl;
            break;
        case MULT:
            cout << "< " << token  << " >" << "  :: arithmetic operator" << endl;
            break;
		case LEFT_PARENT:
			cout << "< " << token  << " >" << "  :: LEFT_PARENT" << endl;
		
		break;
		case RIGHT_PARENT:
			cout << "< " << token << " >" << "  :: RIGHT_PARENT" << endl;
			break;
		case SEMICOLON:
			 cout << "< " << token  << " >" << "  :: SEMICOLON" << endl;
			 output += token;
			 output += "\n ";
			break;
		case ASIGN:
			cout << "< " << token << " >" << "  :: assignment operator" << endl;
			output += token;
			break;
		default:
			break;
	 }
}