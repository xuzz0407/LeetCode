class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = "aeiou"
        cnt = 0

        for i in range(k):
            if s[i] in vowels:
                cnt += 1
        
        ans = cnt

        for r in range(k, len(s)):
            if s[r] in vowels: 
                cnt += 1
            
            l = r - k

            if s[l] in vowels:
                cnt -= 1
            
            ans = max(ans, cnt)
        
        return ans