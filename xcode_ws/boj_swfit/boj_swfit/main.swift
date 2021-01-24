import Foundation
//print("Hello, World!")

/*
 let numbers = [0,1,2,3,4]
 
 var doubleNumbers = [Int]()
 var strings = [String]()
 
 //for-in
 for number in numbers {
 doubleNumbers.append(number * 2)
 strings.append("\(number)")
 }
 
 print(strings)
 
 doubleNumbers = numbers.map{ $0 * 2 }
 strings = numbers.map{ "\($0)" }
 */




/*
 let arrayOfInt = [2,3,4,5,4,7,2]
 func mul10(num: Int) -> Int {
 return num*10
 }
 //let chg = arrayOfInt.map( {(num: Int)->Int in return (num)*10 } )
 let chg = arrayOfInt.map{ $0 * 10 }
 print(arrayOfInt)
 print(chg)
 
 
 var s : String? = readLine()
 print(type(of: s))
 
 if let t = s {
 var ss = t.split(separator: " ")
 print(type(of: ss))
 
 if let x = Int(ss[0]), let y = Int(ss[1]) {
 print(x+y)
 }
 //print(Int(ss[0]) + Int(ss[1]))
 }
 */

//var xx = ss![0]
//print(type(of: xx))
//if s != nil {
//    let ss : [String]? = ((s?).split(separator: " "))
//}
//
//var x = (ss?).toInt()


/*
func sumOfSquare(closure: ((Int)->Int), numbers: Int...) -> Int {
    //print(type(of: numbers))
    var ret : Int = 0
    for x in numbers {
        ret += closure(x)
    }
    return ret
}
 */

//func f(x: Int) -> Int {
//    return x*x
//}

//var res = sumOfSquare(closure: f, numbers: 1,2,3,4,5)
//print(res)

/*
 //0. lambda function - It's called as high order function in Swift
 print(sumOfSquare(closure: {(x: Int)->Int in return x*x}, numbers: 1,2,3,4,5))
 print(sumOfSquare(closure: {(x: Int)->Int in x*x}, numbers: 1,2,3,4,5))
 print(sumOfSquare(closure: {x->Int in x*x}, numbers: 1,2,3,4,5))
 print(sumOfSquare(closure: {x in x*x}, numbers: 1,2,3,4,5))
 print(sumOfSquare(closure: {$0 * $0}, numbers: 1,2,3,4,5))
 
 
 //1. map
 //func map<U>(transform: (T)->U) ->[U]
 let arr = [0,1,2,3]
 //let doubleArr = arr.map({(x: Int)->Int in return x*x})
 let doubleArr = arr.map({$0*$0})
 print(doubleArr)
 
 
 //2. filter
 //func filter(includeElement: (T) -> Bool) -> [T]
 let oddArray = arr.filter({(x: Int)->Bool in return Bool((x%2) != 0)})
 print(oddArray)
 
 let evenArray = arr.filter({$0%2 == 0})
 print(evenArray)
 */


//10171
//let cat = """
//\\    /\\
// )  ( ')
//(  /  )
// \\(__)|
//"""
//print(cat)

//10172
//let dog = """
//|\\_/|
//|q p|   /}
//( 0 )\"\"\"\\
//|"^"`    |
//||_/=\\\\__|
//"""
//print(dog)


//1000
/*
 var s : String? = readLine()
 if let ss : [Substring] = s?.split(separator: " ") {
 if let x = Int(ss[0]), let y = Int(ss[1]) {
 print(x+y)
 print(x-y)
 print(x*y)
 print(x/y)
 print(x%y)
 }
 }
 */

/* 1330
 var s = readLine()
 if let ss = s?.split(separator: " ") {
 if let a = Int(ss[0]), let b = Int(ss[1]) {
 if(a<b) { print("<") }
 else if(a==b) { print("==") }
 else { print(">") }
 }
 }
 */

/* 2753
 var s = readLine()!
 if let x = Int(s) {
 if(x%4 == 0 && (x%100 != 0 || x%400 == 0)) { print(1) }
 else { print(0) }
 }
 */

//let x : Int = Int(readLine()!)!
//let y : Int = Int(readLine()!)!
//if(x>0 && y>0) { print(1) }
//else if(x<0 && y>0) { print(2) }
//else if(x<0 && y<0) { print(3) }
//else if(x>0 && y<0) { print(4) }


