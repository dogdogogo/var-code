-- nil
print("\n-- nil")
print(nil)
print(type(nil))


-- number
print("\n-- number")
print(type(2))
print(type(2.0))
print(type(2e2))
print(type(2e-2))

-- boolean
print("\n-- boolean")
print(type(true))
do
  if nil then
    print("nil is true")
  else
    print("nil is false")
  end

  if 0 then
    print("0 is true")
  else
    print("0 is false")
  end
end

-- string
print("\n-- string")
print(type('abc'))
print(type("abc"))
str = [[
fir line
sec line
]]
print(type(str))

-- table
print("\n-- table")
a = {1, 2, 3}
b = {}
b["key"] = "val"
print(type(a))
print(type(b))

-- function
print("\n-- function")
function add(a, b)
  return a + b
end

sub = function(a, b)
  return a - b
end

print(type(add))
print(type(sub))

-- thread
print("\n-- thread")

-- userdata
print("\n-- userdata")
