const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split('\n'); //줄바꿈 처리 추가


var cnt = 0;

for(let i = 0; i < 15; i++) {
    for(let j=0; j<5; j++) {
        if(input[j].length > i) {
            process.stdout.write(input[j][i]);
        }
    }
    cnt++;
}