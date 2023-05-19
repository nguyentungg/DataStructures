// Write a function called calculateAverage which accepts an array of numbers. 
// The function should return the average or mean of all number in the array. If the array is empty return 0.

function calculateAverage(numbers) {
    if (numbers.length === 0) {
        return 0;
    }

    const total = numbers.reduce((sum, number) => sum + number, 0);
    const average = total / numbers.length;
    return average;
}

const numbers = [1, 2, 3, 4, 5];
const average = calculateAverage(numbers);
console.log(average);  // Output: 3

const emptyArray = [];
const averageEmpty = calculateAverage(emptyArray);
console.log(averageEmpty);  // Output: 0
