class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans = vowel = 0
        for i, c in enumerate(s):
            if c in "aeiou": 
                vowel += 1
            
            left = i - k + 1
            if left < 0: continue

            ans = max(ans, vowel)

            if s[left] in "aeiou":
                vowel -= 1
        
        return ans