All:program3 clean submit

program3: program3.o bomb.o
	gcc -g program3.o bomb.o hidden.o -o program3
program3.o:
	gcc -g -c program3.c
bomb.o:
	gcc -g -c bomb.c
bscript: program3
	gdb ./program3
	./bscript.sh phase1.key phase2.key phase3.key phase4.key phase5.key phase6.key bomb_defused.log
memcheck: program3
	valgrind ./program3
 
clean:  bscript
	rm program3.o bomb.o program3
	mv keys/phase*.key ../program-3-fall18-hahuja2612
	mv keys/bomb_defused.log ../program-3-fall18-hahuja2612
	rm -r keys
 
submit:
	git commit -a -m "from makefile"
	git push
