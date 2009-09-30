#include "bfGen.hh"
#include <string.h>
#include "md5.h"
#include <stdio.h>


bfGen::bfGen(void)
: genVars(0)
, minlen(0)
, maxlen(0)
{
}

bfGen::~bfGen(void)
{
}

bfGen::bfGen(char pchar[],int pminlen,int pmaxlen)
{
	strcpy(charset,pchar);
	minlen=pminlen;
	maxlen=pmaxlen;
	length=minlen;
	reset();
}
void bfGen::reset(void)
{
	maxSim=(int)strlen(charset);
	memset(contor,0,128*sizeof(int));
	genVars=0;
}

int bfGen::incContor(int poz)
{
	if(poz<0)
		return 1;
	contor[poz]++;
	if(contor[poz]==maxSim)
	{
		contor[poz]=0;
		return incContor(poz-1);
	}
	return 0;
}

int bfGen::getStr(char buff[],char hex_output[])
{
	for(int i=0;i<length;i++)
	{
		buff[i]=charset[contor[i]];
	}
	buff[length]=0;
	genVars++;
	makeMd(buff,hex_output);
	if(incContor(length-1)!=0)
	{
		if(length==maxlen)
			return 1;
		else
		{
			length++;
			reset();
		}
	}

	return 0;

}

int bfGen::makeMd(char in[],char out[])
{
	md5_state_t state;
	md5_byte_t digest[16];
	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)in, strlen(in));
	md5_finish(&state, digest);
	for (int di = 0; di < 16; ++di)
	    sprintf(out + di * 2, "%02x", digest[di]);
	return 0;
}
