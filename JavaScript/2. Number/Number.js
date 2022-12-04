//>> isFinite()
console.log(Number.isFinite(1 / 0));
// expected output: false
console.log(Number.isFinite(10 / 5));
// expected output: true
console.log(Number.isFinite(0 / 0));
// expected output: false


//>> isInteger()
function fits(x, y) {
   if (Number.isInteger(y / x)) {
     return 'Fits!';
   }
   return 'Does NOT fit!';
}
console.log(fits(5, 10));
// expected output: "Fits!"
console.log(fits(5, 11));
// expected output: "Does NOT fit!"
  

//>> isNaN()
function typeOfNaN(x) {
  if (Number.isNaN(x)) {
    return 'Number NaN';
  }
  if (isNaN(x)) {
    return 'NaN';
  }
}
console.log(typeOfNaN('100F'));
// expected output: "NaN"
console.log(typeOfNaN(NaN));
// expected output: "Number NaN"
  

//>> isSafeInteger()
function warn(x) {
  if (Number.isSafeInteger(x)) {
    return 'Precision safe.';
  }
  return 'Precision may be lost!';
}
console.log(warn(Math.pow(2, 53)));
// expected output: "Precision may be lost!"
console.log(warn(Math.pow(2, 53) - 1));
// expected output: "Precision safe."
  

//>> parseFloat()
function circumference(r) {
  if (Number.isNaN(Number.parseFloat(r))) {
    return 0;
  }
  return parseFloat(r) * 2.0 * Math.PI ;
}
console.log(circumference('4.567abcdefgh'));
// expected output: 28.695307297889173
console.log(circumference('abcdefgh'));
// expected output: 0
  

//>> parseInt()
function roughScale(x, base) {
  const parsed = Number.parseInt(x, base);
  if (Number.isNaN(parsed)) {
    return 0;
  }
  return parsed * 100;
}
console.log(roughScale(' 0xF', 16));
// expected output: 1500
console.log(roughScale('321', 2));
// expected output: 0
  

//>> toExponential()
function expo(x, f) {
  return Number.parseFloat(x).toExponential(f);
}
console.log(expo(123456, 2));
// expected output: "1.23e+5"
console.log(expo('123456'));
// expected output: "1.23456e+5"
console.log(expo('oink'));
// expected output: "NaN"
  

//>> toFixed()
function financial(x) {
  return Number.parseFloat(x).toFixed(2);
}
console.log(financial(123.456));
// expected output: "123.46"
console.log(financial(0.004));
// expected output: "0.00"
console.log(financial('1.23e+5'));
// expected output: "123000.00" 


//>> toLocaleString()
function eArabic(x){
  return x.toLocaleString('ar-EG');
}
console.log(eArabic(123456.789));
// expected output: "١٢٣٬٤٥٦٫٧٨٩"
console.log(eArabic('123456.789'));
// expected output: "123456.789"
console.log(eArabic(NaN));
// expected output: "ليس رقم"
  

//>> toPrecision()
function precise(x) {
  return x.toPrecision(4);
}
console.log(precise(123.456));
// expected output: "123.5"
console.log(precise(0.004));
// expected output: "0.004000"
console.log(precise(1.23e5));
// expected output: "1.230e+5"
  

//>> toString()
function hexColour(c) {
  if (c < 256) {
    return Math.abs(c).toString(16);
  }
  return 0;
}
console.log(hexColour(233));
// expected output: "e9"
console.log(hexColour('11'));
// expected output: "b"
  

//>> valueOf()
const numObj = new Number(42);
console.log(typeof numObj);
// expected output: "object"
const num = numObj.valueOf();
console.log(num);
// expected output: 42
console.log(typeof num);
// expected output: "number"
