from testcase.commands import Command


def check_parking_lot_error(parking_lot):
    if parking_lot is None:
        return {"message": "No parking lot available"}
    return None


def check_car_id_in_parking_lot(parking_lot, slot_id):
    if slot_id not in parking_lot.parked_slots:
        return {"message": "Car not parked"}
    return None


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
