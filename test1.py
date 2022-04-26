# Task Description
# A vending machine has the following denominations: 1c, 5c, 10c, 25c, 50c, and $1. Your task is to write a program that will be used in a vending machine to return change. Assume that the vending machine will always want to return the least number of coins or notes. Devise a function getChange(M, P) where M is how much money was inserted into the machine and P the price of the item selected, that returns an array of integers representing the number of each denomination to return.

# Example:
# getChange(5, 0.99) // should return [1,0,0,0,0,4]

# getChange(3.14, 1.99) // should return [0,1,1,0,0,1]
# getChange(3, 0.01) // should return [4,0,2,1,1,2]
# getChange(4, 3.14) // should return [1,0,1,1,1,0]
# getChange(0.45, 0.34) // should return [1,0,1,0,0,0]


# 1 dollar = 100 cents
# 1c, 5c, 10c, 25c, 50c, and $1
# []


def getChange(totalMoney, price):
    res = [0] * 6
    print(totalMoney, price)
    changedMoney = str(totalMoney - price)
    print("inital change required", changedMoney)
    # get the number of ones
    ones = changedMoney.split(".")
    res[5] = int(ones[0])
    decimals = ones[1]
    txt3 = float(".{}".format(decimals))

    while txt3:
        if txt3 >= 0.5:
			res[4] = 1
			txt3 -= 0.5
		elif txt3 >= 0.25:
			res[3] = int(txt3 // 0.25)
			txt3 -= res[3] * 0.25
		elif txt3 >= 0.1:
			res[3] = int(txt3 // 0.1)
			txt3 -= res[2] * 0.1
		elif txt3 >= 0.01:
			res[3] = int(txt3)
		return res


print(getChange(5, 0.99))  #  [1,0,0,0,0,4]
