-- arithmetic operators
print("-- arithmetic operators")
a, b = 10, 3
print(a + b)
print(a - b)
print(a * b)
print(a / b)
print(a % b)
print(a ^ b)
print(-a)
print(a // b)

-- relational operators
print("\n-- relational operators")
a, b = 1, 2
print(a == b)
print(a ~= b)
print(a > b)
print(a < b)
print(a >= b)
print(a <= b)

-- logical operators
print("-- logical operators")
a, b = true, false
print(a and b)
print(a or b)
print(not a)
print(not b)

-- special operators
print("\n-- special operators")
print("hello".." lua")
print("hello" .. " luavim")
str = "lua"
print(#str)
tbl = {1, 2, 3, 4, 5}
print(#tbl)
