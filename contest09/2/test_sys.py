from random import randint
from random import choice

# (0^k 1^m)^n   k, m, n > 0

def gen_rand_in_L():
    k = randint(1, 10)
    m = randint(1, 10)
    n = randint(1, 10)
    return ("0" * k + "1" * m) * n

def gen_rand():
    poll = ['0', '1', 'a', 'b']
    n = randint(1, 10)
    s = ''
    for i in range(n):
        s += choice(poll)
    return s


for i in range(10):
    print(gen_rand_in_L())


for i in range(10):
    print(gen_rand())

