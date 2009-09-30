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

	if (!prase_command_line(argc, argv, &gen, key, alfabet)) {
		print_usage();
		return 1;
	}

	cout << "enter string: ";
	char buff[1024], out[16 * 2 + 1], out2[16 * 2 + 1];
	int min, max;
	cin >> buff;
	mymd(buff, out);
	cout << out << "\nalfabet generare:";
	cin >> buff;
	cout << "lungime minima: ";
	cin >> min;
	cout << "lungime maxima: ";
	cin >> max;
	cout << "cheie cautata: ";
	cin >> out;
	bfGen bg(buff, min, max);
	while (bg.getStr(buff, out2) == 0) {
		cout << buff << " --> " << out2 << "\n";
		if (strcmp(out, out2) == 0)
			break;
	}
	cout << "am generat " << bg.genVars - 1 << " valori.......";
	cin >> buff;
	return 0;

}

void mymd(char instr[], char hex_output[]) {
	md5_state_t state;
	md5_byte_t digest[16];
	md5_init(&state);
	md5_append(&state, (const md5_byte_t *) instr, strlen(instr));
	md5_finish(&state, digest);
	for (int di = 0; di < 16; ++di)
		sprintf(hex_output + di * 2, "%02x", digest[di]);
}
