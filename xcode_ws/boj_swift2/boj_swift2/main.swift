let n = Int(readLine()!)!
let v = readLine()?.split{$0==" "}.map{Int($0)!}

var ans = Array(repeating: -1, count: n)

public class Info {
    var val : Int
    var idx : Int
    init(_ val : Int, _ idx : Int) {
        self.val = val
        self.idx = idx
    }
    static func >(lhs: Info, rhs: Info) -> Bool {
        return lhs.val > rhs.val
    }
    static func <(lhs: Info, rhs: Info) -> Bool {
        return lhs.val < rhs.val
    }
}

/*
func swap<T>(_ lhs : inout T, _ rhs : inout T) {
    let tmp = lhs
    lhs = rhs
    rhs = tmp
}
 */

public class Heap {
    var sz : Int
    var v : [Info]
    init() {
        sz=1
        v = [Info]()
        v.append(Info(0,0))
    }
    
    func down(_ c : Int) {
        if(c>=sz) { return }
        let l = c*2
        let r = c*2+1
        var mni = c
        if l<sz && v[mni]>v[l] {mni=l}
        if r<sz && v[mni]>v[r] {mni=r}
        if mni != c {
            let tmp = v[c]
            v[c] = v[mni]
            v[mni] = tmp
            down(mni)
        }
    }
    
    func up(_ c : Int) {
        if(c<=1) { return }
        let p = Int(c/2)
        if v[p] > v[c] {
            let tmp = v[p]
            v[p] = v[c]
            v[c] = tmp
            up(p)
        }
    }
    
    func pop() {
        if sz != 1 {
            let tmp = v[1]
            v[1] = v[sz-1]
            v[sz-1] = tmp
        }
        sz-=1
        down(1)
    }
    
    func push(_ x : Info) {
        if sz < v.count { v[sz] = x }
        else { v.append(x) }
        up(sz)
        sz+=1
    }
    
    func top() -> Info? {
        if sz>=1 { return v[1] }
        else { return nil }
    }
    
    func empty() -> Bool {
        return sz<=1
    }
}

var mnh = Heap()

for i in 0..<n {
    while !mnh.empty() {
        let info : Info = mnh.top()!
        if info.val >= v![i] { break }
        else {
            ans[info.idx] = v![i]
            mnh.pop()
        }
    }
    
    mnh.push(Info(v![i],i))
}

print(ans)

