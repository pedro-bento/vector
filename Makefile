executable = vector
compiler = gcc
flags = -Wall -std=c11
files = main.c $(wildcard vector/*.c)

$(executable): $(files)
	$(compiler) $(flags) -o $(executable) $(files)