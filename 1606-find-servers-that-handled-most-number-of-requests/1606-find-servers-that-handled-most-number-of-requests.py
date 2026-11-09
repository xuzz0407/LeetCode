class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        available = SortedList(range(k))
        busy = []  
        cnt = [0] * k
        for i, (t, duration) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= t:
                _, server = heapq.heappop(busy)
                available.add(server)
            if not available: continue
            pos = available.bisect_left(i % k)
            if pos == len(available): pos = 0
            server = available.pop(pos)
            cnt[server] += 1
            heapq.heappush(busy, (t + duration, server))
        mx = max(cnt)
        return [i for i, c in enumerate(cnt) if c == mx]