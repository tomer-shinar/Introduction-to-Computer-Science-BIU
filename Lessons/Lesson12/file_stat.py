import sys
from collections import defaultdict


def word_count(line, counter):
    """
    count the words in line to counter
    :param line: string of one line from file
    :param counter: default dict of counts
    """
    for word in line.split():
        if word:
            counter[word] += 1


def file_word_count(file_name):
    """
    count the words in a file
    :param file_name: name of file
    :return: default dict of counts
    """
    f = open(file_name, "r")
    lines = f.readlines()
    f.close()
    counter = defaultdict(int)
    for line in lines:
        word_count(line, counter)
    return counter


def print_word_counts(files):
    """
    print the word counts for each file
    :param files: list of file names
    """
    for file in files:
        print(f'the file {file} has the following word count:\n{file_word_count(file)}')


def find_most_common(files):
    """
    print the most common word in each files
    :param files: list of file names
    """
    for file in files:
        counter = file_word_count(file)
        most_common = max(counter.keys(), key=lambda word: counter[word])
        print(f'The most common word in {file} is {most_common}')


def word_set(file):
    """
    create set of all words in file
    :param file: name of file
    :return: set of words
    """
    f = open(file, "r")
    words = set()
    for line in f:
        words |= set(line.split())
    f.close()
    return words


def shared_words(files):
    """
    print words that are in all the files
    :param files: list of file names
    """
    if not files:
        return
    shared = word_set(files[0])
    for file in files[1:]:
        shared &= word_set(file)
    print('All files have the words:')
    print("\n".join(shared))


def main():
    op = sys.argv[1]
    files = sys.argv[2:]
    func_select = {'1': print_word_counts, '2': find_most_common, '3': shared_words}

    if op not in func_select.keys():
        print("no such option")
        return
    func_select[op](files)


if __name__ == '__main__':
    main()