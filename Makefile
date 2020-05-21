all: rsa output.txt

rsa: rsa.c rsa.h mod.c mod.h main.c
	@rm -f *.o rsa output.txt
	@gcc -o rsa main.c rsa.c rsa.h mod.c mod.h

output.txt:
	@./rsa
	@rm -f *.o rsa

clean:
	@rm -f *.o rsa output.txt
