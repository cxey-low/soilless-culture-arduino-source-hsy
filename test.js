//1-11  2%
//12-22 6%
//23    12%

let a = [];
for (let i = 0; i < 11; i += 1) {
  a[i] = i + 1;
  a[i + 11] = i + 1;
}
b = a.length;
for (let i = b; i < b + 11; i += 1) {
  for (let j = 0; j < 6; j += 1) {
    a[i + j * 11] = i - 10;
  }
}
b = a.length;
for (let i = b; i < 100; i += 1) {
  a[i] = 23;
}

console.log(`a : ${a}`);
console.log(`a.length : ${a.length}`);
