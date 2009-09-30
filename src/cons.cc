#include "cons.hh"
#include <iostream>

using namespace std;

void print_usage() {
	cout << "+---------------------------------------------------------+\n";
	cout << "|               Md5Bf - Brute force md5 cracker           |\n";
	cout << "|                       v 0.1                             |\n";
	cout << "|  *****************************************************  |\n";
	cout << "|  -s symbol list  / string to generate from              |\n";
	cout << "|  -k the key to find                                     |\n";
	cout << "|  -g generator                                           |\n";
	cout << "|                                                         |\n";
	cout << "|                                                         |\n";
	cout << "|                                                         |\n";
	cout << "+---------------------------------------------------------+\n";
	system("PAUSE");
}

//check the parameters and if something is wrong return false

bool prase_command_line(int argc, char* argv[], bool *gen, char key[],
		char alfabet[]) {

	if (argc < 2) {
		return false;
	}

	memset(key, 0, 33);
	memset(alfabet, 0, 256);
	*gen = false;

	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 's':
				i++;
				strcpy(alfabet, argv[i]);
				break;
			case 'k':
				i++;
				strcpy(key, argv[i]);
				break;
			case 'g':
				*gen = true;
				break;

			}
		}
	}
	if (*gen == true && strlen(alfabet) == 0)
		return false;
	if (*gen == false && (strlen(alfabet) == 0 || strlen(key) == 0))
		return false;
	return true;
}
