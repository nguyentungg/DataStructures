//>> EPSILON
const result = Math.abs(0.2 - 0.3 + 0.1);
console.log(result);
// expected output: 2.7755575615628914e-17
console.log(result < Number.EPSILON);
// expected output: true


//>> MAX_SAFE_INTEGER
const x = Number.MAX_SAFE_INTEGER + 1;
const y = Number.MAX_SAFE_INTEGER + 2;
console.log(Number.MAX_SAFE_INTEGER);
// expected output: 9007199254740991
console.log(x);
// expected output: 9007199254740992
console.log(x === y);
// expected output: true


//>> MAX_VALUE
function multiply(x, y) {
  if (x * y > Number.MAX_VALUE) {
    return ('Process as Infinity');
  }
  return (x * y);
}
console.log(multiply(1.7976931348623157e+308, 1));
// expected output: 1.7976931348623157e+308
console.log(multiply(1.7976931348623157e+308, 2));
// expected output: "Process as Infinity"
  

//>> MIN_SAFE_INTEGER
const x = Number.MIN_SAFE_INTEGER - 1;
const y = Number.MIN_SAFE_INTEGER - 2;
console.log(Number.MIN_SAFE_INTEGER);
// expected output: -9007199254740991
console.log(x);
// expected output: -9007199254740992
console.log(x === y);
// expected output: true


//>> MIN_VALUE
function divide(x, y) {
  if (x / y < Number.MIN_VALUE) {
    return 'Process as 0';
  }
  return (x / y);
}
console.log(divide(5e-324, 1));
// expected output: 5e-324
console.log(divide(5e-324, 2));
// expected output: Process as 0
  

//>> NaN
function clean(x) {
  // eslint-disable-next-line use-isnan
  if (x === Number.NaN) {
    // can never be true
    return null;
  }
  if (isNaN(x)) {
    return 0;
  }
}
console.log(clean(Number.NaN));
// expected output: 0
  

//>> NEGATIVE_INFINITY
function checkNumber(smallNumber) {
  if (smallNumber === Number.NEGATIVE_INFINITY) {
    return 'Process number as -Infinity';
  }
  return smallNumber;
}
console.log(checkNumber(-Number.MAX_VALUE));
// expected output: -1.7976931348623157e+308
console.log(checkNumber(-Number.MAX_VALUE * 2));
// expected output: "Process number as -Infinity"
  

//>> POSITIVE_INFINITY
function checkNumber(bigNumber) {
  if (bigNumber === Number.POSITIVE_INFINITY) {
    return 'Process number as Infinity';
  }
  return bigNumber;
}
console.log(checkNumber(Number.MAX_VALUE));
// expected output: 1.7976931348623157e+308
console.log(checkNumber(Number.MAX_VALUE * 2));
// expected output: Process number as Infinity
