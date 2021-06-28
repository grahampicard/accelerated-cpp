import csv
import random

names = [
    "Albert",
    "Bobby",
    "Casey",
    "Dierdre",
    "Elyse",
    "Frank",
    "Graham",
    "Hubert",
    "Ines",
    "Jack",
]


for x in (10, 1000, 10000):
    with open (f'testnames-{x}.csv', 'w') as f:
        random.seed(x)
        for name in names:
            for i in range(int(x / 10)):
                cur_name = f"{name}_{i}"
                result = [str(random.randint(1, 99)) for x in range(100)]
                rowlist = [cur_name] + result
                row = ' '.join(rowlist) + '\n'
                f.write(row)
