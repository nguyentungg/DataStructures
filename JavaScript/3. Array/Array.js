//>> Base methods:
// pop(), push(), of(), shift(), unshift(), at()

//>> The following do an in check before accessing the index and do not conflate empty slots with undefined:
// concat(), copyWithin(), every(), indexOf(), lastIndexOf(), map(), 
// filter(), flat(), flatMap(), forEach(),
// reduce(), reduceRight(), reverse(), 
// slice(), some(), sort(), splice()

//>> These methods treat empty slots as if they are undefined:
// fill(), find(), findIndex(), findLast(), findLastIndex(), 
// includes(), join(), keys(), toLocaleString(), values(), entries(),
// group() Experimental, groupToMap() Experimental, 

//>> Others: [@@iterator]()

// =========================================================================== BASE METHODS ==========================================================================
//>> The pop() method removes the last element from an array and returns that element. This method changes the length of the array.
const plants = ['broccoli', 'cauliflower', 'cabbage', 'kale', 'tomato'];
console.log(plants.pop());
// expected output: "tomato"
console.log(plants);
// expected output: Array ["broccoli", "cauliflower", "cabbage", "kale"]
plants.pop();
console.log(plants);
// expected output: Array ["broccoli", "cauliflower", "cabbage"]


//>> The push() method adds one or more elements to the end of an array and returns the new length of the array.
const animalsB = ['pigs', 'goats', 'sheep'];
const count = animalsB.push('cows');
console.log(count);
// expected output: 4
console.log(animalsB);
// expected output: Array ["pigs", "goats", "sheep", "cows"]
animalsB.push('chickens', 'cats', 'dogs');
console.log(animalsB);
// expected output: Array ["pigs", "goats", "sheep", "cows", "chickens", "cats", "dogs"]


//>> The Array.of() method creates a new Array instance from a variable number of arguments, regardless of number or type of the arguments. 
Array.of(1); // [1]
Array.of(1, 2, 3); // [1, 2, 3]
Array.of(undefined); // [undefined]

// Calling of() on non-array constructors
NotArray(len) {
    console.log("NotArray called with length", len);
}
console.log(Array.of.call(NotArray, 1, 2, 3));
// NotArray called with length 3
// NotArray { '0': 1, '1': 2, '2': 3, length: 3 }
console.log(Array.of.call(Object)); // [Number: 0] { length: 0 }
console.log(Array.of.call({}, 1)); // [ 1 ]


//>> The shift() method removes the first element from an array and returns that removed element. This method changes the length of the array. 
const arrayT = [1, 2, 3];
const firstElement = arrayT.shift();
console.log(arrayT);
// expected output: Array [2, 3]
console.log(firstElement);
// expected output: 1


//>> The unshift() method adds one or more elements to the beginning of an array and returns the new length of the array. 
const arrayU = [1, 2, 3];
console.log(arrayU.unshift(4, 5));
// expected output: 5
console.log(arrayU);
// expected output: Array [4, 5, 1, 2, 3]


//>> The at() method takes an integer value and returns the item at that index, allowing for positive and negative integers. 
// Negative integers count back from the last item in the array.
const arrayV = [5, 12, 8, 130, 44];
let index = 2;
console.log(`Using an index of ${index} the item returned is ${arrayV.at(index)}`);
// expected output: "Using an index of 2 the item returned is 8"
index = -2;
console.log(`Using an index of ${index} item returned is ${arrayV.at(index)}`);
// expected output: "Using an index of -2 item returned is 130"


// =================================================================== METHODS CHECK BEFORE ACCESSING ================================================================
//>> The concat() method is used to merge two or more arrays.
const array1 = ['a', 'b', 'c'];
const array2 = ['d', 'e', 'f'];
const array3 = array1.concat(array2);
console.log(array3);
// expected output: Array ["a", "b", "c", "d", "e", "f"]


//>> The copyWithin() method shallow copies part of an array to another location in the same array and returns it without modifying its length.
const array = ['a', 'b', 'c', 'd', 'e'];
// copy to index 0 the element at index 3
console.log(array.copyWithin(0, 3, 4));
// expected output: Array ["d", "b", "c", "d", "e"]
// copy to index 1 all elements from index 3 to the end
console.log(array.copyWithin(1, 3));
// expected output: Array ["d", "d", "e", "d", "e"]


//>> The every() method tests whether all elements in the array pass the test implemented by the provided function. It returns a Boolean value. 
const isBelowThreshold = (currentValue) => currentValue < 40;
const arrayA = [1, 30, 39, 29, 10, 13];
console.log(arrayA.every(isBelowThreshold));
// expected output: true


