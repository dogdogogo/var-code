-- generalized for iterator
print("-- generalized for iterator")
local array = {"Google", "Bing"}
for k, v in ipairs(array) do
  print(k, v)
end
print(pairs(array))

-- stateless iterator
print("\n-- stateless iteratoir")
function square(iteratorMaxCount, currentNumber)
  if currentNumber < iteratorMaxCount then
    currentNumber = currentNumber + 1
    return currentNumber, currentNumber * currentNumber
  end
end
for i, j in square, 3, 0 do
  print(i, j)
end

-- ipairs implementation
print("\n-- ipairs implementation")
function iter(a, i)
  i = i + 1
  local v = a[i]
  print("++", i)
  if v then
    return i, v
  end
end
function ipairs_imp(a)
  return iter, a, 0
end
for i, v in ipairs_imp(array) do
  print(i, v)
end

-- multi-state iterator
print("\n-- multi-state iterator")
function elementIterator(collection)
  local index = 0
  local count = #collection

  return function()
    index = index + 1
    print("++", index)
    if index <= count then
      return collection[index]
    end
  end
end
for element in elementIterator(array) do
  print(element)
end

