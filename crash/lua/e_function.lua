-- function
print("-- function")
function max(num1, num2)
  local result
  if num1 >= num2 then
    result = num1
  else
    result = num2
  end
  return result
end
print(max(101, 1001))
print(result)

-- anonymous function
print("\n-- anonymous function")
myprint = function()
  print("this is an anonymous function")
end
myprint()

-- multiple return values
print("\n-- multiple return values")
function maximum(a)
  local ind = 1
  local val = a[ind]
  for index, value in pairs(a) do
    if value > val then
      ind = index
      val = value
    end
  end
  return ind, val
end
print(maximum({3, 5, 7, 4}))
print(string.find("www.baidu.com", "baidu"))

-- variable parameters
print("\n-- variable parameters")
function average(...)
  local result = 0
  local args = {...}
  for i, v in ipairs(args) do
    result = result + v
  end
  return result / #args
end
print(average(2, 4, 6))

function add(start, ...)
  for i, v in ipairs({...}) do
    start = start + v
  end
  return start
end
print(add(100, 2, 3))

-- select
print("\n-- select")
function test(...)
  a, c = select(3, ...)
  b = select(-2, ...)
  print(a, c)
  print(select(3, ...))
  print(b)
  print(select(-2, ...))
  print(select("#", ...))
end
test(1, 2, 3, 4, 5, 6, 7, 8)
