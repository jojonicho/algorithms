from dataclasses import dataclass
from typing import Optional


@dataclass
class CarDC:
    car_id: str
    color: str


@dataclass
class ParkingLotDC:
    capacity: int


@dataclass
class ParkingLotLeaveDC:
    slot_id: int
