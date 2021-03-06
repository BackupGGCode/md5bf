
DOBJS = main.o bfGen.o md5.o cons.o
DOBJJ =debug/objects/main.o debug/objects/bfGen.o debug/objects/md5.o debug/objects/cons.o

ROBJS = rmain.o rbfGen.o rmd5.o rcons.o
ROBJJ =release/objects/main.o release/objects/bfGen.o release/objects/md5.o release/objects/cons.o

RM = del /Q
 
DBGFLAGS = -g -c -Wall
RELFLAGS = -c -Wall
 
rmain.o:	src/main.cc src/md5.h src/bfGen.hh src/cons.hh
	$(CXX) $(RELFLAGS) -o release/objects/main.o src/main.cc

rbfGen.o:	src/bfGen.cc src/bfGen.hh
	$(CXX) $(RELFLAGS) -o release/objects/bfGen.o src/bfGen.cc

rmd5.o:	src/md5.c src/md5.h
	$(CXX) $(RELFLAGS) -o release/objects/md5.o src/md5.c

rcons.o:	src/cons.cc src/cons.hh
	$(CXX) $(RELFLAGS) -o release/objects/cons.o src/cons.cc

	
release:	$(ROBJS)	
	$(CXX) -o release/md5bf $(ROBJJ)	
	@echo Done Build Release
	
	
#prntru debug
	
main.o:	src/main.cc src/md5.h src/bfGen.hh src/cons.hh
	$(CXX) $(DBGFLAGS) -o debug/objects/main.o src/main.cc

bfGen.o:	src/bfGen.cc src/bfGen.hh
	$(CXX) $(DBGFLAGS) -o debug/objects/bfGen.o src/bfGen.cc

md5.o:	src/md5.c src/md5.h
	$(CXX) $(DBGFLAGS) -o debug/objects/md5.o src/md5.c

cons.o:	src/cons.cc src/cons.hh
	$(CXX) $(DBGFLAGS) -o debug/objects/cons.o src/cons.cc

	
debug:	$(DOBJS)	
	$(CXX) -g -o debug/md5bf $(DOBJJ)	
	@echo Done Build Debug

	
all:	debug release
	@echo All Done
	
clean:	
	$(RM) debug\m* debug\objects\* release\m* release\objects\*
