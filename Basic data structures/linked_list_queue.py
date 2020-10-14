import sys


class Element:
    def __init__(self, value=None, next_=None):
        self.value = value
        self.next_ = next_


class Elements:
    def __init__(self):
        self.head = None
        self.tail = None
        self.len = 0
        self.middle = 0

    def pop(self):
        pop_head = self.head
        self.head = pop_head.next_
        if self.head is None:
            self.tail = None
        self.len -= 1
        self.middle -= 1

    def append(self, new):
        if self.head is None:
            self.head = Element(new, None)
            self.tail = self.head
        elif self.head == self.tail:
            self.tail = Element(new, None)
            self.head.next_ = self.tail
        else:
            last = Element(new, None)
            self.tail.next_ = last
            self.tail = last
        self.len += 1

    def sum(self):
        list_tail = self.tail
        




def commands():
    linked_list = Elements()
    oper = {'+', '-', '*'}
    a = [i for i in input().split(' ')]
    for i in range(len(a)):
        if not(a[i] in oper):
            linked_list.append(a[i])
        elif a[i] == '+':
            linked_list.sum()


commands()
