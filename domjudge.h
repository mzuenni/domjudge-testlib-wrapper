// define exitcodes for testlib.h
#ifndef _DOMJUDGE_TESTLIB_H_
#define _DOMJUDGE_TESTLIB_H_

#ifdef _TESTLIB_H_
#error testlib.h included
#endif

#ifdef OK_EXIT_CODE
#   undef OK_EXIT_CODE
#endif
#define OK_EXIT_CODE 42

#ifdef WA_EXIT_CODE
#   undef WA_EXIT_CODE
#endif
#define WA_EXIT_CODE 43

#ifdef PE_EXIT_CODE
#   undef PE_EXIT_CODE
#endif
#define PE_EXIT_CODE 43

#ifdef DIRT_EXIT_CODE
#   undef DIRT_EXIT_CODE
#endif
#define DIRT_EXIT_CODE 43

#ifdef UNEXPECTED_EOF_EXIT_CODE
#   undef UNEXPECTED_EOF_EXIT_CODE
#endif
#define UNEXPECTED_EOF_EXIT_CODE 43

#define registerTestlibCmd _domjudge_registerTestlibCmd
#define registerInteraction _domjudge_registerInteraction
#include "testlib.h"
#undef registerInteraction
#undef registerTestlibCmd

struct ArgConvert {
	std::string binary, testin, testout, feedback, error;
	std::vector<char*> testlibArgs;
	ArgConvert(int argc, char* argv[]) {
		if (argc != 4) quit(_fail, "wrong number of parameters!");
		binary = std::string(argv[0]);
		testin = std::string(argv[1]);
		testout = std::string(argv[2]);
		feedback = std::string(argv[3]);
		feedback += "/judgemessage.txt";
		error = std::string(argv[3]);
		error += "/judgeerror.txt";

		testlibArgs.push_back(&binary[0]);
		testlibArgs.push_back(&testin[0]);
		testlibArgs.push_back(&feedback[0]);
		testlibArgs.push_back(&testout[0]);
		testlibArgs.push_back(&error[0]);
		testlibArgs.push_back(nullptr);
	}
	int argc() {return 5;}
	char** argv() {return testlibArgs.data();}
};

void registerTestlibCmd(int argc, char* argv[]) {
	ArgConvert tmp(argc, argv);
	_domjudge_registerTestlibCmd(tmp.argc(), tmp.argv());
}

void registerInteraction(int argc, char* argv[]) {
	ArgConvert tmp(argc, argv);
	_domjudge_registerInteraction(tmp.argc(), tmp.argv());
}
#endif
