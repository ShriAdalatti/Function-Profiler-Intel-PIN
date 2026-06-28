#include "pin.H"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using std::string;
using std::ofstream;
using std::map;

// 🔥 map to store instruction count per function
map<string, UINT64> funcInstrCount;

// 🔥 output file
ofstream OutFile("funccount.out");

// 🔥 count instruction for each function
VOID CountInstruction(string *name)
{
    funcInstrCount[*name]++;
}

// 🔥 instrument each routine (function)
VOID Routine(RTN rtn, VOID *v)
{
    if (!RTN_Valid(rtn)) return;

    // only main executable
    if (!IMG_IsMainExecutable(SEC_Img(RTN_Sec(rtn))))
        return;

    // get function name
    string *name = new string(RTN_Name(rtn));

    RTN_Open(rtn);

    // insert call before every instruction
    for (INS ins = RTN_InsHead(rtn); INS_Valid(ins); ins = INS_Next(ins))
    {
        INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)CountInstruction,
                       IARG_PTR, name,
                       IARG_END);
    }

    RTN_Close(rtn);
}

// 🔥 print output at end
VOID Fini(INT32 code, VOID *v)
{
    for (auto it = funcInstrCount.begin(); it != funcInstrCount.end(); it++)
    {
        OutFile << it->first << " : " << it->second << std::endl;
    }
    OutFile.close();
}

// 🔥 main
int main(int argc, char *argv[])
{
    if (PIN_Init(argc, argv))
    {
        std::cerr << "PIN Init Failed\n";
        return 1;
    }

    RTN_AddInstrumentFunction(Routine, 0);
    PIN_AddFiniFunction(Fini, 0);

    PIN_StartProgram();

    return 0;
}
