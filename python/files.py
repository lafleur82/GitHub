def file_read(fname):
    txt = open(fname)
    print(txt.read())


def file_write(fname, filemode, text):
    with open(fname, filemode) as f:
        f.write(text)


def file_read_from_head(fname, numlines):
    from itertools import islice
    with open(fname) as f:
        for line in islice(f, numlines):
            print(line)


file_write("test_file.txt", "a", "File writing is awesome.")
file_read("test_file.txt")