//>> The indexOf() method returns the first index at which a given element can be found in the array, or -1 if it is not present. 
const beasts = ['ant', 'bison', 'camel', 'duck', 'bison'];
console.log(beasts.indexOf('bison'));
// expected output: 1
// start from index 2
console.log(beasts.indexOf('bison', 2));
// expected output: 4
console.log(beasts.indexOf('giraffe'));
// expected output: -1


//>> The lastIndexOf() method returns the last index at which a given element can be found in the array, or -1 if it is not present. 
// The array is searched backwards, starting at fromIndex.
const animals = ['Dodo', 'Tiger', 'Penguin', 'Dodo'];
console.log(animals.lastIndexOf('Dodo'));
// expected output: 3
console.log(animals.lastIndexOf('Tiger'));
// expected output: 1


//>> The map() method creates a new array populated with the results of calling a provided function on every element in the calling array. 
const arrayB = [1, 4, 9, 16];
// pass a function to map
const map1 = arrayB.map(x => x * 2);
console.log(map1);
// expected output: Array [2, 8, 18, 32]


//>> The filter() method creates a shallow copy of a portion of a given array, filtered down to just the elements from the given array 
// that pass the test implemented by the provided function.
const words = ['spray', 'limit', 'elite', 'exuberant', 'destruction', 'present'];
const result = words.filter(word => word.length > 6);
console.log(result);
// expected output: Array ["exuberant", "destruction", "present"]


//>> The flat() method creates a new array with all sub-array elements concatenated into it recursively up to the specified depth. 
const arr1 = [0, 1, 2, [3, 4]];
console.log(arr1.flat());
// expected output: [0, 1, 2, 3, 4]
const arr2 = [0, 1, 2, [[[3, 4]]]];
console.log(arr2.flat(2));
// expected output: [0, 1, 2, [3, 4]]


//>> The flatMap() method returns a new array formed by applying a given callback function to each element of the array, and then flattening the result by one level.
const arrayC = [1, 2, [3], [4, 5], 6, []];
const flattened = arrayC.flatMap(num => num);
console.log(flattened);
// expected output: Array [1, 2, 3, 4, 5, 6]


//>> The forEach() method executes a provided function once for each array element.
const arrayD = ['a', 'b', 'c'];
arrayD.forEach(element => console.log(element));
// expected output: "a"
// expected output: "b"
// expected output: "c"


//>> The reduce() method executes a user-supplied "reducer" callback function on each element of the array, in order,
// passing in the return value from the calculation on the preceding element. 
// The final result of running the reducer across all elements of the array is a single value. 
const arrayE = [1, 2, 3, 4];
// 0 + 1 + 2 + 3 + 4
const initialValue = 0;
const sumWithInitial = arrayE.reduce(
    (accumulator, currentValue) => accumulator + currentValue,
    initialValue
);
console.log(sumWithInitial);
// expected output: 10


//>> The reduceRight() method applies a function against an accumulator and each value of the array (from right-to-left) to reduce it to a single value.
const arrayF = [[0, 1], [2, 3], [4, 5]];
const resultF = arrayF.reduceRight((accumulator, currentValue) => accumulator.concat(currentValue));
console.log(resultF);
// expected output: Array [4, 5, 2, 3, 0, 1]


//>> The reverse() method reverses an array in place and returns the reference to the same array,
// the first array element now becoming the last, and the last array element becoming the first. 
// In other words, elements order in the array will be turned towards the direction opposite to that previously stated.
const arrayG = ['one', 'two', 'three'];
const reversed = arrayG.reverse();
console.log('reversed:', reversed);
// expected output: "reversed:" Array ["three", "two", "one"]
console.log('arrayG:', arrayG); // Careful: reverse is destructive -- it changes the original array.
// expected output: "arrayG:" Array ["three", "two", "one"]


//>> The slice() method returns a shallow copy of a portion of an array into a new array object selected from start to end (end not included)
// where start and end represent the index of items in that array. The original array will not be modified. 
const animalsA = ['ant', 'bison', 'camel', 'duck', 'elephant'];
console.log(animalsA.slice(2));
// expected output: Array ["camel", "duck", "elephant"]
console.log(animalsA.slice(2, 4));
// expected output: Array ["camel", "duck"]
console.log(animalsA.slice(1, 5));
// expected output: Array ["bison", "camel", "duck", "elephant"]
console.log(animalsA.slice(-2));
// expected output: Array ["duck", "elephant"]
console.log(animalsA.slice(2, -1));
// expected output: Array ["camel", "duck"]
console.log(animalsA.slice());
// expected output: Array ["ant", "bison", "camel", "duck", "elephant"]


//>> The some() method tests whether at least one element in the array passes the test implemented by the provided function. 
// It returns true if, in the array, it finds an element for which the provided function returns true; otherwise it returns false. 
// It doesn't modify the array.
const arrayH = [1, 2, 3, 4, 5];
// checks whether an element is even
const even = (element) => element % 2 === 0;
console.log(arrayH.some(even));
// expected output: true


