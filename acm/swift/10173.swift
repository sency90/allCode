var s = readLine()?
var dic : s.split(separator: " ")
print((dic.map{Int($0)!}.reduce(0) {$0 + $1})!)
