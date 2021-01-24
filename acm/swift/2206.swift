import Foundation

let dx = [0,0,1,-1]
let dy = [1,-1,0,0]

struct Info {
    let x : Int
    let y : Int
    let s : Int
}

let nm = readLine()!.split{$0==" "}.map{Int($0)!}
let n = nm[0]
let m = nm[1]

var chk = Array(repeating: Array(repeating: Array(repeating: false, count: 2), count: m), count: n)
//let chkp = [UnsafeMutableBufferPointer(start: &chk[0], count: n*m), UnsafeMutableBufferPointer(start: &chk[1], count: n*m)]

var v = Array(repeating: Array(repeating: 0, count: m), count: n)
//let vp = UnsafeMutableBufferPointer(start: &v, count: n*m)

for i in 0..<n {
    let line = readLine()!.map{Int($0.asciiValue! - 48)}
    for j in 0..<m {
        v[i][j] = line[j]
    }
}

var cnt = 0
var q : [Info] = []
chk[0][0][0] = true;
q.append(Info(x: 0, y: 0, s: 0))
while !q.isEmpty {
    let sz = q.count
    var nq : [Info] = []
    for i in 0..<sz {
        let info = q[i]
        if info.x == n-1 && info.y == m-1 {
            print(cnt+1)
            exit(0)
        }
        for j in 0..<4 {
            let nx = info.x + dx[j]
            let ny = info.y + dy[j]
            var ns = info.s
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) { continue }
            if(v[nx][ny]==1) {
                if ns > 0 { continue }
                else { ns = 1 }
            }
            
            if(chk[nx][ny][ns] == true) { continue }
            chk[nx][ny][ns] = true;
            nq.append(Info(x: nx, y: ny, s: ns))
        }
    }
    q = nq
    cnt += 1
}

print(-1)

