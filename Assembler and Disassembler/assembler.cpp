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

    prog_output << "v2.0 raw\n4*0 ";

    while(prog_input >> input_bytes){
        printf("Input: %s\n", input_bytes.c_str());
        if (input_bytes.compare("LDA")==0){ //operand
            output_bytes = output_bytes+"3 \n";
        }
        else if (input_bytes.compare("LDY")==0){//operand
            output_bytes = output_bytes+"2 \n";
        }
        else if (input_bytes.compare("LDX")==0){//operand
            output_bytes = output_bytes+"1 \n";
        }
        else if (input_bytes.compare("TAX")==0){
            output_bytes = output_bytes+"9 \n";
        }
        else if (input_bytes.compare("SEC")==0){//operand
            output_bytes = output_bytes+"5 \n";
        }
        else if (input_bytes.compare("JMP")==0){//operand
            output_bytes = output_bytes+"b \n";
        }
        else if (input_bytes.compare("ADC")==0){
            output_bytes = output_bytes+"4 \n";
        }
        else if (input_bytes.compare("STA")==0){//operand
            output_bytes = output_bytes+"c \n";
        }
        else if (input_bytes.compare("CLC")==0){
            output_bytes = output_bytes+"8 \n";
        }
        else if (input_bytes.compare("BCS")==0){//operand
            output_bytes = output_bytes+"7 \n";
        }
        else{
            output_bytes = output_bytes + input_bytes+"\n";
        }
    }

    prog_output << output_bytes;
    prog_input.close();
    prog_output.close();
}
