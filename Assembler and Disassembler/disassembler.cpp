#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    ifstream prog_input(argv[1]);
    ofstream prog_output(argv[2]);
    string input_bytes;
    string output_bytes;

    for(int i{0}; i<3;i++){
        prog_input>>input_bytes;
    }
    
    while(prog_input >> input_bytes){
        printf("Input: %s\n", input_bytes.c_str());
        if (input_bytes.compare("3")==0){ //operand
            output_bytes = output_bytes+"LDA ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("2")==0){//operand
            output_bytes = output_bytes+"LDY ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("1")==0){//operand
            output_bytes = output_bytes+"LDX ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("9")==0){
            output_bytes = output_bytes+"TAX ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("5")==0){//operand
            output_bytes = output_bytes+"SEC ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("b")==0){//operand
            output_bytes = output_bytes+"JMP ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("4")==0){
            output_bytes = output_bytes+"ADC ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("c")==0){//operand
            output_bytes = output_bytes+"STA ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("8")==0){
            output_bytes = output_bytes+"CLC ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else if (input_bytes.compare("7")==0){//operand
            output_bytes = output_bytes+"BCS ";
            prog_input>>input_bytes;
            output_bytes = output_bytes+input_bytes+"\n";
        }
        else{
            output_bytes = output_bytes + "Invalid input\n";
        }
    }

    prog_output << output_bytes;
    prog_input.close();
    prog_output.close();

}