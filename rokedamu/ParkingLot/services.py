from dataclass import CarDC
from models import ParkingLot


class ParkingLotService(object):
    def __init__(self) -> None:
        self.parking_lot = None

    def create_parking_lot(self, capacity: int):
        if self.parking_lot is None:
            self.parking_lot = ParkingLot(capacity)
        return self.parking_lot

    def get_parking_lot(self):
        return self.parking_lot

    def park(self, car_dc: CarDC):
        slot_id = self.parking_lot.park(car_dc)
        if slot_id == -1:
            return {"error": "Parking lot full!"}
        self.parking_lot.append_parking_slot_by_color(car_dc.color, slot_id)
        return slot_id

    def leave(self, slot_id: int):
        self.parking_lot.unpark(slot_id)

    def get_parking_slots_by_color(self, color: str):
        return list(self.parking_lot.get_parking_slots_by_color(color=color))
