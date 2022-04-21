message = input()
k = int(input())


def solution(message, k):
    ans = ""
    words = message.split(" ")
    for word in words:
        if len(ans) + len(word) > k:
            break
        ans += word
        ans += " "

    if (len(ans) > 0):
      # remove last character because it's a space
      ans = ans[:-1]
    return ans


