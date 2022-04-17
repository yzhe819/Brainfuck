const BrainFuck = require("./BrainFuck.js");

const brainfuck = new BrainFuck();

console.log("Hello world in brainfuck:\n");

const res = brainfuck.execute(`
++++++++++
[ 
    >+++++++>++++++++++>+++>+<<<<-
]
>++. Print 'H'
>+. Print 'e'
+++++++.. Print 'll'
+++. Print 'o'
>++. Print ' '
<<+++++++++++++++. Print 'W'
>. Print 'o'
+++. Print 'r'
------. Print 'l'
--------. Print 'd'
>+. Print '!'
>. Print '\n'
`);

console.log(res);
