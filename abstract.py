from abc import ABC, abstractmethod


class BankAccount(ABC):
    @abstractmethod
    def currentBalance(self):
        pass

    def printOwner(self):
        pass


class Person:
    def __init__(self, name, dob, gender):
        self.name = name
        self.dob = dob
        self.gender = gender
        print("User initialized")

    def getDetails(self):
        print("Name", self.name)
        print("DOB", self.dob)
        print("Gender", self.gender)


class FixedDeposit(BankAccount):
    def __init__(self, owner: Person) -> None:
        self.type = 'FixedDeposit'
        self.interest = 5
        self.balance = 0
        self.owner = owner

    def currentBalance(self):
        return self.balance

    def addMoney(self, money):
        if money > 0:
            self.balance += money
        print("Your updated balance is", self.balance)

    def printOwner(self):
        return self.owner.getDetails()

    def withDrawMoney(self, money):
        if money <= self.balance:
            print("You have withdrawn money", money)
            self.balance -= money
            print("Your remaining balance is", self.balance)
        else:
            print("you dont have sufficient balance")

    def calculateInterestAfterOneYear(self):
        interestInOneYear = (self.interest/100)*self.balance
        print(interestInOneYear)
        print("Your balance after one year will be",
              self.balance+interestInOneYear)


class Saving(BankAccount):
    def __init__(self, owner: Person) -> None:
        self.type = 'Saving'
        self.interest = 6
        self.balance = 0
        self.owner = owner

    def currentBalance(self):
        print("Current balance", self.balance)

        return self.balance

    def addMoney(self, money):
        if money > 0:
            self.balance += money
        print("Your updated balance is", self.balance)

    def printOwner(self):
        return self.owner.getDetails()

    def withDrawMoney(self, money):
        if money <= self.balance:
            print("You have withdrawn money", money)
            self.balance -= money
            print("Your remaining balance is", self.balance)
        else:
            print("you dont have sufficient balance")

    def calculateInterestAfterOneYear(self):
        interestInOneYear = (self.interest/100)*self.balance
        print(interestInOneYear)
        print("Your balance after one year will be",
              self.balance+interestInOneYear)


class Current(BankAccount):
    def __init__(self, owner: Person) -> None:
        self.type = 'Current'
        self.interest = 10
        self.balance = 0
        self.owner = owner

    def currentBalance(self):
        print(self.balance)
        return self.balance

    def addMoney(self, money):
        if money > 0:
            self.balance += money
        print("Your updated balance is", self.balance)

    def printOwner(self):
        return self.owner.getDetails()

    def withDrawMoney(self, money):
        if money <= self.balance:
            print("You have withdrawn money", money)
            self.balance -= money
            print("Your remaining balance is", self.balance)
        else:
            print("you dont have sufficient balance")

    def calculateInterestAfterOneYear(self):
        interestInOneYear = (self.interest/100)*self.balance
        print(interestInOneYear)
        print("Your balance after one year will be",
              self.balance+interestInOneYear)
        return self.balance+interestInOneYear


print("Input your name")
name = str(input())
print("Hey ", name, "enter your DOB")
dob = str(input())
print("Hey ", name, "enter your Gender")
gender = str(input())

user = Person(name, dob, gender)
print('---------------------------------------------------------------')

print("Enter the type of account you want to open")
print("1. Saving, 2. Fixed Deposit 3. Current")
print('---------------------------------------------------------------')

account_type = int(input())

account = Current(user)

if account_type == 1:
    print("You have selected Savings")
    account = Saving(user)
elif account_type == 2:
    account = FixedDeposit(user)
    print("You have selected Fixed Deposit")
elif account_type == 3:
    print("You have selected Current")
else:
    print("Wrong input, please only enter 1,2 or 3")

print('---------------------------------------------------------------')

print("Details of the account=>")
print("Current balance:", account.balance)
print("Owner:", account.printOwner())
print("Interest Rate:", account.interest)
print("Account type:", account.type)

print('---------------------------------------------------------------')

status = True

while status:
    print('---------------------------------------------------------------')
    print("Enter numbers for further operations.")
    print("Press 1. to add money")
    print("Press 2. to withdraw money")
    print("Press 3. to check balance")
    print("Press 4. to calculate what balance will be after one year of interest")

    print("Press 0 to exit")

    answer = int(input())
    if answer == 1:
        print("Enter the money you want to add.")
        money = float(input())
        account.addMoney(money)
    elif answer == 2:
        print("Enter the money you want to withdraw.")
        money = float(input())
        account.withDrawMoney(money)
    elif answer == 3:
        account.currentBalance()
    elif answer == 4:
        account.calculateInterestAfterOneYear()
    elif answer == 0:
        status = False
        print("Exiting....")
    else:
        print("Wrong input, please try again.")
    print('---------------------------------------------------------------')


# utpal = Person("Utpal", '01/09/1998', 'Male')
# utpal_saving = Saving(utpal)
# print(utpal_saving.interest)
# utpal_saving.addMoney(1000)
# utpal_saving.currentBalance()

# utpal_saving.addMoney(1000)

# utpal_saving.currentBalance()
# utpal_saving.printOwner()
# utpal_saving.calculateInterestAfterOneYear()
