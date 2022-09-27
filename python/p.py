def calc(a,b):
    def f(x):
        nonlocal a,b
        return a*x+b
    return f

f = calc(3,5)
print('f = calc(3,5) -> f(4):', f(4))
