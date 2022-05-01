test: compile
	./bf ./example/Hello.bf
	./min ./example/Hello.bf

add: compile
	./bf ./arithmetic/Addition.bf
	./min ./arithmetic/Addition.bf

sub: compile
	./bf ./arithmetic/Subtraction.bf
	./min ./arithmetic/Subtraction.bf
  
compile:
	gcc Brainfuck.c -o bf
	gcc Brainfuck.min.c -o min