MAN = shell.1

output: main.o analyser.o invoke.o Mab.o
	gcc main.o analyser.o invoke.o Mab.o -o shell

main.o: main.c
	gcc -c main.c

analyser.o: analyser.c analyser.h
	gcc -c analyser.c

invoke.o: invoke.c invoke.h
	gcc -c invoke.c

Mab.o: Mab/Mab.c Mab/Mab.h
	gcc -c Mab/Mab.c

install: output $(MAN)
	@echo "Installing shell..."
	cp shell /usr/local/bin/shell
	@echo "shell installed successfully!"
	@echo "Installing man page..."
	cp $(MAN) /usr/local/share/man/man1/$(MAN)
	@echo "$(MAN) installed successfully!"
	@echo "copping mapping file"
	cp conf/cmd.conf /etc/shell.conf

clean:
	rm -f *.o shell
