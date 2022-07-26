-- one-dimensional array
print("-- one-dimensional array")
local array = {"lua", "go"}
for i = 1, 2 do
  print(array[i])
end
array = {}
for i = -2, 2 do
  array[i] = i
end
for i = -2, 2 do
  print(array[i])
end
print("--> ", array[1])

-- multi-dimensional array
print("\n-- multi-dimensional array")
array = {}
for i = 1, 3 do
  array[i] = {}
  for j = 1, 3 do
    array[i][j] = i + j
  end
end
for i = 1, 3 do
  for j = 1, 3 do
    print(array[i][j])
  end
end

-- multi-dimensional arrays with different index keys
print("\n-- multi-dimensional array with different index keys")
array = {}
local maxRows = 3
local maxColumns = 3
for row = 1, maxRows do
  for col = 1, maxColumns do
    array[row * maxColumns + col] = row + col
  end
end
for row = 1, maxRows do
  for col = 1, maxColumns do
    print(array[row * maxColumns + col])
  end
end

for i, j in pairs(array) do
  print(i, j)
end
