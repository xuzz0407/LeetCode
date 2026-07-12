class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        def convert(time: str) -> int:
            hr, m, s = map(int, time.split(":"))
            return hr * 3600 + m * 60 + s
        
        return convert(endTime) - convert(startTime)