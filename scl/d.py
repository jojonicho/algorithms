from sys import stdin, stdout
import time


class Tree:
    def __init__(self, parent):
        self.parent = parent


class FixedTree(Tree):
    def __init__(self, parent, r, stock):
        super().__init__(parent)
        self.stock = stock
        if self.parent:
            self.subtract_parent(r, stock)

    def get_stock(self):
        return self.stock

    def subtract(self, r, stock):
        self.stock -= r * stock

    def subtract_parent(self, r, stock):
        if self.parent:
            self.parent.subtract(r, stock)


class DynamicTree(Tree):
    def __init__(self, parent, r):
        super().__init__(parent)
        self.r = r
        self.stock = -1

    def get_stock(self):
        if self.stock == -1:
            self.stock = self.parent.get_stock() // self.r
        return self.stock

    def subtract(self, r, stock):
        self.parent.subtract(self.r * r, stock)

    def subtract_parent(self, r, stock):
        self.parent.subtract(self.r * r, stock)


def process_in(ln):
    z = [int(i.strip()) for i in ln.split(" ") if i.strip() != ""]
    return z


l = stdin.readlines()
n, m = process_in(l[0])

root = FixedTree(None, 1, m)

t = [root]

for line in l[1:n]:
    z = process_in(line)
    i = z[1] - 1
    parent = t[i]
    try:
        z[0]
    except:
        pass
    if z[0] == 1:
        t.append(DynamicTree(parent, z[2]))
    elif z[0] == 2:
        t.append(FixedTree(parent, z[2], z[3]))

[stdout.write(str(tr.get_stock()) + "\n") for tr in t]

