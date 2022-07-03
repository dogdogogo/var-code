-- while
print("-- while")
ret, n = 0, 0
while n <= 3 do
  ret = ret + n
  n = n + 1
end
print(ret)

-- for
print("\n-- for")
ret = 1
for i = 1, 5, 2 do
  ret = ret * i
end
print(ret)

days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
for i,j in pairs(days) do print(i .. " --> " .. j) end

-- repeat...until
-- [[
-- Note that the loop is jumped when the condition is true
-- ]]
print("\n-- repeat-until")

ret, n = 1, 1
repeat
  ret = ret * n
  n = n + 1
until n > 5
print(ret)

-- break
print("\n--break")
ret, n = 0, 1
while true do
  ret = ret + n
  n = n + 1
  if n > 5 then break end
end
print(ret)

-- goto
-- [[
-- the goto tag is a separate statement
-- ]]
print("\n-- goto")
ret, n = 1, 1
::label:: do 
  print("goto label")
  n = n + 1 
end
if n <= 5 then
  ret = ret * n
  goto label
end
print(ret)
print("hello") print("lua")

-- continue -> goto implementation
print("\n-- continue -> goto implementation")
ret, times = 0, 0
for i = 1, 3 do
  for j = 1, 3 do
    if j <= i then
      ret = ret + j
    else
      goto continue
    end
    times = times + 1
  end
  ::continue::
end
print(ret , times)
