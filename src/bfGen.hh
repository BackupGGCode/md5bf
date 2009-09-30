#pragma once

class bfGen
{
	char charset[257];
	int length;
	int contor[128]; //la ce caracter din lista de simboluri ma aflu pe pe pozitia n (0-127)
	int maxSim; //number of symbols
	int minlen; //min length of input string
	int maxlen; //max length of input string

private:
	void reset(void);

public:
	bfGen(void);
	bfGen(char pchar[],int pminlen,int pmaxlen);
	~bfGen(void);
	int incContor(int poz);
	int getStr(char buff[],char md5[]);
	static int makeMd(char buff[],char md5[]);
	int genVars;
};
