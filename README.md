# Brainfuck

### Summary:

Brainfuck is a minimalist programming language created in 1993 😅

```c
++++[++++>---<]>-.---[----->+<]>-.+++[->+++<]>++.++++++++.+++++.--------.-[--->+<]>--.+[->+++<]>+.++++++++.-[++>---<]>+.-[--->++<]>-.++++++++++.+[---->+<]>+++.[->+++<]>+.-[->+++<]>.+[----->+<]>.----.+++++.-----.++++.------------.+++++++++++.---.++++++++++.+.[---->+<]>+++.[-->+++++++<]>.++.---.--------.+++++++++++.+++[->+++<]>++.++++++++++++..----.+++++.-------.-[--->+<]>--.++[--->++<]>.-----------.+++++++++++++.-------.--[--->+<]>--.[->+++<]>++.++++++.--.--[--->+<]>-.+[->+++<]>.-[--->+<]>----.-------------.----.--[--->+<]>-.+++[->+++<]>.-.-[--->+<]>-.-[--->++<]>-.+++++.-[->+++++<]>-.[-->+++<]>+.++++++++..------.-----.
```



### Tutorial:

There is an Array of 30000 bytes you can play in. Every byte in array  have the value of 0 by default. You will have a "pointer" which you can  move around in the array. When you are at a byte with your pointer you  can either increment or decrement the value of it, output the value of  it, store a value in it...

| >    | Increment the pointer.                                       |
| ---- | ------------------------------------------------------------ |
| <    | Decrement the pointer.                                       |
| +    | Increment the byte at the pointer.                           |
| -    | Decrement the byte at the pointer.                           |
| .    | Output the byte at the pointer in ASCII.                     |
| ,    | Input a byte and store it in the byte at the pointer.        |
| [    | Jump forward past the matching ] if the byte at the pointer is zero. |
| ]    | Jump backward to the matching [ unless the byte at the pointer is zero. |

You can use this ASCII-table to make things a little bit easier.

![](https://upload.wikimedia.org/wikipedia/commons/7/7b/Ascii_Table-nocolor.svg)

