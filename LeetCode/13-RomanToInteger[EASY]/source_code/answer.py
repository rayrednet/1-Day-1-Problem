def romanToInt(s):
    romanInt = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    
    result = 0
    n = len(s)
    
    for i in range(1, n + 1):
        if i < n and romanInt[s[i - 1]] < romanInt[s[i]]:
            result -= romanInt[s[i - 1]]
        else:
            result += romanInt[s[i - 1]]
    
    return result

s = "III"
print(romanToInt(s))  
