// Write a JS function called dedupe which accepts an array of intergers and returns a new array with all duplicates removed. 
// For example, if an array looked like this [5,5,5,2,2] and was passed into dedupe, it should return this array [5,2].
function dedupe(numbers) {
    const uniqueNumbers = new Set();
    const result = [];

    for (const number of numbers) {
        if (!uniqueNumbers.has(number)) {
            uniqueNumbers.add(number);
            result.push(number);
        }
    }

    return result;
}

const numbers = [5, 5, 5, 2, 2];
const result = DED(numbers);
console.log(result);  // Output: [5, 2]
