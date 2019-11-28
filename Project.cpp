#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se secind
using namespace std;

//TO DO LIST
//FILL THE MAPS FOR INSTRUCTIONS GIVEN // AND IN INT_32T MAIN() ADD INSTRUCTION TYPE IN IF ELSE CONDITION'S GIVEN


map<string,int>opcode;
map<string,int>regValues;
map<string,int>functionValues;
map<string,int>shamtValues;


void initialize()
{
    regValues["$zero"]=0;
    regValues["s0"]=16;
    regValues["s1"]=17;
    regValues["s2"]=18;
    regValues["s3"]=19;
    regValues["s4"]=20;
    regValues["s5"]=21;
    regValues["s6"]=22;
    regValues["s7"]=23;

    regValues["t0"]=8;
    regValues["t1"]=9;
    regValues["t2"]=10;
    regValues["t3"]=11;
    regValues["t4"]=12;
    regValues["t5"]=13;
    regValues["t6"]=14;
    regValues["t7"]=15;
///////R--------FORMAT    
    opcode["add"]=0; 
    opcode["sub"]=0;
    opcode["mul"]=0;
    opcode["and"]=0;
    opcode["or"]=0; 
    opcode["div"]=0; 
    opcode["sll"]=0; 
    opcode["srl"]=0; 
    opcode["sra"]=0;
    opcode["addu"]=0; 
    opcode["jr"]=0;
    opcode["mfhi"]=0;
    opcode["mthi"]=0;
    opcode["mflo"]=0; 
    opcode["mtlo"]=0; 
    opcode["divu"]=0; 
    opcode["xor"]=0; 
    opcode["slt"]=0;


    functionValues["add"]=32;
    functionValues["sub"]=34;
    functionValues["mul"]=24; 
    functionValues["and"]=36;
    functionValues["or"]=37;
    functionValues["div"]=26;
    functionValues["sll"]=0;
    functionValues["srl"]=2;
    functionValues["sra"]=3
    functionValues["addu"]=33; 
    functionValues["jr"]=8;
    functionValues["mfhi"]=16;
    functionValues["mflo"]=18; 
    functionValues["mtlo"]=19; 
    functionValues["divu"]=27; 
    functionValues["xor"]=38; 
    functionValues["slt"]=42;

    shamtValues["add"]=0;
    shamtValues["sub"]=0;
    shamtValues["mul"]=0;
    shamtValues["and"]=0;
    shamtValues["or"]=0;
    shamtValues["div"]=0;
    shamtValues["sll"]=4;
    shamtValues["srl"]=4;
    shamtValues["sra"]=4;


////////I------FORMAT
    opcode["beq"]=4; 
    opcode["bne"]=5;
    opcode["addi"]=8;
    opcode["addiu"]=9;
    opcode["andi"]=12; 
    opcode["ori"]=13; 
    opcode["slti"]=10; 
    opcode["sltiu"]=11; 
    opcode["lui"]=15;
    opcode["lw"]=35;
    opcode["sw"]=43;
    opcode["beq"]=4;
    opcode["blez"]=6; 
    opcode["bgtz"]=7;
    opcode["lbu"]=36;
    opcode["lb"]=32;
    opcode["sh"]=41;
    opcode["sb"]=40;
    
    functionValues["beq"]=0; 
    functionValues["bne"]=0;
    functionValues["addi"]=0;
    functionValues["addiu"]=0;
    functionValues["andi"]=0; 
    functionValues["ori"]=0; 
    functionValues["slti"]=0; 
    functionValues["sltiu"]=0; 
    functionValues["lui"]=0;
    functionValues["lw"]=0;
    functionValues["sw"]=0;
    functionValues["beq"]=0;
    functionValues["blez"]=0; 
    functionValues["bgtz"]=0;
    functionValues["lbu"]=0;
    functionValues["sh"]=0;
    functionValues["lb"]=0;
    functionValues["sb"]=0;
}
void processInstructions(vector<vector<string>>&instructions)
{
   cout<<"Called"<<endl;
    vector<string>binary;
    for(int i=0;i<instructions.size();i++)
    {
        string bit32B="";
        if(instructions[i][instructions[i].size()-1]=="1")   //R FORMAT
        {
            
            bitset<6>opcodeReader(opcode[instructions[i][0]]);
            bitset<5>rs(regValues[instructions[i][2]]);
            bitset<5>rt(regValues[instructions[i][3]]);
            bitset<5>rd(regValues[instructions[i][1]]);
            bitset<5>shamt(shamtValues[instructions[i][0]]);
            bitset<6>func(functionValues[instructions[i][0]]);

            
            bit32B += opcodeReader.to_string();
            bit32B +=rs.to_string();
            bit32B +=rt.to_string();
            bit32B +=rd.to_string();
            bit32B +=shamt.to_string();
            bit32B +=func.to_string();
            cout<<bit32B<<endl;
            binary.pb(bit32B);

        }
        else if(instructions[i][instructions[i].size()-1]=="2")   //LW AND SW
        {
            bitset<6>opcodeReader(opcode[instructions[i][0]]);
            bitset<5>rs(regValues[instructions[i][2]]);
            bitset<5>rt(regValues[instructions[i][1]]);
            bitset<16>immediate(stoi(instructions[i][3]));

            bit32B+=opcodeReader.to_string();
            bit32B+=rs.to_string();
            bit32B+=rt.to_string();
            bit32B+=immediate.to_string();

    
            cout<<bit32B<<endl;
            binary.pb(bit32B);
        }
        else if(instructions[i][instructions[i].size()-1]=="3")   //BEQ AND BNE
        {
            bitset<6>opcodeReader(opcode[instructions[i][0]]);
            bitset<5>rs(regValues[instructions[i][1]]);
            bitset<5>rt(regValues[instructions[i][2]]);
            bitset<16>immediate(stoi(instructions[i][3]));

            bit32B+=opcodeReader.to_string();
            bit32B+=rs.to_string();
            bit32B+=rt.to_string();
            bit32B+=immediate.to_string();

            cout<<bit32B<<endl;
            binary.pb(bit32B);
            
        }
        else if(instructions[i][instructions[i].size()-1]=="4")  //J
        {
            bitset<6>opcodeReader(opcode[instructions[i][0]]);
            bitset<26>immediate(stoi(instructions[i][1]));

            bit32B+=opcodeReader.to_string();
            bit32B+=immediate.to_string();
            
            cout<<bit32B<<endl;
            binary.pb(bit32B);
        }
    }
}
int32_t main()   
{
    initialize(); //INITIALIZE ALL MAPS

    vector<vector<string>>instructions;
    while(1)
    {
        //R=1          LW,SW=2             BEQ,BNE=3      J=4   //PASSED AT LAST TO IDENTIFY FORMAT OF INS. TO MAKE IMPLEMENTATION EASY
        vector<string>temp;
        string x;
        cin>>x;
        if(x=="##")
        {
            break;
        }
        else if(x=="add" || x=="sub" || x=="mul" || x=="and"||x=="or"||x=="add"||x=="sub"||x=="mul"||x=="and"||x=="or"||x=="div"||x=="sll"||x=="srl"||x=="sra"||x=="addu"||x=="jr"||x=="mfhi"||x=="mthi"||x=="mflo"||x=="mtlo"||x=="divu"||x==xor||x=="slt") //R-FORMAT
        {
            string reg1,reg2,reg3;
            cin>>reg1>>reg2>>reg3;
            
            temp.pb(x);
            temp.pb(reg1);
            temp.pb(reg2);
            temp.pb(reg3);
            temp.pb(to_string(1));
        }
        else if(x=="beq"||x=="bne"||x=="addi"||x=="addiu"||x=="andi"||x=="ori"||x=="slti"||x=="sltiu"||x=="lui"||x=="lw"||x=="sw"||x=="beq"||x=="blez"||x=="bgtz"||x=="lbu"||x=="lb"||x=="sh"||x=="sb") //I-FORMAT
        {
            string reg1,reg2;
            string offset;
            cin>>reg1>>offset>>reg2;
            
            temp.pb(x);
            temp.pb(reg1);
            temp.pb(reg2);
            temp.pb(offset);
            temp.pb(to_string(2));
        }
        else if(x=="beq" || x=="bne") //I-FORMAT
        {
            string reg1,reg2;
            string offset;
            cin>>reg1>>reg2>>offset;
            
            temp.pb(x);
            temp.pb(reg1);
            temp.pb(reg2);
            temp.pb(offset);
            temp.pb(to_string(3));
        }
        else if(x=="j")  //JUMP-FORMAT
        {
            string address;
            cin>>address;
           
            temp.pb(x);
            temp.pb(address);
            temp.pb(to_string(4));
        }
        instructions.pb(temp);
    }
    processInstructions(instructions);
}
