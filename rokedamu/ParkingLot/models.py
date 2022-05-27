from dataclass import CarDC
from dataclasses import dataclass, field
import threading
import collections


@dataclass()
class ParkingLot(object):
    capacity: int
    parked_slots: dict = field(default_factory=dict)

    def __init__(self, capacity):
        self.__lock = threading.Lock()
        self.capacity = capacity
        self.parked_slots: dict[int, CarDC] = {}  # slot id, car_dc
        self.__color_to_parking_slots = collections.defaultdict(set)

    def is_available(self, slot_id):
        return slot_id not in self.parked_slots

    def park(self, car_dc):
        self.__lock.acquire()
        slot_id = -1
        for i in range(self.capacity):
            if self.is_available(i):
                slot_id = i
                break
        self.__lock.release()
        self.parked_slots[slot_id] = car_dc
        return slot_id

    def unpark(self, slot_id):
        car_dc = self.parked_slots[slot_id]
        del self.parked_slots[slot_id]

        color = car_dc.color
        self.__color_to_parking_slots[color].remove(slot_id)

    def get_parking_slots_by_color(self, color):
        return self.__color_to_parking_slots[color]

    def append_parking_slot_by_color(self, color, slot_id):
        self.__color_to_parking_slots[color].add(slot_id)
