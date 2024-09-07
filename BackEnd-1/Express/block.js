//Blocking Code - Sync Code
// const fs = require('fs')

// const data = fs.readFileSync('./topic.txt', 'utf-8')
// console.log(data)

// let sum = 0;
// for (let i = 0; i <= 10; i++) {
//     sum += i
// }

// console.log("Sum : " , sum)


// //Non Blocking Code 
const fs = require('fs');

const data = fs.readFile('./topic.txt', 'utf-8', (err, data) => {
    console.log(data)
});

let sum = 0;
for (let i = 0; i <= 10; i++) {
    sum += i;
}

console.log("Sum: ", sum);
