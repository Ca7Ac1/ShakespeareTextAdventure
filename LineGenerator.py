from os.path import exists
import json
import random


def create_chains(path, override=False, store="./Chains.txt", start="./Start.txt"):
    chains = {}
    start_words = []

    if not override and exists(store) and exists(start):
        with open(store, 'r') as file:
            chains = json.load(file)

        with open(start, 'r') as file:
            start_words = json.load(file)

        return chains, start_words

    with open(path, 'r') as file:
        file = file.read().split()
        prev = True
        period = True

        for i in file:
            if period:
                prev = False
                period = False

            if i[-1] in '.!?':
                period = i[-1]
                i = i[:-1]

            if prev:
                chains[prev].append(i)
            else:
                start_words.append(i)

            if i not in chains:
                chains[i] = []

            prev = i

            if period:
                chains[i].append(period)

    with open(store, 'w') as file:
        json.dump(chains, file)

    with open(start, 'w') as file:
        json.dump(start_words, file)

    return chains, start_words


def print_sentences(num, chains, start):
    for i in range(num):
        curr = random.choice(start)
        sentence = curr + " "

        while curr not in '.?!':
            curr = random.choice(chains[curr])
            sentence += curr + " "

        print(sentence.strip())


if __name__ == '__main__':
    chains, start = create_chains("./hamlet.txt")
    print_sentences(100, chains, start)
