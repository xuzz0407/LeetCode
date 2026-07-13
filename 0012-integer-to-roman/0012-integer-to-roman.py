R = (
    ("", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"), 
    ("", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"), 
    ("", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"),  
    ("", "M", "MM", "MMM"),  
)

class Solution:
    def intToRoman(self, num: int) -> str:
        return R[3][num // 1000] + R[2][num // 100 % 10] + R[1][num // 10 % 10] + R[0][num % 10]

