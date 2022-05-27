from dataclass import CarDC
import pytest
import unittest
import numpy as np
import requests

from services import ParkingLotService


# class ApiTest(unittest.TestCase):
#     # def test_get_parking_lot_fail(self):
#     #     r = requests.get("http://localhost:8000/")
#     #     self.assertEqual(r.status_code, 200)
#     #     self.assertEqual(r.json(), {"message": "No parking lot available"})

#     def test_post_parking_lot_success(self):
#         r = requests.post("http://localhost:8000/", json={"capacity": 6})
#         self.assertEqual(r.json(), {"capacity": 6, "parked_slots": {}})


class ServiceTest(unittest.TestCase):
    service = ParkingLotService()

    @classmethod
    def setUpClass(cls):
        print("Starting all the tests.")

    def setUp(self):
        self.service.create_parking_lot(7)
        print("Starting another test.")

    def test_service_create(self):
        parking_lot = ParkingLotService().create_parking_lot(6)
        self.assertIsNotNone(parking_lot)
        self.assertEqual(parking_lot.capacity, 6)
        self.assertEqual(parking_lot.parked_slots, {})

    def test_get_parking_lot_get_expect_parking_lot(self):
        parking_lot = self.service.get_parking_lot()
        self.assertIsNotNone(parking_lot)
        self.assertEqual(parking_lot.capacity, 7)
        self.assertEqual(parking_lot.parked_slots, {})

    def test_post_parking_lot_park_expect_park(self):
        parking_lot = self.service.get_parking_lot()
        self.assertIsNotNone(parking_lot)
        self.assertEqual(parking_lot.capacity, 7)
        self.assertEqual(parking_lot.parked_slots, {})

        car_dc = CarDC(car_id=1, color="red")
        self.service.park(car_dc)
        self.assertEqual(parking_lot.parked_slots, {0: car_dc})

    def test_get_parking_lot_colors_red_expect_slot_id_0(self):
        parking_lot = self.service.get_parking_lot()

        car_dc = CarDC(car_id=1, color="red")
        self.service.park(car_dc)
        self.assertEqual(parking_lot.parked_slots, {0: car_dc})

        slots = self.service.get_parking_slots_by_color(car_dc.color)
        self.assertEqual(slots, [0])