//>> The sort() method sorts the elements of an array in place and returns the reference to the same array, now sorted. 
// The default sort order is ascending, built upon converting the elements into strings, then comparing their sequences of UTF-16 code units values.
const months = ['March', 'Jan', 'Feb', 'Dec'];
months.sort();
console.log(months);
// expected output: Array ["Dec", "Feb", "Jan", "March"]
const arrayI = [1, 30, 4, 21, 100000];
arrayI.sort();
console.log(arrayI);
// expected output: Array [1, 100000, 21, 30, 4]


//>> The splice() method changes the contents of an array by removing or replacing existing elements and/or adding new elements in place. 
// To access part of an array without modifying it, see slice(). 
const monthsA = ['Jan', 'March', 'April', 'June'];
monthsA.splice(1, 0, 'Feb');
// inserts at index 1
console.log(monthsA);
// expected output: Array ["Jan", "Feb", "March", "April", "June"]
monthsA.splice(4, 1, 'May');
// replaces 1 element at index 4
console.log(monthsA);
// expected output: Array ["Jan", "Feb", "March", "April", "May"]


// =================================================================== METHODS TREAT EMPTY SLOTS =====================================================================

//>> The fill() method changes all elements in an array to a static value, from a start index (default 0) to an end index (default array.length). 
// It returns the modified array. 
const arrayJ = [1, 2, 3, 4];
console.log(arrayJ.fill(0, 2, 4)); // fill with 0 from position 2 until position 4
// expected output: [1, 2, 0, 0]
console.log(arrayJ.fill(5, 1)); // fill with 5 from position 1
// expected output: [1, 5, 5, 5]
console.log(arrayJ.fill(6));
// expected output: [6, 6, 6, 6]


//>> The find() method returns the first element in the provided array that satisfies the provided testing function. 
// If no values satisfy the testing function, undefined is returned.
const arrayK = [5, 12, 8, 130, 44];
const found = arrayK.find(element => element > 10);
console.log(found);
// expected output: 12


//>> The findIndex() method returns the index of the first element in an array that satisfies the provided testing function. 
// If no elements satisfy the testing function, -1 is returned. 
const arrayL = [5, 12, 8, 130, 44];
const isLargeNumber = (element) => element > 13;
console.log(arrayL.findIndex(isLargeNumber));
// expected output: 3


//>> The findLast() method iterates the array in reverse order and returns the value of the first element that satisfies the provided testing function. 
// If no elements satisfy the testing function, undefined is returned.
const arrayM = [5, 12, 50, 130, 44];
const foundA = arrayM.findLast((element) => element > 45);
console.log(foundA);
// expected output: 130


//>> The findLastIndex() method iterates the array in reverse order and returns the index of the first element that satisfies the provided testing function. 
// If no elements satisfy the testing function, -1 is returned.
const arrayN = [5, 12, 50, 130, 44];
const isLargeNumberA = (element) => element > 45;
console.log(arrayN.findLastIndex(isLargeNumberA));
// expected output: 3  (of element with value: 130)


//>> The includes() method determines whether an array includes a certain value among its entries, returning true or false as appropriate. 
const arrayO = [1, 2, 3];
console.log(arrayO.includes(2));
// expected output: true
const pets = ['cat', 'dog', 'bat'];
console.log(pets.includes('cat'));
// expected output: true
console.log(pets.includes('at'));
// expected output: false


//>> The join() method creates and returns a new string by concatenating all of the elements in an array (or an array-like object), 
// separated by commas or a specified separator string. If the array has only one item, then that item will be returned without using the separator. 
const elements = ['Fire', 'Air', 'Water'];
console.log(elements.join());
// expected output: "Fire,Air,Water"
console.log(elements.join(''));
// expected output: "FireAirWater"
console.log(elements.join('-'));
// expected output: "Fire-Air-Water"


//>> The keys() method returns a new Array Iterator object that contains the keys for each index in the array.
const arrayP = ['a', 'b', 'c'];
const iterator = arrayP.keys();
for (const key of iterator) {
    console.log(key);
}
// expected output: 0
// expected output: 1
// expected output: 2


//>> The toLocaleString() method returns a string representing the elements of the array. 
// The elements are converted to Strings using their toLocaleString methods and these Strings are separated by a locale-specific String (such as a comma ",").
const arrayQ = [1, 'a', new Date('21 Dec 1997 14:12:00 UTC')];
const localeString = arrayQ.toLocaleString('en', { timeZone: 'UTC' });
console.log(localeString);
// expected output: "1,a,12/21/1997, 2:12:00 PM",
// This assumes "en" locale and UTC timezone - your results may vary


