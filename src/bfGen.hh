#pragma once

class bfGen
{
	char charset[257];
	int length;
	int contor[128]; //la ce caracter din lista de simboluri ma aflu pe pe pozitia n (0-127)
	int maxSim; //numarul de simboluri
public:
	bfGen(void);
	bfGen(char pchar[],int pminlen,int pmaxlen);
	~bfGen(void);
private:
	void reset(void);
public:
	int incContor(int poz);
	int getStr(char buff[],char md5[]);
	static int makeMd(char buff[],char md5[]);
	int genVars;
private:
	int minlen;
public:
	int maxlen;
};
