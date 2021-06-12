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
    "Krista",
    "Lenny",
    "Manny"
]


with open ('testnames.csv', 'w') as f:
    random.seed(1)
    for name in names:
        for i in range(100):
            cur_name = f"{name}_{i}"
            result = [str(random.randint(1, 99)) for x in range(100)]
            rowlist = [cur_name] + result
            row = ' '.join(rowlist) + '\n'
            f.write(row)
