
import unittest

from abstract import Person


class TestStringMethods(unittest.TestCase):
    def __init__(self, methodName: str = ...) -> None:
        super().__init__(methodName)
        self.person1 = Person('Utpal', '0/09/1998', 'male')

    def test_name(self):
        self.assertEqual('Utpal', self.person1.name)


if __name__ == '__main__':
    unittest.main()
