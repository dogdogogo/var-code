-- if
-- [[
-- lua considers false and nil to be false, and true and non-nil to be true
-- ]]
print("-- if")
if 0 then
  print("0 is true")
else
  print("0 is false")
end

if nil then
  print("nil is true")
else
  print("nil is false")
end

a, b = 100, 101
if a > 1 and b > 2 then
  print("yes")
end

-- if-elseif-else
print("\n-- if-elseif-else")
a = 100
if a < 10 then
  print("a < 10")
elseif a < 50 then
  print("a < 50")
elseif a < 100 then
  print("a < 100")
else
  print("a < 1000")
end
