let n = Int(readLine()!)!

let ed = readLine()?.split{$0==" "}.map{Int($0)!}
let v = readLine()?.split{$0==" "}.map{Int($0)!}

var sum : [Int] = Array(repeating: 0, count: n+1)
for i in 1..<n {
    if let ed = ed {
        sum[i] = sum[i-1]+ed[i-1]
    }
}

struct Info {
    let x : Int
    let idx : Int
}

var _vpair : [Info] = []
for i in 0..<n {
    if let v = v {
        _vpair.append(Info(x: v[i], idx: i))
    }
}

var vpair = _vpair.sorted(by: {(lhs : Info, rhs : Info) -> Bool in return (lhs.x < rhs.x) ? true:false })

var last : Int = n-1
var ans : Int = 0
for i in 0..<n {
    if vpair[i].idx >= last { continue }
    ans += (sum[last] - sum[vpair[i].idx]) * vpair[i].x
    last = vpair[i].idx
}

print(ans)
