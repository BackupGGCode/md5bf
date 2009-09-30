#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "md5.h"
#include "bfGen.hh"
#include "cons.hh"

void mymd(char instr[], char out[]);

int main(int argc, char *argv[]) {
	bool gen; // daca functioneaza in mod generator
	char key[33]; //cheia cautata
	char alfabet[256]; // sirul de caractere folosit / in mod genetaror sirul de criptat
	int l,L;
	if (!prase_command_line(argc, argv, &gen, key, alfabet,&l,&L)) {
		print_usage();
		return 1;
	}

	if(gen==true)
	{
		bfGen::makeMd(alfabet,key);
		cout<<alfabet <<" -> "<<key;
		return 0;
	}
	else
	{
		char buff[1024], out2[16 * 2 + 1];
		bfGen bg(alfabet, l, L);
		cout << "+---------------------------------------------------------+\n";
		cout << "| Starting cracker with:                                  |\n";
		cout << "|  *****************************************************  |\n";
		cout << "|  -s "<< alfabet << "\n";
		cout << "|  -l "<< l << "\n";
		cout << "|  -L "<< L << "\n";
		cout << "+---------------------------------------------------------+\n";
		system("pause");
		while (bg.getStr(buff, out2) == 0) {
			cout << buff << " --> " << out2 << "\n";
			if (strcmp(key, out2) == 0)
				break;
		}
		cout  << bg.genVars - 1 << " values generated ";
		return 0;
	}
}
