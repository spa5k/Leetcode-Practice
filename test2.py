from __future__ import annotations

import random

# class Student:
#     def __init__(self, name, rollnumber, program_name):
#         print("Student has been initialized")
#         self.name = name
#         self.roll_number = rollnumber
#         self.program_name = program_name

#     def standard(self):
#         print("No defined standard, generic student.")

#     def subject_list(self):
#         print("No Subjects yet!")

#     def in_masters(self):
#         if self.program_name=='masters':
#             print("In Masters - True")
#             return True
#         print("Not in Mastesr - False")
#         return False
#     def in_phd(self):
#         if self.program_name=='phd':
#             print("In PHD - True")
#             return True
#         print("Not in PHD - False")
#         return False
#     def in_fellowship(self):
#         master_status=self.in_masters()
#         phd_status=self.in_phd()

#         if(master_status or phd_status):
#             print("Roll number in fellowship - True")
#             return True
#         print("Not in fellowship - False")
#         return False


# class PGDStudent(Student):
#     def __init__(self, name, rollnumber, program_name):
#         super().__init__(name=name, rollnumber=rollnumber, program_name=program_name)
#         print("PG Student class")

#     def standard(self):
#         print("PG Student standard")

#     def subject_list(self):
#         print("Post graduate subjects")


# class MasterStudent(Student):
#     def __init__(self, name, rollnumber):
#         super().__init__(name=name, rollnumber=rollnumber, program_name='masters')
#         print("Master Student class")

#     def standard(self):
#         print("Master Student standard")

#     def subject_list(self):
#         print("Master graduate subjects")


# class UGStudent(Student):
#     def __init__(self, name, rollnumber, program_name,subjects):
#         super().__init__(name=name, rollnumber=rollnumber, program_name=program_name)
#         self.subjects=subjects
#         print("UG Student class")

#     def standard(self):
#         print("UG Student standard")

#     def subject_list(self):
#         print("Under graduate subjects",self.subjects)

# class PHDStudent(Student):
#     def __init__(self, name, rollnumber, program_name,subjects):
#         super().__init__(name=name, rollnumber=rollnumber, program_name=program_name)
#         self.subjects=subjects
#         print("PHD Student class")

#     def standard(self):
#         print("PHD Student standard")

#     def subject_list(self):
#         print("PHD subjects",self.subjects)


# ugstudent = UGStudent("Utpal", "1231233", "electrical",["english",'biology'])
# ugstudent.standard()
# ugstudent.in_masters()
# ugstudent.in_fellowship()
# ugstudent.subject_list()

# masterstudent=MasterStudent("Utpal2",'1')
# masterstudent.in_fellowship()
# masterstudent.in_masters()

# masterstudent_no_fellowship=MasterStudent("Utpal2",'11')
# masterstudent_no_fellowship.in_fellowship()
# masterstudent_no_fellowship.in_masters()


# Python Code for object
# oriented concepts using
# the abstract factory
# design pattern


class Course_At_GFG:

	""" GeeksforGeeks portal for courses """

	def __init__(self, courses_factory = None):
		"""course factory is out abstract factory"""

		self.course_factory = courses_factory

	def show_course(self):

		"""creates and shows courses using the abstract factory"""

		course = self.course_factory()

		print(f'We have a course named {course}')
		print(f'its price is {course.Fee()}')


class DSA:

	"""Class for Data Structure and Algorithms"""

	def Fee(self):
		return 11000

	def __str__(self):
		return "DSA"

class STL:

	"""Class for Standard Template Library"""

	def Fee(self):
		return 8000

	def __str__(self):
		return "STL"

class SDE:

	"""Class for Software Development Engineer"""

	def Fee(self):
		return 15000

	def __str__(self):
		return 'SDE'

def random_course():

	"""A random class for choosing the course"""

	return random.choice([SDE, STL, DSA])()


if __name__ == "__main__":

	course = Course_At_GFG(random_course)

	for i in range(5):
		course.show_course()



# class AbstractFactory(ABC):
#     @abstractmethod
#     def createPGDStudent(self) -> PGDStudent:
#         pass

#     @abstractmethod
#     def createMastersStudent(self) -> MasterStudent:
#         pass


# class ConcreteFactory1(AbstractFactory):
#     def createPGDStudent(self) -> PGDStudent:
#         return ConcreteProductA1()

#     def createMastersStudent(self) -> MasterStudent:
#         return ConcreteProductB1()


# class ConcreteFactory2(AbstractFactory):
#     def createPGDStudent(self) -> PGDStudent:
#         return ConcreteProductA2()

#     def createMastersStudent(self) -> MasterStudent:
#         return ConcreteProductB2()


# class PGDStudent(ABC):
#     @abstractmethod
#     def useful_function_a(self) -> str:
#         pass


# class ConcreteProductA1(PGDStudent):
#     def useful_function_a(self) -> str:
#         return "The result of the product A1."


# class ConcreteProductA2(PGDStudent):
#     def useful_function_a(self) -> str:
#         return "The result of the product A2."


# class MasterStudent(ABC):
#     @abstractmethod
#     def useful_function_b(self) -> None:
#         pass

#     @abstractmethod
#     def another_useful_function_b(self, collaborator: PGDStudent) -> None:
#         pass


# class ConcreteProductB1(MasterStudent):
#     def useful_function_b(self) -> str:
#         return "The result of the product B1."

#     def another_useful_function_b(self, collaborator: PGDStudent) -> str:
#         result = collaborator.useful_function_a()
#         return f"The result of the B1 collaborating with the ({result})"


# class ConcreteProductB2(MasterStudent):
#     def useful_function_b(self) -> str:
#         return "The result of the product B2."

#     def another_useful_function_b(self, collaborator: PGDStudent):
#         result = collaborator.useful_function_a()
#         return f"The result of the B2 collaborating with the ({result})"


# def client_code(factory: AbstractFactory) -> None:
#     product_a = factory.createPGDStudent()
#     product_b = factory.createMastersStudent()

#     print(f"{product_b.useful_function_b()}")
#     print(f"{product_b.another_useful_function_b(product_a)}", end="")


# if __name__ == "__main__":
#     print("Client: Testing client code with the first factory type:")
#     client_code(ConcreteFactory1())

#     print("\n")

#     print("Client: Testing the same client code with the second factory type:")
#     client_code(ConcreteFactory2())