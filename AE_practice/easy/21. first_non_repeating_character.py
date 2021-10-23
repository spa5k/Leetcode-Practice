def firstNonRepeatingCharacter(string):
    hash = {}

    for idx in range(len(string)):
        if string[idx] in hash:
            hash[string[idx]] += 1
        else:
            hash[string[idx]] = 1

    for idx in range(len(string)):
        if hash[string[idx]] == 1:
            return idx

    return -1
