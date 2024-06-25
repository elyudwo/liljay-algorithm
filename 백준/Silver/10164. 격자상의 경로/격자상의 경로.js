const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split(' ');

let n = parseInt(input[0]);
let m = parseInt(input[1]);
let o = parseInt(input[2]);

let arr = [];

// 배열 초기화
for(let i = 0; i <= 300; i++) {
    arr[i] = [0, 0];
}

arr[1][0] = 1;

for(let i = 1; i <= 225; i++) {
    let tmp1 = i + m;

    if (tmp1 <= 225) {
        arr[tmp1][0] += arr[i][0];
        arr[tmp1][1] += arr[i][1];
    }
    if (tmp1 == o) {
        arr[tmp1][1] += arr[i][0];
    }


    let tmp2 = i + 1;
    if(i % m == 0) {
        continue;
    }
    
    if (tmp2 <= 225) {
        arr[tmp2][0] += arr[i][0];
        arr[tmp2][1] += arr[i][1];
    }
    if (tmp2 == o) {
        arr[tmp2][1] += arr[i][0];
    }
}

if(o == 0) {
    console.log(arr[n*m][0]);
}
else {
    console.log(arr[n*m][1]);
}

