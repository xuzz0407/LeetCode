class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x, y = max(x1, min(xCenter, x2)), max(y1, min(yCenter, y2))
        return (xCenter - x) ** 2 + (yCenter - y) ** 2 <= radius ** 2