from os.path import exists


def parse_character(read_path, name, force=False):
    file_path = "./" + name + ".txt"
    read_path = "./" + read_path + ".txt"

    if not force and exists(file_path):
        return

    lines = ""
    with open(read_path, "r") as reader:
        reader = reader.readlines()

        is_char = False
        for i in reader:
            if len(i.split()) == 1:
                if i.strip() == name.upper():
                    is_char = True
                elif i.strip() == i.strip().upper():
                    is_char = False

                continue

            if is_char:
                lines += i.strip().strip(",") + " "

    formatted = ""

    for i in lines.split(" "):
        if not(i == i.upper or i == '\t'):
            formatted += i + " "

    with open(file_path, "w") as writer:
        writer.write(formatted)


def generate_formatted_text(path, force=False):
    path = "./" + path + ".txt"
    write_path = './formatted_text.txt'

    if not force and exists(write_path):
        return

    fixed = []

    with open('./full_text.txt', "r", errors="replace") as reader:
        lines = reader.readlines()

        for i in lines:
            if not ("FTLN" in i.split(" ") or "ACT" in i.split(" ") or "SCENE" in i.split(" ")):
                fixed.append(i)

    with open(write_path, "w") as writer:
        for i in fixed:
            writer.write(i.strip() + '\n')


if __name__ == '__main__':
    generate_formatted_text("full_text", force=True)
    parse_character("formatted_text", "hamlet", force=True)
