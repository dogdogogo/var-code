-- local
-- [[
-- all variables in lua are global, unless they are explicitly declared as local
-- variables with local
-- ]]
print("\n-- local")
a = 5
local b = 5
b = b + 1
print(a, b)

function joke()
  c = 5
  local d = 6
end
joke()
print(c, d)

do
  local a = 6
  b = 7
  print(a, b)
end
print(a, b)

-- assignment statement
print("\n-- assignment statement")
a = "hello" .. "lua"
print(a)
a, b = 1, 2
print(a, b)
a, b = b, a
print(a, b)
a, b, c = 1, 2
print(a, b, c)
a, b = 11, 12 ,13
print(a, b)
function retTwoVal()
  return 101, 102
end
a, b = retTwoVal()
print(a, b)

-- index
-- [[
-- a simplified way of writing when the index is a string type --> name.index
-- ]]
print("\n-- index")
site = {}
site["baidu"] = "www.baidu.com"
print(site["baidu"])
print(site.baidu)
