-- string
-- [[
-- str3 can be line feed
-- ]]
print("-- string")
local str1 = 'lua'
local str2 = "lua"
local str3 = [[lua]]
print(str1, str2, str3)
print(str3)

-- string method
print("\n-- string method")
str1 = "lua"
str2 = "LUA"
str3 = "aaaa"
str4 = "this is a lua file"
print(string.upper(str1), str1)
print(string.lower(str2), str2)
print(string.gsub(str3, 'a', 'z', 3))
print(string.find(str4, "lua", 1))
print(string.reverse(str1), str1)
print(string.format("the value is %d.", 101))
print(string.char(97, 98, 99, 100))
print(string.byte("abcd", 3))
print(string.len(str1))
print(string.rep(str1, 3))
print(str1 .. str2)
for word in string.gmatch("aa bb cc", "%a+") do
  print(word)
end
print(string.match("abc abc1 abc2", "%a+%d+", 1))

s = "Deadline is 30/05/2022, firm"
date = "%d%d/%d%d/%d%d%d%d"
print(string.sub(s, string.find(s, date)))

-- string interception
print("\n-- string interception")
print(string.sub("i love lua", 3, -1))



