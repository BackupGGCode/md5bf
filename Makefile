
all:	main.o bfGen.o md5.o
	$(CXX) -o md5bf main.o bfGen.o md5.o	
	@echo All Done

main.o:	main.cc md5.h bfGen.hh
	$(CXX) -c main.cc

bfGen.o:	bfGen.cc bfGen.hh
	$(CXX) -c bfGen.cc

md5.o:	md5.c md5.h
	$(CXX) -c md5.c
