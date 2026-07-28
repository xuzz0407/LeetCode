class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        l = ''.join(sorted(s[:n//2]))
        return l +  (s[n//2] if n % 2 else '') + l[::-1]