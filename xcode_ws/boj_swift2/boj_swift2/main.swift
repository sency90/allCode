import Foundation

/*
public class Heap<T: Comparable> {
    var v: [T?]
    var idx: Int = 0
    
    init() {
        v = [T?]() //Array(repeating: T(), count: 100000)
        v.append(nil)
        idx = v.count
    }
    
    func push(_ val: T?) {
        if(v.count == idx) { v.append(val) }
        else { v[idx] = val }
        pushup(Int(idx/2), idx)
        idx+=1
    }
    
    func pushup(_ par: Int, _ child: Int) {
        if(par == 0) { return }
        if(v[par]! > v[child]!) {
            let tmp = v[par]
            v[par] = v[child]
            v[child] = tmp
            //swap(&(self.v[par]), &(self.v[child]))
            pushup(Int(par/2), par)
        }
    }
    
    func pop() {
        if(idx <= 1) { return }
        v[1] = v[idx-1]
        idx-=1
        
        popdown(1)
    }
    func popdown(_ at: Int) {
        let l = at*2, r = at*2+1
        var mni = at
        
        if(l<idx && v[l]!<v[mni]!) { mni = l }
        if(r<idx && v[r]!<v[mni]!) { mni = r }
        if(mni != at) {
            let tmp = v[mni]
            v[mni] = v[at]
            v[at] = tmp
            popdown(mni)
        }
    }
    
    var top: T? {
        if(idx <= 1) { return nil }
        return v[1]
    }
    var empty: Bool { idx <= 1 }
}

let n: Int = Int(readLine()!)!
var arr: [Int]? = readLine()?.components(separatedBy: " ").map{ Int($0)! }

var i = n-1
var ans : [Int] = Array(repeating: -1, count: arr!.count)
var mnh = Heap<Int>()
for _ in 0..<n {
    while(!mnh.empty) {
        if let mn = mnh.top {
            if(arr![i] < mn) {
                ans[i] = mn
                break
            }
            mnh.pop()
        }
    }
    mnh.push(arr![i])
    
    i-=1
}
print(ans)


 */


/*
let n : Int = Int(readLine()!)!
var arr : [Int] = (readLine()?.components(separatedBy: " ").map{ Int($0)! })!
arr.sort()

let m : Int = Int(readLine()!)!
let v : [Int] = (readLine()?.components(separatedBy: " ").map{ Int($0)! })!

for i in 0..<m {
    var lo = 0
    var hi = arr.count-1
    //print(String(format: "lo:%d, hi:%d", lo, hi))
    
    while(lo <= hi) {
        let mid = Int((lo + hi)/2)
        if(arr[mid] >= v[i]) { hi = mid-1 }
        else { lo = mid+1 }
    }
    
    let ans = hi+1
    if(ans >= arr.count) { print("0") }
    else if(arr[ans] == v[i]) { print("1") }
    else { print("0") }
}
    
 */


let v : [Int] = (readLine()?.components(separatedBy: " ").map{ Int($0)! })!
let n = v[0]
let m = v[1]

var lo=m, hi=100

while(lo <= hi) {
    let mid : Int = (Int((lo + hi)/2))
    if(mid % 2 == 0) {
        if(n % mid == 1) {
            // Int(mid/2)-1개 Int(n/mid) mid/2개
            let preLim = Int(mid/2)-1
            let postLim = Int(mid/2)
            for _ in 0..<= preLim { print(mid-preLim+1) }
        }
        else if(n % mid == mid-1) {}
    }
}


