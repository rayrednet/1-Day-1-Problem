class Solution:
    def isPalindrome(self, x):
        # Handle base cases
        if x < 0:
            return False
        if x < 10:
            return True
        
        # Initialize variables
        original = x
        reversed_num = 0
        
        # Reverse the number
        while x > 0:
            digit = x % 10
            # we dont need to perfom handling overflow like in cpp
            # bcs python can handle it more gracefully
            reversed_num = (reversed_num * 10) + digit
            x //= 10
        
        return original == reversed_num

solution = Solution()
print(solution.isPalindrome(121))  # Output: True
print(solution.isPalindrome(-121))  # Output: False
print(solution.isPalindrome(1234567899))  # Output: False
