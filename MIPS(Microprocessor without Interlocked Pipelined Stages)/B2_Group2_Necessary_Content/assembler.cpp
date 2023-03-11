#include<bits/stdc++.h>
#include <bitset>

#define T0 "0000"
#define T1 "0001"
#define T2 "0010"
#define T3 "0011"
#define T4 "0100"
#define ZERO "0111"
#define INSTRUCTION_SIZE 1

#define J "0000"
#define BNEQ "0001"
#define SUB "0010"
#define ADD "0011"
#define ADDI "0100"
#define SLL "0101"
#define ORI "0110"
#define OR "0111"
#define BEQ "1000"
#define LW "1001"
#define NOR "1010"
#define AND "1011"
#define SRL "1100"
#define SUBI "1101"
#define ANDI "1110"
#define SW "1111"



using namespace std;

int lineCount= 0;
vector<pair<string,int> > labelAddress;

vector<string> split(const string &s)
{
    vector<string> elements;
    string item = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '\t') {
            if (item != "") {
                elements.push_back(item);
                item = "";
            }
        }
        else {
            item += s[i];
        }
    }

    if (item != "") {
        elements.push_back(item);
    }

    return elements;
}

string toHex(string str) {
    string hex = "";
    for (int i = 0; i < str.size(); i += 4) {
        string temp = str.substr(i, 4);
        if (temp == "0000") {
            hex += "0";
        } else if (temp == "0001") {
            hex += "1";
        } else if (temp == "0010") {
            hex += "2";
        } else if (temp == "0011") {
            hex += "3";
        } else if (temp == "0100") {
            hex += "4";
        } else if (temp == "0101") {
            hex += "5";
        } else if (temp == "0110") {
            hex += "6";
        } else if (temp == "0111") {
            hex += "7";
        } else if (temp == "1000") {
            hex += "8";
        } else if (temp == "1001") {
            hex += "9";
        } else if (temp == "1010") {
            hex += "a";
        } else if (temp == "1011") {
            hex += "b";
        } else if (temp == "1100") {
            hex += "c";
        } else if (temp == "1101") {
            hex += "d";
        } else if (temp == "1110") {
            hex += "e";
        } else if (temp == "1111") {
            hex += "f";
        }
    }
    return hex;
}

void pushbackLabels(string line){

    vector<string> v= split(line);
    if(v[0]=="sub"||v[0]=="ori"||v[0]=="bneq"||v[0]=="addi"||
        v[0]=="beq"||v[0]=="or"||v[0]=="sw"||v[0]=="srl"||
        v[0]=="and"||v[0]=="andi"||v[0]=="lw"||v[0]=="add"||
        v[0]=="sll"||v[0]=="subi"||v[0]=="j"||v[0]=="nor");
    else {
        labelAddress.push_back(make_pair(v[0], lineCount));
    }
}