/* 2884
 let s = readLine()
 if let ss = s?.split(separator: " ") {
 var h = Int(ss[0])!
 var m = Int(ss[1])!
 
 if(m-45<0) { h-=1; m+=15; }
 else { m-=45; }
 
 if(h<0) { h=23; }
 print("\(h) \(m)")
 }
 */


/* 2739
 let x = Int(readLine()!)!
 for y in 1..<10
 {
 print("\(x) * \(y) = \(x * y)")
 }
 */

//let tc = Int(readLine()!)!
//for _ in 0..<tc
//{
//    print((readLine()!.split(separator: " ").map{Int($0)!}.reduce(0) { $0 + $1 })!)
//}


/* 8393
 let n = Int(readLine()!)!
 var ret : Int = 0;
 for i in 1...n {
 ret += i;
 }
 print(ret)
 */

/*
 let n = Int(readLine()!)!
 print(type(of: n))
 */


/*
class Stock {
    var code : String?
    var price : Double?
}

func findStockCode(company: String) -> Stock? {
    if(company == "Apple") {
        let aapl : Stock = Stock()
        aapl.code = "AAPL"
        aapl.price = 90.32
        return aapl
    }
    else if(company == "Google") {
        let goog = Stock()
        goog.code = "GOOG"
        goog.price = 556.36
        return goog
    }
    return nil;
}
 */

/*
 if let stock = findStockCode(company: "Apple") {
 if let sharePrice = stock.price{
 let totalCost = sharePrice * 100
 print("$\(totalCost)")
 }
 }
 */

/*
 1. optional: 값이 있을 수도 있고,올 없을 수도 있다는 뜻.
 2. optional type: type뒤에 물음표를 붙여서 사용
 3. optional binding:
 func f() -> Type? { ... }
 let s = func()
 위와 같이 코딩한 경우 s의 타입은 'Type?' 이다.
 그럼 s값에 접근하기 위해선 optinal Type을 풀어줘야 한다.
 if let m_s = s { ... }
 위와 같이 코딩해야 s의 Wrapping 상태를 풀어 접근 할 수 있다.
 이렇게 if let, if var 등을 쓰는 방식을 optional binding이라 한다.
 
 4. optional chaning:
 위에서 언급한 예시의 s에서 멤버변수등에 접근할 때,
 if let, if var 처럼 쓰려면 불편하다.
 그래서 nil이 있는지 바로 판단할 수 있는 기호가 있는데, 그게 바로 물음표 기호이다.
 s?.memberVar?.memberVar2
 위와 같은 형태로 접근가능하다.
 만약 wrapping 상태를 강제로 벗기고 싶다면 !를 써서 가능한데,
 ?는 문장의 맨 뒤에 올 수 없지만
 !는 문장의 맨 뒤에 올 수 있다.
 
 5. 타입 변환시 해당 Type의 optional Type으로 변형된다.
 */




//var stock : Stock = findStockCode(company: "Apple")!
//print(type(of: stock))
//
//if var totalCost = findStockCode(company: "Apple")?.price {
//    totalCost *= 100
//    print("$\(totalCost)")
//}



//print(readLine()!.split(separator: " ").map{ Int($0)! }.reduce(0){ $0 + $1 })

//Closures = lambda function
//전역변수는 이름을 갖고 있고 어떤 값도 capture하지 못하는 closure이다.
//nested 함수는 그들의 enclosing 함수로부터 값들을 capture할 수 있고 이름도 있는 closure?

//{(parameters) -> return type in
//    statements
//}

//print((readLine()?.split(separator: " ").map({ Int($0)! }).reduce(0){ $0 + $1 })!)

//let names = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]
//var reverseNames = names.sorted(by: {(s1: String, s2: String) -> Bool in return s1 > s2})
//for v in reverseNames
//{
//    print(v)
//}

//import Foundation
//setbuf(stdout, nil);
//_ = readLine()
//let v = readLine()!.split{$0==" "}.map{Int($0)!}
//var mn = 1000000
//var mx = -1000000
//for i in v {
//    if mn > i {
//        mn = i
//    }
//    if mx < i {
//        mx = i
//    }
//}
//print(mn, mx)

let v = readLine()?.split{$0==" "}.map{Int($0)!}
let a = v[0]!

