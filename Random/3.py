import heapq

A = list(map(float, input().split()))
# Defining these functions because there is no max heap in python


def heappush(heap, item):
    return heapq.heappush(heap, -item)


def heappop(heap):
    return -heapq.heappop(heap)


def solution(A):
    aSum = sum(A)
    half = aSum / 2
    A = [-a for a in A]
    heapq.heapify(A)
    removed, ans = 0, 0

    while removed < half:

        x = heappop(A)
        x /= 2
        removed += x
        heappush(A, x)
        ans += 1

    print(ans)


solution(A)
