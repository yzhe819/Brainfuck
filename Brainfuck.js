const { Writable, Readable } = require("stream"),
  { ReadStream } = require("tty"),
  { readSync, closeSync } = require("fs"); // Import modules to manipulate streams

const encoder = new TextEncoder(); // To encode sting to Uint8Array

const isPositiveInteger = (num) => Number.isInteger(num) && num > -1; // Check if the number is positive integer

module.exports = class Brainfuck {
  constructor({ stdin, stdout, memory, cursor } = {}) {
    this.stdin = stdin instanceof Readable ? stdin : process.stdin; // Set input stream
    this.stdout = stdout instanceof Writable ? stdout : process.stdout; // Set output stream

    this.temp = new Uint8Array(1); // Temporary memory
    this.memory =
      memory instanceof Uint8Array
        ? memory
        : isPositiveInteger(memory) && memory > 0
        ? new Uint8Array(memory)
        : new Uint8Array(30000); // Memory

    this.cursor = isPositiveInteger(cursor) ? cursor : 0;

    this.result = ""; // the final Result

    if (this.stdin instanceof ReadStream) {
      this.stdin.setRawMode(true); // Config the input flow
    }
  }

  // Get current value
  get = () => this.memory[this.cursor];

  // Set current value
  set = (value) =>
    isPositiveInteger(value) && (this.memory[this.cursor] = value);

  // Set cursor position
  goto = (position) => {
    if (isPositiveInteger(position)) {
      this.cursor = position;
      this.correct();
    }
  };

  // Correct position
  correct = () => {
    if (this.cursor > this.memory.length) {
      this.cursor = this.memory.length;
    } else if (this.cursor < 0) {
      this.cursor = 0;
    }
  };

  // Read input
  input = () => {
    this.temp[0] = 0;
    this.stdin.resume();
    readSync(this.stdin.fd, this.temp, 0, 1);
    closeSync(this.stdin.fd);
    this.stdin.pause();
    return this.temp[0];
  };

  // Write output
  output = (value) => {
    if (value instanceof Uint8Array) {
      this.stdout.write(value);
      this.result += value.toString();
    } else if (Number.isInteger(value) && value > 0) {
      const str = String.fromCharCode(value);
      this.stdout.write(str);
      this.result += str;
    } else if (typeof value == "string") {
      const str = encoder.encode(value);
      this.stdout.write(str);
      this.result += str;
    }
  };

  // interprets the brainfuck code
  execute = (code) => {
    if (typeof code != "string") return;
    const chars = [...code[Symbol.iterator]()].filter((c) =>
      "+-><.,[]".includes(c)
    );
    let index = 0;
    do {
      index = this.handler(chars, index);
      if (typeof index != "number") break; // for error case and invalid index
    } while (index);
    return this.result;
  };

  // Handler code
  handler = (chars, index) => {
    if (!Array.isArray(chars) || !Number.isInteger(index) || index < 0)
      return false;
    const currentChar = chars[index];
    if (!currentChar || typeof currentChar != "string") return false;

    if (currentChar == ".") this.output(this.get()); // Write output
    else if (currentChar == ",") this.set(this.input()); // Read input
    else if (currentChar == "+")
      this.set(this.get() + 1); // Increment current value
    else if (currentChar == "-")
      this.set(this.get() - 1); // Decrement current value
    else if (currentChar == ">")
      this.goto(this.cursor + 1); // Increment cursor position
    else if (currentChar == "<")
      this.goto(this.cursor - 1); // Decrement cursor position
    else if (currentChar == "[") {
      // If current value is 0 goto next ]
      if (this.get() == 0)
        while (chars[index] != "]") {
          if (index > chars.length) break;
          index++;
        }
    } else if (currentChar == "]") {
      // If current value is not 0 goto previous [
      if (this.get() != 0)
        while (chars[index] != "[") {
          if (index < 0) break;
          index--;
        }
    }

    return ++index;
  };
};
