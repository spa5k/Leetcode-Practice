P = list(map(int, input().split()))
S = list(map(int, input().split()))


def solution():
    S.sort(reverse=True)
    # sum of P list
    pSum = sum(P)

    ans = 0
    currSum = 0
    for i in range(0, len(S)):
        ans += 1
        currSum += S[i]
        if currSum >= pSum:
            break

    return ans


print(solution())
