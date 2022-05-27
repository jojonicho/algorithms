from commands import Command


def execute(line) -> bool:
    raw_command = line.split()
    command = raw_command[0]
    args = raw_command[1:]

    if command == Command.EXIT.value:
        return 1
    print(command, args)
    return 0


with open("testcase/in.txt") as f:
    lines = f.readlines()
    print(lines)
    for line in lines:
        if execute(line):
            break
