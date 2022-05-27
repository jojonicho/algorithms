from enum import Enum


class Command(Enum):
    CREATE_PARKING_LOT = "create_parking_lot"
    REGISTRATION_NUMBERS_FOR_CARS_WITH_COLOUR = (
        "registration_numbers_for_cars_with_colour"
    )
    SLOT_NUMBERS_FOR_CARS_WITH_COLOUR = "slot_numbers_for_cars_with_colour"
    PARK = "park"
    STATUS = "status"
    LEAVE = "leave"
    EXIT = "exit"