string convert(string line) {
    string instruction="";
    vector<string> v= split(line);



    string item = v[0];
    if(item=="j") instruction+="0000";
    else if(item=="bneq") instruction+="0001";
    else if(item=="sub") instruction+="0010";
    else if(item=="add") instruction+="0011";
    else if(item=="addi") instruction+="0100";
    else if(item=="sll") instruction+="0101";
    else if(item=="ori") instruction+="0110";
    else if(item=="or") instruction+="0111";
    else if(item=="beq") instruction+="1000";
    else if(item=="lw") instruction+="1001";
    else if(item=="nor") instruction+="1010";
    else if(item=="and") instruction+="1011";
    else if(item=="srl") instruction+="1100";
    else if(item=="subi") instruction+="1101";
    else if(item=="andi") instruction+="1110";
    else if(item=="sw") instruction+="1111";
    else {
        labelAddress.push_back(make_pair(item, lineCount));
        vector<string> temp;
        for (int j=1; j<v.size(); j++){
            temp.push_back(v[j]);
        }
        v=temp;
        item = v[0];
        // instruction
        if(item=="j") instruction+="0000";
        else if(item=="bneq") instruction+="0001";
        else if(item=="sub") instruction+="0010";
        else if(item=="add") instruction+="0011";
        else if(item=="addi") instruction+="0100";
        else if(item=="sll") instruction+="0101";
        else if(item=="ori") instruction+="0110";
        else if(item=="or") instruction+="0111";
        else if(item=="beq") instruction+="1000";
        else if(item=="lw") instruction+="1001";
        else if(item=="nor") instruction+="1010";
        else if(item=="and") instruction+="1011";
        else if(item=="srl") instruction+="1100";
        else if(item=="subi") instruction+="1101";
        else if(item=="andi") instruction+="1110";
        else if(item=="sw") instruction+="1111";
    }


    // R format : sub, or, and, add, nor
    if((instruction=="0010")||(instruction=="0111")||(instruction=="1011")||(instruction=="0011")||(instruction=="1010")) {

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        

        if (v[3]=="$t0") instruction+=T0;
        else if (v[3]=="$t1") instruction+=T1;
        else if (v[3]=="$t2") instruction+=T2;
        else if (v[3]=="$t3") instruction+=T3;
        else if (v[3]=="$t4") instruction+=T4;
        else if (v[3]=="$zero") instruction+=ZERO;
        

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;

        return instruction;
    }


    // S format : srl, sll
    else if((instruction=="1100")||(instruction=="0101")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        

        int const_int=stoi(v[3]);
        string const_str="0000";

        for(int j=0; const_int>0; j++) {
            const_str[const_str.size()-j-1]=(const_int%2)?'1':'0';
            const_int= const_int/2;
        }

        instruction+=const_str;

        return instruction;
    }


    // I format constant : ori, addi, andi, subi
    else if((instruction=="0110")||(instruction=="0100")||(instruction=="1110")||(instruction=="1101")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;
        

        int const_int=stoi(v[3]);
        //cout<<const_int<<endl;

        string const_str = bitset<4>(const_int).to_string();



        instruction+=const_str;

        return instruction;
    }


    // I format control : beq, bneq
    else if((instruction=="1000")||(instruction=="0001")){

        if (v[2]=="$t0") instruction+=T0;
        else if (v[2]=="$t1") instruction+=T1;
        else if (v[2]=="$t2") instruction+=T2;
        else if (v[2]=="$t3") instruction+=T3;
        else if (v[2]=="$t4") instruction+=T4;
        else if (v[2]=="$zero") instruction+=ZERO;
        

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;


        int bAddress;
        for(int j=0; j<labelAddress.size(); j++){
                
            if(labelAddress[j].first == v[3] + ":") {
                bAddress=labelAddress[j].second;
            }
        }


        int const_int=(bAddress-lineCount-1)*INSTRUCTION_SIZE; //+1?
        string const_str = bitset<4>(const_int).to_string();

        instruction+=const_str;

        return instruction;
    }


    // I format memory : sw, lw
    else if((instruction=="1001")||(instruction=="1111")){

        string constant;
        stringstream ss2(v[2]);
        if (getline(ss2,item,'(')) {
            constant=item;
        }
        if (getline(ss2,item,')')) {
            if (item=="$t0") instruction+=T0;
            else if (item=="$t1") instruction+=T1;
            else if (item=="$t2") instruction+=T2;
            else if (item=="$t3") instruction+=T3;
            else if (item=="$t4") instruction+=T4;
            else if (item=="$zero") instruction+=ZERO;
        }

        if (v[1]=="$t0") instruction+=T0;
        else if (v[1]=="$t1") instruction+=T1;
        else if (v[1]=="$t2") instruction+=T2;
        else if (v[1]=="$t3") instruction+=T3;
        else if (v[1]=="$t4") instruction+=T4;
        else if (v[1]=="$zero") instruction+=ZERO;

        int const_int=stoi(constant)*INSTRUCTION_SIZE;
        string const_str = bitset<4>(const_int).to_string();

        instruction+=const_str;

        return instruction;
    }


    // J format : j
    else if((instruction=="0000")){

        int jAddress;
        for(int j=0; j<labelAddress.size(); j++){

            if(labelAddress[j].first == v[1] + ":") {
                jAddress=labelAddress[j].second;
            }
        }


        
        int const_int=jAddress*INSTRUCTION_SIZE;
        string const_str = bitset<8>(const_int).to_string();

        instruction+=const_str;

        instruction+="0000";

        return instruction;
    }

    else return instruction;
}

int main ()
{
    string line;
    ifstream fin ("assembly.txt");
    ofstream fout ("machine.txt");
    ofstream fout1("hexFile.txt");
    if (fin.is_open()) {
        while (getline (fin,line)) {
            
            pushbackLabels(line);
            lineCount++;
        }
        fin.close();

        // for(int i = 0; i < labelAddress.size(); i++){
        //     cout << labelAddress[i].first << ", " << labelAddress[i].second << endl;
        // }

        fin.open("assembly.txt");
        lineCount=0;
        while (getline (fin,line)) {
            // lineCount++;
            string str_bin=convert(line);
            string str_hex=toHex(str_bin);
            fout<<str_bin<<endl;
            fout1<<str_hex<<endl;
            lineCount++;
        }
        fin.close();
    }
    else cout<<"Unable to open file"<<endl;
    fout.close();
    return 0;
}