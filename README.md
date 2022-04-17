# Brainfuck

Hello Brainfuck 👋

### Summary:

Brainfuck is a minimalist programming language, which only consists of only eight simple commands, a data pointer and an instruction pointe. And it is fully Turing complete.

| Command    | Function                                      |
| ---- | ------------------------------------------------------------ |
| >    | Increment the pointer.                                       |
| <    | Decrement the pointer.                                       |
| +    | Increment the byte at the pointer.                           |
| -    | Decrement the byte at the pointer.                           |
| .    | Output the byte at the pointer in ASCII.                     |
| ,    | Input a byte and store it in the byte at the pointer.        |
| [    | Jump forward past the matching ] if the byte at the pointer is zero. |
| ]    | Jump backward to the matching [ unless the byte at the pointer is zero. |



### Principle:

You can use a 30000-byte array to play with. By default, the value of every byte in the array is 0. You'll be given a "pointer" that you can move around the array with. You can either increment or decrement the value of a byte using your pointer, output the value of it, or store a value in it...



### Start:

The first step is to clone this repo and go to the root folder of it.

```shell
git clone https://github.com/yzhe819/Brainfuck.git
```

The second step is to compile, use gcc to compile a Brainfuck.exe.

```shell
gcc Brainfuck.c -o Brainfuck
```

Then, you can drag the Hello.BF file into this Brainfuck.exe.

Or run with the following command line below, it will read the entire file and print the output.

```shell
Brainfuck ./Hello.BF
```

Finally, you can see the "Hello, World!" appear on your screen.

```shell
PS D:\project\Brainfuck> .\Brainfuck ./Hello.BF
Hello, World!
```



Feel free to modify the program and code and hope to have fun.
