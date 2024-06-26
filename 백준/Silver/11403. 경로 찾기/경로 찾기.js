const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split('\n');

let n = +input.shift();
let arr = [];

for(const row of input) {
    arr.push(row.split(" ").map(Number));
}

for(let k = 0; k < n; k++) {
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < n; j++) {
            if(arr[i][k] && arr[k][j]) {
                arr[i][j] = 1;
            }
        }
    }
}

for(let i = 0; i<n; i++) {
    console.log(arr[i].join(" "));
}