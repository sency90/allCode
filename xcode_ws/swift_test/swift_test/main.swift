
let nickname: String? = nil
let fullname: String = "John Appleseed"
let informalgreeting = "Hi \(nickname ?? fullname)"

var optionalString: String? = "Hello"
print(optionalString==nil)

var optionalName: String? = nil
var greeting = "Hello!"
if let name = optionalName {
    greeting = "Hello, \(name)"
}
print(greeting)