//>> The values() method returns a new array iterator object that iterates the value of each index in the array.
const arrayR = ['a', 'b', 'c'];
const iteratorA = arrayR.values();
for (const value of iteratorA) {
    console.log(value);
}
// expected output: "a"
// expected output: "b"
// expected output: "c"


//>> The entries() method returns a new Array Iterator object that contains the key/value pairs for each index in the array. 
const arrayS = ['a', 'b', 'c'];
const iterator1 = arrayS.entries();
console.log(iterator1.next().value);
// expected output: Array [0, "a"]
console.log(iterator1.next().value);
// expected output: Array [1, "b"]

//>> The group() method groups the elements of the calling array according to the string values returned by a provided testing function. 
// The returned object has separate properties for each group, containing arrays with the elements in the group. 
const inventory = [
    { name: "asparagus", type: "vegetables", quantity: 5 },
    { name: "bananas", type: "fruit", quantity: 0 },
    { name: "goat", type: "meat", quantity: 23 },
    { name: "cherries", type: "fruit", quantity: 5 },
    { name: "fish", type: "meat", quantity: 22 },
];
const resultA = inventory.group(({ type }) => type);
/* ResultA is:
{
  vegetables: [
    { name: 'asparagus', type: 'vegetables', quantity: 5 },
  ],
  fruit: [
    { name: "bananas", type: "fruit", quantity: 0 },
    { name: "cherries", type: "fruit", quantity: 5 }
  ],
  meat: [
    { name: "goat", type: "meat", quantity: 23 },
    { name: "fish", type: "meat", quantity: 22 }
  ]
}
*/
// Using group() on sparse arrays
console.log([1, , 3].group((x) => x)); // { 1: [1], undefined: [undefined], 3: [3] }
// Calling group() on non-array objects
const arrayLike = {
    length: 3,
    0: 2,
    1: 3,
    2: 4,
};
console.log(Array.prototype.group.call(arrayLike, (x) => x % 2));
// { 0: [2, 4], 1: [3] }

// Group with condition
function myCallback({ quantity }) {
    return quantity > 5 ? "ok" : "restock";
}
const result2 = inventory.group(myCallback);
/* Result is:
{
  restock: [
    { name: "asparagus", type: "vegetables", quantity: 5 },
    { name: "bananas", type: "fruit", quantity: 0 },
    { name: "cherries", type: "fruit", quantity: 5 }
  ],
  ok: [
    { name: "goat", type: "meat", quantity: 23 },
    { name: "fish", type: "meat", quantity: 22 }
  ]
}
*/


//>> The groupToMap() method groups the elements of the calling array using the values returned by a provided testing function. 
// The final returned Map uses the unique values from the test function as keys, which can be used to get the array of elements in each group.
const inventoryA = [
    { name: "asparagus", type: "vegetables", quantity: 9 },
    { name: "bananas", type: "fruit", quantity: 5 },
    { name: "goat", type: "meat", quantity: 23 },
    { name: "cherries", type: "fruit", quantity: 12 },
    { name: "fish", type: "meat", quantity: 22 },
];
const restock = { restock: true };
const sufficient = { restock: false };
const resultB = inventoryA.groupToMap(({ quantity }) =>
    quantity < 6 ? restock : sufficient,
);
console.log(resultB.get(restock));
// [{ name: "bananas", type: "fruit", quantity: 5 }]

// Using groupToMap() on sparse arrays
console.log([1, , 3].groupToMap((x) => x));
// Map { 1 => [1], undefined => [undefined], 3 => [3] }

// Calling groupToMap() on non-array objects
const arrayLikeA = {
    length: 3,
    0: 2,
    1: 3,
    2: 4,
};
console.log(Array.prototype.groupToMap.call(arrayLikeA, (x) => x % 2));
// Map { 0 => [2, 4], 1 => [3] }


// ======================================================================== OTHER METHODS ============================================================================
//>> The @@iterator method returns an iterator that yields the value of each index in the array.
const arr = ["a", "b", "c", "d", "e"];
const arrIter = arr[Symbol.iterator]();
console.log(arrIter.next().value); // a
console.log(arrIter.next().value); // b
console.log(arrIter.next().value); // c
console.log(arrIter.next().value); // d
console.log(arrIter.next().value); // e

// Handling strings and string arrays with the same function
function logIterable(it) {
    if (typeof it[Symbol.iterator] !== "function") {
        console.log(it, "is not iterable.");
        return;
    }
    for (const letter of it) {
        console.log(letter);
    }
}
// Array
logIterable(["a", "b", "c"]);
// expected output:
// a
// b
// c

// String
logIterable("abc");
// expected output: 
// a
// b
// c

// Number
logIterable(123);
// expected output: 
// 123 is not iterable.
