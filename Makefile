program_name=den

compile: $(program_name)

$(program_name): *.o

	@echo linking den...

	@cc -o $(program_name) *.o

*.o:

	@echo compiling den...

	@cc -c *.c

clean:
	@echo removing object files and binary...
	@rm *.o $(program_name)

install: compile

	@echo copyng binfile...

	@cp $(program_name) /usr/bin/$(program_name)

uninstall:
	@echo removing binfile...
	@rm /usr/bin/$(program_name)

reinstall: uninstall install
