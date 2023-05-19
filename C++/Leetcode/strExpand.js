// Write a function called strExpand which accepts string of where letters are all grouped together (like aaee or bbccdd) and returns a new sting with each letter fowllowed by a count of a the number of time it appears. 
// For instance, given the input "aaee" you would return "a2e2"
function strExpand(str) {
    let expandedStr = '';
    let count = 1;

    for (let i = 0; i < str.length; i++) {
        if (str[i] === str[i + 1]) {
            count++;
        } else {
            expandedStr += str[i] + count;
            count = 1;
        }
    }

    return expandedStr;
}

const input = "aaee";
const expandedString = strExpand(input);
console.log(expandedString);  // Output: "a2e2"

const input2 = "bbccdd";
const expandedString2 = strExpand(input2);
console.log(expandedString2);  // Output: "b2c2d2"
