// Write a function called IsPangram which returns true if every single lower-cased letter of the English alphabet is used. 
// Every character in the string will be lowercase so you do not need to worry about upper and lower case.

function IsPangram(str) {
    const letters = new Set();

    for (const ch of str) {
        if (/[a-z]/.test(ch)) {
            letters.add(ch);
        }
    }

    return letters.size === 26;
}

const sentence = "the quick brown fox jumps over the lazy dog";
const isPangram = IsPangram(str);
console.log(isPangram);  // Output: true

const sentence2 = "hello world";
const isPangram2 = IsPangram(str);
console.log(isPangram2);  // Output: false
